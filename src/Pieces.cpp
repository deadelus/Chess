#include <iostream>
#include "Pieces.h"
#include "Echiquier.h"
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
bool Piece::toMoveIsValid(Echiquier *e,int x, int y){
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
bool Roi::toMoveIsValid(Echiquier *e,int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();
    //PETIT ROQUE

    if(xOrigin != x || yOrigin != y){
        for(int i = xOrigin-1; i <= xOrigin+1; i++){
            for(int j = yOrigin-1; j <= yOrigin+1; j++){
                //cout << " x : " << x << " y : " << y << endl;
                if(i == x && j == y){
                    if(e->coordIsFree(x, y)){
                        isValid = Piece::toMoveIsValid(e,x, y);
                    }else{
                        if(e->comparerPiece(*this,x,y)){
                            isValid = Piece::toMoveIsValid(e,x, y);
                        }
                    }
                }
            }
        }

    }

    if((this->getIsRoqued())){
        cout << " je passe ici " << endl;
        isRoqued = false;
        isValid = true;
    }

    return isValid;
}

bool Roi::roque(Echiquier *e, int x, int y){
int yRoque(0);
Piece *p(0);
Tour *t(0);

int xOrigin = this->getX();
int yOrigin = this->getY();
bool isValid = false;

if(!(this->getIsRoqued())){
    yRoque = (this-getColor())?8:1;

    cout << "NOIR : " << yRoque <<  endl;
    this->toString();

    if(xOrigin == 5 && yOrigin == yRoque){
        //PETIT ROQUE
        if(x == 7){
            p = e->getPiece(xOrigin+3, yOrigin);
            t = dynamic_cast<Tour*>(p);
            if(t != 0){
                t->toString();
                isValid = Piece::toMoveIsValid(e,x,y);
                cout << "Piece::toMoveIsValid(e,x,y) : " << isRoqued <<  endl;
                if(isValid){
                    isRoqued = e->deplacerPiece(t,t->getX()-2, yRoque);
                    cout << "e->deplacerPiece(t,t->getX()-2, yRoque) : " << t->getX() <<  endl;
                    if(isRoqued){
                        isValid = e->deplacerPiece(this, xOrigin+2, yRoque);
                        cout << "e->deplacerPiece(this, xOrigin+2, yRoque) : " << this->getX() <<  endl;
                    }
                }
            }
        }

        //GRAND ROQUE
        if(x == 3){
            p = e->getPiece(xOrigin-4, yOrigin);
            t = dynamic_cast<Tour*>(p);
            if(t != 0){
                isValid = Piece::toMoveIsValid(e,x,y);
                if(isValid){
                    isRoqued = e->deplacerPiece(t,t->getX()+3, yRoque);
                    if(isRoqued){
                        isValid = e->deplacerPiece(this, xOrigin-2, yRoque);
                    }
                }
            }
        }
    }
}

return isValid;
}

bool Roi::getIsRoqued(){
    return isRoqued;
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
bool Reine::toMoveIsValid(Echiquier *e,int x, int y){
    bool isValid = false;

    if((Tour::toMoveIsValid(e,x,y)) ){
       //||(Fou::toMoveIsValid(e,x,y))){
        isValid = e->comparerPiece(*this, x, y);
    }

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
bool Fou::toMoveIsValid(Echiquier *e,int x, int y){
    bool isValid = true;
    int xOrigin = getX();
    int yOrigin = getY();
    int i = 0;

    //On a besoin que du x car les diagonales representent une fonction linéaire tel que y = x,
    if(xOrigin != x || yOrigin != y){
        // Calcul des lignes et colonnes
        if(yOrigin > y && xOrigin > x){
            int X = xOrigin-1;
            for(int Y = yOrigin-1; Y>=y; Y--){
                //cout << i << " A X= " << X << " Y = " << Y << endl;
                if(isValid){
                    if((e->coordIsFree(X, Y))){
                        isValid = Piece::toMoveIsValid(e,X, Y);
                    }
                    else if(Y == y){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,X, Y);
                        }
                    }else{
                        isValid = false;
                    }
                }
                X--;
            }
        }

        else if(yOrigin < y && xOrigin > x){
            int X = xOrigin-1;
            for(int Y = yOrigin+1; Y<=y; Y++){
                //cout << i << " B  X= " << X << " Y = " << Y << endl;
                //i++;
                if(isValid){
                    if((e->coordIsFree(X, Y))){
                        //cout << "FOU is free" << i << endl;
                        isValid = Piece::toMoveIsValid(e,X, Y);
                    }
                    else if(Y == y){
                        //cout << "FOU if x==y" << endl;
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,X, Y);
                        }
                    }else{
                        //cout << "else X= " << X << " Y = " << Y << endl;
                        isValid = false;
                    }
                }
                X--;
            }
        }
        else if(yOrigin > y && xOrigin < x){
            int Y = yOrigin-1;
            for(int X = xOrigin+1; X>=x; X++){
                //cout << i << " C  GROSSE PUTE X= " << X << " Y = " << Y << endl;
                if(isValid){
                    if((e->coordIsFree(X, Y))){
                        isValid = Piece::toMoveIsValid(e,X, Y);
                    }
                    else if(X == x){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,X, Y);
                        }
                    }else{
                        isValid = false;
                    }
                }
                Y--;
            }
        }
        else if(yOrigin < y && xOrigin < x){
            int Y = yOrigin+1;
            for(int X = xOrigin+1; X<=x; X++){
                //cout << i << " D X= " << X << " Y = " << Y << endl;
                if(isValid){
                    if((e->coordIsFree(X, Y))){
                        isValid = Piece::toMoveIsValid(e,X, Y);
                    }
                    else if(X == x){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,X, Y);
                        }
                    }else{
                        isValid = false;
                    }
                }
                Y++;
            }
        }
        else{
            isValid = false;
        }
    }else{
        isValid = false;
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
bool Cavalier::toMoveIsValid(Echiquier *e,int x, int y){
    bool isValid = false;
    int xOrigin = this->getX();
    int yOrigin = this->getY();

    //On a besoin que du x car les diagonales representent une fonction linéaire tel que y = x,
    if(xOrigin != x && yOrigin != y){
        if((e->comparerPiece(*this, x, y))){
            // Calcul des lignes et colonnes
            if(x == xOrigin+1 && y == yOrigin+2){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin+1 && y == yOrigin-2){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin+2 && y == yOrigin+1){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin+2 && y == yOrigin-1){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin-1 && y == yOrigin+2){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin-1 && y == yOrigin-2){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin-2 && y == yOrigin+1){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
            else if(x == xOrigin-2 && y == yOrigin-1){
                isValid = Piece::toMoveIsValid(e,x, y);
            }
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
bool Tour::toMoveIsValid(Echiquier *e, int x, int y){
    bool isValid = true;
    int xOrigin = this->getX();
    int yOrigin = this->getY();
    //On a besoin que du x car les diagonales representent une fonction linéaire tel que y = x,
    if(xOrigin != x || yOrigin != y){
        // Calcul des lignes et colonnes
        if(yOrigin > y && x == xOrigin){
            for(int Y = yOrigin-1; Y>=y; Y--){
              if(isValid){
                    if((e->coordIsFree(xOrigin, Y))){
                        isValid = Piece::toMoveIsValid(e,xOrigin, Y);
                    }
                    else if(Y == y){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,xOrigin, Y);
                        }
                    }else{
                        isValid = false;
                    }
                }
            }
        }
        else if(yOrigin < y && x == xOrigin){
            int i = 0;
            for(int Y = yOrigin+1; Y<=y; Y++){
                if(isValid){
                    i++;
                    if((e->coordIsFree(xOrigin, Y))){
                         cout << "TOUR is free" << i << endl;
                        isValid = Piece::toMoveIsValid(e,xOrigin, Y);
                    }
                    else if(Y == y){
                        cout << "TOUR x==y" << endl;
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,xOrigin, Y);
                        }
                    }else{
                        isValid = false;
                    }
                }
            }
        }
        else if(xOrigin > x && y == yOrigin){
            for(int X = xOrigin-1; X>=x; X--){
                if(isValid){
                    if((e->coordIsFree(X, yOrigin))){
                        isValid = Piece::toMoveIsValid(e,X, yOrigin);
                    }
                    else if(X == x){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,X, yOrigin);
                        }
                    }else{
                        isValid = false;
                    }
                }
            }
        }
        else if(xOrigin < x && y == yOrigin){
            for(int X = xOrigin+1; X<=x; X++){
                    if(isValid){
                    if((e->coordIsFree(X, yOrigin))){
                        isValid = Piece::toMoveIsValid(e,X, yOrigin);
                    }
                    else if(X == x){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,X, yOrigin);
                        }
                    }else{
                        isValid = false;
                    }
                }
            }
        }
        else{
            isValid = false;
        }
    }else{
        isValid = false;
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
bool Pion::toMoveIsValid(Echiquier *e,int x, int y){
    bool isValid = false;

    int xOrigin = this->getX();
    int yOrigin = this->getY();
    bool color  = this->getColor();

    //cout << " Origine x " << xOrigin << " Des x " << x << endl;
    //cout << " Origine y " << yOrigin << " Des y " << y << endl;

    if(xOrigin != x || yOrigin != y){
        if(color == BLANC){
            if((y == 4) && (x == xOrigin)){
                if(e->coordIsFree(x, y)){
                    isValid = Piece::toMoveIsValid(e,x, y);
                }
            }
            else if((x == xOrigin+1 && y == yOrigin+1)||
               (x == xOrigin-1 && y == yOrigin+1)){
                    if(!(e->coordIsFree(x, y))){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,x, y);
                        }
                    }
            }
            else if(x == xOrigin && y == yOrigin+1){
                    if(e->coordIsFree(x, y)){
                        isValid = Piece::toMoveIsValid(e,x, y);
                    }
            }
        }
        else if(color == NOIR){
            if((y == 5)&&(x == xOrigin)){
                if(e->coordIsFree(x, y)){
                    isValid = Piece::toMoveIsValid(e,x, y);
                }
            }
            else if((x == xOrigin+1 && y == yOrigin-1)||
               (x == xOrigin-1 && y == yOrigin-1)){
                    if(!(e->coordIsFree(x, y))){
                        if(e->comparerPiece(*this, x, y)){
                            isValid = Piece::toMoveIsValid(e,x, y);
                        }
                    }
            }
            else if(x == xOrigin && y == yOrigin-1){
                    if(e->coordIsFree(x, y)){
                        isValid = Piece::toMoveIsValid(e,x, y);
                    }
            }
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
    isRoqued = false;
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
