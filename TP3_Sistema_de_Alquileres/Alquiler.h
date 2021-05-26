#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include "Motocicleta.h"
#include "Vehiculo.h"
#include "Lista.h"
#include "Camioneta.h"
#include "Automovil.h"
#include "Trafic.h"
#include "Cliente.h"
#include "Adicionales.h"
#include "Timing.h"
using namespace std;
class Alquiler
{
	friend class Lista_Alquileres;
	Vehiculo* Alquilado;
	Cliente* Usuario;
	Adicionales Extras;
	tm Fecha_Adquisicion;
	tm Fecha_Retorno;
	float Tarifa_por_Dia;
	float Tarifa_Total;
public:
	Alquiler(Vehiculo* vehiculo, Cliente* cliente, int duracion);
	//Alquiler();
	~Alquiler();
	void Set_Extras(Adicional ad1, int can1, Adicional ad2, int can2);
	Vehiculo* Get_Vehiculo();
	float Calcular_Tarifa_Dia(Adicional ad1, int can1, Adicional ad2, int can2);
	float Calcular_Tarifa_Total();
	string To_String_e_Imprimir();

};

