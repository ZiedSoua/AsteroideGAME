/*
 * GestionnaireRessources.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef GESTIONNAIRERESSOURCES_H_
#define GESTIONNAIRERESSOURCES_H_
#include <SFML/Graphics.hpp>
#include <string_view>
#include <iostream>
#include <unordered_map>
#include "ExceptionRessourceIntrouvable.h"

template<typename T>
class GestionnaireRessources {
public:
	GestionnaireRessources()=delete;
	static T const& getRessources(std::string_view const& chemin){
		auto resultat = ressources.find(chemin);
		if(resultat==std::end(ressources))
		{
			if(!ressources[chemin].loadFromFile(chemin.data())) {
				throw ExceptionRessourceIntrouvable{chemin};
			}
			return ressources[chemin];
		}
		return resultat->second;
	}

private:
	static std::unodred_map<std::string_view , T> ressources;
};

#endif /* GESTIONNAIRERESSOURCES_H_ */
