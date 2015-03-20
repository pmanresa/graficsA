#ifndef CONJUNTBOLES_H
#define CONJUNTBOLES_H

#include <stdio.h>
#include <bola.h>
#include <objecte.h>

#define maxboles 5

class ConjuntBoles: public Objecte

{
private:



public:
    ConjuntBoles();
    ~ConjuntBoles();

    static const int NumVerticesF = 20000000;

    virtual void make();
    virtual void toGPU(QGLShaderProgram *p);
    virtual void draw();
    virtual void aplicaTG(mat4 m);
    virtual void aplicaTGPoints(mat4 m);
    virtual void aplicaTGCentrat(mat4 m);

    Bola* boles[maxboles];



};

#endif // CONJUNTBOLES_H
