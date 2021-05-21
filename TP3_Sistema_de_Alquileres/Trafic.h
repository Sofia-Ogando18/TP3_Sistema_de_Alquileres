#pragma once
#include "Vehiculo.h"
using namespace std;
class Trafic :
    public Vehiculo
{
	friend class  Adicionales;
public:
	Trafic();
	~Trafic();

};

