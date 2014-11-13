#include <iostream>
#include <typeinfo>
#include "Pieces.h"
#include "Joueur.h"
#include "Echiquier.h"
#define BLANC true
#define NOIR false
#define DROITE true
#define GAUCHE false

using namespace std;

void recap();
void newGame(Echiquier &e, JoueurBlanc &jb, JoueurNoir &jn);

int main()
{
    cout << "Jeu d'echec!" << endl;

    JoueurBlanc *jb = new JoueurBlanc();
    JoueurNoir *jn = new JoueurNoir();
    Echiquier *e = new Echiquier();
    newGame(*e, *jb, *jn);
    int tour = 0, numPiece, x, y;
    bool gameOver = false, saisiOk = false, echec = false;
    vector<Piece*> lesPieces;
    Piece *p(0);
    Roi *r(0);

    while(!gameOver){
        /* DEBUT DE LA MAIN */
        e->toString();

        if(tour%2==0){
            cout << endl << " TOUR N." << tour <<  " - JOUEUR BLANC" << endl << endl;
            lesPieces = move(jb->getPieces());
            jb->mesPieces();
        }
        else{
            cout << endl << " TOUR N." << tour <<  " - JOUEUR NOIR" << endl << endl;
            lesPieces = move(jn->getPieces());
            jn->mesPieces();
        }
/*

        p = lesPieces[8];
        r = dynamic_cast<Roi*>(p);

        cout << dynamic_cast<Roi*>(p) << endl;
*/
        while(!saisiOk){
            if(echec){
                cout << endl << " ECHEC ! DEPLACEZ LE ROI !" << endl;
                cout << endl << " ENTRER LE N. DE LA PIECE : " << endl;
                cin >> numPiece;
                p = lesPieces[numPiece-1];
                r = dynamic_cast<Roi*>(p);
            }
            else{
                cout << endl << " ENTRER LE N. DE LA PIECE : " << endl;
                cin >> numPiece;
            }

            cout << endl << " ENTRER LA COLONNE : " << endl;
            cin >> x;
            cout << endl << " ENTRER LA LIGNE: " << endl;
            cin >> y;

            if(numPiece<1 || numPiece > 16  || x<1 || x>8 || y<1 || y>8){
                cout << endl << " SAISI INCORRECTE !  " << endl;
            }
            else{
                saisiOk = e->deplacerPiece(lesPieces[numPiece-1], x, y);
                if(!saisiOk)
                    cout << endl << " SAISI INCORRECTE !  " << endl;
            }

        }

        //e->toString();

        lesPieces.clear();
        saisiOk = false;
        if(tour==10)
            gameOver = true;
        tour++;
    }
    /* FIN DE LA MAIN */
    //cout << endl << numPiece;
    return 0;
}

void newGame (Echiquier &e, JoueurBlanc &jb, JoueurNoir &jn){
    vector<Piece*> lesPiecesBlanches = move(jb.getPieces());
    vector<Piece*> lesPiecesNoires = move(jn.getPieces());

    //cout << lesPiecesBlanches.size() <<endl;

    vector<Piece*>::iterator pb = lesPiecesBlanches.begin();
    vector<Piece*>::iterator pn = lesPiecesNoires.begin();


    while(pb != lesPiecesBlanches.end())
    {
        e.placerPiece(*pb);
        //(*p)->toString();
        pb++;
    }

    while(pn != lesPiecesNoires.end())
    {
        e.placerPiece(*pn);
        //(*p)->toString();
        pn++;
    }
}

void recap(){
    /*
    RECAPITULATIF
    */

    int i=10;
    int *pi(0);
    int *pi2(0);

    pi = &i;
    pi2 = pi;

    cout << "i = " << i << endl;
    cout << "pi = " << pi << endl;
    cout << "*pi = " << *pi << endl;
    cout << "pi2 = " << pi2 << endl;

}
