#pragma once
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <list>
#include <set>
using namespace std;
class gestor_futbolistas {
private:
	struct infoFutbolista {
		int numEquipos; // Numero de equipos por los que ha pasado un jugador
		string equipoActual; // Nombre del equipo actual en el que esta
		list<string>::iterator iterador;// Iterador para saber en que posicion de la lista de su equipo esta
		set<string> equipos; // Conjunto con los diferentes equipos en los que ha jugador
	};
	unordered_map<string,infoFutbolista> mapaJugadores;
	unordered_map<string, list<string>> mapaEquipos;

public:

	void fichar(const string& jugador, const string& equipo) {

		if (!mapaJugadores.count(jugador)) {
			mapaJugadores[jugador].numEquipos = 1;
			mapaJugadores[jugador].equipoActual = equipo;
			mapaEquipos[equipo].push_front(jugador);
			mapaJugadores[jugador].iterador = mapaEquipos[equipo].begin();
			mapaJugadores[jugador].equipos.insert(equipo);
		}

		else if (mapaJugadores.count(jugador) && equipo != mapaJugadores[jugador].equipoActual) {
			mapaJugadores[jugador].numEquipos++;
			mapaEquipos[mapaJugadores[jugador].equipoActual].erase(mapaJugadores[jugador].iterador);
			mapaJugadores[jugador].equipoActual = equipo;
			mapaEquipos[equipo].push_front(jugador);
			mapaJugadores[jugador].iterador = mapaEquipos[equipo].begin();
			mapaJugadores[jugador].equipos.insert(equipo);
		}
		
	}

	string equipo_actual(const string& jugador) {
		if (!mapaJugadores.count(jugador))
			throw domain_error("Jugador inexistente");
		return mapaJugadores[jugador].equipoActual;
	}
	
	int fichados(const string& equipo) {
		if (!mapaEquipos.count(equipo))
			throw domain_error("Equipo inexistente");;
		return mapaEquipos[equipo].size();
	}

	vector<string> ultimos_fichajes(const string& equipo, const int& n) {
		if (!mapaEquipos.count(equipo))
			throw domain_error("Equipo inexistente");
		vector<string> sol;
		int contador = 0;
		auto it = mapaEquipos[equipo].begin();
		while (contador < n && contador < mapaEquipos[equipo].size()) {
			sol.push_back(*it);
			++it;
			contador++;
		}
		return sol;
	}

	int cuantos_equipos(const string& jugador) {
		if (!mapaJugadores.count(jugador))
			return 0;
		return mapaJugadores[jugador].equipos.size();
	}
};