#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Compte.h"

using namespace std;

class Client {
private:
    string nom;
    string prenom;
    string numcin;
    int numTel;
    Compte compte; // Le compte associé au client

public:
    // Constructeur
    Client(string, string, string, int, Compte);


    // Méthodes CLIENT
    void afficherClient(); // Afficher un client et son compte
    void modifierClient(string, string, string, int);

    // Compte
    void virementCompte(Client &, float);
    void crediterCompte(float);
    void debiterCompte(int, float);   // Débite le compte
    void consulterCompte();             // Affiche les informations du compte
    void commanderChequierCompte();
};

#endif
