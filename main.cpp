#include <iostream>
#include "Pieces.h"
#include "Joueur.h"
#define BLANC true
#define NOIR false
#define DROITE true
#define GAUCHE false

using namespace std;

int main()
{
    cout << "Jeu d'echec!" << endl;

/*

    RECAPITULATIF

    int i=10;
    int *pi(0);
    int *pi2(0);

    pi = &i;
    pi2 = pi;

    cout << "i = " << i << endl;
    cout << "pi = " << pi << endl;
    cout << "*pi = " << *pi << endl;
    cout << "pi2 = " << pi2 << endl;
*/


    JoueurBlanc jb;
    JoueurNoir jn;

    vector<Piece*> lesPieces = move(jb.getPieces());

    cout << lesPieces.size() <<endl;

    vector<Piece*>::iterator p = lesPieces.begin();

    while(p != lesPieces.end())
    {
        (*p)->toString();
        p++;
    }

    return 0;
}
