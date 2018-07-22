/*
 * SFrucht.h
 *
 *  Created on: 08.02.2017
 *      Author: esit
 */

#ifndef SRC_SFRUCHT_H_
#define SRC_SFRUCHT_H_

#include "Obst.h"

class SFrucht : public Obst
{
public:
	SFrucht(char *name) : Obst{name} {}
	SFrucht(std::string &name) : Obst{name} {}

public:
	void Druck() {
		std::cout << "(S) " << dieFrucht << "\n";
	}
};



#endif /* SRC_SFRUCHT_H_ */
