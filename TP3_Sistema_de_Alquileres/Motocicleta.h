#pragma once
#include "Vehiculo.h"
using namespace std;
class Motocicleta :
    public Vehiculo
{
	friend class Adicionales;
public:
	Motocicleta();
	void set_Tarifa_dia();
	void PasoMantenimiento();
	~Motocicleta();

};

