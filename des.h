#ifndef DES_H
#define DES_H
#include <string>
#include <tchar.h>
#include <QThread>
using namespace std;
class DES:public QObject
{
    Q_OBJECT
public:
    DES();
    ~DES(){}
    string des_encrypt_ECB(string str1, string str2);
    string des_encryptforImage_ECB(string str1, string str2);
    string des_encrypt_CBC(string str1, string str2);
    string des_encryptforImage_CBC(string str1, string str2);
    string des_decrypt_ECB(string str, string str2);
    string des_decryptforImage_ECB(string str,string str2);
    string des_decrypt_CBC(string str, string str2);
    string des_decryptforImage_CBC(string str, string str2);
    string threeDes_encrypt(string str1,string str2,int mode3des,int modedes);
    string threeDesforImage_encrypt(string str1,string str2,int mode3des,int modedes);
    string threeDes_decrypt(string str1,string str2,int mode3des,int modedes);
    string threeDesforImage_decrypt(string str1,string str2,int mode3des,int modedes);
    void IVgenerate();
    bool weakkey_detect(string str);
    string TCHAR2STRING(TCHAR *STR);
    float getPercents();
    string des_LongToStr(uint32_t IV);
    string des_LongLongToStr(uint64_t IV);
    string longToA(long n,int radix);
    string charpadH(string str1);
    string des_BitStrToStr(string bstr);
    string des_G(string str);
    string des_H(string s);
    string uint_32ToA(uint32_t n,int radix);
    string des_2To32(string str);
signals:
    void send2image(float a);
private:
    string final_permutation(string s);
    string P_box(string s);
    string S_box(string s);
    string desXOR(string s1, string s2);
    string plaintext_righthalf_extended_permutation(string s);
    string secret_key_compression_replacement(string s);
    string secret_ket_left_move(int k, string s);
    string secret_key_initial_permutation(string s);
    string plaintext_initial_permutation(string s);
    string des_f(string str1, string str2);
    void des_generateKeys(string s);
    string des_HToStr(string hstr);
    string des_GToBase64(string s);
    string des_StrToBitStr(string str);
    string charpad(string str1);
    void setPercents(float persents);
    string desKeys[20];
    string IV;
    float percents;
    //数据初始置换表
    int T1[8][8] = { 58,50,42,34,26,18,10,2,
                    60,52,44,36,28,20,12,4,
                    62,54,46,38,30,22,14,6,
                    64,56,48,40,32,24,16,8,
                    57,49,41,33,25,17,9,1,
                    59,51,43,35,27,19,11,3,
                    61,53,45,37,29,21,13,5,
                    63,55,47,39,31,23,15,7 };
    //密钥初始置换表
    int T2[8][7] = { 57,49,41,33,25,17,9,
                    1,58,50,42,34,26,18,
                    10,2,59,51,43,35,27,
                    19,11,3,60,52,44,36,
                    3,55,47,39,31,23,15,
                    7,62,54,46,38,30,22,
                    14,6,61,53,45,37,29,
                    21,13,5,28,20,12,4 };

    //密钥循环左移位数表
    int T3[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };

    //密钥压缩置换表
    int T4[8][6] = { 14,17,11,24,1,5,
                    3,28,15,6,21,10,
                    23,19,12,4,26,8,
                    16,7,27,20,13,2,
                    41,52,31,37,47,55,
                    30,40,51,45,33,48,
                    44,49,39,56,34,53,
                    46,42,50,36,29,32 };

    //数据扩展表
    int T5[8][6] = { 32,1,2,3,4,5,
                    4,5,6,7,8,9,
                    8,9,10,11,12,13,
                    12,13,14,15,16,17,
                    16,17,18,19,20,21,
                    20,21,22,23,24,25,
                    24,25,26,27,28,29,
                    28,29,30,31,32,1 };

    //S盒置换表
    int S[8][4][16] = { {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
                       {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},{ 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{ 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
                       {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
                       {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
                       {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
                       {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
                       {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
                       {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}} };

    //P盒置换表
    int P[4][8] = { 16,7,20,21,
                   29,12,28,17,
                   1,15,23,26,
                   5,18,31,10,
                   2,8,24,14,
                   32,27,3,9,
                   19,13,30,6,
                   22,11,4,25 };

    //最终置换表
    int T6[8][8] = { 40,8,48,16,56,24,64,32,
                    39,7,47,15,55,23,63,31,
                    38,6,46,14,54,22,62,30,
                    37,5,45,13,53,21,61,29,
                    36,4,44,12,52,20,60,28,
                    35,3,43,11,51,19,59,27,
                    34,2,42,10,50,18,58,26,
                    33,1,41,9,49,17,57,25 };
};

#endif // DES_H
