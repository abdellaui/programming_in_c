/*
 * Frucht.h
 *
 *  Created on: 08.02.2017
 *      Author: esit
 */

#ifndef SRC_FRUCHT_H_
#define SRC_FRUCHT_H_

#include <iostream>

class Frucht
{
protected:
	std::string dieFrucht;

public:
	Frucht(char *name) : dieFrucht{name} {}
	Frucht(std::string &name) : dieFrucht{name} {}

	virtual void Druck() {
		std::cout << "(F) " << dieFrucht << "\n";
	}

	virtual ~Frucht() {};
};



#endif /* SRC_FRUCHT_H_ */
