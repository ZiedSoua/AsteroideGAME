/*
 * ElementEspace.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "ElementEspace.h"
#include <iostream>
#include "GestionnaireRessources.h"
#include <SFML/Graphics.hpp>

ElementEspace::ElementEspace(std::string_view const& cheminImage) {

	sprite.setTexture(GestionnaireRessoures<sf::Texture>::getRessources(cheminImage));
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.getX(), position.getY());
}


void ElementEspace::actualiser(float temps)
{
	mettreAJour(temps);
	auto deplacement = vitesse*temps;
	position += deplacement;
	sprite.setPosition(position.getX(), position.getY());
	sprite.rotate(vitesseAngulaire*temps);
}

void ElementEspace::mettreAJour([[maybe_unsed]] float temps)
{

}

void ElementEspace::afficher(sf::RenderWindow& fenetre) const {
	auto affichage = std::array<Vecteur 9>
}

