#include <iostream>
#include "Pieces.h"
#include "Joueur.h"
#include "Echiquier.h"
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
    Echiquier e;

    vector<Piece*> lesPiecesBlanches = move(jb.getPieces());
    vector<Piece*> lesPiecesNoires = move(jn.getPieces());

    //cout << lesPiecesBlanches.size() <<endl;

    vector<Piece*>::iterator pb = lesPiecesBlanches.begin();
    vector<Piece*>::iterator pn = lesPiecesNoires.begin();


    while(pb != lesPiecesBlanches.end())
    {
        e.placerPiece(*pb);
        //(*p)->toString();
        pb++;
    }

    while(pn != lesPiecesNoires.end())
    {
        e.placerPiece(*pn);
        //(*p)->toString();
        pn++;
    }

    e.toString();

    return 0;
}
