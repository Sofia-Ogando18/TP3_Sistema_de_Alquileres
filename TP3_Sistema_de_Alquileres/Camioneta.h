#pragma once
#include "Vehiculo.h"
using namespace std;
class Camioneta :
    protected Vehiculo
{
	friend class Adicionales;
public:
	Camioneta();
	~Camioneta();

};

