/*
 * Explosion.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "ElementEspace.h"
#include <SFML/Audio.hpp>

class Explosion : public ElementEspace {
public:
	Explosion(Coordonnees const& p_position);
	virtual void reagirCollision(TypeElement typeAutre) override ;
protected :
	virtual void mettreAjour(float temps ) override ;
private :
	float age{0};
	sf::Sound son{};
	static constexpr float DUREE_VIE{0.1f};
};

#endif /* EXPLOSION_H_ */
