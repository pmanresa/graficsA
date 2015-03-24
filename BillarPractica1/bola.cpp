#include <bola.h>

Bola::Bola() : Objecte(NumVerticesF)
{

    std::cout<<"Estic en el constructor del Bola\n";
    // Bola centrat al 0,0,0 amb dimensió 1 a totes les seves arestes
    xorig = 0; yorig = 10; zorig = 0;

    capsa.a = 1;
    capsa.h = 1;
    capsa.p = 1;

    //make();

}

Bola::Bola(GLfloat x, GLfloat y, GLfloat z, GLfloat radio, QString indexbola) : Objecte(NumVerticesF)
{

    std::cout<<"Estic en el constructor del Bola\n";
    // Bola centrat al 0,0,0 amb dimensió 1 a totes les seves arestes
    xorig = x;
    yorig = y;
    zorig = z;
    this->radio = radio;


    make(indexbola);
    capsa = calculCapsa3D();
    double aristaMax = 0.0;

    if(capsa.a > capsa.p){
        aristaMax=capsa.a;
    } else{
        aristaMax=capsa.p;
    }
    if(capsa.h > aristaMax){
        aristaMax=capsa.h;
    }
    double escala = 3.5 * radio/aristaMax;

    mat4 m = Translate(xorig, yorig, zorig)*Scale(escala, escala, escala);
    aplicaTG(m);//sale la bola con radio r y posicion x0,y0,z0
    capsa = calculCapsa3D();

}

// Destructora
Bola::~Bola()
{
}

void Bola::triangle( const point4& a, const point4& b, const point4& c )
{
    points[Index] = a;
    colors[Index] = vertex_colors[1];
    Index++;
    points[Index] = b;
    colors[Index] = vertex_colors[1];
    Index++;
    points[Index] = c;
    colors[Index] = vertex_colors[1];
    Index++;
}


// Realitzacio de la geometria del Bola en una genList o en el vertex array, segons el que visualitzem

void Bola::make(QString indexbola)
{
    std::cout<<"Estic en el make de la Bola\n";

    // generacio de la geometria dels triangles per a visualitzar-lo
    Index = 0;

    // Vertices of a unit Bola centered at origin, sides aligned with axes
    v[0] = point4( 0.0, 0.0, 1.0, 1.0  );
    v[1] = point4(  0.0, 0.942809, -0.333333, 1.0  );
    v[2] = point4(  -0.816497, -0.471405, -0.333333, 1.0  );
    v[3] = point4(  0.816497, -0.471405, -0.333333, 1.0 );


    // RGBA colors
    vertex_colors[0] =    color4( 1.0, 1.0, 1.0, 1.0 );  // black
    vertex_colors[1] =    color4( 1.0, 1.0, 1.0, 1.0 );  // red
    vertex_colors[2] =    color4( 1.0, 1.0, 1.0, 1.0 );  // yellow
    vertex_colors[3] =    color4( 1.0, 1.0, 1.0, 1.0 );  // green

    point4 v1;
    point4 v2;
    point4 v3;

    int i =0;

    triangle( v[0], v[1], v[2]);
    triangle( v[3], v[2], v[1]);
    triangle( v[0], v[3], v[1]);
    triangle( v[0], v[2], v[3]);


    divide_triangle(v[0], v[1], v[2] ,0);
    divide_triangle(v[3], v[2], v[1], 0);
    divide_triangle(v[0], v[3], v[1], 0);
    divide_triangle(v[0], v[2], v[3], 0);

    initTextura(indexbola);

}

void Bola::divide_triangle( const point4& a, const point4& b, const point4& c, int i)
{

    point4 v1;
    point4 v2;
    point4 v3;

   if (i < NumMaxIteracions ){

        i++;

        v1 = this->normalize( a + b );
        v2 = this->normalize( a + c );
        v3 = this->normalize( b + c );

        divide_triangle(a,v1,v2, i);
        divide_triangle(c, v2, v3, i);
        divide_triangle(b, v3, v1, i);
        divide_triangle(v1, v3, v2, i);

    }else{

       triangle( a, b, c);

   }

}

point4 Bola::normalize(point4 vector){



    float modulo = sqrt(pow(vector[0],2)+pow(vector[1],2)+pow(vector[2],2));

    vector[0] = vector[0]/modulo;
    vector[1] = vector[1]/modulo;
    vector[2] = vector[2]/modulo;
    vector[3] = 1.0;

    return vector;

}

void Bola::initTextura(QString indexBola)
 {
     qDebug() << "Initializing textures...";

     QString fileTextura = "://resources/Bola";
     fileTextura.append(indexBola).append(".jpg");

     // Carregar la textura
     glActiveTexture(GL_TEXTURE1);
     texture = new QOpenGLTexture(QImage(fileTextura));
     texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
     texture->setMagnificationFilter(QOpenGLTexture::Linear);

     texture->bind(0);

 }



