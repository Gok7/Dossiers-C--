#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    int i, j, valeur_inserer = 1;
    int tampon;
    int MAT[3][3];


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            MAT[i][j] = valeur_inserer;
            valeur_inserer++;
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tampon=MAT[i][j];
            MAT[i][j] = MAT[j][i];
            MAT[j][i]=tampon;
            cout<<"ligne "<<i<<" colonne "<<j<<" : "<<MAT[i][j]<<endl;
        }
        
            
    }
    
    return 0;
}

