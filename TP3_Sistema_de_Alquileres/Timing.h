#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

int Calcular_Dias(tm FInicio, tm FFinal) {
	int diff_anio;
	int diff_dia;
	int diff_mes;

	diff_anio = FFinal.tm_year - FInicio.tm_year;
	diff_mes = FFinal.tm_mon - FInicio.tm_mon + (diff_anio * 12);
	diff_dia = FFinal.tm_mday - FInicio.tm_mday + (diff_mes * 30); //asumimos que todos los meses tienen 30 dias

	return diff_dia;
};


