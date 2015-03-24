#ifndef PLABASE_H
#define PLABASE_H

#include <objecte.h>

const int NumVertices = 6; //(1 faces)*(2 triangles/face)*(3 vertices/triangle)

/*
 * Objecte Pla base
 */

class PlaBase : public Objecte
{
public:
    PlaBase();
    virtual void make();
    ~PlaBase();
private:
    int a; //amplada
    int p; //profunditat
    //int h;

    point4 vertices[4];
    color4 vertex_colors[4];

    void quad( int a, int b, int c, int d );
    void initTextura();
};

#endif // PLABASE_H
