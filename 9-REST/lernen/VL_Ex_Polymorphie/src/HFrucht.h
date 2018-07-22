/*
 * HFrucht.h
 *
 *  Created on: 08.02.2017
 *      Author: esit
 */

#ifndef SRC_HFRUCHT_H_
#define SRC_HFRUCHT_H_

#include "Frucht.h"

class HFrucht : public Frucht
{
public:
	HFrucht(char *name) : Frucht{name} {}
	HFrucht(std::string &name) : Frucht{name} {}

public:
	void Druck() {
		std::cout << "(H) " << dieFrucht << "\n";
	}
};


#endif /* SRC_HFRUCHT_H_ */
