#include "Client.h"

// Constructeur simplifié
Client::Client(string c_nom, string c_prenom, string c_numcin, int c_numTel, Compte c_compte) 
{
    nom = c_nom;
    prenom = c_prenom;
    numcin = c_numcin;
    numTel = c_numTel;
    compte = c_compte;  // Associe le compte directement dans le corps du constructeur
}

// Méthode pour afficher un client et son compte
void Client::afficherClient() {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "NumCIN: " << numcin << endl;
    cout << "Numero Tel: +33 " << numTel << endl;
    cout << "/Y\\ --> Informations du client affichees avec succes ! " << endl;
}

// Méthode pour modifier les informations du client
void Client::modifierClient(string mod_nom, string mod_prenom, string mod_numcin, int mod_num) {
    nom = mod_nom;
    prenom = mod_prenom;
    numcin = mod_numcin;
    numTel = mod_num;
    cout << "/Y\\ --> Client modifie avec succes !" << endl;
}

void Client::virementCompte(Client destinataire, float montant) 
{
    compte.virementCompte(destinataire.compte, montant);
}

void Client::crediterCompte(float montant) // Crédite le compte
{
    compte.crediterCompte(montant);
}

void Client::debiterCompte(int code_secret, float montant)   // Débite le compte
{
    compte.debiterCompte(code_secret, montant);
}
void Client::consulterCompte()          // Affiche les informations du compte
{
    compte.consulterCompte();
}