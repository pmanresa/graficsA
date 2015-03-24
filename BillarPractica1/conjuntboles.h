#ifndef CONJUNTBOLES_H
#define CONJUNTBOLES_H

#include <stdio.h>
#include <bola.h>
#include <objecte.h>

#define maxboles 5

class ConjuntBoles

{

public:
    ConjuntBoles();
    ~ConjuntBoles();

    vector<Bola*> boles;

};

#endif // CONJUNTBOLES_H
