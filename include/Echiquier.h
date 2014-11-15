#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <vector>
#include "Pieces.h"
//#include <memory>
//#include <array>


class Echiquier
{
    public:
        Echiquier();
        virtual ~Echiquier();
        void placerPiece(Piece *p);
        bool deplacerPiece(Piece *p, int oldX, int oldY);

        void addPiece(Piece *p);//AJOUTE UNE PIECE SUR L'ECHIQUIER
        void delPiece(Piece *p);//ENLEVE UNE PIECE DE L'ECHIQUIER

        bool coordIsValid(int x, int y);
        bool coordIsFreeToKing(int x, int y);
        bool coordIsFree(int x, int y);
        bool comparerPiece(Piece &p, int x, int y);
        Piece* getPieces();
        Piece* getPiece(int x, int y);
        void toString();
    protected:
    private:
        //std::array<std::array<std::unique_ptr<Piece>,8>,8> echiquier;
        //std::array<std::array<Piece*,8>,8> echiquier;
        Piece *echiquier[8][8];

};

#endif // ECHIQUIER_H
