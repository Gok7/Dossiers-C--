#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef struct {
    int x;
    int y;
} T_POINT;


T_POINT les_points[10]; 

void Initialise_les_points(int P_valeur_x, int P_valeur_y) {
    for (int Compteur = 0; Compteur < 9; Compteur++) {
        les_points[Compteur].x = P_valeur_x;
        les_points[Compteur].y = P_valeur_y;
    }
}

void Calcule_les_diagonales(int P_variable){
    float L_racine;
    float tempo1;
    float tempo2;
    
    tempo1=les_points[P_variable].x*les_points[P_variable].x;
    tempo2=les_points[P_variable].y*les_points[P_variable].y;
    tempo2+=tempo1;
    L_racine=sqrt(tempo1);
}



void Affiche() {
    for (int Compteur = 0; Compteur < 9; Compteur++) {
        cout << les_points[Compteur].x;
        cout << les_points[Compteur].y;
    }
}

int main(int argc, char** argv) {
    Initialise_les_points(10, 20);
    Affiche();
    return 0;
}

