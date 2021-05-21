#pragma once
#include "Vehiculo.h"
using namespace std;
class Trafic :
    protected Vehiculo
{
	friend class  Adicionales;
public:
	Trafic();
	~Trafic();

};

