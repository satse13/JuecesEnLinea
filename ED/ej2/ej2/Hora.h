#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Hora {
private:
	int hora, minuto, segundo;
	const int MINUTOS_HORA = 60;
	const int SEGUNDOS_MINUTO = 60;
	const int HORAS_DIA = 24;
	const int MINUTO_DIA = HORAS_DIA * MINUTOS_HORA;
	const int SEGUNDOS_DIA = MINUTO_DIA * SEGUNDOS_MINUTO;

public:
	 
	Hora() {}

	Hora(int h, int m, int s) :hora(h), minuto(m), segundo(s) {
		if (h < 0 || h >= HORAS_DIA || m < 0 || m >= MINUTOS_HORA || s < 0 || s >= SEGUNDOS_MINUTO)
			throw invalid_argument("Hora incorrecta");
	}	

	Hora& operator =(Hora const& other) {
		if (this != &other) {
			hora = other.hora; minuto = other.minuto; segundo = other.segundo;
		}
		return *this;
	}
	Hora operator +(Hora const& other) const {

		Hora sol;

		sol.segundo = segundo + other.segundo;
		sol.minuto = minuto + other.minuto + (sol.segundo/60);
		sol.hora = hora + other.hora + (sol.minuto/60);

		if (sol.hora > 23)
			throw overflow_error("hoy no");
		else {

			sol.hora = sol.hora % 24;
			sol.minuto = sol.minuto % 60;
			sol.segundo = sol.segundo % 60;
			
		}
		return sol;
	}

	int getHora() const {
		return hora;
	}
	int getMinuto() const {
		return minuto;
	}
	int getSegundo() const {
		return segundo;
	}
	bool operator < (const Hora& h2) const {
		return (this->hora < h2.hora || (this->hora == h2.hora && this->minuto < h2.minuto) || (this->hora == h2.hora && this->minuto == h2.minuto && this->segundo < h2.segundo));
	}
	bool operator == (const Hora& h2) const {
		return this->hora == h2.hora && this->minuto == h2.minuto && this->segundo == h2.segundo;
	}
};

inline ostream& operator<< (ostream& salida, const Hora& h) {
	cout.fill('0');
	cout.width(2);
	salida << right << h.getHora();
	salida << ":";
	cout.fill('0');
	cout.width(2);
	salida << right << h.getMinuto();
	salida << ":";
	cout.fill('0');
	cout.width(2);
	salida << right << h.getSegundo();
	return salida;
}
inline istream& operator>> (istream& entrada, Hora& h) {
	int hora, minuto, segundo;
	char vacio;
	entrada >> hora >> vacio >> minuto >> vacio >> segundo;
	h = Hora(hora, minuto, segundo);
	return entrada;
}