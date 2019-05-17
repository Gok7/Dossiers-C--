#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct T_MAILLON {
    int Data;
    T_MAILLON* Suivant;
    T_MAILLON* Precedant;
} T_MAILLON;

typedef struct{
T_MAILLON* Debut_Liste;
T_MAILLON* Fin_Liste;
}T_Liste;


void Affiche_Liste(T_Liste* P_liste) {
    T_MAILLON* L_Maillon_Courant;
    L_Maillon_Courant = P_liste->Debut_Liste;

    while (L_Maillon_Courant != NULL) {
        cout << L_Maillon_Courant->Data << " ";
        L_Maillon_Courant = L_Maillon_Courant->Suivant;
    }
    cout << "Fin liste" << endl;
}

void Affiche_un_Maillon(T_MAILLON* P_Maillon) {
    cout<<"Adresse maillon :  "<<P_Maillon<<" ";
    if (P_Maillon != NULL) {
        cout <<"Valeur : "<< P_Maillon->Data << " ";
        cout <<"Suivant :  "<<P_Maillon->Suivant << " " << endl;
        Affiche_un_Maillon(P_Maillon->Suivant);
    }
}

void Supprimer_Liste(T_Liste* P_liste) {
    T_MAILLON* L_Maillon_Suivant;

    while (P_liste->Debut_Liste != NULL) {
        L_Maillon_Suivant = P_liste->Debut_Liste->Suivant;
        delete P_liste->Debut_Liste;
        P_liste->Debut_Liste = L_Maillon_Suivant;
    }
}

void Ajoute_Au_Debut(T_Liste* P_liste,int P_Valeur) {

    T_MAILLON* L_Maillon = new T_MAILLON; //1 creation nouveau maillon
    if (P_liste->Debut_Liste == NULL) {
        P_liste->Fin_Liste = L_Maillon;
    }
    L_Maillon->Suivant = P_liste->Debut_Liste; //2 chainer nouveau maillon avec le premier
    P_liste->Debut_Liste = L_Maillon; //3 dire que le nouveau maillon est le premier
    L_Maillon->Data = P_Valeur; //4 initialiser le Data
  
}

void Ajoute_Fin(T_Liste* P_liste,int P_Valeur) {
    if(P_liste->Debut_Liste==NULL){
        Ajoute_Au_Debut(P_liste,P_Valeur);
    }
    else{
        T_MAILLON* L_Nouveau= new T_MAILLON;
        P_liste->Fin_Liste->Suivant=L_Nouveau;
        L_Nouveau->Suivant=NULL;
        L_Nouveau->Data=P_Valeur;
        P_liste->Fin_Liste=L_Nouveau;
    }
}

void Initialisation_Liste(T_Liste* P_liste){
     P_liste->Debut_Liste = NULL;
     P_liste->Fin_Liste = NULL;
}

int main(int argc, char** argv) {

    T_Liste Ma_liste;
    T_Liste Ma_liste_deux;
    Initialisation_Liste(&Ma_liste);
    Initialisation_Liste(&Ma_liste_deux);
    Ajoute_Au_Debut(&Ma_liste,30);
    Ajoute_Au_Debut(&Ma_liste,40);
    Ajoute_Au_Debut(&Ma_liste_deux,5);
    Affiche_un_Maillon(Ma_liste.Debut_Liste);
    cout<<"**********************************"<<endl;
    Affiche_un_Maillon(Ma_liste_deux.Debut_Liste);
    return 0;
}


//pour vendredi travailler sur l'ajout à la fin, si la liste existe, on cherche 
//le dernier maillon. si la liste existe pas, on utilise la fonction ajoute au début
//-Essayer de reecrire le parcours de la liste de façon récursive
//Travailler sur l'ajout d'un Element en plein milieu suivant un critère, par ex
//par ordre croissant.

//petit controle vendredi 14 dec
//gros controle a la rentrée


