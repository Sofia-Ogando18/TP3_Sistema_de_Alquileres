#pragma once
#include "Vehiculo.h"
using namespace std;
class Motocicleta :
    public Vehiculo
{
	friend class Adicionales;
public:
	Motocicleta();
	~Motocicleta();

};

