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
int tour = 0, numPiece = 0, x = 0, y = 0;
bool gameOver = false, saisiOk = false, echec = false, saisiRoiOk = false, deplacerRoiOk = false;;
vector<Piece*> *lesPieces;
vector<Piece*> lesPiecesBlanches;
vector<Piece*> lesPiecesNoires;
Roi *r(0);
char roque;


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
    Roi *rSaisi(0);
    Piece *pSaisi(0);

    while(!gameOver){
        /* DEBUT DE LA MAIN */
        e->toString();

        if(tour%2==0){
            cout << endl << " TOUR N. " << tour << " " << jb->getNom() << endl << endl;
            lesPieces = &lesPiecesBlanches;

            cout << " test : " << endl;

            (*lesPieces)[1]->toString();


            jb->mesPieces();
            r = jb->getRoi();
            r->toString();

            if(eMat(*r)){
                gameOver = true;
                cout << endl  <<   jn->getNom() << " VOUS A MIS ECHEC ET MAT " << endl << endl;
            }
        }
        else{
            cout << endl << " TOUR N. " << tour << " " <<   jn->getNom() << endl << endl;
            lesPieces = &lesPiecesNoires;
            jn->mesPieces();
            r = jn->getRoi();
            r->toString();

            if(eMat(*r)){
                gameOver = true;
                cout << endl  <<   jb->getNom() << " VOUS A MIS ECHEC ET MAT " << endl << endl;
            }

        }

        while(!saisiOk && !gameOver){
            if(isEchec(*r, r->getX(), r->getY())){
                cout << endl << " ECHEC ! DEPLACEZ LE ROI !" << endl;
                while(!saisiOk){
                    if(!saisiRoiOk){
                        cout << endl << " ENTRER LE N. DE LA PIECE : " << endl;
                        cin >> numPiece;
                        cout << endl << " ENTRER LA COLONNE : " << endl;
                        cin >> x;
                        cout << endl << " ENTRER LA LIGNE: " << endl;
                        cin >> y;


                            if(numPiece<1 || numPiece > 16  || x<1 || x>8 || y<1 || y>8){
                                cout << endl << " SAISI INCORRECTE ! VOUS SORTEZ DE L'ECHIQUIER " << endl;
                                saisiRoiOk = false;
                            }
                            else if(isEchec(*r, x, y)){
                                cout << endl << " SAISI INCORRECTE ! VOUS ETES TOUJOURS EN ECHEC  " << endl;
                            }
                            else{
                                saisiOk = e->deplacerPiece((*lesPieces)[numPiece-1], x, y);
                                if(!saisiOk)
                                    cout << endl << " SAISI INCORRECTE ! DEPLACEMENT IMPOSSIBLE ";
                                    saisiRoiOk = false;
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
                    cout << endl << "SAISI INCORRECTE ! VOUS SORTEZ DE L'ECHIQUIER" << endl;
                }
                else{
                    pSaisi = (*lesPieces)[numPiece-1];
                    rSaisi = dynamic_cast<Roi*>(pSaisi);
                    cout << rSaisi << endl;
                    if(rSaisi != 0){
                       if(isEchec(*rSaisi, x, y)){
                            cout << endl << " SAISI INCORRECTE VOUS SEREZ EN ECHEC ICI!  " << endl;
                       }
                       else if((
                           (y==8 && x==7)||
                           (y==8 && x==3)||
                           (y==1 && x==7)||
                           (y==1 && x==3))&&
                           !(rSaisi->getIsRoqued())){

                                while(roque != 'y' && roque != 'n'){
                                    cout << "Voulez vous roquer ? [y / n]" << endl;
                                    cin >> roque;
                                }

                           if(roque == 'y'){
                                saisiOk = rSaisi->roque(e,x,y);
                                if(!saisiOk){
                                    cout << endl << " SAISI INCORRECTE ! ROQUE IMPOSSIBLE  " << endl;
                                }
                           }
                        }
                        else{
                            saisiOk = e->deplacerPiece((*lesPieces)[numPiece-1], x, y);
                            if(!saisiOk){
                                cout << endl << " SAISI INCORRECTE ! DEPLACEMENT IMPOSSIBLE  " << endl;
                            }
                       }
                    }
                    else{
                        saisiOk = e->deplacerPiece((*lesPieces)[numPiece-1], x, y);
                        if(!saisiOk){
                            cout << endl << " SAISI INCORRECTE ! DEPLACEMENT IMPOSSIBLE  " << endl;
                        }
                    }
                }
            }
        }
    saisiOk = false;
    if(tour==10)
        gameOver = true;
    tour++;

    }

    return 0;
}

void newGame (Echiquier &e, JoueurBlanc &jb, JoueurNoir &jn){
    lesPiecesBlanches = jb.getPieces();
    lesPiecesNoires = jn.getPieces();

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
    bool isFree = false;

    int x = r.getX();
    int y = r.getY();

    for(int i=x-1; i<x+1; i++){
        for(int j=y-1; j<y+1; j++){
            if(isEchec(r,x,y) && !r.toMoveIsValid(e,i,j)){
                isFree = true;
            }else{
                return false;
            }
        }
    }
    return isFree;
}

bool isEchec(Roi &r, int x, int y){
    bool color = r.getColor();
    cout << &r << endl;
    bool Echec = false;
    bool stop = false;

    vector<Piece*>::iterator ivpb = lesPiecesBlanches.begin();
    vector<Piece*>::iterator ivpn = lesPiecesNoires.begin();
    cout << endl << endl <<  " ---- ECHEC ? ----" << endl << endl;
    if(color){
        while(ivpn != lesPiecesNoires.end() && !stop)
        {
            if((*ivpn)->toMoveIsValid(e,x,y)){
                Echec=true;
                (*ivpn)->toString();
                cout << "ECHEC AVEC NOIR" << endl;
                stop = true;
            }

            ivpn++;
        }
    }
    else{
        while(ivpb != lesPiecesBlanches.end() && !stop)
        {
            if((*ivpb)->toMoveIsValid(e,x,y)){
                Echec=true;
                (*ivpb)->toString();
                cout << "ECHEC AVEC BLANC" << endl;
                stop = true;
            }

            ivpb++;
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
