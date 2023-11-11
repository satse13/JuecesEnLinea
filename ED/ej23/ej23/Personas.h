#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Persona {
private:
	int edad;
	string nombre;
public:

	Persona() {}

	Persona(int e, string n) :edad(e), nombre(n) {
		 
	}

	Persona& operator =(Persona const& other) {
		if (this != &other) {
			edad = other.edad; nombre = other.nombre; 
		}
		return *this;
	}
	
	int getEdad() const {
		return edad;
	}
	string getNombre() const {
		return nombre;
	}
	 
	 
	bool operator == (const Persona& p2) const {
		return this->edad == p2.edad && this->nombre == p2.nombre;
	}
};

inline istream& operator>> (istream& entrada, Persona& p) {
	int edad;
	string nombre;
	char vacio;
	entrada >> edad >> vacio >> nombre;
	p = Persona(edad, nombre);
	return entrada;
}
inline ostream& operator<< (ostream& salida, const Persona& p) {
	salida << p.getNombre();

	return salida;
}