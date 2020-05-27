/*
 * Missile.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef MISSILE_H_
#define MISSILE_H_
#include "ElementEspace.h"
#include <SFML/Audio.hpp>

class Missile: public ElementEspace {
public:
	Missile(Coordonnees const& p_position float rotation);
	virtual void reagirCollision(TypeElement typeAutre) override ;
	private:
	sf::Sound son{};
	static constexpr float VITESSE{2000.f};
};

#endif /* MISSILE_H_ */
