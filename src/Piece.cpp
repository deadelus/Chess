#include <iostream>
#include <string>
#include "Piece.h"
#define BLANC true
#define NOIR false

using namespace std;

Piece::Piece()
{
    //ctor
}

Piece::Piece(int x, int y, bool color)
{
    //ctor
    this->setX(x);
    this->setY(y);
    this->setColor(color);
}

Piece::~Piece()
{
    //dtor
    //cout << "Destruction Piece" << endl;
}
//METHODES GENERALES
int Piece::getX(){
    return X;
}

int Piece::getY(){
    return Y;
}

void Piece::setX(int x){
    X=x;
}

void Piece::setY(int y){
    Y=y;
}

bool Piece::getColor(){
    return Color;
}

void Piece::setColor(bool color){
    Color=color;
}

void Piece::kill(Echiquier *Echiquier, Piece &autre){
    Piece *PieceADetruire(&autre);
    Echiquier->delPiece(*PieceADetruire);
}

void Piece::toMove(Echiquier *Echiquier, int x, int y){
    int oldX = this->getX();
    int oldY = this->getY();
    this->setX(x);
    this->setY(y);

    Piece *autre = Echiquier->getPiece(x,y);

    Piece::kill(Echiquier, *autre);
    Echiquier->deplacerPiece(*this, oldX, oldY);
}

//PIECE
bool Piece::toMoveIsValid(Echiquier *Echiquier, int x, int y){
    bool isValid = false;
    if(Echiquier->coordIsValid(x,y)){
        if(Echiquier->coordIsNotFree(x,y)){
            if(!Echiquier->comparerPiece(this, x, y)){
                isValid = true;
            }
        }
    }
    return isValid;
}

string Piece::myCode(){
    string code = "?";
    return code;
}
void Piece::toString(){
    cout << "Ceci est une Piece" << endl;
}

//ROI
bool Roi::toMoveIsValid(Echiquier *Echiquier, int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    if(xOrigin != x && yOrigin != y){
        for(int i = xOrigin; i <= xOrigin+1; i++){
            for(int j = yOrigin; j <= yOrigin+1; j++){
                if(i == x && j == y){
                    isValid = true;
                }
            }
        }
       isValid = Piece::toMoveIsValid(Echiquier, x, y);
    }
    return isValid;
}

string Roi::myCode(){
    string code;
    if(this->getColor() == BLANC){
        code = "k";
        return code;
    }
    else{
        code = "K";
        return code;
    }
}

void Roi::toString(){
    cout << "Ceci est un Roi" << endl;
}

//REINE
bool Reine::toMoveIsValid(Echiquier *Echiquier, int x, int y){
    bool isValid = false;
    isValid = Tour::toMoveIsValid(Echiquier, x, y);
    isValid = Fou::toMoveIsValid(Echiquier, x, y);

    return isValid;
}

string Reine::myCode(){
    string code;
    if(this->getColor() == BLANC){
        code = "q";
        return code;
    }
    else{
        code = "Q";
        return code;
    }
}

void Reine::toString(){
    cout << "Ceci est une Reine" << endl;
}

//FOU
bool Fou::toMoveIsValid(Echiquier *Echiquier, int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    //On a besoin que du x car les diagonales representent une fonction lin�aire tel que y = x,
    if(xOrigin != x && yOrigin != y){
        // Calcul des diagonales
        for(int i = 0; i<8; i++){
            if(x == xOrigin+i && y == xOrigin+i){
                isValid = true;
            }
            if(x == xOrigin+i && y == xOrigin-i){
                isValid = true;
            }
            if(x == xOrigin-i && y == xOrigin+i){
                isValid = true;
            }
            if(x == xOrigin-i && y == xOrigin-i){
                isValid = true;
            }
        }
       isValid = Piece::toMoveIsValid(Echiquier, x, y);
    }

    return isValid;
}

string Fou::myCode(){
    string code;
    if(this->getColor() == BLANC){
        code = "f";
        return code;
    }
    else{
        code = "F";
        return code;
    }
}

void Fou::toString(){
    cout << "Ceci est un Fou" << endl;
}


//CAVALIER
bool Cavalier::toMoveIsValid(Echiquier *Echiquier, int x, int y){
bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    //On a besoin que du x car les diagonales representent une fonction lin�aire tel que y = x,
    if(xOrigin != x && yOrigin != y){
        // Calcul des lignes et colonnes
        if(x == xOrigin+1 && y == yOrigin+2){
            isValid = true;
        }
        if(x == xOrigin+1 && y == yOrigin-2){
            isValid = true;
        }
        if(x == xOrigin+2 && y == yOrigin+1){
            isValid = true;
        }
        if(x == xOrigin+2 && y == yOrigin-1){
            isValid = true;
        }
        if(x == xOrigin-1 && y == yOrigin+2){
            isValid = true;
        }
        if(x == xOrigin-1 && y == yOrigin-2){
            isValid = true;
        }
        if(x == xOrigin-2 && y == yOrigin+1){
            isValid = true;
        }
        if(x == xOrigin-2 && y == xOrigin-1){
            isValid = true;
        }

       isValid = Piece::toMoveIsValid(Echiquier, x, y);
    }

    return isValid;
}

string Cavalier::myCode(){
    string code;
    if(this->getColor() == BLANC){
        code = "c";
        return code;
    }
    else{
        code = "C";
        return code;
    }
}

void Cavalier::toString(){
    cout << "Ceci est un Cavalier" << endl;
}

//TOUR
bool Tour::toMoveIsValid(Echiquier *Echiquier, int x, int y){
bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();
    //On a besoin que du x car les diagonales representent une fonction lin�aire tel que y = x,
    if(xOrigin != x && yOrigin != y){
        // Calcul des lignes et colonnes

        for(int i = 0; i<8; i++){
            if(x == xOrigin && y == xOrigin+i){
                isValid = true;
            }
            if(x == xOrigin+i && y == xOrigin){
                isValid = true;
            }
            if(x == xOrigin && y == xOrigin-i){
                isValid = true;
            }
            if(x == xOrigin-i && y == xOrigin){
                isValid = true;
            }
        }

       isValid = Piece::toMoveIsValid(Echiquier, x, y);
    }

    return isValid;
}
string Tour::myCode(){
    string code;
    if(this->getColor() == BLANC){
        code = "t";
        return code;
    }
    else{
        code = "T";
        return code;
    }
}

void Tour::toString(){
    cout << "Ceci est une Tour" << endl;
}

//PION
bool Pion::toMoveIsValid(Echiquier *Echiquier, int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    if((x == xOrigin+1 && y == yOrigin+1)||(x == xOrigin-1 && y == yOrigin+1)){
       isValid = Piece::toMoveIsValid(Echiquier, x, y);
    }

    return isValid;
}

string Pion::myCode(){
    string code;
    if(this->getColor() == BLANC){
        code = "x";
        return code;
    }
    else{
        code = "X";
        return code;
    }
}

void Pion::toString(){
    cout << "Ceci est un Pion" << endl;
}

//ctor

Roi::Roi(bool color) : Piece(5,(color)?1:8,color){
    //cout << "Constructeur Roi" << endl;
}

Reine::Reine(bool color) : Piece(4,(color)?1:8, color), Tour(color, true), Fou(color, true){
    //cout << "Constructeur Reine" << endl;
}

Tour::Tour (bool color, bool position) : Piece((position)?1:8,(color)?1:8,color){
    //cout << "Constructeur Tour" << endl;
}

Cavalier::Cavalier(bool color, bool position) : Piece((position)?2:7,(color)?1:8,color){
    //cout << "Constructeur Cavalier" << endl;
}

Fou::Fou(bool color, bool position) : Piece((position)?3:6,(color)?1:8,color){
    //cout << "Constructeur Fou" << endl;
}

Pion::Pion(bool color, int x) : Piece(x,(color)?2:7,color){
    //cout << "Constructeur Pion" << endl;
}
