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

    vector<Piece*>::iterator p = lesPieces.begin();

    while(p != lesPieces.end())
    {
        delete *p;
        p++;
    }
}

vector<Piece*> Joueur::getPieces(){
    return lesPieces;
}

void  Joueur::setPieces(vector<Piece*> vp){
    this->lesPieces = move(vp);
}

//Constructeur class fille

// blanc

JoueurBlanc::JoueurBlanc()// : Joueur (true)
{
    cout << "Constructeur Joueur Blanc" << endl;
    vector<Piece*> *lesPieces = new vector<Piece*>;

    for(int i=1; i<=8; i++){
        Pion *p = new Pion(BLANC, i);
        lesPieces->push_back(p);
    }

    Roi *r = new Roi(BLANC);
    Reine *R = new Reine(BLANC);
    Tour *TourDROITE = new Tour(BLANC, DROITE);
    Fou *FouDROITE = new Fou(BLANC, DROITE);
    Tour *TourGAUCHE = new Tour(BLANC, GAUCHE);
    Fou *FouGAUCHE = new Fou(BLANC, GAUCHE);
    Cavalier *CavalierDROITE = new Cavalier(BLANC,DROITE);
    Cavalier *CavalierGAUCHE = new Cavalier(BLANC,GAUCHE);

    lesPieces->push_back(r);
    lesPieces->push_back(R);
    lesPieces->push_back(TourDROITE);
    lesPieces->push_back(TourGAUCHE);
    lesPieces->push_back(FouDROITE);
    lesPieces->push_back(FouGAUCHE);
    lesPieces->push_back(CavalierDROITE);
    lesPieces->push_back(CavalierGAUCHE);

    this->setPieces(*lesPieces);
}

// noir


JoueurNoir::JoueurNoir()//                                                                                                                                                                                                                                : Joueur (false)
{
    cout << "Constructeur Joueur Noir" << endl;
    vector<Piece*> *lesPieces = new vector<Piece*>;

    for(int i=1; i<=8; i++){
        Pion *p = new Pion(NOIR, i);
        lesPieces->push_back(p);
    }

    Roi *r = new Roi(NOIR);
    Reine *R = new Reine(NOIR);
    Tour *TourDROITE = new Tour(NOIR, DROITE);
    Fou *FouDROITE = new Fou(NOIR, DROITE);
    Tour *TourGAUCHE = new Tour(NOIR, GAUCHE);
    Fou *FouGAUCHE = new Fou(NOIR, GAUCHE);
    Cavalier *CavalierDROITE = new Cavalier(NOIR,DROITE);
    Cavalier *CavalierGAUCHE = new Cavalier(NOIR,GAUCHE);

    lesPieces->push_back(r);
    lesPieces->push_back(R);
    lesPieces->push_back(TourDROITE);
    lesPieces->push_back(TourGAUCHE);
    lesPieces->push_back(FouDROITE);
    lesPieces->push_back(FouGAUCHE);
    lesPieces->push_back(CavalierDROITE);
    lesPieces->push_back(CavalierGAUCHE);

    this->setPieces(*lesPieces);
}

void Joueur::toString(){
    cout << "Un joueur" << endl;
}
