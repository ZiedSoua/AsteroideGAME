/*
 * Espace.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef ESPACE_H_
#define ESPACE_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "ElementEspace.h"

class Espace {
public:
	Espace();
	void ajouter(std::unique_ptr<ElementEspace> element);
	void actualiser();
	void gererCollision();
	void afficher(sf::RenderWindow& fenetre) const;
	void nettoyer();
	void vider();
	inline bool estVide() const {return elements.empty() && aAjouter.empty();};

private :
	std::vector<std::unique_ptr<ElementEspace>> elements{};
	std::vector<std::unique_ptr<ElementEspace>> aAjouter{};
	sf::Clock chrono{};
};

#endif /* ESPACE_H_ */
