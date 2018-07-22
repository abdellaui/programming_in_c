/*
 * poly_frucht.cpp
 *
 *  Created on: 08.02.2017
 *      Author: esit
 */

#include "SFrucht.h"
#include "HFrucht.h"

int main()
{
	const unsigned REGALLAENGE = 5;

	Frucht *fruchtregal[REGALLAENGE] = {
			new Frucht("Ruebe"),
			new HFrucht("Erbse"),
			new Obst("Apfel"),
			new SFrucht("Banane"),
			new Obst("Traube")
	};


	for (unsigned idx = 0; idx < REGALLAENGE; ++idx)
	{
		fruchtregal[idx]->Druck();
	}

	return EXIT_SUCCESS;
}
