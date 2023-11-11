#pragma once
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <set>
using namespace std;

class Carnet {
private :
	
	unordered_map<string, int> personas;
	int v[16] = { 0 };

public:
	Carnet() {};
	
	void nuevo(const string& dni) {
		if(personas.count(dni))
			throw std::domain_error("Conductor duplicado");
		personas[dni] = 15;
		v[15]++;
	}

	void quitar(const string& dni,const int& puntos) {
		if(!personas.count(dni))
			throw std::domain_error("Conductor inexistente");
		int& puntosDni = personas[dni];
		v[puntosDni]--;
		if (puntosDni < puntos) {
			puntosDni = 0;
			v[puntosDni]++;
		}
		else {
			puntosDni -= puntos;
			v[puntosDni]++;
		}
	}

	int consultar(const string& dni)const {
		if (!personas.count(dni)) {
			throw std::domain_error("Conductor inexistente");
		}
		return personas.at(dni);
	}

	int cuantos_con_puntos(const int& puntos)const  {
		if (puntos < 0 || puntos > 15) {
			throw std::domain_error("Puntos no validos");
		}
		return v[puntos];
	}
};