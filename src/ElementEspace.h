/*
 * ElementEspace.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef ELEMENTESPACE_H_
#define ELEMENTESPACE_H_

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

enum class TypeElement {VAISSEAU,ASTEROIDE,MISSILE,AUTRE};

class ElementEspace {
public:
	explicit ElementEspace(std::string_view const& );
	virtual ~ElementEspace()=default;
	ElementEspace(ElementEspace const& autre)=delete;
	void operator=(ElementEspace const& autre)=delete;
	void actualiser();
	virtual void afficher(sf::RenderWindow& fenetre) const ;

	static inline bool estDetruit(std::unique_ptr<ElementEspace>& element) {return element->detruit;};

	float getRayon() const ;
	void testerCollision(ElementEspace& autre);
	virtual void reagirCollision()= 0;

protected :
	virtual void mettreAJour(float temps);
	TypeElement type{TypeElement::AUTRE};
	bool detruit{false};
	sf::Texture texture{};
	sf::Sprite sprite{};
	Coordonnees position{};
	Vecteur vitesse{0.f,0.f};
	float vitesseAngulaire{};

};

#endif /* ELEMENTESPACE_H_ */
