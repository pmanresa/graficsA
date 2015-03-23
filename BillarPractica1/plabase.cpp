#include <plabase.h>

PlaBase::PlaBase() : Objecte(NumVerticesF)
{

    std::cout<<"Estic en el constructor del PlaBase\n";

    // PlaBase centrat al 0,0,0 amb dimensió 1 a totes les seves arestes
    xorig = 0; yorig = 0; zorig = 0;
    capsa.a = 15;
    capsa.h = 25;
    capsa.p = 1;

    // Vertices of a unit PlaBasee centered at origin, sides aligned with axes
    vertices[0] = point4( -0.5, -0.5,  0.5, 1.0 );
    vertices[1] = point4( -0.5,  0.5,  0.5, 1.0 );
    vertices[2] = point4(  0.5,  0.5,  0.5, 1.0 );
    vertices[3] = point4(  0.5, -0.5,  0.5, 1.0 );

    // RGBA colors
    vertex_colors[0] =    color4( 1.0, 1.0, 1.0, 1.0 );  // black
    vertex_colors[1] =    color4( 1.0, 1.0, 1.0, 1.0 );  // red
    vertex_colors[2] =    color4( 1.0, 1.0, 1.0, 1.0 );  // yellow
    vertex_colors[3] =    color4( 1.0, 1.0, 1.0, 1.0 );  // green



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

    // Matriu translacio
    /*mat4 trans = Translate(xorig, yorig, zorig);
    mat4 escala = Scale(capsa.a,capsa.h,capsa.p);

    aplicaTG(trans*escala);



*/

   // mat4 escala = Scale(capsa.a,capsa.h,capsa.p);

    //aplicaTG(escala);

    initTextura();

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
void PlaBase::toGPU(QGLShaderProgram *pr){

    program = pr;

    std::cout<<"Passo les dades de l'objecte a la GPU\n";

    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER,sizeof(vertexsTextura) * Index + sizeof(point4) * Index + sizeof(color4) * Index,
                  NULL, GL_STATIC_DRAW );
    program->link();

    glEnable( GL_DEPTH_TEST );
    glEnable(GL_TEXTURE_2D);
    program->bind();

}

// Pintat en la GPU.
void PlaBase::draw()
{
    // S'activa la textura i es passa a la GPU
    texture->bind(0);
    program->setUniformValue("texMap", 0);

    // cal activar el buffer de l'objecte. Potser que ja n'hi hagi un altre actiu
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    // per si han canviat les coordenades dels punts
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(point4) * Index, &points[0] );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4) * Index, sizeof(color4) * Index, &colors[0] );
    glBufferSubData( GL_ARRAY_BUFFER, (sizeof(point4) * Index)+(sizeof(color4)*Index), sizeof(vertexsTextura), &vertexsTextura[0] );

    // Per a conservar el buffer
    int vertexLocation = program->attributeLocation("vPosition");
    int colorLocation = program->attributeLocation("vColor");
    int coordTextureLocation = program->attributeLocation("vCoordTexture");

    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer("vPosition", GL_FLOAT, 0, 4);
    program->enableAttributeArray(colorLocation);
    program->setAttributeBuffer("vColor", GL_FLOAT, sizeof(point4) * Index, 4);
    program->enableAttributeArray(coordTextureLocation);
    program->setAttributeBuffer("vCoordTexture", GL_FLOAT, (sizeof(point4)*Index)+(sizeof(color4)*Index),4);

    // Activació de la correspondencia entre les variables
    program->bindAttributeLocation("vPosition", vertexLocation);
    program->bindAttributeLocation("vColor", colorLocation);
    program->bindAttributeLocation("vCoordTexture", coordTextureLocation);

    glPolygonMode(GL_FRONT_AND_BACK,
                  GL_FILL);
    glDrawArrays( GL_TRIANGLES, 0, Index );

    // Abans nomes es feia: glDrawArrays( GL_TRIANGLES, 0, NumVerticesP );
}


