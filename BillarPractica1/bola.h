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
    ~Bola();
    void make();


private:

    void triangle( const point4& a, const point4& b, const point4& c );
    void initTextura();
    point4 normalize(point4);
    static const int NumVerticesF = 12;

    point4 v[4]; // 4 vertexs de la Bola (tetraedre inicial)
    color4 vertex_colors[4]; // 4 colors RGBA associats a cada vertex


    QOpenGLTexture *texture;
};

#endif // BOLA_H