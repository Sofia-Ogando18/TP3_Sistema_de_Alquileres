#include "Timing.h"
int Calcular_Dias(tm FInicio, tm FFinal) {
	int diff_anio;
	int diff_dia;
	int diff_mes;

	diff_anio = FFinal.tm_year - FInicio.tm_year;
	diff_mes = FFinal.tm_mon - FInicio.tm_mon + (diff_anio * 12);
	diff_dia = FFinal.tm_mday - FInicio.tm_mday + (diff_mes * 30); //asumimos que todos los meses tienen 30 dias

	return diff_dia;
};

string Pasar_Fecha_to_String(tm Fecha) {
	string Fechita;
	Fechita = "\n" + to_string(Fecha.tm_mday) + "/" + to_string(Fecha.tm_mon) + "/" + to_string(Fecha.tm_year);
	return Fechita;
}

tm Calcular_Dias_Reverso(tm FInicio, int duracion) {
	tm Aux = FInicio;
	if (FInicio.tm_mday + duracion < 30) { FInicio.tm_mday = FInicio.tm_mday + duracion; }
	if(FInicio.tm_mday + duracion>30){
		FInicio.tm_mday = FInicio.tm_mday + duracion - 30;
		if (FInicio.tm_mon + 1 < 12) { FInicio.tm_mon = FInicio.tm_mon + 1; }
		if (FInicio.tm_mon + 1 > 12) {
			FInicio.tm_mon = 1;
			FInicio.tm_year = FInicio.tm_year + 1;
		}
	}
	return Aux;
}