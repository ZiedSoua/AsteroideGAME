/*
 * Missile.cpp
 *
 *  Created on: v
 *      Author: Zied
 */

#include "Missile.h"
#include "GestionnaireRessources.h"

Missile::Missile(Coordonnees const& p_position float rotation): ElementEspae{"ressources/missile.png"} {
	type= TypeElement::MISSILE;
	position = p_position;
	sprite.setRotation(rotation);
	vitesse = Vecteur::creerDepuisAngle(VITESSE, rotation);
	son.setBuffer(GestionnaireRessources<sf::SoundBuffer>::getRessource("ressources/laser.wav"));
	son.play();
}

void Missile::reagirCollision(TypeElement typeAutre)
{
	if(typeAutre != TypeElement::VAISSEAU)
		detruit = true ;
}

