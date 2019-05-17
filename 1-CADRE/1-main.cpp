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

#define DISTANCE_TERRE 12.0f
#define DISTANCE_LUNE 2.0f
#define DISTANCE_NEW_PLANETE 10.0f

#define VITESSE_ROTATION_TERRE 1.0f
#define VITESSE_NEW_PLANETE 1.0f
#define VITESSE_ROTATION_LUNE -10.0f

#define INCLINAISON_NEW_PLANETE 10.0f
#define INCLINAISON_TERRE 10.0f
#define INCLINAISON_LUNE 1.8f
#define nounours
//#define planete
using namespace std;


//##############################################################################


bool Plein_Ecran = true;
GLint La_Fenetre_Principale;
#define RESOLUTION_PLEIN_ECRAN "1024x768:32@60"

GLUquadricObj* Objet_Quadric;
float Deplacement_X = 0.0f;
float Delta_X = 0.1f;

float Deplacement_Y = 0.0f;
float Delta_Y = 3.0f;

float Deplacement_Z = 0.0f;
float Delta_Z = 0.5f;

float Angle_Y=0;

float Angle_Terre=0.0f;
float Angle_Lune=0.0f;
float Angle_New_Planete=0.0f;

float Couleur_Soleil[]={1.0f,0.0f,0.0f,0.0f};

bool Animation = true;
//##############################################################################

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
#ifdef planete
    if (Animation == true) {
        Angle_Terre += VITESSE_ROTATION_TERRE;
        Angle_Terre =fmod(Angle_Terre ,360.0);
        Angle_Lune += VITESSE_ROTATION_LUNE;
        Angle_Lune=fmod(Angle_Lune,360.0);
        Angle_New_Planete+=VITESSE_NEW_PLANETE;
        Angle_New_Planete=fmod(Angle_New_Planete,360.0);
#endif planete
#ifdef nounours
        Angle_Y+=Delta_Y;
        Deplacement_Z+=Delta_Z;
        if(Deplacement_Z==30){
            Deplacement_Z=-30;
        }
#endif
        glutPostRedisplay();

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
    
#ifdef planete
    //SOLEIL
    glMaterialfv(GL_FRONT,GL_DIFFUSE,Couleur_Soleil);
    glutSolidSphere(5.0,40,40);
    
    glPushMatrix();//photo
    //TERRE
    glRotatef(INCLINAISON_TERRE,0,0,1);
    glRotatef(Angle_Terre,0,1,0);
    glTranslatef(DISTANCE_TERRE,0,0);
    glutSolidSphere(1.0,20,20);
    
    //LUNE
    
    glRotatef(INCLINAISON_LUNE,0,0,1);
    glRotatef(Angle_Lune,0,1,0);
    glTranslatef(DISTANCE_LUNE,0,0);
    glutSolidSphere(0.5,20,20);
    
    glPopMatrix();
    //Nouvelle Planete
    
    glRotatef(INCLINAISON_NEW_PLANETE,0,0,1);
    glRotatef(Angle_New_Planete,0,1,1);
    glTranslatef(DISTANCE_NEW_PLANETE,0,0);
    glutSolidSphere(0.9,20,20);
    #endif
    
  
    //glPopMatrix(); revenir1 Pop pour 1 Push, sinon crash
    
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