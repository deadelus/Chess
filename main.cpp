#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#define BLANC true
#define NOIR false

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Echiquier *e = new Echiquier();
    JoueurBlanc jb();


    delete e;
    return 0;
}
