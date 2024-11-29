#ifndef SHADER_H
#define SHADER_H

#include <QtOpenGL/QOpenGLShaderProgram>
#include <QString>
#include <QVector3D>
#include <QMatrix4x4>

class Shader {
public:
    Shader();
    ~Shader();

    bool load(const QString& vertexPath, const QString& fragmentPath);
    void use();
    void setUniform(const QString& name, const QMatrix4x4& matrix);
    void setUniform(const QString& name, const QVector3D& vector);
    void setUniform(const QString& name, float value);
    void setUniform(const QString& name, int value);

private:
    QOpenGLShaderProgram* m_program;
};

#endif // SHADER_H
