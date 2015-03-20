#include "conjuntboles.h"


ConjuntBoles::ConjuntBoles(): Objecte(NumVerticesF)
{

    for (int i = 0; i< maxboles; i++){
        Bola *bola;
        bola = new Bola((GLfloat)0,(GLfloat)i*5);
        boles[i] = bola;
    }



}

void ConjuntBoles::make(){
    for (int i = 0; i< maxboles; i++){
       boles[i]->make();
    }

}

void ConjuntBoles::draw()
{

    for (int i = 0; i< maxboles; i++){
        boles[i]->draw();
    }
}

void ConjuntBoles::aplicaTG(mat4 m){
    for (int i = 0 ; i< maxboles; i++){
        boles[i]->aplicaTG(m);
    }
}
void ConjuntBoles::aplicaTGPoints(mat4 m){
    for (int i = 0 ; i< maxboles; i++){
        boles[i]->aplicaTGPoints(m);
    }
}
void ConjuntBoles::aplicaTGCentrat(mat4 m){
    for (int i = 0 ; i< maxboles; i++){
        boles[i]->aplicaTGCentrat(m);
    }
}

void ConjuntBoles::toGPU(QGLShaderProgram *p){
    for (int i = 0 ; i< maxboles; i++){
        boles[i]->toGPU(p);
    }
}

ConjuntBoles::~ConjuntBoles()
{
    delete boles;

}

