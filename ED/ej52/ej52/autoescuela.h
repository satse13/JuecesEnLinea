#pragma once
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <set>
#include<string>
using namespace std;

template <class alumno, class profesor>
class Autoescuela {

public:
 
	unordered_map<profesor, set<alumno>> mapaProfesores; // Clave el nombre y valor sus alumnos
	unordered_map <alumno, pair<int, profesor>> mapaAlumnos; // Clave el nombre y valor su puntuacion y profesor 

	Autoescuela() {}

	void alta(const alumno& a, const profesor& p) {
		if (mapaAlumnos.count(a)) 
			mapaProfesores[mapaAlumnos[a].second].erase(a);
		else
			mapaAlumnos[a].first = 0;
		mapaAlumnos[a].second = p;
		mapaProfesores[p].insert(a);
	}

	bool es_alumno(const alumno& a, const profesor& p) const  {
 		return (mapaAlumnos.at(a).second == p);
	}

	int puntuacion(const alumno& a) const {
		if (!mapaAlumnos.count(a))
			throw domain_error("El alumno " + a + " no esta matriculado");
		return mapaAlumnos.at(a).first;
	}
	void actualizar(const alumno& a, const int& n) {
		if (!mapaAlumnos.count(a))
			throw domain_error("El alumno " + a + " no esta matriculado");
		mapaAlumnos[a].first += n;
	}
	set<string> examen(const profesor& p, const int& N) const {
		set<string> sol;
		if (mapaProfesores.count(p) && mapaProfesores.at(p).size() > 0) {
			auto it = mapaProfesores.at(p).begin();
			while (it != mapaProfesores.at(p).end()) {
				if (mapaAlumnos.at(*it).first >= N) {
					sol.insert(*it);
				}
				++it;
			}
		}
		return sol;
	}
	void aprobar(const alumno& a) {
		if (!mapaAlumnos.count(a)) {
			throw domain_error("El alumno " + a + " no esta matriculado");
		}
		profesor prof = mapaAlumnos.at(a).second;
		mapaProfesores[prof].erase(a);
		mapaAlumnos.erase(a);
	}
};