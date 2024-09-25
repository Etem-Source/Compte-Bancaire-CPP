#include <iostream>
#include "Client.h"
#include "Compte.h"
#include <windows.h>

using namespace std;

void cacherSaisie() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));  // Désactiver l'affichage : Pour saisir code secret
}

void afficherSaisie() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);  // Réactiver l'affichage : Pour saisir code secret
}

// Création de trois comptes bancaires
    Compte compte1(50, 1234, "FR751000100010001"); // Solde + CodeSecret + RIB
    Compte compte2(50, 5678, "FR751000100010002"); // "
    Compte compte3(50, 9876, "FR751000100010003"); // "

    // Création de trois clients avec leurs comptes respectifs
    Client C1("S", "Etem", "FR-IRIB2875G718", 701020304, compte1); // Nom + Prénom + CIN + Num + CompteBancaire
    Client C2("G", "Corentin", "FR-IRIB1234J567", 601020305, compte2); // "
    Client C3("P", "Luka", "FR-IRIB8901M234", 501020306, compte3); // "

int main() 
{
    int choix;
    int choixConsulterCompte;
    int choixCrediterCompte;
    float choixCrediterCompteMontant;
    int choixDebiterCompte;
    float choixDebiterCompteMontant;
    int choixDebiterCompteCodeSecret;
    int choixVirementCompte;
    int choixVirementCompteDestinataire;
    float choixVirementCompteMontant;
    int choixCommanderChequier;


    // - - - - - - - - - - Menu - - - - - - - - - -    
    cout << "- - - - - - - - - - Menu - - - - - - - - - -  " << endl; 
    cout << "" << endl; 
    cout << "> Gestion Clients Bancaires" << endl;
    cout << " 1. Afficher client" << endl;
    cout << " 2. Crediter client" << endl;
    cout << " 3. Debiter client" << endl;
    cout << " 4. Virement client" << endl;
    cout << " 5. Commander chequier client" << endl; 
    cout << "" << endl;
    cout << "> Ordinateur" << endl;
    cout << " 0. Quittez" << endl;
    cout << "" << endl;
    // - - - - - - - - - - Menu - - - - - - - - - -    
    cin >> choix; 
    switch (choix)
    {
    case 1:
        system("cls");

        cout << "" << endl; 
        cout << "> Gestion Clients Bancaires - Afficher client" << endl;
        cout << "Choissisez le client a afficher (1, 2 ou 3) : " << endl;
        cin >> choixConsulterCompte;
        switch (choixConsulterCompte)
        {
        case 1:
            C1.afficherClient();
            C1.consulterCompte();
            break;
        case 2:
            C2.afficherClient();
            C2.consulterCompte();
            break;
        case 3:
            C3.afficherClient();
            C3.consulterCompte();
            break;
        default:
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            break;
        }
        main();
        break;
    case 2:
        system("cls");

        cout << "" << endl; 
        cout << "> Gestion Clients Bancaires - Crediter client" << endl;
        cout << "Choissisez le client a crediter (1, 2 ou 3) : " << endl;
        cin >> choixCrediterCompte;
        if(choixCrediterCompte >= 1 && choixCrediterCompte <= 3)
        {}
        else
        {
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            main();
        }
        cout << "Choissisez le montant a crediter (Min: 0, Max: 5000): " << endl;
        cin >> choixCrediterCompteMontant;
        if(choixCrediterCompteMontant > 0 && choixCrediterCompteMontant <= 5000)
        {}
        else
        {
            cout << " /!\\ Votre montant est inferieur a 0 ou superieur a 5000 ... !" << endl;
            main();
        }
        switch (choixCrediterCompte)
        {
        case 1:
            C1.crediterCompte(choixCrediterCompteMontant);
            break;
        case 2:
            C2.crediterCompte(choixCrediterCompteMontant);
            break;
        case 3:
            C3.crediterCompte(choixCrediterCompteMontant);
            break;
        default:
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            break;
        }
        main();
        break;
    case 3:
        system("cls");

        cout << "" << endl; 
        cout << "> Gestion Clients Bancaires - Debiter client" << endl;
        cout << "Choissisez le client a debiter (1, 2 ou 3) : " << endl;
        cin >> choixDebiterCompte;
        if(choixDebiterCompte >= 1 && choixDebiterCompte <= 3)
        {}
        else
        {
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            main();
        }
        cout << "Choissisez le montant a debiter (Min: 0, Max: 5000) : " << endl;
        cin >> choixDebiterCompteMontant;
        if(choixDebiterCompteMontant > 0 && choixDebiterCompteMontant <= 5000)
        {}
        else
        {
            cout << " /!\\ Votre montant est inferieur a 0 ou superieur a 5000 ... !" << endl;
            main();
        }
        cout << "Veuillez saisir le code secret : " << endl;
        cacherSaisie();
        cin >> choixDebiterCompteCodeSecret;
        afficherSaisie();
        switch (choixDebiterCompte)
        {
        case 1:
            C1.debiterCompte(choixDebiterCompteCodeSecret, choixDebiterCompteMontant);
            break;
        case 2:
            C2.debiterCompte(choixDebiterCompteCodeSecret, choixDebiterCompteMontant);
            break;
        case 3:
            C3.debiterCompte(choixDebiterCompteCodeSecret, choixDebiterCompteMontant);
            break;
        default:
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            break;
        }
        main();
        break;
    case 4:
        system("cls");
        
        cout << "" << endl; 
        cout << "> Gestion Clients Bancaires - Virement client" << endl;
        cout << "Choissisez le client qui va envoyer (1, 2 ou 3) : " << endl;
        cin >> choixVirementCompte;
        if(choixVirementCompte >= 1 && choixVirementCompte <= 3)
        {}
        else
        {
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            main();
        }
        cout << "Choissisez le client qui va recevoir (1, 2 ou 3) : " << endl;
        cin >> choixVirementCompteDestinataire;
        if(choixVirementCompteDestinataire >= 1 && choixVirementCompteDestinataire <= 3)
        {}
        else
        {
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            main();
        }
        cout << "Choissisez le montant qui va etre envoyer (Min: 0, Max: 5000) : " << endl;
        cin >> choixVirementCompteMontant;
        if(choixVirementCompteMontant > 0 && choixVirementCompteMontant <= 5000)
        {}
        else
        {
            cout << " /!\\ Votre montant est inferieur a 0 ou superieur a 5000 ... !" << endl;
            main();
        }
        switch (choixVirementCompte)
        {
        case 1:
            if(choixVirementCompteDestinataire == 1)
            {
                cout << "/!\\ Vous ne pouvez pas vous envoyer un virement a vous meme ! " << endl;
            }
            else if(choixVirementCompteDestinataire == 2)
            {
                C1.virementCompte(C2, choixVirementCompteMontant);
            }
            else if(choixVirementCompteDestinataire == 3)
            {
                C1.virementCompte(C3, choixVirementCompteMontant);
            }
            break;
        case 2:
            if(choixVirementCompteDestinataire == 1)
            {
                C2.virementCompte(C1, choixVirementCompteMontant);
            }
            else if(choixVirementCompteDestinataire == 2)
            {
                cout << "/!\\ Vous ne pouvez pas vous envoyer un virement a vous meme ! " << endl;
            }
            else if(choixVirementCompteDestinataire == 3)
            {
                C2.virementCompte(C3, choixVirementCompteMontant);
            }
            break;
        case 3:
            if(choixVirementCompteDestinataire == 1)
            {
                C3.virementCompte(C1, choixVirementCompteMontant);
            }
            else if(choixVirementCompteDestinataire == 2)
            {
                C3.virementCompte(C2, choixVirementCompteMontant);
            }
            else if(choixVirementCompteDestinataire == 3)
            {
                cout << "/!\\ Vous ne pouvez pas vous envoyer un virement a vous meme ! " << endl;
            }
            break;
        default:
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            main();
            break;
        }
        main();
        break;
    case 5:
        system("cls");
        
        cout << "" << endl; 
        cout << "> Gestion Clients Bancaires - Commander chequier client" << endl;
        cout << "Choissisez le client qui va commander le chequier (1, 2 ou 3) : " << endl;
        cin >> choixCommanderChequier;
        switch (choixCommanderChequier)
        {
        case 1:
            C1.commanderChequierCompte();
            break;
        case 2:
            C2.commanderChequierCompte();
            break;
        case 3:
            C3.commanderChequierCompte();
            break;
        default:
            cout << " /!\\ Vous n'avez pas choisi entre 1 et 3 ... !" << endl;
            break;
        }
        main();
        break;
    case 0:
        break;
    default:
        cout << " /!\\ Vous n'avez pas choisi entre 0 et 4 ... !" << endl;
        main();
        break;
    };

    return 0;
}
