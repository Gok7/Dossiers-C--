#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct T_MAILLON {
    int Data;
    T_MAILLON* Suivant;
} T_MAILLON;

typedef struct T_TETE {
    T_MAILLON* Debut_liste;
    T_TETE* Tete_suivante;
} T_TETE;

T_TETE* Debut_tete=NULL;

/*
void Ajoute_Au_Debut(int P_Valeur) {

    T_MAILLON* L_Maillon = new T_MAILLON; //1 creation nouveau maillon
    if (Debut_Liste == NULL) {
        Fin_Liste = L_Maillon;
    }
    L_Maillon->Suivant = Debut_Liste; //2 chainer nouveau maillon avec le premier
    Debut_Liste = L_Maillon; //3 dire que le nouveau maillon est le premier
    L_Maillon->Data = P_Valeur; //4 initialiser le Data 
}
*/
void Affiche_Data() {

    T_TETE* L_tete=Debut_tete;
            
    while (L_tete != NULL) {
        T_MAILLON* L_Maillon_Courant = L_tete->Debut_liste;
        while (L_Maillon_Courant != NULL) {
            cout << L_Maillon_Courant->Data << " ";
            L_Maillon_Courant = L_Maillon_Courant->Suivant;
        }
        L_tete=L_tete->Tete_suivante;
    }
    cout << "Fin " << endl;
}

int main(int argc, char** argv) {
    
    Debut_tete=new T_TETE;
    Debut_tete->Debut_liste=new T_MAILLON;//tete 1
    Debut_tete->Tete_suivante->Debut_liste = new T_MAILLON;//tete 2
    Debut_tete->Tete_suivante->Tete_suivante->Debut_liste = new T_MAILLON;//tete 3
    
    Debut_tete->Debut_liste->Suivant=new T_MAILLON;//tete 1 maillon 1
    Debut_tete->Debut_liste->Suivant->Data=9;
    
    Debut_tete->Debut_liste->Suivant->Suivant=new T_MAILLON;//tete 1 maillon 2
    Debut_tete->Debut_liste->Suivant->Suivant->Data=8;
    
    Debut_tete->Debut_liste->Suivant->Suivant->Suivant=new T_MAILLON;//tete 1 maillon 3
    Debut_tete->Debut_liste->Suivant->Suivant->Suivant->Data=7;
    
    Debut_tete->Debut_liste->Suivant->Suivant->Suivant->Suivant=NULL;
    
    Debut_tete->Tete_suivante->Debut_liste=new T_MAILLON;//tete 2 maillon 1
    
    
    Affiche_Data();

    return 0;
}