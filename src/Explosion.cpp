/*
 * Explosion.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Explosion.h"
#include "GestionnaireRessources.h"

Explosion::Explosion(Coordonnees const& p_position): ElementEspace{"ressources/explosion.png"}
{
	position = p_psoition ;
	son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessources("ressources/explosion.wav"));
	son.play();
}

void Explosion::mettreAJour(float temps)
{
	age+=temps ;
	if(age<DUREE_VIE)
	{
		sprite.setScale(age/DUREE_VIE,age/DUREE_VIE);
	}
	else
	{
		sprite.setScale(0,0);
		if(son.getStatus()==sf::SoundSource::Stopped)
			detruit=true;
	}
}

void Explosion::reagirCollision(TypeElement typeAutre) {}

Explosion::~Explosion() {
	// TODO Auto-generated destructor stub
}

