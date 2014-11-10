#include <iostream>
#include "Joueur.h"
#define BLANC true
#define NOIR false

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

//Constructeur class fille

// blanc

JoueurBlanc::JoueurBlanc()// : Joueur (true)
{
    cout << "Constructeur Joueur Blanc" << endl;
}

// noir


JoueurNoir::JoueurNoir()//                                                                                                                                                                                                                                : Joueur (false)
{
    cout << "Constructeur Joueur Noir" << endl;
}

