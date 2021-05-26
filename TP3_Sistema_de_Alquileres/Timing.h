#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
using namespace std;
int Calcular_Dias(tm FInicio, tm FFinal);

string Pasar_Fecha_to_String(tm Fecha);

tm Calcular_Dias_Reverso(tm FInicio, int duracion);