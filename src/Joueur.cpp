#include <iostream>
#include "Joueur.h"
#define BLANC true
#define NOIR false
#define DROITE true
#define GAUCHE false

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
    cout << "Destruction Joueur" << endl;
}

vector<Piece*> Joueur::getPieces(){
    return lesPieces;
}

//Constructeur class fille

// blanc

JoueurBlanc::JoueurBlanc()// : Joueur (true)
{
    cout << "Constructeur Joueur Blanc" << endl;
    for(int i=1; i<=8; i++){
        lesPieces.push_back(new Pion(i, BLANC));
    }

    Roi Roi(BLANC);
    Reine Reine(BLANC);
    Tour TourDROITE(BLANC, DROITE);
    Fou FouDROITE(BLANC, DROITE);
    Tour TourGAUCHE(BLANC, GAUCHE);
    Fou FouGAUCHE(BLANC, GAUCHE);
    Cavalier CavalierDROITE(BLANC,DROITE);
    Cavalier CavalierGAUCHE(BLANC,GAUCHE);

    lesPieces.push_back(&Roi);
    lesPieces.push_back(&Reine);
    lesPieces.push_back(&TourDROITE);
    lesPieces.push_back(&TourGAUCHE);
    lesPieces.push_back(&FouDROITE);
    lesPieces.push_back(&FouGAUCHE);
    lesPieces.push_back(&CavalierDROITE);
    lesPieces.push_back(&CavalierGAUCHE);

    //cout << lesPieces.size() <<endl;
}

// noir


JoueurNoir::JoueurNoir()//                                                                                                                                                                                                                                : Joueur (false)
{
    cout << "Constructeur Joueur Noir" << endl;
    for(int i=1; i<=8; i++){
        lesPieces.push_back(new Pion(i, NOIR));
    }

    Roi Roi(NOIR);
    Reine Reine(NOIR);
    Tour TourDROITE(NOIR, DROITE);
    Fou FouDROITE(NOIR, DROITE);
    Tour TourGAUCHE(NOIR, GAUCHE);
    Fou FouGAUCHE(NOIR, GAUCHE);
    Cavalier CavalierDROITE(NOIR,DROITE);
    Cavalier CavalierGAUCHE(NOIR,GAUCHE);

    lesPieces.push_back(&Roi);
    lesPieces.push_back(&Reine);
    lesPieces.push_back(&TourDROITE);
    lesPieces.push_back(&TourGAUCHE);
    lesPieces.push_back(&FouDROITE);
    lesPieces.push_back(&FouGAUCHE);
    lesPieces.push_back(&CavalierDROITE);
    lesPieces.push_back(&CavalierGAUCHE);
}

