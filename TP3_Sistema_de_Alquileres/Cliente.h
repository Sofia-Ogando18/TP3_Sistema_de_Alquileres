#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
using namespace std;
class Cliente
{
	int DNI;
	string Nombre_Apellido;
	string Direccion;
public:
	Cliente();
	string To_String_e_Imprimir();
	~Cliente();

};

