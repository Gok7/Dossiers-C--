/*
 * penser à ajouter la lib glut32
 */

#include <stdlib.h>
#include <iostream>
#include "windows.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut/glut.h"
#include <math.h>
#define Nombre_Maxi_Personnage 100

using namespace std;


//##############################################################################


bool Plein_Ecran = false;
GLint La_Fenetre_Principale;
#define RESOLUTION_PLEIN_ECRAN "1024x768:32@60"



bool Animation = true;

//##############################################################################

typedef struct {
    float X;
    float Y;
    float Z;

    float Couleur[4];

    float VX;
    float VY;
    float VZ;

} T_PERSONNAGE;

T_PERSONNAGE Les_Personnage[Nombre_Maxi_Personnage];
int Nombre_Personnage = 0;

void Initialise_Personnage(T_PERSONNAGE* P_Personnage) {

    for (int i = 0; i <= Nombre_Maxi_Personnage; i++) {
        P_Personnage->X = rand() % 15;
        P_Personnage->Y = rand() % 15;
        P_Personnage->Z = -rand() % 50;

        P_Personnage->Couleur[0] = (rand() % 100) / 100.0f;
        P_Personnage->Couleur[1] = (rand() % 100) / 100.0f;
        P_Personnage->Couleur[2] = (rand() % 100) / 100.0f;
        P_Personnage->Couleur[3] = (rand() % 100) / 100.0f;

        P_Personnage->VX = (rand() % 500) / 1000.0f;
        P_Personnage->VY = (rand() % 500) / 1000.0f;
        P_Personnage->VZ = (rand() % 500) / 1000.0f;
    }
}

void Affiche_Personnage(T_PERSONNAGE* P_Personnage) {

    glPushMatrix();
    glTranslatef(P_Personnage->X, P_Personnage->Y, P_Personnage->Z);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, P_Personnage->Couleur);
    glutSolidSphere(0.5f, 20, 20);

    glPopMatrix();

}

void Deplace_Personnage(T_PERSONNAGE* P_Personnage) {

    P_Personnage->X += P_Personnage->VX;
    P_Personnage->Y += P_Personnage->VY;
    P_Personnage->Z += P_Personnage->VZ;

    if ((P_Personnage->X > 15.0f) || (P_Personnage->X < 15.0f)) {
        P_Personnage->VX = -P_Personnage->VX;
    }

    if ((P_Personnage->Y > 15.0f) || (P_Personnage->Y < 15.0f)) {
        P_Personnage->VY = -P_Personnage->VY;
    }
    if ((P_Personnage->Z > 0) || (P_Personnage->Z<-50)) {
        P_Personnage->VZ = -P_Personnage->VZ;
    }

}

void Initialisation_3D() {
    if (Plein_Ecran) {
        glutGameModeString(RESOLUTION_PLEIN_ECRAN);
        glutEnterGameMode();
    } else {
        La_Fenetre_Principale = glutCreateWindow("************Nounours************");
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1024.0f / 768.0f, 1.5, 100.0);

    gluLookAt(0.0, 0.0, 20.0, // est Ã  0,0,20 (x y z)
            0.0, 0.0, 0.0, // regarde 0,0,0 (le centre)
            0.0, 1.0, 0.0); // vecteur orientation  (vers le haut)


    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);


    srand(GetTickCount());

}

//------------------------------------------------------------------------------

void Fin_3D() {
    if (Plein_Ecran) {
        glutLeaveGameMode();
    } else {
        glutDestroyWindow(La_Fenetre_Principale);
    }

    exit(0);
}
//#############################################################################

//------------------------------------------------------------------------------


//----------------------------------------------------------------------------

void Ajoute_Un_Personnage() {
    if (Nombre_Personnage < Nombre_Maxi_Personnage) {
        Initialise_Personnage(&Les_Personnage[Nombre_Personnage]);
        Nombre_Personnage++;
    }
}

void Affiche_Les_Personnages() {
    for (int L_Index = 0; L_Index < Nombre_Personnage; L_Index++) {
        Affiche_Personnage(&Les_Personnage[L_Index]);
    }
}

void Deplace_Les_Personnages() {
    for (int L_Index = 0; L_Index < Nombre_Personnage; L_Index++) {
        Deplace_Personnage(&Les_Personnage[L_Index]);
    }
}

void Animation_Scene() {
    if (Animation == true) {
        Deplace_Les_Personnages();
    }
    glutPostRedisplay();

}

void Gestion_Clavier(unsigned char P_Touche, int P_X, int P_Y)// x y coordonné de la souris
{
    switch (P_Touche) {
        case 'q': Fin_3D();
            break;
        case 'a': Animation = !Animation;
            break;
        case 'z': Ajoute_Un_Personnage();
            break;
    }
    glutPostRedisplay();
}

void Affichage_Scene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |
            GL_STENCIL_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //......................

    Affiche_Les_Personnages();


    //......................
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    Initialisation_3D();

    glutDisplayFunc(Affichage_Scene);
    glutKeyboardFunc(Gestion_Clavier);
    glutIdleFunc(Animation_Scene);

    glutMainLoop();

    return (EXIT_SUCCESS);
}

/*glClearColor(1.0f, 0.0f, 0.0f, 0.0f); for red
glClearColor(0.0f, 1.0f, 0.0f, 0.0f); for green
glClearColor(0.0f, 0.0f, 1.0f, 0.0f); for blue
glClearColor(1.0f, 0.0f, 1.0f, 0.0f); for purple
glClearColor(0.0f, 0.0f, 0.5f, 0.0f); for dark blue*/

/*Pour la prochaine fois : faire rebondir les boules entre elles: 
 * dire si les boules sont assez proches des unes des autres. si la distance x,y
 * est inférieur à 2 fois le diametre.
 */