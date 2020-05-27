/*
 * Vecteur.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Vecteur.h"
#include <cmath>

void Vecteur::operator+=(Vecteur const& autre){
	x +=autre.x;
	y +=autre.y;
}
void Vecteur::operator-=(Vecteur const& autre){
	x -=autre.x;
	y -=autre.y;
}
Vecteur Vecteur::operator*(float coeff) const{
	return {x*coeff, y*coeff};
}
Vecteur Vecteur::creerDepuisAngle(float taille, float angleEnDegre){
	return {taille*cos(angleEnDegre/180.f * M_PI),taille*sin(angleEnDegre/180.f*M_PI)};
}

