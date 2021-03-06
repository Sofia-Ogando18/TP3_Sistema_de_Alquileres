#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include "Timing.h"
using namespace std;
class Vehiculo
{
	friend class Adicionales;
	friend class Alquiler;
protected:
	unsigned int Patente;
	unsigned int Chasis;
	string Color;
	unsigned int Poliza;
	float Precio_Por_Dia;
	tm Fecha_Ult_Mantenimiento;
	unsigned int Cant_Pasajeros_Max;
	float Tarifa_Base;

public:
	/*generamos un ?nico To_String_e_Imprimir para todos los tipos de veh?culo porque pusimos los extras
	cantidad de cascos como una caracter?stica del alquiler en lugar de una caracteristica de veh?culo.
	Los veh?culos nos quedaron todos con los mismos atributos, se diferencian en ciertos m?todos*/
	void set_ultimo_mantenimiento();
	virtual void set_Tarifa_dia(int extras) = 0;
	virtual void  PasoMantenimiento() = 0;
	string To_String_e_Imprimir_Vehiculo();

};

