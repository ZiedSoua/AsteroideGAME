/*
 * Jeu.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef JEU_H_
#define JEU_H_

#include "Espace.h"

class Jeu {
	public:
		Jeu(Espace& p_espace);
		void demarrer();
		void terminer();
		inline bool estEnCours() const { return enCours; } ;
		void afficher(sf::RenderWindow& fenetre) const;
		void initialiserException(std::exception const& exception);
	private :
		Espace& espace ;
		bool enCours{false};
		sf::Sprite spriteAccueil{};
		sf::Font police{};
		std::unique_ptr<sf::Text> texteException{nullptr};

};

#endif /* JEU_H_ */
