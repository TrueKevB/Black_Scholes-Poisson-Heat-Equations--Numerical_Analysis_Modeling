#include <iostream>
#include <bits/stdc++.h>

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

#include"vecteur_template_main.h"

#include "TP3/tp3_exo1/tp3_exo1h.h"
#include "TP3/tp3_exo1/tp3_exo1.cpp"

#include "TP3/tp3_exo2/tp3_exo2h.h"
#include "TP3/tp3_exo2/tp3_exo2.cpp"

#include "TP3/tp3_exo3/tp3_exo3h.h"
#include "TP3/tp3_exo3/tp3_exo3.cpp"

#include "TP4/tp4_exo1/tp4_exo1h.h"
#include "TP4/tp4_exo1/tp4_exo1.cpp"

#include "TP4/tp4_exo2/tp4_exo2h.h"
#include "TP4/tp4_exo2/tp4_exo2.cpp"

#include "TP4/tp4_exo3/tp4_exo3h.h"
#include "TP4/tp4_exo3/tp4_exo3.cpp"




using namespace std;


int main() {
    int choix = -1;

    //while (choix != 0) {
        std::cout << " | \n | \n=====================================" ;
        std::cout << "\nKOUADIO Akou Blaise & SONHAFO Mesellius \n M1 MFCA - 2025_2026 \n";
        std::cout << "=====================================\n=====================================" ;
        std::cout << "\n=========== MENU PRINCIPAL ===========\n";
        std::cout << "=====================================\n=====================================\n\n" ;
        std::cout << "Choisissez un exercice a executez ou APPUYEZ SUR << 0 >> pour sortir : \n\n\n";
        std::cout << "1) TP3_Exo1 : Ax=b avec A symetrique en stockage profil \n\n";
        std::cout << "2) TP3_Exo2 : Ax=b avec A tridiagonale en stockage bande \n\n";
        std::cout << "3) TP3_Exo3 : Produit matrice vecteur en stockage CSR \n\n";
        std::cout << "4) TP4_Exo1 : Resolution du probleme de Poisson 1D \n\n";
        std::cout << "5) TP4_Exo2 :  Deux schemas numeriques pour l'equation de la chaleur \n\n";
        std::cout << "6) TP4_Exo3 : Resolution de l'equation de Black-Scholes \n\n";
        std::cout << "0) Quitter\n | \n | \n Votre Choix : " ;
        std::cin >> choix;
        std::cout << "\n=====================================\n...........EXECUTION...........\n=====================================\n | \n | \n" ;


        switch (choix) {
            case 1:
                std::cout << "1) TP3_Exo1 : Ax=b avec A symetrique en stockage profil \n\n";
                tp3_exo1();
                std::cout << "\n===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                break;
            case 2:
                 std::cout << "2) TP3_Exo2 : Ax=b avec A tridiagonale en stockage bande \n\n";
                tp3_exo2();
                std::cout << "\n===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                break;
            case 3:
                std::cout << "3) TP3_Exo3 : Produit matrice vecteur en stockage CSR \n\n";
                tp3_exo3();
                std::cout << "\n===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                 break;
            case 4:
                std::cout << "4) TP4_Exo1 : Resolution du probleme de Poisson 1D \n\n";
                tp4_exo1();
                std::cout << "\n===================================================\n";
                std::cout << "CONSULTEZ LES REPRESENTATIONS GRAPHIQUES DANS LE CODE PYTHON : \npython_GRAPHES_TP4.ipynb \nA LA RACINE DU FICHIER PROINCIPALE\n";
                std::cout << "===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                break;
            case 5:
                std::cout << "5) TP4_Exo2 :  Deux schemas numeriques pour l'equation de la chaleur \n\n";
                tp4_exo2();
                std::cout << "\n===================================================\n";
                std::cout << "CONSULTEZ LES REPRESENTATIONS GRAPHIQUES DANS LE CODE PYTHON : \npython_GRAPHES_TP4.ipynb \nA LA RACINE DU FICHIER PROINCIPALE\n";
                std::cout << "===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                break;
            case 6:
                std::cout << "6) TP4_Exo3 : Resolution de l'equation de Black-Scholes \n\n";
                tp4_exo3();
                std::cout << "\n===================================================\n";
                std::cout << "CONSULTEZ LES REPRESENTATIONS GRAPHIQUES DANS LE CODE PYTHON : \npython_GRAPHES_TP4.ipynb \nA LA RACINE DU FICHIER PROINCIPALE\n";
                std::cout << "===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                break;
            case 0: std::cout << "\n===================================================\n";
                    std::cout << ".................Fin du programme.................\nVEUILLEZ RELANCER LE PROGRAMME POUR PASSER A UN AUTRE EXERCICE\n";
                    std::cout << "===================================================";
                    break;
            default: std::cout << "\n Choix invalide. Veuillez reessayer.\n";
        }
    //}

    return 0;
}
