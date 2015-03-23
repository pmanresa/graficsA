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

    void make();
    void toGPU(QGLShaderProgram *p);
    void draw();
    void aplicaTG(mat4 m);
    void aplicaTGPoints(mat4 m);
    void aplicaTGCentrat(mat4 m);

    Bola* boles[maxboles];



};

#endif // CONJUNTBOLES_H
