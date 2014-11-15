#include <iostream>
#include <typeinfo>
#include "Pieces.h"
#include "Joueur.h"
#include "Echiquier.h"
#define BLANC true
#define NOIR false
#define DROITE true
#define GAUCHE false

/*

 VERIFIER DANS CHAQUE CASE SI LA COORDONNE EST PRISE ET SI OUI LA TUE


*/

using namespace std;

void recap();
void newGame(Echiquier &e, JoueurBlanc &jb, JoueurNoir &jn);
bool eMat(Roi &r);
bool isEchec(Roi &r, int x, int y);

JoueurBlanc *jb = new JoueurBlanc();
JoueurNoir *jn = new JoueurNoir();
Echiquier *e = new Echiquier();
int tour = 0, numPiece, x, y;
bool gameOver = false, saisiOk = false, echec = false, saisiRoiOk = false, deplacerRoiOk = false;;
vector<Piece*> lesPieces;
vector<Piece*> lesBlanches = move(jb->getPieces());
vector<Piece*> lesNoires = move(jn->getPieces());
Roi *r(0);


int main()
{
    cout << "Jeu d'echec!" << endl;

    string nomJoueurBlanc = "whiteNoNamed";
    string nomJoueurNoir = "blackNoNamed";

    cout << "Entrez le nom du joueur blanc" << endl;

    getline(cin, nomJoueurBlanc);

    cout << "Entrez le nom du joueur noir" << endl;

    getline(cin, nomJoueurNoir);

    jn->setNom(nomJoueurNoir);
    jb->setNom(nomJoueurBlanc);

    newGame(*e, *jb, *jn);
    Piece *p(0);

    while(!gameOver){
        /* DEBUT DE LA MAIN */
        e->toString();

        if(tour%2==0){
            cout << endl << " TOUR N. " << tour << " " << jb->getNom() << endl << endl;
            lesPieces = move(jb->getPieces());

            jb->mesPieces();
            r = jb->getRoi();
            if(eMat(*r)){
                gameOver = true;
                cout << endl  <<   jn->getNom() << " VOUS A MIS ECHEC ET MAT " << endl << endl;
            }
        }
        else{
            cout << endl << " TOUR N. " << tour << " " <<   jn->getNom() << endl << endl;
            lesPieces = move(jn->getPieces());
            jn->mesPieces();
            r = jn->getRoi();
            if(eMat(*r)){
                gameOver = true;
                cout << endl  <<   jb->getNom() << " VOUS A MIS ECHEC ET MAT " << endl << endl;
            }
        }

/*
        p = lesPieces[8];
        r = dynamic_cast<Roi*>(p);

        cout << dynamic_cast<Roi*>(p) << endl;
*/
        while(!saisiOk && !gameOver){
            if(isEchec(*r, r->getX(), r->getY())){
                while(!saisiOk){
                    if(!saisiRoiOk){
                        cout << endl << " ECHEC ! DEPLACEZ LE ROI !" << endl;
                        cout << endl << " ENTRER LE N. DE LA PIECE : " << endl;
                        cin >> numPiece;
                        p = lesPieces[numPiece-1];
                        r = dynamic_cast<Roi*>(p);
                        if(r != NULL){
                            saisiRoiOk = true;
                        }
                    }
                    else{
                        cout << endl << " ENTRER LE N. DE LA PIECE : " << endl;
                        cin >> numPiece;
                        cout << endl << " ENTRER LA COLONNE : " << endl;
                        cin >> x;
                        cout << endl << " ENTRER LA LIGNE: " << endl;
                        cin >> y;

                        if(isEchec(*r, x, y)){
                            if(numPiece<1 || numPiece > 16  || x<1 || x>8 || y<1 || y>8){
                                cout << endl << " SAISI INCORRECTE !  " << endl;
                            }
                            else{
                                saisiOk = e->deplacerPiece(lesPieces[numPiece-1], x, y);
                                if(!saisiOk)
                                    cout << endl << " SAISI INCORRECTE !  " << endl;
                            }
                        }
                        else{
                            cout << endl << " SAISI INCORRECTE !  " << endl;
                        }
                    }
                }
            }
            else{
                cout << endl << " ENTRER LE N. DE LA PIECE : " << endl;
                cin >> numPiece;
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


bool eMat(Roi &r){
    bool color = r.getColor();
    bool isFree = false;

    int x = r.getX();
    int y = r.getY();

    for(int i=x-1; i<x+1; i++){
        for(int j=y-1; j<y+1; j++){
            isFree=r.toMoveIsValid(*e,x,y);
            isFree=isEchec(r,x,y);
        }
    }
    return false;
}

bool isEchec(Roi &r, int x, int y){
    bool color = r.getColor();
    bool Echec = false;

    vector<Piece*>::iterator pb = lesBlanches.begin();
    vector<Piece*>::iterator pn = lesNoires.begin();

    if(!color){
        while(pb != lesBlanches.end())
        {
            Echec=(*pb)->toMoveIsValid(*e,x, y);
            pb++;
        }
    }
    else{
        while(pn != lesNoires.end())
        {
            Echec=(*pn)->toMoveIsValid(*e,x, y);
            if(Echec){
                (*pn)->toString();
            }

            pn++;
        }
    }
    //Echec=p->toMoveIsValid(r->getX(), r->getY());

    return Echec;
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
