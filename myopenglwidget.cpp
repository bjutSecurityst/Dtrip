#include "myopenglwidget.h"
#include "QFile"
#include "QuickSort.h"
#include "QImageReader"
#include "QMouseEvent"
#include "math.h"
//3D模型展示界面
MyOpenGLWidget::MyOpenGLWidget(int mode,QWidget *parent):QOpenGLWidget(parent)
{
    int i=0;
    connect(&tm_,&QTimer::timeout,this,&MyOpenGLWidget::slotTimeout);
    tm_.start(30);
    this->mode=mode;
}
//opengl初始函数
void MyOpenGLWidget::initializeGL()
{
    // 1.初始化OpenGL函数，否则OpenGL函数不可调用
    initializeOpenGLFunctions();
    //设置着色器
    program_.addCacheableShaderFromSourceFile(QOpenGLShader::Vertex,":/box.vert");
    program_.addCacheableShaderFromSourceFile(QOpenGLShader::Fragment,":/box.frag");
    program_.link();
    //加载模型
    load();
    load2();
    //创建缓冲区
    vbo_.create();
    vbo_.bind();
    vbo_.allocate(mMeshDataBuffer.data(),mMeshDataBuffer.size() * sizeof(float));
    //加载材质
    QImage textureSrc;
    //冠军材质
    if(mode==1){
        textureSrc = QImage(pathCreator("gold.png"));;
        if (textureSrc.isNull()) {
            qDebug() << "not find picture" << "\n";
            return;
        } else {
            qDebug() << textureSrc.format();
        }
    }
    //一般材质
    else{
        QImageReader reader(pathCreator("Color Map2.jpg"));
        reader.setScaledSize(QSize(8000, 4000));  // 缩放图片到适当大小，减少内存消耗
        reader.setAutoTransform(true);
        textureSrc = reader.read();
        //QImage textureSrc(":/gradbackground.png");
        if (textureSrc.isNull()) {
            qDebug() << "not find picture" << "\n";
            return;
        } else {
            qDebug() << textureSrc.format();
        }
    }
    textureSrc = textureSrc.convertToFormat(QImage::Format_RGB888);
    texture_ = new QOpenGLTexture(textureSrc);
    texture_->setWrapMode(QOpenGLTexture::Repeat);
    texture_->setMinMagFilters(QOpenGLTexture::Nearest,QOpenGLTexture::Linear);
    //设置摄像机位置
    cameraLocation_.setX(0);
    cameraLocation_.setY(aty);
    cameraLocation_.setZ(3);
    // cameraLocation_.setX(0);
    // cameraLocation_.setY(10);
    // cameraLocation_.setZ(23);
    //设置光源位置
    lightLocation_.setX(120);
    lightLocation_.setY(120);
    lightLocation_.setZ(120);
}
//改变显示区域大小
void MyOpenGLWidget::resizeGL(int w, int h)
{
    pMatrix_.setToIdentity();
    pMatrix_.perspective(45,float(w)/h,0.01f,100.0f);
}
//MYOPENGL绘制函数
void MyOpenGLWidget::paintGL()
{
    //清除内容
    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //旋转一定角度
    QMatrix4x4 vMatrix;
    //vMatrix.lookAt(cameraLocation_,QVector3D(0,10,0),QVector3D(0,1,0));
    vMatrix.lookAt(cameraLocation_,QVector3D(0,looky,0),QVector3D(0,1,0));
    QMatrix4x4 mMatrix;
    mMatrix.translate(0,-0.8);
    //    mMatrix.rotate(angleX_,1,0,0);
    mMatrix.rotate(angleY,0,1,0);
    //    mMatrix.rotate(anglZ_,0,0,1);
    render(f,pMatrix_,vMatrix,mMatrix,cameraLocation_,lightLocation_);
}
//绘制子函数
void MyOpenGLWidget::render(QOpenGLExtraFunctions *f, QMatrix4x4 &pMatrix, QMatrix4x4 &vMatrix, QMatrix4x4 &mMatrix, QVector3D &cameraLocation, QVector3D &lightCation)
{
    //绑定渲染程序与缓冲区
    //启用深度检测
    f->glEnable(GL_DEPTH_TEST);
    program_.bind();
    vbo_.bind();
    f->glActiveTexture(GL_TEXTURE0 + 0);
    program_.setUniformValue("uPMatrix",pMatrix);
    program_.setUniformValue("uVMatrix",vMatrix);
    program_.setUniformValue("uMMatrix",mMatrix);  
    program_.setUniformValue("uLightLocation",lightCation);
    program_.setUniformValue("uCamera",cameraLocation);
    program_.setUniformValue("sTexture",0);

    program_.enableAttributeArray(0);
    program_.enableAttributeArray(1);
    program_.enableAttributeArray(2);
    program_.setAttributeBuffer(0,GL_FLOAT,0,3,3*sizeof(GLfloat));
    program_.setAttributeBuffer(2,GL_FLOAT,vexCache.size() * sizeof(GLfloat),2,2*sizeof(GLfloat));
    program_.setAttributeBuffer(1,GL_FLOAT,(vexCache.size() + texCache.size()) * sizeof(GLfloat),3,3*sizeof(GLfloat));
    texture_->bind(0);
    // f->glDrawArrays(GL_TRIANGLES,0,vexCache.size()/3);
    GLuint VAO, VBO;
    // 创建 VBO 和 VAO绘制球体模型
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mMeshDataBuffer.size() * sizeof(float), mMeshDataBuffer.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindVertexArray(VAO);
    f->glDrawArrays(GL_TRIANGLES, 0, mMeshDataBuffer.size()/8);
    //2，绘制RANK模型
    program_.setAttributeBuffer(0,GL_FLOAT,0,3,3*sizeof(GLfloat));
    program_.setAttributeBuffer(2,GL_FLOAT,vexCache2.size() * sizeof(GLfloat),2,2*sizeof(GLfloat));
    program_.setAttributeBuffer(1,GL_FLOAT,(vexCache2.size() + texCache2.size()) * sizeof(GLfloat),3,3*sizeof(GLfloat));
    texture_->bind(0);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, mMeshDataBuffer2.size() * sizeof(float), mMeshDataBuffer2.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindVertexArray(VAO);
    f->glDrawArrays(GL_TRIANGLES, 0, mMeshDataBuffer2.size()/8);

    //收尾
    program_.disableAttributeArray(0);
    program_.disableAttributeArray(1);
    program_.disableAttributeArray(2);
    texture_->release();
    vbo_.release();
    program_.release();
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
    }
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
    }
    // f->glEnable(GL_CULL_FACE);
    f->glCullFace(GL_BACK); // 剔除背面，保留正面

}
//球体模型加载函数
void MyOpenGLWidget::load(){
    QFile objFile(pathCreator("earth.obj")); // 读取模型文件
    if(!objFile.open(QIODevice::ReadOnly)){
        qDebug() << "open" << "failed";
        return;
    }
    std::vector<std::tuple<int, int, int>> faceCache;
    int mode=0,modepre=0;
    while(!objFile.atEnd()) {
        QByteArray line = objFile.readLine();
        if(line.last(2)=="\r\n") line = line.remove(line.length() - 2,2); // remove \r\n
        else line = line.remove(line.length() - 1,1); // remove \r\n
        if(line.isEmpty()) {
            continue;
        }

        QList<QByteArray> valInLine = line.split(' ');
        valInLine.removeAll(QByteArray());
        QString dataType = valInLine.takeFirst();
        if(dataType == "v") {
            vexCache.push_back(std::make_tuple(valInLine.at(0).toFloat(), valInLine.at(1).toFloat(), valInLine.at(2).toFloat()));
        }
        else if(dataType == "vt") {
            texCache.push_back(std::make_tuple(valInLine.at(0).toFloat(), valInLine.at(1).toFloat()));
        }
        else if(dataType == "vn") {
            norCache.push_back(std::make_tuple(valInLine.at(0).toFloat(), valInLine.at(1).toFloat(), valInLine.at(2).toFloat()));
        }
        else if(dataType == "f") {
            QList<QByteArray> intStr = valInLine.first().split('/');
            if(valInLine.size()==4){
                int v = valInLine.size() > 0 ? valInLine.first().toInt() : 0;
                int vt = valInLine.size() > 1 ? valInLine.at(1).toInt() : 0;
                int vn = valInLine.size() > 2 ? valInLine.at(2).toInt() : 0;
                faceCache.push_back(std::make_tuple(v, v, v));
                faceCache.push_back(std::make_tuple(vt, vt, vt));
                faceCache.push_back(std::make_tuple(vn, vn, vn));

                v = valInLine.size() > 0 ? valInLine.first().toInt() : 0;
                vt = valInLine.size() > 1 ? valInLine.at(2).toInt() : 0;
                vn = valInLine.size() > 2 ? valInLine.at(3).toInt() : 0;
                faceCache.push_back(std::make_tuple(v, v, v));
                faceCache.push_back(std::make_tuple(vt, vt, vt));
                faceCache.push_back(std::make_tuple(vn, vn, vn));
            }
            else if(valInLine.size()==3 && intStr.size()==1){
                int v = valInLine.size() > 0 ? valInLine.first().toInt() : 0;
                int vt = valInLine.size() > 1 ? valInLine.at(1).toInt() : 0;
                int vn = valInLine.size() > 2 ? valInLine.at(2).toInt() : 0;
                faceCache.push_back(std::make_tuple(v, v, v));
                faceCache.push_back(std::make_tuple(vt, vt, vt));
                faceCache.push_back(std::make_tuple(vn, vn, vn));
            }
            else{
                for (const auto &str : valInLine) {
                    QList<QByteArray> intStr = str.split('/');
                    if(intStr.size()==3){
                        int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                        int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                        int vn = intStr.size() > 2 ? intStr.last().toInt() : 0;
                        faceCache.push_back(std::make_tuple(v, vt, vn));
                    }
                    else if (intStr.size() == 4) {
                        int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                        int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                        int vn = intStr.size() > 2 ? intStr.at(2).toInt() : 0;
                        faceCache.push_back(std::make_tuple(v, vt, vn));

                        v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                        vt = intStr.size() > 1 ? intStr.at(2).toInt() : 0;
                        vn = intStr.size() > 2 ? intStr.at(3).toInt() : 0;
                        faceCache.push_back(std::make_tuple(v, vt, vn));
                    }
                    else{
                        QList<QByteArray> intStr = str.split(' ');
                        if(intStr.size()==3){
                            int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                            int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                            int vn = intStr.size() > 2 ? intStr.last().toInt() : 0;
                            faceCache.push_back(std::make_tuple(v, vt, vn));
                        }
                        else if (intStr.size() == 4) {
                            int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                            int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                            int vn = intStr.size() > 2 ? intStr.at(2).toInt() : 0;
                            faceCache.push_back(std::make_tuple(v, vt, vn));

                            v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                            vt = intStr.size() > 1 ? intStr.at(2).toInt() : 0;
                            vn = intStr.size() > 2 ? intStr.at(3).toInt() : 0;
                            faceCache.push_back(std::make_tuple(v, vt, vn));
                        }
                    }
                }
            }
        }
    }
    objFile.close();
    for (auto face : faceCache) {  // x y z u v xn yn zn
        std::tuple<float, float, float> vex = vexCache[std::get<0>(face)-1];
        mMeshDataBuffer.push_back(std::get<0>(vex));
        mMeshDataBuffer.push_back(std::get<1>(vex));
        mMeshDataBuffer.push_back(std::get<2>(vex));

        if (std::get<2>(face) - 1 >= norCache.size()) {
            norCache.push_back({0.0f, 0.0f, 1.0f}); // 如果法线缺失，设置默认值
            std::tuple<float, float, float> nor = norCache[std::get<2>(face)-1];
            mMeshDataBuffer.push_back(std::get<0>(nor));
            mMeshDataBuffer.push_back(std::get<1>(nor));
            mMeshDataBuffer.push_back(std::get<2>(nor));
        }
        else{
            std::tuple<float, float, float> nor = norCache[std::get<2>(face)-1];
            mMeshDataBuffer.push_back(std::get<0>(nor));
            mMeshDataBuffer.push_back(std::get<1>(nor));
            mMeshDataBuffer.push_back(std::get<2>(nor));
        }
        if (std::get<1>(face) - 1 >= texCache.size()) {
            texCache.push_back({0.5f, 0.5f}); // 如果纹理缺失，设置默认值
            std::tuple<float, float> tex = texCache[std::get<1>(face)-1];
            mMeshDataBuffer.push_back(std::get<0>(tex));
            mMeshDataBuffer.push_back(std::get<1>(tex));
        }
        else{
            std::tuple<float, float> tex = texCache[std::get<1>(face)-1];
            mMeshDataBuffer.push_back(std::get<0>(tex));
            mMeshDataBuffer.push_back(std::get<1>(tex));
        }
    }
}
//RANK模型加载函数
void MyOpenGLWidget::load2(){
    QFile objFile(pathCreator("无标题.obj")); // 读取模型文件
    if(!objFile.open(QIODevice::ReadOnly)){
        qDebug() << "open" << "failed";
        return;
    }
    std::vector<std::tuple<int, int, int>> faceCache;
    int mode=0,modepre=0;
    while(!objFile.atEnd()) {
        QByteArray line = objFile.readLine();
        if(line.last(2)=="\r\n") line = line.remove(line.length() - 2,2); // remove \r\n
        else line = line.remove(line.length() - 1,1); // remove \r\n
        if(line.isEmpty()) {
            continue;
        }

        QList<QByteArray> valInLine = line.split(' ');
        valInLine.removeAll(QByteArray());
        QString dataType = valInLine.takeFirst();
        if(dataType == "v") {
            vexCache2.push_back(computeRotate(std::make_tuple(valInLine.at(0).toFloat(), valInLine.at(1).toFloat(), valInLine.at(2).toFloat()),45));
        }
        else if(dataType == "vt") {
            texCache2.push_back(std::make_tuple(valInLine.at(0).toFloat(), valInLine.at(1).toFloat()));
        }
        else if(dataType == "vn") {
            norCache2.push_back(std::make_tuple(valInLine.at(0).toFloat(), valInLine.at(1).toFloat(), valInLine.at(2).toFloat()));
        }
        else if(dataType == "f") {
            QList<QByteArray> intStr = valInLine.first().split('/');
            if(valInLine.size()==4){
                int v = valInLine.size() > 0 ? valInLine.first().toInt() : 0;
                int vt = valInLine.size() > 1 ? valInLine.at(1).toInt() : 0;
                int vn = valInLine.size() > 2 ? valInLine.at(2).toInt() : 0;
                faceCache.push_back(std::make_tuple(v, v, v));
                faceCache.push_back(std::make_tuple(vt, vt, vt));
                faceCache.push_back(std::make_tuple(vn, vn, vn));

                v = valInLine.size() > 0 ? valInLine.first().toInt() : 0;
                vt = valInLine.size() > 1 ? valInLine.at(2).toInt() : 0;
                vn = valInLine.size() > 2 ? valInLine.at(3).toInt() : 0;
                faceCache.push_back(std::make_tuple(v, v, v));
                faceCache.push_back(std::make_tuple(vt, vt, vt));
                faceCache.push_back(std::make_tuple(vn, vn, vn));
            }
            else if(valInLine.size()==3 && intStr.size()==1){
                int v = valInLine.size() > 0 ? valInLine.first().toInt() : 0;
                int vt = valInLine.size() > 1 ? valInLine.at(1).toInt() : 0;
                int vn = valInLine.size() > 2 ? valInLine.at(2).toInt() : 0;
                faceCache.push_back(std::make_tuple(v, v, v));
                faceCache.push_back(std::make_tuple(vt, vt, vt));
                faceCache.push_back(std::make_tuple(vn, vn, vn));
            }
            else{
                for (const auto &str : valInLine) {
                    QList<QByteArray> intStr = str.split('/');
                    if(intStr.size()==3){
                        int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                        int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                        int vn = intStr.size() > 2 ? intStr.last().toInt() : 0;
                        faceCache.push_back(std::make_tuple(v, vt, vn));
                    }
                    else if (intStr.size() == 4) {
                        int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                        int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                        int vn = intStr.size() > 2 ? intStr.at(2).toInt() : 0;
                        faceCache.push_back(std::make_tuple(v, vt, vn));

                        v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                        vt = intStr.size() > 1 ? intStr.at(2).toInt() : 0;
                        vn = intStr.size() > 2 ? intStr.at(3).toInt() : 0;
                        faceCache.push_back(std::make_tuple(v, vt, vn));
                    }
                    else{
                        QList<QByteArray> intStr = str.split(' ');
                        if(intStr.size()==3){
                            int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                            int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                            int vn = intStr.size() > 2 ? intStr.last().toInt() : 0;
                            faceCache.push_back(std::make_tuple(v, vt, vn));
                        }
                        else if (intStr.size() == 4) {
                            int v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                            int vt = intStr.size() > 1 ? intStr.at(1).toInt() : 0;
                            int vn = intStr.size() > 2 ? intStr.at(2).toInt() : 0;
                            faceCache.push_back(std::make_tuple(v, vt, vn));

                            v = intStr.size() > 0 ? intStr.first().toInt() : 0;
                            vt = intStr.size() > 1 ? intStr.at(2).toInt() : 0;
                            vn = intStr.size() > 2 ? intStr.at(3).toInt() : 0;
                            faceCache.push_back(std::make_tuple(v, vt, vn));
                        }
                    }
                }
            }
        }
    }
    objFile.close();
    for (auto face : faceCache) {  // x y z u v xn yn zn
        std::tuple<float, float, float> vex = vexCache2[std::get<0>(face)-1];
        mMeshDataBuffer2.push_back(std::get<0>(vex));
        mMeshDataBuffer2.push_back(std::get<1>(vex));
        mMeshDataBuffer2.push_back(std::get<2>(vex));

        if (std::get<2>(face) - 1 >= norCache2.size()) {
            norCache2.push_back({0.0f, 0.0f, 1.0f}); // 如果法线缺失，设置默认值
            std::tuple<float, float, float> nor = norCache2[std::get<2>(face)-1];
            mMeshDataBuffer2.push_back(std::get<0>(nor));
            mMeshDataBuffer2.push_back(std::get<1>(nor));
            mMeshDataBuffer2.push_back(std::get<2>(nor));
        }
        else{
            std::tuple<float, float, float> nor = norCache2[std::get<2>(face)-1];
            mMeshDataBuffer2.push_back(std::get<0>(nor));
            mMeshDataBuffer2.push_back(std::get<1>(nor));
            mMeshDataBuffer2.push_back(std::get<2>(nor));
        }
        if (std::get<1>(face) - 1 >= texCache2.size()) {
            texCache2.push_back({0.5f, 0.5f}); // 如果纹理缺失，设置默认值
            std::tuple<float, float> tex = texCache2[std::get<1>(face)-1];
            mMeshDataBuffer2.push_back(std::get<0>(tex));
            mMeshDataBuffer2.push_back(std::get<1>(tex));
        }
        else{
            std::tuple<float, float> tex = texCache2[std::get<1>(face)-1];
            mMeshDataBuffer2.push_back(std::get<0>(tex));
            mMeshDataBuffer2.push_back(std::get<1>(tex));
        }
    }
}
//计时器函数，用于旋转模型
void MyOpenGLWidget::slotTimeout()
{
    angleX_ += 2;
    angleY += 2;
    anglZ_ += 2;
    update();
}
std::tuple<float, float, float> computeNormal(
    const std::tuple<float, float, float>& v1,
    const std::tuple<float, float, float>& v2,
    const std::tuple<float, float, float>& v3)
{
    QVector3D p1(std::get<0>(v1), std::get<1>(v1), std::get<2>(v1));
    QVector3D p2(std::get<0>(v2), std::get<1>(v2), std::get<2>(v2));
    QVector3D p3(std::get<0>(v3), std::get<1>(v3), std::get<2>(v3));

    QVector3D normal = QVector3D::crossProduct(p2 - p1, p3 - p1).normalized();
    return {normal.x(), normal.y(), normal.z()};
}
//用于摄像头的移动
void MyOpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(pressstate){
        float npos=event->pos().ry();
        float move=(npos-pos)/10;
        aty-=move;
        looky-=move;
        cameraLocation_.setX(0);
        cameraLocation_.setY(aty);
        cameraLocation_.setZ(3);
        pos=npos;
    }
}

void MyOpenGLWidget::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton) {
        pressstate=true;
        pos=event->pos().ry();
    }
}
void MyOpenGLWidget::mouseReleaseEvent(QMouseEvent *event) {

}
//计算绕y轴旋转后模型的位置
std::tuple<float, float, float> MyOpenGLWidget::computeRotate(
    const std::tuple<float, float, float>& v1,int rotation)
{
    float a=sin((float)rotation/180*3.1415926),b=cos((float)rotation/180*3.1415926);
    std::vector<float> rotate={b,0,a,0,1,0,-a,0,b};
    float result[3]={0,0,0},source[3];
    source[0]=std::get<0>(v1);
    source[1]=std::get<1>(v1);
    source[2]=std::get<2>(v1);
    int i=0,j,k;
    for(int i=0;i<3;i++){
        k=0;
        for(j=0;j<3;j++){
            result[i]+=rotate[i*3+j]*source[k];
            k++;
        }
    }
    return {result[0], result[1], result[2]};
}
