#pragma once
#include "Vehiculo.h"
using namespace std;
class Motocicleta :
    protected Vehiculo
{
	friend class Adicionales;
public:
	Motocicleta();
	~Motocicleta();

};

