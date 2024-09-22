#ifndef COMPTE_H
#define COMPTE_H

#include <iostream>
#include <string>

using namespace std;

class Compte 
{
    private:
        static int nextId;  // Variable statique pour suivre le prochain ID
        int idUnique;       // ID unique du compte
        float solde;         // Solde du compte
        int codeSecret;      // Code secret à 4 chiffres
        string rib;          // RIB

    public:
        // Constructeur défaut
        Compte();

        // Constructeur paramètres
        Compte(float, int, string);
            

        // Méthodes pour les opérations sur le compte
        void crediterCompte(float); // Crédite le compte
        void debiterCompte(int, float);   // Débite le compte
        void virementCompte(Compte, float); // Vireme
        void consulterCompte();             // Affiche les informations du compte
        void commanderChequierCompte();
};

#endif
