#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
using namespace std;
class Vehiculo
{
	friend class Adicionales;
	friend class Alquiler;
protected:
	int Patente;
	int Chasis;
	string Color;
	int Poliza;
	float Precio_Por_Dia;
	tm Fecha_Ult_Mantenimiento;
	int Cant_Pasajeros_Max;
	float Tarifa_Base;

public:
	/*generamos un único To_String_e_Imprimir para todos los tipos de vehículo porque pusimos los extras
	cantidad de cascos como una característica del alquiler en lugar de una caracteristica de vehículo.
	Los vehículos nos quedaron todos con los mismos atributos, se diferencian en ciertos métodos*/
	void set_ultimo_mantenimiento();
	virtual void set_Tarifa_dia() = 0;
	virtual void  PasoMantenimiento() = 0;
	string To_String_e_Imprimir_Vehiculo();

};

