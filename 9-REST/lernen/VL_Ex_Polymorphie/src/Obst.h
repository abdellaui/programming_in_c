/*
 * Obst.h
 *
 *  Created on: 08.02.2017
 *      Author: esit
 */

#ifndef SRC_OBST_H_
#define SRC_OBST_H_

#include "Frucht.h"

class Obst : public Frucht
{
public:
	Obst(char *name) : Frucht{name} {}
	Obst(std::string &name) : Frucht{name} {}

public:
	void Druck() {
		std::cout << "(O) " << dieFrucht << "\n";
	}
};

#endif /* SRC_OBST_H_ */
