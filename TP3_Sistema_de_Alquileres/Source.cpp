#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include "Lista_Alquileres.h"


int main()
{
	//creamos un vehiculo de cada uno
	Trafic* combi = new Trafic();
	Motocicleta* moto = new Motocicleta();
	Automovil* Auto = new Automovil();
	Camioneta* cam = new Camioneta();
	//creamos un cliente que los alquile y una lista de alquileres
	Cliente* portenio = new Cliente();
	Lista_Alquileres* alquileres_total = new Lista_Alquileres(4);

	

	system("pause");
	return 0;
}
