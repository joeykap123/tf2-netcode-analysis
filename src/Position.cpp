#include "Position.h"


struct Position 
{
    double x; double y; double z;

    Position() : x(0), y(0), z(0) 
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Position(double x_,double y_,double z_): x(x_), y(y_), z(z_)
    {
        x_ = x;
        y_ = y;
        z_ = z;
    }


    // Operator Overloads
    Position operator+(const Position& other) const 
    {
        
    }
    Position operator-(const Position& other) const
    {

    }
    Position operator*(double scalar) const
    {

    }
    Position operator/(double scalar) const 
    {

    }
};

