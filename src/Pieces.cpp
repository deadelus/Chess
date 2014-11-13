#include <iostream>
#include "Pieces.h"
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

//PIECE
bool Piece::toMoveIsValid(int x, int y){
    bool isValid = false;
    if(x>0 && x<9 && y>0 && y<9){
        isValid = true;
    }
    return isValid;
}

void Piece::toMove(int x, int y){
    setX(x);
    setY(y);
}

char Piece::myCode(){
    char code = '?';
    return code;
}
void Piece::toString(){
    cout << "Ceci est une Piece" << endl;
}

//ROI
bool Roi::toMoveIsValid(int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    if(xOrigin != x && yOrigin != y){
        for(int i = xOrigin-1; i <= xOrigin+1; i++){
            for(int j = yOrigin-1; j <= yOrigin+1; j++){
                if(i == x && j == y){
                    isValid = true;
                }
            }
        }
       isValid = Piece::toMoveIsValid(x, y);
    }
    return isValid;
}

char Roi::myCode(){
    char code;
    if(this->getColor() == BLANC){
        code = 'k';
        return code;
    }
    else{
        code = 'K';
        return code;
    }
}

void Roi::toString(){
    cout << "Ceci est un Roi en x: " << this->getX() << " y: " << this->getY() << endl;
}

//REINE
bool Reine::toMoveIsValid(int x, int y){
    bool isValid = false;
    isValid = Tour::toMoveIsValid(x, y);
    isValid = Fou::toMoveIsValid(x, y);

    return isValid;
}

char Reine::myCode(){
    char code;
    if(this->getColor() == BLANC){
        code = 'q';
        return code;
    }
    else{
        code = 'Q';
        return code;
    }
}

void Reine::toString(){
    cout << "Ceci est une Reine en x: " << this->getX() << " y: " << this->getY() << endl;
}

//FOU
bool Fou::toMoveIsValid(int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    //On a besoin que du x car les diagonales representent une fonction linéaire tel que y = x,
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
       isValid = Piece::toMoveIsValid(x, y);
    }

    return isValid;
}

char Fou::myCode(){
    char code;
    if(this->getColor() == BLANC){
        code = 'f';
        return code;
    }
    else{
        code = 'F';
        return code;
    }
}

void Fou::toString(){
    cout << "Ceci est un Fou en x: " << this->getX() << " y: " << this->getY() << endl;
}


//CAVALIER
bool Cavalier::toMoveIsValid(int x, int y){
bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    //On a besoin que du x car les diagonales representent une fonction linéaire tel que y = x,
    if(xOrigin != x && yOrigin != y){
        isValid = Piece::toMoveIsValid(x, y);
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
    }

    return isValid;
}

char Cavalier::myCode(){
    char code;
    if(this->getColor() == BLANC){
        code = 'c';
        return code;
    }
    else{
        code = 'C';
        return code;
    }
}

void Cavalier::toString(){
    cout << "Ceci est un Cavalier en x: " << this->getX() << " y: " << this->getY() << endl;
}

//TOUR
bool Tour::toMoveIsValid(int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();
    //On a besoin que du x car les diagonales representent une fonction linéaire tel que y = x,
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

       isValid = Piece::toMoveIsValid(x, y);
    }

    return isValid;
}
char Tour::myCode(){
    char code;
    if(this->getColor() == BLANC){
        code = 't';
        return code;
    }
    else{
        code = 'T';
        return code;
    }
}

void Tour::toString(){
    cout << "Ceci est une Tour en x: " << this->getX() << " y: " << this->getY() << endl;
}

//PION
bool Pion::toMoveIsValid(int x, int y){
    bool isValid = false;

    int xOrigin = this->getX();
    int yOrigin = this->getY();
    bool color  = this->getColor();

    //cout << " Origine x " << xOrigin << " Des x " << x << endl;
    //cout << " Origine y " << yOrigin << " Des y " << y << endl;

    if((y == 4)
        &&(color==BLANC)
        && (x == xOrigin)){
        isValid = Piece::toMoveIsValid(x, y);
    }

    if((y == 5)
       &&(color==NOIR)
       &&(x == xOrigin)){
        isValid = Piece::toMoveIsValid(x, y);
    }

    if(color == BLANC){
        if((x == xOrigin && y == yOrigin+1)||
           (x == xOrigin+1 && y == yOrigin+1)||
           (x == xOrigin-1 && y == yOrigin+1)){
            isValid = Piece::toMoveIsValid(x, y);
        }
    }

    else{
        if((x == xOrigin && y == yOrigin-1)||
           (x == xOrigin+1 && y == yOrigin-1)||
           (x == xOrigin-1 && y == yOrigin-1)){
            isValid = Piece::toMoveIsValid(x, y);
        }
    }

    return isValid;
}

char Pion::myCode(){
    char code;
    if(this->getColor() == BLANC){
        code = 'x';
        return code;
    }
    else{
        code = 'X';
        return code;
    }
}

void Pion::toString(){
    cout << "Ceci est un Pion en x: " << this->getX() << " y: " << this->getY() << endl;
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
