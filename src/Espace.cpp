/*
 * Espace.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#include "Espace.h"

Espace::Espace() {

}

void Espace::ajouter(std::unique_ptr<ElementEspace> element)
{
	elements.push_back(element);
}

void Espace::actualiser()
{
	auto tempsBoucle = chrono.restart().asSeconds();
	for(auto i{0u};i<elements.size();i++)
	{
		elements[i]->actualiser(tempsBoule);
	}
}

void Espace::gererCollision(){
	for(auto i{0u};i<elements.size();i++)
	{
		for(auto j{0u};j<elements.size();j++)
		{
			if(i!=j)
				elements[i]->testerCollision(*elements[j]);
		}
	}
}

void Espace::afficher(sf::RenderWindow& fenetre) const {
	for(auto& element: elements)
		element->afficher(fenetre);
}

void Espace::nettoyer()
{
	auto finTableau = std::remvoe_if(std::begin(elements),std::end(elements),ElementEspace::estDetruit);
	elements.erase(finTableau,std::end(elements));
}
