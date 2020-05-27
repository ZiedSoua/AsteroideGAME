/*
 * Vaisseau.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef VAISSEAU_H_
#define VAISSEAU_H_

#include <SFML/Graphis.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"
#include "ElementEspace.h"
#include "Explosion.h"
#include "Espace.h"
#include "Jeu.h"

class Vaisseau: public ElementEspace {
public:
	explicit Vaisseau(Jeu& p_jeu,Espace& p_espace, sf::Color const& couleur);
	virtual void reagirCollision(TypeElement typeAutre) override ;
protected :
	virtual void mettreAjour(float temps) override ;
private:
	void atualiserEtat();
	bool accelerationEnCours{false};
	bool tourneAGauhe{false};
	bool tourneADroite{false};

	Jeu& jeu;
	Espace& espace;
	sf::Clock dernierTir{};

	static constexpr float ACCELERATION{7000.f};
	static constexpr float COEF_FROTTEMENTS{2.f};
	static constexpr float VITESSE_ANGULAIRE{100.f};

};

#endif /* VAISSEAU_H_ */
