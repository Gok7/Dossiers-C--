#include <cstdlib>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>

using namespace std;

bool Fin_Application = true;

int Largeur_Fenetre = 800;
int Hauteur_Fenetre = 600;

int GLFWCALL Demande_De_Fermeture_Fenetre() {

    cout << "Fermeture de la fenêtre" << endl;
    
    return 0;
}

void GLFWCALL Gestion_Clavier(int P_touche, int P_action){
    
    cout << "Evenement clavier" << endl;
}

void Initialise_Glfw() {
    glfwInit();
    glfwOpenWindow(Largeur_Fenetre, Hauteur_Fenetre, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);

    glfwSetWindowTitle(" Titre de la fenêtre");
    glfwSwapInterval(0); //désactive la synchro
    glfwSetWindowCloseCallback(Demande_De_Fermeture_Fenetre); //call back veut dire un appel en tache de fond.
    //très important. fonction d'interruption, appelé par l'OS.
    glfwSetKeyCallback(Gestion_Clavier); //appelé à chaque appuis sur une touche

}

void Fin_glfw() {
    
    glfwTerminate();
}

void Affichage_Scene(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);//efface le buffer pixel, profondeur, et masque
    glMatrixMode(GL_MODELVIEW);//on remet la matrice au niveau initial.
    glLoadIdentity();
    //........
    // inserer le code ici svp.
    //.......
    glfwSwapBuffers();//affiche réellement l'image.
}

void Initialisation_Scene() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//met la valeur 1 dans la matrice séléctionné préalablement.
    gluPerspective(65.0,//65 = angle d'ouverture
    (double)Largeur_Fenetre/(double)Hauteur_Fenetre,1.5,100.0);
    //coef rapport Largeur/Hauteur casté en double. 1.5 : near clear : on affiche pas, c'est trop proche
    // 100 : trop loin, on affiche pas, économise temps GPU.
    gluLookAt(0.0,0.0,20.0,//est a 0,0,20 ( x y z)
            0.0,0.0,0.0,// regarde 0,0,0 (le centre)
            0.0,1.0,0.0);//vecteur orientation ( vers le haut)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH); //shader, moyen de réfléction de la lumière sur une surface. SMOOTH donne un bon rendu
    glClearColor(0.0, 0.0, 0.0, 0.0);//couleur choisi lors de l'effaçage de l'écran
    glClearDepth(1.0f);//buffer flottant. valeur d'initialisation. Ne cherchez pas à comprendre, c'est trop complexe.
    
    glEnable(GL_LIGHTING);//disjoncteur de l'umière
    glEnable(GL_LIGHT0);//GL gère 9 lumière en standard
    glEnable(GL_DEPTH_TEST);//test si on a besoin du buffer, par exemple si l'affichage est en 3d ou pas.
    //pour le texte on désactive le calcul de profondeur par exemple.
}

int main(int argc, char** argv) {
    
    Initialise_Glfw();
    Initialisation_Scene();
    
    while(Fin_Application==false){//boucle de rendu
        
        Affichage_Scene();
    }
    
    
    
    
    Fin_glfw();
    
    return 0;
}

