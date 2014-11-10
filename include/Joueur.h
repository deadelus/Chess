#ifndef JOUEUR_H
#define JOUEUR_H
#include "Piece.h"
#include <string>
#include <vector>


using namespace std;

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();
        vector<Piece*> getPieces();
        string getNom();
        void setPieces();
        void setPieces(const vector<Piece*> &lesPieces);
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
