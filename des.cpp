#include <windows.h>
#include "des.h"
#include <stack>
#include <math.h>
#include <string>
#include <algorithm>
#include <bitset>
#include <random>
#include "QDebug"
DES::DES() {}

string DES::charpad(string str1) {
    string temp_str = "";
    int divide_times = (str1.size() % 8 ? str1.size() / 8 + 1 : str1.size() / 8);		//计算分组个数
    for (int i = 0; i < divide_times; i++) {										//每个分组单独转换成二进制串
        string str1_temp = str1.substr(8 * i, 8);  //substr(start,len)
        bool jude = false;
        int addchars = 0;
        //是否取整？要加多少padding字节
        if (str1_temp.size() % 8) {
            jude = true;
            addchars = 8 - str1_temp.size() % 8;
        }
        int sub = str1_temp.size() * 8;
        //由于无法填充NUL（二进制全0），因此先填上a
        if (jude) {
            for (int i = 0; i < addchars; i++) {
                str1_temp += 'a';
            }
        }
        str1_temp = des_StrToBitStr(str1_temp);
        //把a所在二进制位换为0
        if (jude) {
            for (int i = 0; i < addchars * 8; i++) {
                str1_temp[sub+i] = '0';
            }
        }
        temp_str += str1_temp;

    }
    return temp_str;
}

string DES::charpadH(string str1) {
    string temp_str = "";
    int divide_times = (str1.size() % 16 ? str1.size() / 16 + 1 : str1.size() / 16);		//计算分组个数
    for (int i = 0; i < divide_times; i++) {										//每个分组单独转换成二进制串
        string str1_temp = str1.substr(16 * i, 16);  //substr(start,len)
        bool jude = false;
        int addchars = 0;
        //是否取整？要加多少padding字节
        if (str1_temp.size() % 16) {
            jude = true;
            addchars = 16 - str1_temp.size() % 16;
        }
        int sub = str1_temp.size() * 4;
        //由于无法填充NUL（二进制全0），因此先填上a
        if (jude) {
            for (int i = 0; i < addchars; i++) {
                str1_temp += 'a';
            }
        }
        str1_temp = des_H(str1_temp);
        //把a所在二进制位换为0
        if (jude) {
            for (int i = 0; i < addchars * 4; i++) {
                str1_temp[sub+i] = '0';
            }
        }
        temp_str += str1_temp;

    }
    return temp_str;
}

//8字节字符串转64位二进制字符串
string DES::des_StrToBitStr(string str)
{
    bitset<64> bstr;
    for (int i = 0; i < 8; i++)
    {
        bitset<8> bits = bitset<8>(str[i]);
        for (int j = 0; j < 8; j++)
        {
            bstr[i * 8 + j] = bits[7 - j];
        }
    }
    string s = bstr.to_string();
    //添加一个翻转操作
    reverse(begin(s), end(s));
    return s;
}

/**

 *最终置换函数 64位->64位

 *函数说明：s为完成最后一轮循环得到的64为数据

 *返回值为密文或明文

 */
string DES::final_permutation(string s)
{
    string rs = "";
    rs.reserve(64);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rs += s[T6[i][j] - 1];
        }
    }
    return rs;
}

/**

 *P盒置换函数 32位->32位

 *函数说明：s为S盒的输出

 */
string DES::P_box(string s)
{
    string rs = "";
    rs.reserve(32);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rs += (s[P[i][j] - 1]);
        }
    }
    return rs;
}

/**

 *S盒置换函数 48位->32位

 *函数说明：s为48位数据

 *返回值为32位

 */
string DES::S_box(string s)
{
    string rs = "";
    rs.reserve(32);
    string s1;
    int k1, k2;//S盒的行号和列号
    int h = 1;//决定使用哪个S盒
    //使用 for 循环遍历输入字符串 s，每次处理 6 位，并选择相应的 S 盒（h 从 1 到 8）
    for (int i = 0; i <= 42; i = i + 6, h++)
    {
        //根据当前 6 位子串计算 S 盒的行号 k1 和列号 k2。
        k1 = (s[i] - '0') * 2 + (s[i + 5] - '0') * 1;//根据第一位和最后一位来计算行号
        k2 = (s[i + 1] - '0') * 8 + (s[i + 2] - '0') * 4 + (s[i + 3] - '0') * 2 + (s[i + 4] - '0') * 1;//根据中间四位计算列号
        int x = S[h - 1][k1][k2];
        s1 = "";
        int y = 8;
        //获取X的每个二进制位
        for (int j = 1; j <= 4; j++)
        {
            if (x < y)
            {
                s1 += "0";
                y /= 2;
            }
            else
            {
                s1 += "1";
                x = x % y;
                y /= 2;
            }
        }
        rs += s1;
    }
    return rs;
}

/**

 *异或运算函数

 *要求位数相同

 */
string DES::desXOR(string s1, string s2)
{
    string rs = "";
    rs.reserve(s1.size());
    for (int i = 0; i < s1.length() && i < s2.length(); i++)
    {
        rs += ((s1[i] - '0') ^ (s2[i] - '0')) + '0';
    }
    return rs;
}

/**

 *数据扩展函数 32->48

 *函数说明：s为数据的右半部分 32位

 *扩展成48位的输出

 */
string DES::plaintext_righthalf_extended_permutation(string s)
{
    string rs = "";
    rs.reserve(48);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rs += s[T5[i][j] - 1];
        }
    }
    return rs;
}

/**

 *密钥压缩置换函数 56位->48位

 *函数说明：s为56为的密钥

 *输出为48位的子密钥

 */
string DES::secret_key_compression_replacement(string s)
{
    string rs = "";
    rs.reserve(48);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rs += s[T4[i][j] - 1];
        }
    }
    return rs;
}

/**

 *密钥循环左移函数 56位->56位

 *函数说明：k为左移位数 s为密钥

 *返回值位数不变

 */
string DES::secret_ket_left_move(int k, string s)//密钥循环左移k位
{
    string s1 = s.substr(0, 28);
    string s2 = s.substr(28, 28);
    string rs = s1.substr(k, 28 - k) + s1.substr(0, k) + s2.substr(k, 28 - k) + s2.substr(0, k);
    return rs;
}

/**

 *密钥初始置换函数 64位->56位

 *函数说明：s为64位的初始密钥

 *返回值为56位

 */
string DES::secret_key_initial_permutation(string s)
{

    string rs = "";
    rs.reserve(56);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            rs += s[T2[i][j] - 1];
        }
    }

    return rs;
}

/**

 *明文初始置换函数 64位->64位

 *函数说明：s为初始明文 64位

 *返回值为6位

 */
string DES::plaintext_initial_permutation(string s)//明文初始置换
{
    string rs = "";
    rs.reserve(64);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            rs += s[T1[i][j] - 1];
        }
    }
    return rs;
}

/**

 *16进制转2进制函数

 *函数说明：s为16进制字符串

 *返回为2进制字符串

 */
string DES::des_H(string s)
{
    string s1;
    string rs = "",rs_mid="";
    for (int i = 0; i < s.length(); i++)
    {
        int x;
        if (s[i] >= '0' && s[i] <= '9')
        {
            x = s[i] - '0';
        }
        else
        {
            x = s[i] - 'A' + 10;
        }
        s1 = "";
        int y = 8;
        for (int j = 1; j <= 4; j++)
        {
            if (x < y)
            {
                y /= 2;
                s1 += "0";
            }
            else
            {
                s1 += "1";
                x = x % y;
                y = y / 2;
            }
        }
        if(s.length()<=500) rs += s1;
        else{
            rs_mid+=s1;
            if(i%500==0 || i==(s.length()-1)){
                rs+=rs_mid;
                rs_mid="";
            }
        }
    }
    return rs;
}

/**

*2进制转16进制函数

*str为2进制字符串

*返回值为16进制字符串

*/
string DES::des_G(string str)
{
    string rs = "";
    rs.reserve(str.size()/4);
    char temp;
    for (int i = 0; i <= str.length() - 4; i = i + 4)
    {
        int x = (str[i] - '0') * 8 + (str[i + 1] - '0') * 4 + (str[i + 2] - '0') * 2 + str[i + 3] - '0';

        if (x >= 10)
        {
            temp = (char)(x - 10 + 'A');
        }
        else
        {
            temp = (char)(x + '0');
        }
        rs += temp;
    }
    return rs;
}

/**

 *封装函数f

 *函数说明：接收32位数据和48位的子密钥 产生一个32位的输出

 *str1:32位数据  str2:48位的子密钥

 *返回值32位

 */

string DES::des_f(string str1, string str2)
{
    string expendR = plaintext_righthalf_extended_permutation(str1);
    //cout<<"32位数据扩展为48位结果:"<<expendR<<endl;

    string rs = desXOR(expendR, str2);
    //cout<<"密钥和扩展数据异或结果:"<<rs<<endl;

    rs = S_box(rs);
    //cout<<"S盒替代结果(48->32):"<<rs<<endl;

    rs = P_box(rs);
    //cout<<"P盒替代结果(32->32):"<<rs<<endl;

    return rs;
}

/**

 *子密钥生成函数

 *函数说明：s为给定的密钥

 *生成16个子密钥

 */


void DES::des_generateKeys(string s)
{

    s = secret_key_initial_permutation(s);

    for (int i = 1; i <= 16; i++)
    {
        s = secret_ket_left_move(T3[i - 1], s);
        desKeys[i] = secret_key_compression_replacement(s);
    }
}
/*
* 0/1字符串装换为字符形式的字符串
*/
string DES::des_BitStrToStr(string bstr)
{
    string str = "";
    //每八位转化成十进制，然后将数字结果转化成字符
    int sum;
    for (int i = 0; i < bstr.size(); i += 8)
    {
        sum = 0;
        for (int j = 0; j < 8; j++)
            if (bstr[i + j] == '1')
                sum = sum * 2 + 1;
            else
                sum = sum * 2;
        if(sum==0) str+=' ';
        else str += char(sum);
    }
    return str;

}

string DES::des_HToStr(string hstr){
    hstr=des_H(hstr);
    hstr=des_BitStrToStr(hstr);
    return hstr;
}
string DES::des_LongLongToStr(uint64_t IV){
    stack<int> binarystack;
    string s="";
    while(IV>0){
        int i=IV%2;
        IV=(IV-i)/2;
        binarystack.push(i);
    }
    if(binarystack.size()<64){
        for(int i=0;i<64-binarystack.size();i++){
            s+='0';
        }
    }
    while(!binarystack.empty()){
        int i=binarystack.top();
        binarystack.pop();
        s+=('0'+i);
    }
    return s;
}

string DES::des_LongToStr(uint32_t IV){
    stack<int> binarystack;
    string s="";
    while(IV>0){
        int i=IV%2;
        IV=(IV-i)/2;
        binarystack.push(i);
    }
    if(binarystack.size()<32){
        for(int i=0;i<32-binarystack.size();i++){
            s+='0';
        }
    }
    while(!binarystack.empty()){
        int i=binarystack.top();
        binarystack.pop();
        s+=('0'+i);
    }
    return s;
}

string DES::des_2To32(string str){
    string rs = "";
    rs.reserve(str.size()/5);
    char temp;
    for (int i = 0; i <= str.length() - 5; i = i + 5)
    {
        int x = (str[i] - '0') * 16 + (str[i + 1] - '0') * 8 + (str[i + 2] - '0') * 4 + (str[i + 3] - '0')*2+(str[i + 4]-'0');

        if (x >= 10)
        {
            temp = (char)(x - 10 + 'a');
        }
        else
        {
            temp = (char)(x + '0');
        }
        rs += temp;
    }
    return rs;
}

string DES::longToA(long n,int radix)    //n是待转数字，radix是指定的进制
{
    string ans="";
    do{
        long t=n%radix;
        if(t>=0&&t<=9)	ans+=t+'0';
        else ans+=t-10+'a';
        n/=radix;
    }while(n!=0);	//使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(),ans.end());
    return ans;
}

string DES::uint_32ToA(uint32_t n,int radix)    //n是待转数字，radix是指定的进制
{
    string ans="";
    do{
        uint32_t t=n%radix;
        if(t>=0&&t<=9)	ans+=t+'0';
        else ans+=t-10+'a';
        n/=radix;
    }while(n!=0);	//使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(),ans.end());
    return ans;
}

/**

 *DES加密函数 64位->64位

 *函数说明：str1为64位的给定明文

 *返回值为64位的密文

 */

string DES::des_encrypt_ECB(string str1, string str2)
{
    str1 = charpad(str1);  //明文分组和填充，返回01字符串
    str2 = des_StrToBitStr(str2);

    des_generateKeys(str2);  //生成16个子密钥

    int divi_times = str1.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str1.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str1.substr(i*100*64,6400);
        }
        rs_array[size-1]=str1.substr((size-1)*100*64,(str1.size()-100*64*(size-1)));
    }
    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str1_temp = str1.substr(i * 64, 64);

            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            rs_temp += rs;
        }
        else{
            string str1_temp = rs_array[i/100].substr((i%100) * 64, 64);
            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0){
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }

    return des_G(rs_temp);
}

string DES::des_encryptforImage_ECB(string str1, string str2)
{
    str1 = charpadH(str1);  //明文分组和填充，返回01字符串
    str2 = des_StrToBitStr(str2);

    des_generateKeys(str2);  //生成16个子密钥


    int divi_times = str1.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str1.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str1.substr(i*100*64,6400);
        }
        rs_array[size-1]=str1.substr((size-1)*100*64,(str1.size()-100*64*(size-1)));
    }
    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str1_temp = str1.substr(i * 64, 64);

            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            rs_temp += rs;
        }
        else{
            string str1_temp = rs_array[i/100].substr((i%100) * 64, 64);

            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0) {
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }

    return des_G(rs_temp);
}

/**

*解密函数

*str为密文

*输出明文

*/
string DES::des_decrypt_ECB(string str,string str2)
{
    str=des_H(str);
    int divi_times = str.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str.substr(i*100*64,6400);
        }
        rs_array[size-1]=str.substr((size-1)*100*64,(str.size()-100*64*(size-1)));
    };
    str2 = des_StrToBitStr(str2);
    des_generateKeys(str2);

    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str_temp = str.substr(i * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            rs_temp = rs_temp + rs;
        }
        else{
            string str_temp = rs_array[i/100].substr((i%100) * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0) {
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }
    rs_temp = des_BitStrToStr(rs_temp);
    return rs_temp;
}

string DES::des_decryptforImage_ECB(string str,string str2)
{
    int i=str.length();
    str=charpadH(str);
    int divi_times = str.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str.substr(i*100*64,6400);
        }
        rs_array[size-1]=str.substr((size-1)*100*64,(str.size()-100*64*(size-1)));
    }
    str2 = des_StrToBitStr(str2);
    des_generateKeys(str2);

    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str_temp = str.substr(i * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            rs_temp = rs_temp + rs;
        }
        else{
            string str_temp = rs_array[i/100].substr((i%100) * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0){
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }
    rs_temp = des_G(rs_temp);
    return rs_temp;
}

bool DES::weakkey_detect(string str){
    string s[4]={"0101010101010101","1F1F1F1F0E0E0E0E","E0E0E0E0F1F1F1F1","FEFEFEFEFEFEFEFE"};
    for(int i=0;i<4;i++){
        if(str==s[i]) return true;
    }
    return false;
}

string DES::des_encrypt_CBC(string str1, string str2)
{
    int i=0,j=0;
    str1 = charpad(str1);  //明文分组和填充，返回01字符串
    str2 = des_StrToBitStr(str2);
    des_generateKeys(str2);  //生成16个子密钥


    int divi_times = str1.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str1.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str1.substr(i*100*64,6400);
        }
        rs_array[size-1]=str1.substr((size-1)*100*64,(str1.size()-100*64*(size-1)));
    }
    string last="";

    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str1_temp = str1.substr(i * 64, 64);
            if(!i){
                str1_temp= desXOR(str1_temp,IV);
            }
            else{
                str1_temp= desXOR(str1_temp,last);
            }
            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            last=rs;
            rs_temp = rs_temp + rs;
        }
        else{
            string str1_temp = rs_array[i/100].substr((i%100) * 64, 64);
            if(!i){
                str1_temp= desXOR(str1_temp,IV);
            }
            else{
                str1_temp= desXOR(str1_temp,last);
            }
            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            last=rs;
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0) {
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }

    return des_G(rs_temp);
}

string DES::des_encryptforImage_CBC(string str1, string str2)
{
    int i=0,j=0;
    str1 = charpadH(str1);  //明文分组和填充，返回01字符串
    str2 = des_StrToBitStr(str2);
    des_generateKeys(str2);  //生成16个子密钥


    int divi_times = str1.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str1.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str1.substr(i*100*64,6400);
        }
        rs_array[size-1]=str1.substr((size-1)*100*64,(str1.size()-100*64*(size-1)));
    }
    string last="";

    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str1_temp = str1.substr(i * 64, 64);
            if(!i){
                str1_temp= desXOR(str1_temp,IV);
            }
            else{
                str1_temp= desXOR(str1_temp,last);
            }
            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            last=rs;
            rs_temp = rs_temp + rs;
        }
        else{
            string str1_temp = rs_array[i/100].substr((i%100) * 64, 64);
            if(!i){
                str1_temp= desXOR(str1_temp,IV);
            }
            else{
                str1_temp= desXOR(str1_temp,last);
            }
            //第一步:明文初始置换 64->64
            str1_temp = plaintext_initial_permutation(str1_temp);

            //第二步:数据分组
            string left = str1_temp.substr(0, 32);
            string right = str1_temp.substr(32, 32);
            string newleft;

            //第三步:16轮迭代
            for (int i = 1; i <= 16; i++)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //第四步:合并数据 注意位R16L16
            string rs = right + left;

            //结尾置换
            rs = final_permutation(rs);
            last=rs;
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0) {
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }

    return des_G(rs_temp);
}

string DES::des_decrypt_CBC(string str, string str2)
{
    str=des_H(str);
    int divi_times = str.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str.substr(i*100*64,6400);
        }
        rs_array[size-1]=str.substr((size-1)*100*64,(str.size()-100*64*(size-1)));
    }
    string last="";
    str2 = des_StrToBitStr(str2);
    des_generateKeys(str2);  //生成16个子密钥
    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str_temp = str.substr(i * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            if(!i){
                rs= desXOR(rs,IV);
            }
            else{
                rs= desXOR(rs,last);
            }
            last=str.substr(i * 64, 64);
            rs_temp = rs_temp + rs;
        }
        else{
            string str_temp = rs_array[i/100].substr((i%100) * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            if(!i){
                rs= desXOR(rs,IV);
            }
            else{
                rs= desXOR(rs,last);
            }
            last=str.substr(i * 64, 64);
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0) {
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }
    rs_temp = des_BitStrToStr(rs_temp);
    return rs_temp;
}

string DES::des_decryptforImage_CBC(string str, string str2)
{
    str=charpadH(str);
    int divi_times = str.size() / 64;  //分成多少组去进行des
    string rs_temp = "",rs_mid="";
    string *rs_array;
    int size;
    rs_temp.reserve(str.size());
    rs_mid.reserve(6400);
    if(divi_times>100){
        int full=divi_times%100;
        size=divi_times/100;
        if(full!=0) size=size+1;
        rs_array=new string[size];
        for(int i=0;i<size-1;i++){
            rs_array[i]=str.substr(i*100*64,6400);
        }
        rs_array[size-1]=str.substr((size-1)*100*64,(str.size()-100*64*(size-1)));
    }
    string last="";
    str2 = des_StrToBitStr(str2);
    des_generateKeys(str2);  //生成16个子密钥
    for (int i = 0; i < divi_times; ++i) {
        if(divi_times<=100){
            string str_temp = str.substr(i * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            if(!i){
                rs= desXOR(rs,IV);
            }
            else{
                rs= desXOR(rs,last);
            }
            last=str.substr(i * 64, 64);
            rs_temp = rs_temp + rs;
        }
        else{
            string str_temp = rs_array[i/100].substr((i%100) * 64, 64);
            //把密文当作明文进行初始明文置换
            str_temp = plaintext_initial_permutation(str_temp);

            //左右分组
            string left = str_temp.substr(0, 32);
            string right = str_temp.substr(32, 32);

            string newleft;

            //逆序的子密钥使用 16轮迭代
            for (int i = 16; i >= 1; i--)
            {
                newleft = right;
                right = desXOR(left, des_f(right, desKeys[i]));
                left = newleft;
            }

            //合并
            string rs = right + left;

            //最后置换
            rs = final_permutation(rs);
            if(!i){
                rs= desXOR(rs,IV);
            }
            else{
                rs= desXOR(rs,last);
            }
            last=str.substr(i * 64, 64);
            rs_mid += rs;
            if(i%100==99 || i==divi_times-1){
                rs_temp+=rs_mid;
                rs_mid="";
            }
        }
        if(divi_times>100 && i%(divi_times/100)==0 && divi_times!=0) {
            qDebug() <<"des "<<(i/(float)divi_times)*100<<"%";
            emit send2image((i/(float)divi_times)*100);
        }
    }
    rs_temp = des_G(rs_temp);
    return rs_temp;
}

string DES::threeDes_encrypt(string str1,string str2,int mode3des,int modedes)
{
    if(mode3des==0){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_encrypt_ECB(str1,str2_1);
            str1=des_encrypt_ECB(str1,str2_2);
            str1=des_encrypt_ECB(str1,str2_3);
        }
        else{
            IVgenerate();
            str1=des_encrypt_CBC(str1,str2_1);
            str1=des_encrypt_CBC(str1,str2_2);
            str1=des_encrypt_CBC(str1,str2_3);
        }
    }
    else if(mode3des==1){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_encrypt_ECB(str1,str2_1);
            str1=des_decrypt_ECB(str1,str2_2);
            str1=des_encrypt_ECB(str1,str2_3);
        }
        else{
            IVgenerate();
            str1=des_encrypt_CBC(str1,str2_1);
            str1=des_decrypt_CBC(str1,str2_2);
            str1=des_encrypt_CBC(str1,str2_3);
        }
    }
    else if(mode3des==2){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_encrypt_ECB(str1,str2_1);
            str1=des_encrypt_ECB(str1,str2_2);
            str1=des_encrypt_ECB(str1,str2_1);
        }
        else{
            IVgenerate();
            str1=des_encrypt_CBC(str1,str2_1);
            str1=des_encrypt_CBC(str1,str2_2);
            str1=des_encrypt_CBC(str1,str2_1);
        }
    }
    else if(mode3des==3){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_encrypt_ECB(str1,str2_1);
            str1=des_decrypt_ECB(str1,str2_2);
            str1=des_encrypt_ECB(str1,str2_1);
        }
        else{
            IVgenerate();
            str1=des_encrypt_CBC(str1,str2_1);
            str1=des_decrypt_CBC(str1,str2_2);
            str1=des_encrypt_CBC(str1,str2_1);
        }
    }
    return str1;
}

string DES::threeDesforImage_encrypt(string str1,string str2,int mode3des,int modedes)
{
    if(mode3des==0){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_encryptforImage_ECB(str1,str2_1);
            str1=des_encryptforImage_ECB(str1,str2_2);
            str1=des_encryptforImage_ECB(str1,str2_3);
        }
        else{
            IVgenerate();
            str1=des_encryptforImage_CBC(str1,str2_1);
            str1=des_encryptforImage_CBC(str1,str2_2);
            str1=des_encryptforImage_CBC(str1,str2_3);
        }
    }
    else if(mode3des==1){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_encryptforImage_ECB(str1,str2_1);
            str1=des_decryptforImage_ECB(str1,str2_2);
            str1=des_encryptforImage_ECB(str1,str2_3);
        }
        else{
            IVgenerate();
            str1=des_encryptforImage_CBC(str1,str2_1);
            str1=des_decryptforImage_CBC(str1,str2_2);
            str1=des_encryptforImage_CBC(str1,str2_3);
        }
    }
    else if(mode3des==2){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_encryptforImage_ECB(str1,str2_1);
            str1=des_encryptforImage_ECB(str1,str2_2);
            str1=des_encryptforImage_ECB(str1,str2_1);
        }
        else{
            IVgenerate();
            str1=des_encryptforImage_CBC(str1,str2_1);
            str1=des_encryptforImage_CBC(str1,str2_2);
            str1=des_encryptforImage_CBC(str1,str2_1);
        }
    }
    else if(mode3des==3){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_encryptforImage_ECB(str1,str2_1);
            str1=des_decryptforImage_ECB(str1,str2_2);
            str1=des_encryptforImage_ECB(str1,str2_1);
        }
        else{
            IVgenerate();
            str1=des_encryptforImage_CBC(str1,str2_1);
            str1=des_decryptforImage_CBC(str1,str2_2);
            str1=des_encryptforImage_CBC(str1,str2_1);
        }
    }
    return str1;
}

string DES::threeDes_decrypt(string str1,string str2,int mode3des,int modedes)
{
    if(mode3des==0){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_decrypt_ECB(str1,str2_3);
            str1=des_decrypt_ECB(str1,str2_2);
            str1=des_decrypt_ECB(str1,str2_1);
        }
        else{
            str1=des_decrypt_CBC(str1,str2_3);
            str1=des_decrypt_CBC(str1,str2_2);
            str1=des_decrypt_CBC(str1,str2_1);
        }
    }
    else if(mode3des==1){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_decrypt_ECB(str1,str2_3);
            str1=des_encrypt_ECB(str1,str2_2);
            str1=des_decrypt_ECB(str1,str2_1);
        }
        else{
            str1=des_decrypt_CBC(str1,str2_3);
            str1=des_encrypt_CBC(str1,str2_2);
            str1=des_decrypt_CBC(str1,str2_1);
        }
    }
    else if(mode3des==2){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_decrypt_ECB(str1,str2_1);
            str1=des_decrypt_ECB(str1,str2_2);
            str1=des_decrypt_ECB(str1,str2_1);
        }
        else{
            str1=des_decrypt_CBC(str1,str2_1);
            str1=des_decrypt_CBC(str1,str2_2);
            str1=des_decrypt_CBC(str1,str2_1);
        }
    }
    else if(mode3des==3){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_decrypt_ECB(str1,str2_1);
            str1=des_encrypt_ECB(str1,str2_2);
            str1=des_decrypt_ECB(str1,str2_1);
        }
        else{
            str1=des_decrypt_CBC(str1,str2_1);
            str1=des_encrypt_CBC(str1,str2_2);
            str1=des_decrypt_CBC(str1,str2_1);
        }
    }
    return str1;
}

string DES::threeDesforImage_decrypt(string str1,string str2,int mode3des,int modedes)
{
    if(mode3des==0){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_decryptforImage_ECB(str1,str2_3);
            str1=des_decryptforImage_ECB(str1,str2_2);
            str1=des_decryptforImage_ECB(str1,str2_1);
        }
        else{
            str1=des_decryptforImage_CBC(str1,str2_3);
            str1=des_decryptforImage_CBC(str1,str2_2);
            str1=des_decryptforImage_CBC(str1,str2_1);
        }
    }
    else if(mode3des==1){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8),str2_3=str2.substr(16,8);
        if(!modedes){
            str1=des_decryptforImage_ECB(str1,str2_3);
            str1=des_encryptforImage_ECB(str1,str2_2);
            str1=des_decryptforImage_ECB(str1,str2_1);
        }
        else{
            str1=des_decryptforImage_CBC(str1,str2_3);
            str1=des_encryptforImage_CBC(str1,str2_2);
            str1=des_decryptforImage_CBC(str1,str2_1);
        }
    }
    else if(mode3des==2){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_decryptforImage_ECB(str1,str2_1);
            str1=des_decryptforImage_ECB(str1,str2_2);
            str1=des_decryptforImage_ECB(str1,str2_1);
        }
        else{
            str1=des_decryptforImage_CBC(str1,str2_1);
            str1=des_decryptforImage_CBC(str1,str2_2);
            str1=des_decryptforImage_CBC(str1,str2_1);
        }
    }
    else if(mode3des==3){
        string str2_1=str2.substr(0,8),str2_2=str2.substr(8,8);
        if(!modedes){
            str1=des_decryptforImage_ECB(str1,str2_1);
            str1=des_encryptforImage_ECB(str1,str2_2);
            str1=des_decryptforImage_ECB(str1,str2_1);
        }
        else{
            str1=des_decryptforImage_CBC(str1,str2_1);
            str1=des_encryptforImage_CBC(str1,str2_2);
            str1=des_decryptforImage_CBC(str1,str2_1);
        }
    }
    return str1;
}

void DES::IVgenerate(){
    std::random_device rd;
    std::mt19937_64 g2 (rd());
    uint64_t u64Random = g2();
    IV=des_LongLongToStr(u64Random);
    int i=0;
}

std::string DES::TCHAR2STRING(TCHAR *STR)
{
    int iLen = WideCharToMultiByte(CP_ACP, 0, STR, -1, NULL, 0, NULL, NULL);
    char* chRtn = new char[iLen*sizeof(char)];
    WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);
    std::string str(chRtn);
    delete chRtn;
    return str;
}

string DES::des_GToBase64(string bstr){
    string str = "";
    char base64_char[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    //每六位转化成十进制，然后将数字结果转化成字符
    int sum;
    for (int i = 0; i < bstr.size(); i += 6)
    {
        sum = 0;
        for (int j = 0; j < 6; j++)
            if (bstr[i + j] == '1')
                sum = sum * 2 + 1;
            else
                sum = sum * 2;
        str = str + base64_char[sum];
    }
    return str;
}

float DES::getPercents(){
    return percents;
}

void DES::setPercents(float a){
    this->percents=a;
}
