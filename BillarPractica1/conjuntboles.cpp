#include "conjuntboles.h"


ConjuntBoles::ConjuntBoles()
{
    boles = new Bola[15];
    make();

}

void ConjuntBoles::make(){
    int i;
    for (i = 0; i< 15; i++){
        boles[i] = &Bola((float)i,(float)i);
    }

}

void ConjuntBoles::draw()
{

}




ConjuntBoles::~ConjuntBoles()
{
    delete boles;
}

