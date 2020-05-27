//============================================================================
// Name        : AsteroideGame.cpp
// Author      : Zied
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SFML/Graphis.hpp>
#include "Espace.h"
#include "Jeu.h"


using namespace std;

constexpr int LONGUEUR_FENETRE{800};
constexpr int HAUTEUR_FENETRE{600};

int main() {
	sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE,HAUTEUR_FENETRE}, "ASteroids"};
	Coordonnes::initialiserEspace(LONGUEUR_FENETRE,HAUTEUR_FENETRE);
	auto espace = Espace{};
	auto jeu = Jeu{espace};

	while(fenetre.isOpen())
	{
		try{
			auto evenement = sf::Event{};
			while(fenetre.pollEvent(evenement))
			{
				if(evenement.type==sf::Event::Closed)
					fenetre.close();
				if(evenement.type==sf::Event::KeyPressed && !jeu.estEnCours())
					jeu.demarrer();
			}
			espace.actualiser();
			espace.gererCollision();

			fenetre.clear();
			espace.afficher(fenetre);
			jeu.afficher(fenetre);
			fentre.display();
		}
	}
	return 0;
}
