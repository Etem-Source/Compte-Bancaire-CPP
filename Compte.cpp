#include "Compte.h"

// Initialisation de la variable statique
int Compte::nextId = 0;

// Constructeur défaut
Compte::Compte() 
{
    // idUnique = nextId++;
    // solde = 0;
    // codeSecret = 0;
    // rib = "";
}

// Constructeur paramètres
Compte::Compte(float c_solde, int c_codeSecret, string c_rib) 
{
    idUnique = nextId++;  // Assigner l'ID et incrémenter
    solde = c_solde;
    codeSecret = c_codeSecret;
    rib = c_rib;
}

// Créditer le compte
void Compte::crediterCompte(float montant) 
{
    solde += montant;
    cout << "/Y\\ --> Compte " << idUnique << " credite de " << montant << " euros avec succes !" << endl;
}

// Débiter le compte
void Compte::debiterCompte(int debiter_codesecret, float debiter_montant) 
{
    if (solde >= -50 && solde - debiter_montant >= -50) 
    {
        if(debiter_codesecret == codeSecret)
        {
            solde -= debiter_montant;
            cout << "/Y\\ --> Compte " << idUnique << " debite de " << debiter_montant << " euros avec succes !" << endl;
        }
        else
        {
            cout << "/!\\ --> Mauvais code secret pour debiter du compte " << idUnique << ": " << debiter_montant << " euros !" << endl;
        }
    } 
    else 
    {
        cout << "/!\\ --> Solde insuffisant pour debiter du compte " << idUnique << " : " << debiter_montant << " euros !" << endl;
    }
}

void Compte::virementCompte(Compte compteDest, float montant) 
{
    if (montant <= 0) 
    {
        cout << "/!\\ --> Le montant doit être positif pour un virement !" << endl;
    }
    else
    {
        if (solde >= -50 && solde - montant >= -50) 
        {
            solde -= montant;           // Débiter le montant du compte source
            compteDest.crediterCompte(montant);  // Crédite le montant au compte de destination (copie)
            cout << "/Y\\ --> Virement de " << montant << " euros effectue avec succes !" << endl;
        } 
        else 
        {
            cout << "/!\\ --> Solde insuffisant pour effectuer le virement de " << montant << " euros !" << endl;
        }
    }
}


// Affiche les informations du compte
void Compte::consulterCompte() 
{
    cout << "ID Unique: " << idUnique << endl;
    cout << "Solde: " << solde << " euros" << endl;
    cout << "Code Secret: " << codeSecret << endl;
    cout << "RIB: " << rib << endl;
    cout << "/Y\\ --> Compte " << idUnique << " consulte avec succes !" << endl;
}

void Compte::commanderChequierCompte()
{
    if(chequier == 0)
    {
        cout << "/Y\\ --> Compte " << idUnique << " chequier commander avec succes !" << endl;
        chequier = 1;
    }
    else
    {
        cout << "/!\\ --> Le compte " << idUnique << " possede deja un chequier !" << endl;
    }
}
