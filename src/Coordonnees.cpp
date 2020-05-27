/*
 * Coordonnees.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Coordonnees.h"

int Coordonnees::max_x = 0 ;
int Coordonnees::max_y = 0 ;

Coordonnees::Coordonnees():x{400},y{300}
{
}

Coordonnees::Coordonnees(float const& a, float const& b):x{a},y{b}
{
    if(x>max_x)
        x-=max_x;
    if(y>max_y)
        y-=max_y;
}

float Coordonnees::getX() const
{
    return x ;
}

float Coordonnees::getY() const
{
    return  y ;
}

void Coordonnees::initialiserEspace(int mx , int my)
{
    Coordonnees::max_x = mx ;
    Coordonnees::max_y = my ;
}

void Coordonnees::operator +=(Vecteur const& v)
{
    x+=v.x;
    if(x>max_x)
        x-=max_x;
    y+=v.y;
    if(y>max_y)
        y-=max_y;
}


