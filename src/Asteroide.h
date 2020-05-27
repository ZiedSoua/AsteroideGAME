/*
 * Asteroide.h
 *
 *  Created on: 15 mar. 2020
 *      Author: Zied
 */

#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_

#include "ElementEspace.h"
class Asteroide : public ElementEspace {
public:
	explicit Asteroide();
	virtual void reagirCollision(TypeElement typeAutre) override;
};

#endif /* ASTEROIDE_H_ */
