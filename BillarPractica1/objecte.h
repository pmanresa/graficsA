#ifndef OBJECTE_H
#define OBJECTE_H

#include <QObject>
#include <vector>
#include <Common.h>
#include <cara.h>

#include <QGLShaderProgram>
#include <QOpenGLTexture>

typedef Common::vec4  color4;
typedef Common::vec4  point4;

using namespace std;

class Objecte : public QObject
{
    Q_OBJECT
protected:
    QString nom; // nom del fitxer on esta el cotxe
    vector<Cara> cares; // cares de l'objecte
    vector<point4> vertexs; // vertexs de l'objecte sense repetits
    GLfloat tam; // Escala de l'objecte aplicada al fitxer d'entrada

    // Programa de shaders de la GPU
    QGLShaderProgram *program;
    GLuint buffer; // Buffer de comunicacio amb la GPU

    // Estructures de vertexs i colors per passar a la GPU
    int     numPoints;
    point4 *points;
    color4 *colors;
    int Index; // index de control del numero de vertexs a posar a la GPU

    vec2 *vertexsTextura;

public:

    // Sistema de coordenades d'un objecte: punt origen i eixos de rotació
    GLfloat xorig, yorig, zorig;
    float xRot;
    float yRot;
    float zRot;

    // Capsa mínima contenidora de l'objecte
    Capsa3D capsa;
    QOpenGLTexture *texture;

    //Constructors
    Objecte(const int npoints, QObject *parent = 0);
    Objecte(const int npoints, QString n);
    ~Objecte();

    // Funcions virtual. En cas que el constructor la sobrecarregui es carregarà aquesta última instància
    // llegeix un model en format OBJ
    virtual void readObj(QString filename);

    // make(): omple l'estructura de points i colors de l'objecte, inicialitza NumVertices
    // Si l'objecte es construeix procedimentalment es sobrecarrega el make
    virtual void make();

    // Pintat amb la GPU
    virtual void draw();

    // Pas generic de vertexs i colors a la GPU
    void toGPU(QGLShaderProgram *p);

    // Calcula la capsa 3D contenidora de l'objecte
    Capsa3D calculCapsa3D();

    // Aplica una TG qualsevol a un objecte
    void aplicaTG(mat4 m);
    void aplicaTGPoints(mat4 m);

    // Aplica una TG centrada en el punt central de la capsa de l'objecte a un objecte
    void aplicaTGCentrat(mat4 m);

private:
    void construeix_cara ( char **words, int nwords, Objecte*objActual, int vindexUlt);

};



#endif // OBJECTE_H
