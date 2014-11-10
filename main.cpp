#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "Partie.h"
#define BLANC true
#define NOIR false

using namespace std;

int main()
{
    cout << "Jeu d'echec!" << endl;

    Partie *p = new Partie();

    Echiquier *e = p->getEchiquier();
    JoueurBlanc *jb = p->getJoueurBlanc();

    vector<Piece*> lesPieces = jb->getPieces();
/*
    for(unsigned int i=0; i<lesPieces.size(); i++){
        cout << "a" << endl;
    }
*/
    e->toString();
/*
    for(int it = 0; it<jb->getPieces().size(); ++it)
    {
        delete jb->getPieces()[it];
    }
*/
/*
    delete p;
    delete jb;
    delete e;
*/
    return 0;
}
