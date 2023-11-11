#pragma once
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <set>
#include <list>
#include <vector>

using namespace std;

class Clase {
private:
	unordered_map<string, pair<int,list<string>::iterator>> mapaAlumnos; // Mapa con clave el nombre y valor su nivel y su posicion en su lista de grupo
	set<string> grad; // Conjunto con los alumnos graduados
	unordered_map<int,list<string>> vGrupos; // Mapa con clave el grupo y valor listas de sus alumnos
	 
 
	// Conservo en el mapa de alumnos los que ya estan graduados con nivel 7 pq es mas eficiente saber que existen
	// mirando en el mapa que en el set de graduados

public:

	void nuevo_estudiante(const string& dni, const int& grupo) {
		if (mapaAlumnos.count(dni))
			throw domain_error("Estudiante existente");
		if (grupo < 1 || grupo > 6)
			throw domain_error("Grupo incorrecto");
		vGrupos[grupo].push_back(dni);
 		mapaAlumnos[dni] = { grupo,--vGrupos[grupo].end() };
	}
	
	void promocionar(const string& dni) {
		if(!mapaAlumnos.count(dni))
			throw domain_error("Estudiante no existente");
		if (mapaAlumnos[dni].first == 7) 
			throw domain_error("Estudiante ya graduado");
		int& grupo = mapaAlumnos[dni].first;
		auto it = mapaAlumnos[dni].second;
		vGrupos[grupo].erase(it);
		mapaAlumnos[dni].first++;
		vGrupos[grupo].push_back(dni);
		mapaAlumnos[dni].second = --vGrupos[grupo].end();
		if (mapaAlumnos[dni].first == 7)
			grad.insert(dni);
	}

	int grupo_estudiante(const string& dni) const {
		if (!mapaAlumnos.count(dni))
			throw domain_error("Estudiante no existente");
		if(mapaAlumnos.at(dni).first == 7) 
			throw domain_error("Estudiante ya graduado");
		return mapaAlumnos.at(dni).first;
	}

	vector<string> graduados() const {
		auto it = grad.begin();
		vector<string> v(grad.size());
		for (int i = 0; i < (int)grad.size(); i++, ++it) {
			v[i] = *it;
		}
		return v;
	}

	string novato(const int& grupo) {
		if (grupo < 1 || grupo > 6)
			throw domain_error("Grupo incorrecto");
		if(vGrupos[grupo].empty())
			throw domain_error("Grupo vacio");
		return vGrupos[grupo].back();
	}

};