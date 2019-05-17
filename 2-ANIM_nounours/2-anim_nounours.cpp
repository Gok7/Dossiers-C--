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
#define nounours

using namespace std;


//##############################################################################


bool Plein_Ecran = false;
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
int Nombre_Personnage=0;

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
    
    #ifdef nounours
    glRotated(-45,0,1,0);
    glTranslatef(0, 0, 0);
    //glRotatef(90.0, 0, 1, 0);
    gluSphere(Objet_Quadric, 5.0, 5, 5); //ventre  //Droite et gauche par rapport 
    //à l'angle de vue de l'utilisateur.
    glTranslatef(0, 6, 2.0); //tete
    gluSphere(Objet_Quadric, 2.0, 20, 20);

    glTranslatef(0, -1, 2.0); //nez
    gluSphere(Objet_Quadric, 0.3, 20, 20);

    glMaterialfv(GL_FRONT,GL_DIFFUSE,Couleur_Soleil);//rouge
    glTranslatef(-0.5, 0.8, -0.3); //oeil gauche
    gluSphere(Objet_Quadric, 0.5, 20, 20);
    
    glTranslatef(1, 0, 0); //oeil droit
    gluSphere(Objet_Quadric, 0.5, 20, 20);

    glTranslatef(-0.5, -0.9, -0.8); //bouche
    gluSphere(Objet_Quadric, 1.1, 20, 20);

    glTranslatef(-0.6, -0.4, 1); //detail bouche
    gluSphere(Objet_Quadric, 0.1, 20, 20);

    glTranslatef(1.2, 0, 0); //detail bouche
    gluSphere(Objet_Quadric, 0.1, 20, 20);

    glTranslatef(-0.05, -0.05, 0); //detail bouche
    gluSphere(Objet_Quadric, 0.1, 20, 20);

    float x = 0.05, y = 0.05, z = 0.05;

    for (int i = 0; i < 5; i++) {// y et x baisse moitié droite bouche
        glTranslatef(-x, -y, 0);
        gluSphere(Objet_Quadric, 0.1, 20, 20);
    }
    for (int i = 0; i < 12; i++) {// mileu bouche
        glTranslatef(-x, 0, 0);
        gluSphere(Objet_Quadric, 0.1, 20, 20);
    }
    for (int i = 0; i < 5; i++) {// moitié gauche bouche
        glTranslatef(-x, y, 0);
        gluSphere(Objet_Quadric, 0.1, 20, 20);
    }
    glTranslatef(-0.6, 3, -1.5); //oreille gauche
    gluSphere(Objet_Quadric, 0.8, 20, 20);

    glTranslatef(2.4, 0, 0); //oreille droite
    gluSphere(Objet_Quadric, 0.8, 20, 20);

    glTranslatef(2.4, -5, -2); //bras droit
    gluSphere(Objet_Quadric, 2, 20, 20);

    glTranslatef(-7.4, 0, 0); //bras gauche
    gluSphere(Objet_Quadric, 2, 20, 20);

    glTranslatef(9.4, 0, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0.5, -0.5, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0.5, -0.5, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0, -0.5, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0.2, -0.5, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0.2, -0.5, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0.2, -0.5, 0); //détail bras droit
    gluSphere(Objet_Quadric, 1, 20, 20);

    glTranslatef(0, -1.3, 0); //Main droite
    gluSphere(Objet_Quadric, 1.1, 20, 20);

    glTranslatef(1.1, 0, 0); //Main droite pouce
    gluSphere(Objet_Quadric, 0.5, 20, 20);
    
    glTranslatef(-0.3, -1.1, 0); //Main droite doigt 1
    gluSphere(Objet_Quadric, 0.3, 20, 20);
    
    glTranslatef(-0.6, -0.1, 0); //Main droite doigt 2
    gluSphere(Objet_Quadric, 0.3, 20, 20);
   
    glTranslatef(-0.6, 0, 0); //Main droite doigt 3
    gluSphere(Objet_Quadric, 0.3, 20, 20);
    
    glTranslatef(-0.7, 0.3, 0); //Main droite doigt 4
    gluSphere(Objet_Quadric, 0.3, 20, 20);
    
    glTranslatef(-6, 3.5, 0);//buste
    gluSphere(Objet_Quadric, 4, 20, 20);
    //à partir de la j'arrête de commenter, il est minuit.
    glTranslatef(-6, 2, 0);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(-0.5, 0, 0);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(0, 0, 0.5);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(0, 0, 0.5);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(0, 0, 0.5);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(0, 0, 0.5);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(0, 0, 0.5);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    glTranslatef(0, 1, 0);
    gluSphere(Objet_Quadric, 0.5, 20, 20);
    
    glTranslatef(0.3, -0.3, 0.3);
    gluSphere(Objet_Quadric, 0.3, 20, 20);

    for (int i = 0; i < 14; i++) {
        glTranslatef(0, 0, 0.15);
        gluSphere(Objet_Quadric, 0.3, 20, 20);
    }
    for (int i = 0; i < 14; i++) {
          glTranslatef(0, 0, -0.15);
    }
    glTranslatef(4, -7.5, -3);
    gluSphere(Objet_Quadric, 2, 20, 20);
    
    glTranslatef(5, 0, 0);
    gluSphere(Objet_Quadric, 2, 20, 20);

    for (int i = 0; i < 10; i++) {
        glTranslatef(0, -0.5, 0);
        gluSphere(Objet_Quadric, 1, 20, 20);
    }
    glTranslatef(-5, 0, 0);
    gluSphere(Objet_Quadric, 1, 20, 20);
    
    for (int i = 0; i < 10; i++) {
        glTranslatef(0, 0.5, 0);
        gluSphere(Objet_Quadric, 1, 20, 20);
    }

    for (int i = 0; i < 10; i++) {
        glTranslatef(0, -0.5, 0);
    }
    float delta=0.1;
    for (int i = 0; i < 12; i++) {
        glTranslatef(0, 0, 0.25);
        gluSphere(Objet_Quadric, 1-delta, 20, 20);
        delta=delta+0.1;
    }
    
    for (int i = 0; i < 12; i++) {
        glTranslatef(0, 0, -0.25);
    }
    glTranslatef(5, 0, 0);
    delta=0;
    for (int i = 0; i < 12; i++) {
        glTranslatef(0, 0, 0.25);
        gluSphere(Objet_Quadric, 1-delta, 20, 20);
        delta=delta+0.1;
    }
    #endif
      //  glTranslatef(P_Personnage->X, P_Personnage->Y, P_Personnage->Z);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, P_Personnage->Couleur);
        
    glPopMatrix();

}

void Deplace_Personnage(T_PERSONNAGE* P_Personnage){
    
    P_Personnage->X += P_Personnage->VX;
    P_Personnage->Y += P_Personnage->VY;
    P_Personnage->Z += P_Personnage->VZ;
    
    if((P_Personnage->X>15.0f)||(P_Personnage->X<15.0f)){
        P_Personnage->VX=-P_Personnage->VX;
    }
    
    if((P_Personnage->Y>15.0f)||(P_Personnage->Y<15.0f)){
        P_Personnage->VY=-P_Personnage->VY;
    }
    if((P_Personnage->Z>0)||(P_Personnage->Z<-50)){
        P_Personnage->VZ=-P_Personnage->VZ;
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
    Objet_Quadric = gluNewQuadric();
}

void Fin_Scene() {
    gluDeleteQuadric(Objet_Quadric);
}

void Fin_3D() {
    if (Plein_Ecran) {
        glutLeaveGameMode();
    } else {
        glutDestroyWindow(La_Fenetre_Principale);
    }

    exit(0);
}

void Ajoute_Un_Personnage(){
    if(Nombre_Personnage<Nombre_Maxi_Personnage){
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
    Fin_Scene();
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