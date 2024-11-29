#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLExtraFunctions>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
class MyOpenGLWidget : public QOpenGLWidget,QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit MyOpenGLWidget(int mode,QWidget *parent= nullptr);
    ~MyOpenGLWidget(){
        vexCache.clear();
        norCache.clear();
        texCache.clear();
        mMeshDataBuffer.clear();
        vexCache2.clear();
        norCache2.clear();
        texCache2.clear();
        mMeshDataBuffer2.clear();
        if (texture_) {
            delete texture_;
            texture_ = nullptr;
        }

        GLuint VAO = 0, VBO = 0;
        if (VAO) {
            glDeleteVertexArrays(1, &VAO);
        }
        if (VBO) {
            glDeleteBuffers(1, &VBO);
        }
        if (vbo_.isCreated()) {
            vbo_.destroy();
        }
    }

private:
    QOpenGLTexture *texture_{nullptr};
    QOpenGLBuffer vbo_;
    QOpenGLShaderProgram program_;
    QTimer tm_;
    QVector3D cameraLocation_,lightLocation_;
    QMatrix4x4 pMatrix_;
    qreal angleX_,angleY,anglZ_;
    std::vector<std::tuple<float, float, float>> vexCache, norCache,vexCache2, norCache2;
    std::vector<std::tuple<float, float>> texCache,texCache2;
    std::vector<float> mMeshDataBuffer,mMeshDataBuffer2;
    void slotTimeout();
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void load();
    void load2();
    void initsize(QString filename,QImage &textureImg);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    std::tuple<float, float, float> computeRotate(const std::tuple<float, float, float>& v1,int rotation);
    void render(QOpenGLExtraFunctions *f,QMatrix4x4 &pMatrix,QMatrix4x4 &vMatrix,QMatrix4x4 &mMatrix,QVector3D &cameraLocation,QVector3D &lightCation);
    float looky=0,aty=0,pos=0;
    int mode=0;
    bool pressstate=false;
};

#endif // MYOPENGLWIDGET_H
