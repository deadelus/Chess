#ifndef PARTIE_H
#define PARTIE_H
#include "Echiquier.h"
#include "Joueur.h"

class Partie
{
    public:
        Partie();
        virtual ~Partie();
        void creerPartie();
        Echiquier* getEchiquier();
        JoueurBlanc* getJoueurBlanc();
        JoueurNoir* getJoueurNoir();
    protected:
    private:
        Echiquier *e;
        JoueurBlanc *jb;
        JoueurNoir *jn;
};

#endif // PARTIE_H
