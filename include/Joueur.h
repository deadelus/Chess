#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <vector>
#include "Pieces.h"

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();
        std::vector<Piece*> getPieces();
        std::string getNom();
        Roi* getRoi();
        void setPieces(std::vector<Piece*> vp);
        void mesPieces();
        void setNom(std::string n);
        void setRoi(Roi &roi);
        void toString();
    protected:
        std::vector<Piece*> lesPieces;
        Roi* roi;
        std::string Nom;
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
