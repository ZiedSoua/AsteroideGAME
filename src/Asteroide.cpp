/*
 * Asteroide.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Asteroide.h"
#include <iostream>
#include <random>
#include "Explosion.h"

Asteroide::Asteroide(Esapce& p_espace, Asteroide* parent): ElementEspace{"ressources/asteroide.png"}, espace{p_espace} {

	type= TypeElement::ASTEROIDE;
	auto generateur = std::random_device{};
	auto distributionPosition = std::uniform_real_distribution<float>{-150,150};
	auto distributionVitesse = std::uniform_real_distribution<float>{80,120};
	auto distributionAngle = std::uniform_real_distribution<float>{0,360};
	auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10,30};
	vitesse = Vecteur::CreerDepuisAngle(distributionVitesse(generateur),distributionAngle(generateur));
	vitesseAngulaire = distributionVitesseAngulaire(generateur);
	if(parent)
	{
		sprite.setScale(parent->sprite.setScale().x/1.4,parent->sprite.setScale().y/1.4);
		position= parent->position;
	}
	else
	{
		position = {distributionPosition(generateur), distributionPosition(generateur)};
	}
}


void Asteroide::reagirCollision(TypeElement typeAutre)
{
	if(typeAutre == TypeElement::MISSILE)
	{
		detruit =true ;
		if(sprite.getScale().x > 0.1)
		{
			espace.ajouter(std::make_unique<Asteroide>(espace,this));
			espace.ajouter(std::make_unique<Asteroide>(espace,this));
		}
		espace.ajouter(std::make_unique<Explosxion>(position));
	}
}

Asteroide::~Asteroide() {
	// TODO Auto-generated destructor stub
}

