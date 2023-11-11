#pragma once
#include <iostream>
#include <stdexcept>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <list>
#include<vector>
using namespace std;

class Empleo{
private:
	unordered_map<string, list<string>> mapaEmpleos; // Mapa que para cada empleo tiene una lista de empleados
	unordered_map<string, unordered_map<string,list<string>::iterator>> mapaPersonas;// Mapa con personas y mapas de empleo, con posicion en la lista de ese empleo
public:
	Empleo() {}

	void altaOficina(const string& nombre, const string& empleo) {

		if (!mapaPersonas[nombre].count(empleo)) {
			mapaEmpleos[empleo].push_back(nombre);
			mapaPersonas[nombre][empleo] = --mapaEmpleos[empleo].end();;
		}
	}

	string ofertaEmpleo(const string& empleo) {
		if (!mapaEmpleos.count(empleo))
			throw domain_error("No existen personas apuntadas a este empleo");

		string sol = *mapaEmpleos[empleo].begin();
 		
		for (auto i : mapaPersonas[sol]) {
			mapaEmpleos[i.first].erase(mapaPersonas[sol][i.first]);
			if (mapaEmpleos[i.first].empty())
				mapaEmpleos.erase(i.first);
		}

		mapaPersonas.erase(sol);
 
		return sol;
	}

	vector<string> listadoEmpleos(const string& persona) {
		if (!mapaPersonas.count(persona))
			throw domain_error("Persona inexistente");
		auto it = mapaPersonas[persona].begin();
		vector<string> v(mapaPersonas[persona].size());
		for (int i = 0; i < (int)mapaPersonas[persona].size(); i++, ++it) {
			v[i] = it->first;
		}
		sort(v.begin(),v.end());
		return v;
	}




};