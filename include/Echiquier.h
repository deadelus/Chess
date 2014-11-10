#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <vector>

class Piece;

using namespace std;

class Echiquier
{
    public:
        Echiquier();
        virtual ~Echiquier();
        void placerPiece(Piece &p);

        void addPiece(Piece &p);//AJOUTE UNE PIECE SUR L'ECHIQUIER
        void delPiece(Piece &p);//ENLEVE UNE PIECE DE L'ECHIQUIER

        bool coordIsValid(int x, int y);
        bool coordIsFree(int x, int y);
        bool comparerPiece(Piece *p, int x, int y);
        Piece* getPiece(int x, int y);
        void toString();
    protected:
    private:
        Piece* echiquier[8][8];
};

#endif // ECHIQUIER_H
