#pragma once
#include "Horas.h"
using namespace std;
class Pelicula {
private: 
	string nombre;
	Hora inicio,duracion, fin;
public: 
	Pelicula() {}
	Pelicula(Hora ini, Hora dur, string titulo) : inicio(ini), duracion(dur), nombre(titulo) {
		fin = ini + dur;
	}

	Hora getFin() const  {
		return fin;
	}
	string  getNombre() const {
		return nombre;
	}

	bool operator < (const Pelicula& p2) const {
		if (this->fin < p2.fin)
			return true;
		else {
			if (this->fin == p2.fin)
				return this->nombre < p2.nombre;
			else return false;
		}
	}
};