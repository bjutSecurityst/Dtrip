#include "shader.h"
#include <QtOpenGL/QOpenGLShader>
#include <QtOpenGL/QOpenGLShaderProgram>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Shader::Shader()
    : m_program(new QOpenGLShaderProgram)
{
}

Shader::~Shader()
{
    delete m_program;
}

bool Shader::load(const QString& vertexPath, const QString& fragmentPath)
{
    QFile vertexFile(vertexPath);
    QFile fragmentFile(fragmentPath);

    if (!vertexFile.open(QIODevice::ReadOnly | QIODevice::Text) ||
        !fragmentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open shader files.";
        return false;
    }

    QTextStream vStream(&vertexFile);
    QTextStream fStream(&fragmentFile);

    QString vertexCode = vStream.readAll();
    QString fragmentCode = fStream.readAll();

    if (!m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexCode)) {
        qWarning() << "Vertex Shader Error:" << m_program->log();
        return false;
    }
    if (!m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentCode)) {
        qWarning() << "Fragment Shader Error:" << m_program->log();
        return false;
    }

    if (!m_program->link()) {
        qWarning() << "Shader Program Link Error:" << m_program->log();
        return false;
    }

    return true;
}

void Shader::use()
{
    m_program->bind();
}

void Shader::setUniform(const QString& name, const QMatrix4x4& matrix)
{
    m_program->setUniformValue(name.toUtf8().constData(), matrix);
}

void Shader::setUniform(const QString& name, const QVector3D& vector)
{
    m_program->setUniformValue(name.toUtf8().constData(), vector);
}

void Shader::setUniform(const QString& name, float value)
{
    m_program->setUniformValue(name.toUtf8().constData(), value);
}

void Shader::setUniform(const QString& name, int value)
{
    m_program->setUniformValue(name.toUtf8().constData(), value);
}
