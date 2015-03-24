#include "conjuntboles.h"


ConjuntBoles::ConjuntBoles()
{
    GLfloat x0 = 0.;
    GLfloat y0 = 0.03;    //Comença a la posicio y = 3
    GLfloat z0 = 0.;

    GLfloat radio = 0.03;

    Bola *bola;

    Capsa3D capsa;

    capsa.a=1;
    capsa.h=1;
    capsa.p=1;

    GLfloat z1 = 0.5;
    GLfloat x2 = 0.0 - 3 * radio;
    GLfloat z2 = 0.5 + 2 * radio;
    GLfloat x3 = 0.0 - 4 * radio;
    GLfloat z3 = 0.5 + 4 * radio;
    GLfloat x4 = 0.0 - 5 * radio;
    GLfloat z4 = 0.5 + 6 * radio;
    GLfloat x5 = 0.0 - 6 * radio;
    GLfloat z5 = 0.5 + 8 * radio;

    QString indexBola;

    // Colocacio boles
    for(int i=0; i<15;i++){
        if(i==0){                       // Primera fila
            z0 = z1;
            indexBola = "1";

        }else if(i>0 && i<3){           // Segona fila

            x0 = x2 + 2 * i * radio;
            z0 = z2;

            if(i==1)indexBola = "10";
            else indexBola = "2";

        }else if(i>2 && i<6){           // Tercera fila

            x0 = x3 + 2 * (i-2) * radio;
            z0 = z3;

            if(i==3)indexBola = "3";
            if(i==4)indexBola = "8";
            if(i==5)indexBola = "11";

        }else if(i>5 && i<10){          // Quarta fila

            x0 = x4 + 2 * (i-5) * radio;
            z0 = z4;

            if(i==6)indexBola = "13";
            if(i==7)indexBola = "4";
            if(i==8)indexBola = "12";
            if(i==9)indexBola = "5";

        }else if(i>9 && i<15){          // Quinta fila

            x0 = x5 + 2 * (i-9) * radio;
            z0 = z5;

            if(i==10)indexBola = "7";
            if(i==11)indexBola = "14";
            if(i==12)indexBola = "9";
            if(i==13)indexBola = "6";
            if(i==14)indexBola = "15";
        }

        //Cream la bola
        bola = new Bola(x0, y0, z0, radio, indexBola);
        boles.push_back(bola);
    }

}

ConjuntBoles::~ConjuntBoles()
{
    //delete boles;

}

