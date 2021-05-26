#pragma once
#include "Vehiculo.h"
using namespace std;
class Camioneta :
    public Vehiculo
{
	friend class Adicionales;
public:
	Camioneta();
	void set_Tarifa_dia(int extras);
	void PasoMantenimiento();
	~Camioneta();

};

