/*
 * penser à ajouter la lib glut32
 */

#include <stdlib.h>
#include <iostream>
#include "windows.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <GL/glfw.h>

using namespace std;


//##############################################################################


bool Plein_Ecran = true;
GLint La_Fenetre_Principale;
#define RESOLUTION_PLEIN_ECRAN "1024x768:32@60"

GLUquadricObj* Objet_Quadric;

bool Animation = true;
//##############################################################################

void Initialisation_3D() {
    if (Plein_Ecran) {
        glutGameModeString(RESOLUTION_PLEIN_ECRAN);
        glutEnterGameMode();
    } else {
        La_Fenetre_Principale = glutCreateWindow("anim");
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

    Objet_Quadric = gluNewQuadric();
}

void Fin_Scene() {
    gluDeleteQuadric(Objet_Quadric);
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

void Animation_Scene() {
    if (Animation == true) {
        glutPostRedisplay();
    }

}
//------------------------------------------------------------------------------

void Gestion_Clavier(unsigned char P_Touche, int P_X, int P_Y)// x y coordonné de la souris
{
    switch (P_Touche) {
        case 'q': Fin_3D();
            break;
        case 'a': Animation=!Animation;
            break;
    }
    glutPostRedisplay();

}

//----------------------------------------------------------------------------

void Affichage_Scene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT |
            GL_STENCIL_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    Fin_Scene();

    return (EXIT_SUCCESS);
}

/*glClearColor(1.0f, 0.0f, 0.0f, 0.0f); for red
glClearColor(0.0f, 1.0f, 0.0f, 0.0f); for green
glClearColor(0.0f, 0.0f, 1.0f, 0.0f); for blue
glClearColor(1.0f, 0.0f, 1.0f, 0.0f); for purple
glClearColor(0.0f, 0.0f, 0.5f, 0.0f); for dark blue*/