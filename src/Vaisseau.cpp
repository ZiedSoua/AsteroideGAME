/*
 * Vaisseau.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Vaisseau.h"
#include <iostream>
#include "Missile.h"

Vaisseau::Vaisseau(Jeu& p_jeu,Espace& p_espace, sf::Color const& couleur): ElementEspace{"ressources/vaisseau.png"},jeu{p_jeu}, espace{p_espace} {
	type = TypeElement::VAISSEAU;
	sprite.setolor(couleur);
}

void Vaisseau::atualiserEtat() {
	accelarationEnCours = sf::Keyboard::isKeyPressed{sf::Keyboard::Up};
	tourneAGauche = sf::Keyboard::isKeyPressed{sf::Keyboard::Left};
	tourneADroite = sf::Keybord::isKeyPresse{sf::Keyboard::Right};
	if(sf::Keybord::isKeyPresse{sf::Keyboard::Space} && dernierTir.getElapsedTime().asSeconds() > 0.1) {
		espace.ajouter(std::make_unique<Misille>(position, sprite.getRotation()));
		dernierTir.restart();
	}
}

void Vaisseau::mettreAjour(float temps){
	actualiserEtat();
	if(!detruit) {
		if(accelerationEnCours) {
			vitesse += Vecteur::creerDepuisAngle(ACCELERATION*temps,sprite.getRotation());
		}
		vitesse -= vitesse * COEFF_FROTTEMENTS * temps ;

		if(tourneAGauche)
			vitesseAngulaire = -VITESSE_ANGULAIRE;
		else if (touneADroite)
			vitesseAngulaire = VITESSE_ANGULAIRE;
		else
			vitesseAngulaire = 0;
	}
}

void Vaisseau::reagirCollision(TypeElement typeAutre)
{
	if(typeAutre==TypeElement::ASTEROIDE)
	{
		detruit = true;
		espace.ajouter(std::make_unique<Explosion>(position));
	}
}
