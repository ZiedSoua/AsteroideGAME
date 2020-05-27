/*
 * Jeu.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Jeu.h"
#include "Vaisseau.h"
#include "Asteroide.h"
#include "GestionnaireRessources.h"
#include <memory>
#include "font.h"
#include <string>
#include <SFML/Graphis.hpp>

using namespace std::string_literals;

const sf::Color COULEUR_VAISSEAU{sf::Color{128,255,128}};

Jeu::Jeu(Espace& p_espace): espace{p_espace} {
	if(!police.loadFromMemory(Air_Americana_ttf,Air_Americana_ttf_size))
		throw std::runtime_error{"Police introuvable"};
	texteScore.setFont(police);
	try {
		spriteAcceuil.setTexture(GestionnaireRessources<sf::Texture>::getRessources("ressources/acceuil.png"));
	}
	catch(std::exception const& exception) {
		initialiserException(exception);
	}

}

void Jeu::demarrer(){
	enCours= true ;
	espace.ajouter(std::make_unique<Vaisseau>(*this,espace,COULEUR_VAISSEAU));
	espace.ajouter(std::make_unique<Asteroide>(espace);
	espace.ajouter(std::make_unique<Asteroide>(espace);
	espace.ajouter(std::make_unique<Asteroide>(espace);
}

void Jeu::terminer(){
	enCours= false ;
	espace.vider();
}

void Jeu::afficher(sf::RenderWindow& fenetre) const {
	if(texteException)
		fenetre.draw(*texteException);
	else
		{
		if(!enCours && espace.estVide())
				fenetre.draw(spriteAcceuil);
		}


}

void Jeu::initialiserException(std::exception const& exception)
{
	texteException = std::make_unique<sf::Text>();
	texteException->setFont(police);
	texteException->setString(exception.what());
	texteException->setFillColor(sf::Color::Red);
}
