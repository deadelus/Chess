#include <iostream>
#include "Partie.h"
#define BLANC true
#define NOIR false


Partie::Partie()
{
    //ctor
    cout << "Nouvelle partie" << endl;
    Echiquier *e = new Echiquier();
    JoueurBlanc *jb = new JoueurBlanc();
    //JoueurNoir *jn = new JoueurNoir();

    vector<Piece*> lesPiecesBlanche = jb->getPieces();
    vector<Piece*> lesPiecesNoire = jb->getPieces();

    for(unsigned int i=0; i<lesPiecesBlanche.size(); i++){
        e->placerPiece(*lesPiecesBlanche[i]);
        e->placerPiece(*lesPiecesNoire[i]);
    }
}

Partie::~Partie()
{
    /*dtor
    delete e;
    delete jb;
    delete jn;
    */
}

Echiquier* Partie::getEchiquier(){
    return e;
}

JoueurBlanc* Partie::getJoueurBlanc(){
    return jb;
}

JoueurNoir* Partie::getJoueurNoir(){
    return jn;
}
