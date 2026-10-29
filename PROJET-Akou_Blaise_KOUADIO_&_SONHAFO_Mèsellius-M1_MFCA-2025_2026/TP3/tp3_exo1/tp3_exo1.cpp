
#include <string>
#if !defined (__IOSTREAM_H)
#include <iostream>
#endif
#if !defined (__FSTREAM_H)
#include <fstream>
#endif
#if !defined (__ASSERT_H)
#include <assert.h>
#endif
#if !defined(__STRING_H)
#include <string>
#endif
#if !defined (__VECTOR_H)
#include <vector>
#endif

#if !defined (TP3_EXO1H_H)
#include "tp3_exo1h.h"
#endif

using namespace std;

void tp3_exo1() {
//int main(){

    string nom_fichier("matriceA1.txt");
    ifstream file;
    file.open(nom_fichier,ios::in); // ouverture du fichier
    assert(!file.fail()); // verifier ouverture correcte du fichier

    int N;
    file >> N;
    cout << "Dim = " << N << endl;
    cout << "Apleine = \n";
    double Apleine[N*N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            file >> Apleine[i*N+j];
            cout << Apleine[i*N+j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    mat_profil A;
    A=matrice_profil(Apleine,N);
    const int N1 = 5;
    double A2[N1 * N1] = {
    1, 0, 2, 0, 0,
    0, 2, 0, 0, 0,
    2, 0, 5, -1, 3,
    0, 0, -1, 2, 0,
    0, 0, 3, 0, -6
    };
    cout << "Matrice A2 :" << endl;
    for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        cout << A2[i * N + j] << " ";
    }
    cout << endl;
}

    cout << "Matrice profil = "<< endl;
    cout << "INDIAG : " << A.INDIAG << endl;
    cout << "ATAB   : " << A.ATAB << endl;



    vector<double> x(N, 1.0);


    vector<double> y = prod_mat_vect_sym2(A2, x);


    cout << "Produit Ax = [ ";
    for (double val : y) cout << val << " ";
    cout << "]" << endl;


    factorisation_LDL(A);

cout << "Apres factorisation LDL :" << endl;
cout << "INDIAG : " << A.INDIAG << endl;
    cout << "ATAB   : " << A.ATAB << endl;


    vector<double> b = {1, 2, 3, 4, 5};
    ecrire_vect("vecteur_b.txt", b);
    cout << "Vecteur b enregistre dans : vecteur_b.txt" << endl;


    string fichier_entree = "vecteur_b.txt";
    vector<double> b1 = lire_vect(fichier_entree);
    cout << "Vecteur lu depuis le fichier : vecteur_b.txt  " << fichier_entree << " : " << b1 << endl;


vector<double> x1 = resolution_LDL(A, b1);

cout << "Solution x* = [ ";
for (double val : x1) cout << val << " ";
cout << "]" << endl;





vector<double> Ax1 = prod_mat_vect_sym2(A2, x1);
cout << "Ax* = [ " << Ax1 << " ] \n";



 vector<double> diff = Ax1 - b1;
        cout << "Ax* - b = " << diff << endl;



double erreur = norme_2(diff);
cout << "Norme euclidienne de l'erreur ||Ax - b||2 = " << erreur << endl;



    ecrire_vect("resolution1.txt", x1);
    cout << "Le vecteur x* a ete enregistre dans le ficher : resolution1.txt " << endl << "Proche de 0 le resultat est acceptable" << endl;

    //return 0;



}
