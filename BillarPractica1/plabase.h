#ifndef PLABASE_H
#define PLABASE_H
#include <Common.h>
#include <QGLShaderProgram>
#include <QOpenGLTexture>

#include <stdio.h>
#include <objecte.h>

//const int NumVertices = 6; //(6 faces)(2 triangles/face)(3 vertices/triangle)

typedef vec4  color4;
typedef vec4  point4;

class PlaBase: public Objecte
{

  public:


      PlaBase();
      PlaBase(int an, int al, GLfloat x0, GLfloat y0, GLfloat z0);
      ~PlaBase();
      void make();



  private:

      void quad( int a, int b, int c, int d );
      void initTextura();

      static const int NumVerticesF = 6;

      int a; // amplada
      int h; // alcada
      //int p; // profunditat


      point4 vertices[4]; // 4 vertexs del PlaBase
      color4 vertex_colors[4]; // 4 colors RGBA associats a cada vertex

     /* int Index;
      point4 points[NumVertices]; // 6 punts: PlaBase triangulat
      color4 colors[NumVertices]; // colors en aquests punts
      */
      vec2 vertexsTextura[NumVerticesF]; // coordenades de textura associades a cada vertex


      QOpenGLTexture *texture;
};

#endif // PlaBase_H
