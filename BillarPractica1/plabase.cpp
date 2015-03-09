#include <plabase.h>

PlaBase::PlaBase() : Objecte(NumVerticesF)
{

    std::cout<<"Estic en el constructor del PlaBase\n";
    // PlaBase centrat al 0,0,0 amb dimensió 1 a totes les seves arestes
    xorig = 0; yorig = 0; zorig = 0;
    a = 1.0;
    h = 1.0;


    // Vertices of a unit PlaBasee centered at origin, sides aligned with axes
    vertices[0] = point4( -0.5, -0.5,  0.5, 1.0 );
    vertices[1] = point4( -0.5,  0.5,  0.5, 1.0 );
    vertices[2] = point4(  0.5,  0.5,  0.5, 1.0 );
    vertices[3] = point4(  0.5, -0.5,  0.5, 1.0 );



    // RGBA colors
    vertex_colors[0] =    color4( 0.0, 0.0, 0.0, 1.0 );  // black
    vertex_colors[1] =    color4( 1.0, 0.0, 0.0, 1.0 );  // red
    vertex_colors[2] =    color4( 1.0, 1.0, 0.0, 1.0 );  // yellow
    vertex_colors[3] =    color4( 0.0, 1.0, 0.0, 1.0 );  // green


    make();

}

// Constructora amb tots els parametres
PlaBase::PlaBase(int an, int al, const GLfloat x0, GLfloat y0, GLfloat z0): Objecte(NumVerticesF)
{
    std::cout<<"Estic en el constructor parametritzat del PlaBase\n";
    a = an;
    h = al;

    xorig = x0;
    yorig = y0;
    zorig = z0;
}

// Destructora
PlaBase::~PlaBase()
{
}

// quad generates two triangles for each face and assigns colors
//    to the vertices

void PlaBase::quad( int a, int b, int c, int d )
{
    colors[Index] = vertex_colors[a]; points[Index] = vertices[a];
    vertexsTextura[Index] = vec2(0.0, 0.0);
    Index++;
    colors[Index] = vertex_colors[b]; points[Index] = vertices[b];
    vertexsTextura[Index] = vec2(1.0, 0.0);
    Index++;
    colors[Index] = vertex_colors[c]; points[Index] = vertices[c];
    vertexsTextura[Index] = vec2(1.0, 1.0);
    Index++;
    colors[Index] = vertex_colors[a]; points[Index] = vertices[a];
    vertexsTextura[Index] = vec2(0.0, 0.0);
    Index++;
    colors[Index] = vertex_colors[c]; points[Index] = vertices[c];
    vertexsTextura[Index] = vec2(1.0, 1.0);
    Index++;
    colors[Index] = vertex_colors[d]; points[Index] = vertices[d];
    vertexsTextura[Index] = vec2(0.0, 1.0);
    Index++;
}


// Realitzacio de la geometria del PlaBase en una genList o en el vertex array, segons el que visualitzem

void PlaBase::make()
{
    std::cout<<"Estic en el make del PlaBase\n";
    // generacio de la geometria dels triangles per a visualitzar-lo
    Index = 0;
    quad( 1, 0, 3, 2 );




    //initTextura();

}

void PlaBase::initTextura()
 {
     qDebug() << "Initializing textures...";


     // Carregar la textura
     glActiveTexture(GL_TEXTURE0);
     texture = new QOpenGLTexture(QImage("://resources/Bola4.jpg"));
     texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
     texture->setMagnificationFilter(QOpenGLTexture::Linear);

     texture->bind(0);

 }





