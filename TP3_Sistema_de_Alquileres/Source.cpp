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
	//creamos clientes que los alquilen y una lista de alquileres
	Cliente* portenio = new Cliente();
	Cliente* portenio1 = new Cliente("Marcelo Fuentes","calle falsa 123",443489);
	Cliente* portenio2 = new Cliente("Martin Gomez", "la calle sin numero", 3467854);
	Lista_Alquileres* alquileres_total = new Lista_Alquileres(4);
	alquileres_total->crear_alquiler(combi, portenio, 10);
	alquileres_total->crear_alquiler(moto, portenio1, 15);
	alquileres_total->crear_alquiler(Auto, portenio2, 8);
	alquileres_total->crear_alquiler(cam, portenio, 12);
	//Le ponemos extras
	alquileres_total->Set_Extras(0, Silla_Ninios, 5, Asiento_Rebatible, 10);
	alquileres_total->Set_Extras(1, Casco, 2, Asiento_Rebatible, 1); //sabemos que el asiento rebatible no va, es para que la máquina lo saque
	alquileres_total->Set_Extras(2, Nada, 0, Nada, 0);
	alquileres_total->Set_Extras(3, Porta_Equipaje, 1, Nada, 0);
	//Imprimimos todo
	alquileres_total->Listar_por_Vehiculo_y_Dar_Precio();


	system("pause");
	return 0;
}
