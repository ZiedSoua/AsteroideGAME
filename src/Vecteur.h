/*
 * Vecteur.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef VECTEUR_H_
#define VECTEUR_H_

struct Vecteur {
	void operator+=(Vecteur const& autre);
	void operator-=(Vecteur const& autre);
	Vecteur operator*(float coeff) const;
	static Vecteur creerDepuisAngle(float taille, float angleEnDegre);
	float x{0.f};
	float y{0.f};
};

#endif /* VECTEUR_H_ */
