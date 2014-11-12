#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <vector>
#include "Pieces.h"

using namespace std;

class Joueur
{
    public:
        Joueur();
        Joueur(bool color);
        virtual ~Joueur();
        vector<Piece*> getPieces();
        string getNom();
        void setPieces(vector<Piece*> vp);
        bool getColor();
        void toString();
    protected:
        vector<Piece*> lesPieces;
        string Nom;
        bool color;
    private:
};

class JoueurBlanc : public Joueur{
    public:
        JoueurBlanc();
};

class JoueurNoir : public Joueur{
    public:
        JoueurNoir();
};

#endif // JOUEUR_H
