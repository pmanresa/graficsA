#ifndef CONJUNTBOLES_H
#define CONJUNTBOLES_H

#include <stdio.h>
#include <objecte.h>
#include <bola.h>


class ConjuntBoles
{
private:
    Bola* boles;

public:
    ConjuntBoles();
    ~ConjuntBoles();


    void make();
    void draw();



};

#endif // CONJUNTBOLES_H
