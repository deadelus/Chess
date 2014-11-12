#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <vector>
#include "Pieces.h"

using namespace std;

class Echiquier
{
    public:
        Echiquier();
        virtual ~Echiquier();
        void placerPiece(Piece *p);
        void deplacerPiece(Piece *p, int oldX, int oldY);

        void addPiece(Piece *p);//AJOUTE UNE PIECE SUR L'ECHIQUIER
        void delPiece(Piece *p);//ENLEVE UNE PIECE DE L'ECHIQUIER

        bool coordIsValid(int x, int y);
        bool coordIsNotFree(int x, int y);
        bool comparerPiece(Piece &p, int x, int y);
        Piece* getPiece(int x, int y);
        void toString();
    protected:
    private:
        Piece* echiquier[8][8];
};

#endif // ECHIQUIER_H
