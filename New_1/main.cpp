#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>

using namespace std;

typedef struct{
    float x;
    float y;
}T_POINT;

T_POINT Les_points[100];

void Init() {
    for (int compteur = 0; compteur < 100; compteur++) {
        Les_points[compteur].x = 0;
        Les_points[compteur].y = 0;
    }
}

bool Verifie_collision(int P_Index_1, int P_index_2) {

    bool L_Collision = false;
    if (Les_points[P_Index_1].x == Les_points[P_Index_1].x &&
            Les_points[P_Index_1].y == Les_points[P_Index_1].y) {
        L_Collision = true;
    }
    return L_Collision;
}

void Affiche() {
    for (int compteur = 0; compteur < 100; compteur++) {
        cout<<compteur;
        cout<<" X : "<<Les_points[compteur].x;
        cout<<" Y : "<<Les_points[compteur].y<<endl;
    }
}

int main(int argc, char** argv) {

    Init();
    Verifie_collision();
    Affiche();
    
    return 0;
}

