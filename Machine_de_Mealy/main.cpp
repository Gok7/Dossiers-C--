#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef struct{
    char lettre_crypte;
    int etape_suivante;
}T_SUBSTITUTION;

typedef struct{
    T_SUBSTITUTION les_transitions[256];
}T_ETAPE;


int main(int argc, char** argv) {
    T_SUBSTITUTION.lettre_crypte='T';
    T_SUBSTITUTION.etape_suivante=1;
    T_SUBSTITUTION.lettre_crypte='*';
    T_SUBSTITUTION.etape_suivante=2;
    
    
    
    return 0;
}

