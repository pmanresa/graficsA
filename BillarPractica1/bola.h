#ifndef BOLA_H
#define BOLA_H
#include <Common.h>
#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <stdio.h>
#include <objecte.h>

typedef vec4  color4;
typedef vec4  point4;

class Bola: public Objecte
{
public:
    Bola();
    Bola(GLfloat x, GLfloat y, GLfloat z, GLfloat radio, QString indexbola);
    ~Bola();
    void make(QString indexbola);
    QOpenGLTexture *texture;

private:

    void triangle( const point4& a, const point4& b, const point4& c );
    point4 normalize(point4);
    void divide_triangle( const point4& a, const point4& b, const point4& c, int i );
    void initTextura(QString indexBola);

    GLfloat radio;

    static const int NumVerticesF = 2000000;
    int NumMaxIteracions = 5;

    point4 v[4]; // 4 vertexs de la Bola (tetraedre inicial)
    color4 vertex_colors[4]; // 4 colors RGBA associats a cada vertex

};

#endif // BOLA_H
