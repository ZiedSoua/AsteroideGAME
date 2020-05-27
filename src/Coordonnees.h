/*
 * Coordonnees.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef COORDONNEES_H_
#define COORDONNEES_H_
#include "Vecteur.h"

class Coordonnees {
public:
public :
	Coordonnees();
	Coordonnees(float const& a, float const& b);
	float getX() const;
	float getY() const ;
	static void initialiserEspace(int  mx , int my);
	void operator += (Vecteur const& v);

	static int max_x , max_y;

	private :
	float x,y;

};

#endif /* COORDONNEES_H_ */
