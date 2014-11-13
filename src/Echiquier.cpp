#include <iostream>
#include "Echiquier.h"


using namespace std;

Echiquier::Echiquier()
{
    cout << "Creation de l'echiquier!" << endl;

    for(int x = 0; x<8; x++){
        //cout << x << endl;
        for(int y = 0; y<8; y++){
            echiquier[x][y]=NULL;
            //cout << y;
        }
        //cout << endl;
    }
    //ctor
}

Echiquier::~Echiquier()
{
    cout << "Destruction de l'echiquier!" << endl;
    //dtor
}

void Echiquier::placerPiece(Piece *p){

    int x = p->getX();
    int y = p->getY();

    echiquier[x-1][y-1] = p;

    if(x>=1&&x<=8){
        if(y>=1&&y<=8){
        }
    }
}

bool Echiquier::deplacerPiece(Piece *p, int x, int y){
    bool isValid = p->toMoveIsValid(x,y);
    cout << isValid << endl;

    if(isValid){
        int oldX = p->getX();
        int oldY = p->getY();
        echiquier[oldX-1][oldY-1] = NULL;
        echiquier[x-1][y-1] = p;
        p->toMove(x, y);
    }

    return isValid;
}

void Echiquier::delPiece(Piece *p){
    int x = p->getX();
    int y = p->getY();
    if(x>=1&&x<=8){
        if(y>=1&&y<=8){
            if(echiquier[x-1][y-1] == p){
                echiquier[x-1][y-1] = NULL;
                delete p;
            }
        }
    }
}

bool Echiquier::coordIsValid(int x, int y){
    bool isValid = false;
    if(x>=1&&x<=8){
        if(y>=1&&y<=8){
            isValid=true;
        }
    }
    return isValid;
}

bool Echiquier::coordIsNotFree(int x, int y){
    bool isFree = false;
    if(x>=1&&x<=8){
        if(y>=1&&y<=8){
            if(echiquier[x-1][y-1] == NULL){
                isFree = true;
            }
        }
    }
    return isFree;
}

bool Echiquier::comparerPiece(Piece &p, int x, int y){
    bool isDiferent;
    Piece *P = this->getPiece(x, y);


    if(p.getColor() != P->getColor()){
        isDiferent = true;
    }


    return isDiferent;
}

Piece* Echiquier::getPiece(int x, int y){
    Piece *p;
    if(x>=1&&x<=8){
        if(y>=1&&y<=8){
            p = echiquier[x-1][y-1];
        }
    }
    return p;
}

void Echiquier::toString(){
    cout << endl;
    int X = 1;
    for(int y = 1; y<=8; y++){
        cout << " " << X++ << " " ;
        for(int x = 1; x<=8; x++){
                // this->coordIsNotFree(x,y)
            if(this->coordIsNotFree(x,y)){
               if((x+y)%2==0){
                cout << "#";
               }
               else{
                cout << " ";
               }
            }
            else{
                cout << echiquier[x-1][y-1]->myCode();
            }
        }
        cout << "  " << endl;
    }
    cout << endl;
    cout << "   12345678" << endl;
}
