#ifndef PIECE_H
#define PIECE_H

class Echiquier;
class Piece
{
    public:
        Piece();
        Piece(int x, int y, bool color);
        virtual ~Piece();
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        bool getColor();
        void setColor(bool color);

        void toMove(int x, int y);
        virtual bool toMoveIsValid(int x, int y);

        virtual char myCode();
        virtual void toString();
    protected:
        bool Color;// Noir = 0, Blanc = 1
        int X;
        int Y;
    private:
};

class Roi : public Piece{
    public:
        Roi(bool color);
        bool toMoveIsValid(int x, int y);
        char myCode();
        void toString();
};

class Fou : virtual public Piece{
    public:
        Fou(bool color, bool position);
        bool toMoveIsValid(int x, int y);
        char myCode();
        void toString();
};

class Tour : virtual public Piece{
    public:
        Tour(bool color, bool position);
        bool toMoveIsValid(int x, int y);
        char myCode();
        void toString();
};

class Reine : public Tour, public Fou{
    public:
        Reine(bool color);
        bool toMoveIsValid(int x, int y);
        char myCode();
        void toString();
};

class Cavalier : virtual public Piece{
    public:
        Cavalier(bool color, bool position);
        bool toMoveIsValid(int x, int y);
        char myCode();
        void toString();
};

class Pion : virtual public Piece{
    public:
        Pion(bool color, int x);
        bool toMoveIsValid(int x, int y);
        char myCode();
        void toString();
};

#endif // PIECE_H
