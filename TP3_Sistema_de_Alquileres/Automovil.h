#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include "Vehiculo.h"
using namespace std;
class Automovil :
    public Vehiculo
{
    friend class Adicionales;
public:
	Automovil();
	void set_Tarifa_dia();
	void PasoMantenimiento();
	~Automovil();

};

