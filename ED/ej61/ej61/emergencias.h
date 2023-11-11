#pragma once
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
using namespace std;
 
template <class paciente> 
class Urgencias {
	using iterador = typename list<paciente>::iterator;
private:
	unordered_map<paciente,pair<int, iterador>> mapaPacientes; // Mapa con clave un paciente y valor su gravedad y un iterador al paciente en la lista correspondiente
	set<paciente> rec; // Conjunto con los pacientes ya recuperados ordenados alfabeticamente
	list<paciente> listaGraves; // Lista con los pacientes graves
	list<paciente> listaMedios; // Lista con los pacientes medios
	list<paciente> listaLeves; // Lista con los pacientes leves

	// Se utiliza una lista para cada gravedad porque en el momento en el que haya que insertar 
	// un nuevo paciente, lo haremos al final de la lista correspondiente, con coste constante
	// pero si tuviesemos una lista con todos juntos seria mas problematico insertar por el medio
public:

	Urgencias(){}

	void nuevo_paciente(const paciente &p,const int& g) { //Todas las operaciones son constantes - O(1)
		if (mapaPacientes.count(p))
			throw domain_error("Paciente repetido");
		if (g < 1 || g > 3)
			throw domain_error("Gravedad incorrecta");
		switch (g) {
		case 1:
			listaLeves.push_back(p);
			mapaPacientes[p] = { g, --listaLeves.end() };
			break;
		case 2:
			listaMedios.push_back(p);
			mapaPacientes[p] = { g,--listaMedios.end() };
			break;
		case 3:
			listaGraves.push_back(p);
			mapaPacientes[p] = { g,--listaGraves.end() };
			break;
		}	
	}

	int gravedad_actual(const paciente& p) const { // Coste constante - O(1)
		if (!mapaPacientes.count(p))
			throw domain_error("Paciente inexistente");
		return mapaPacientes.at(p).first;
	}

	paciente siguiente()  { // O(1)
		paciente sol;
		// Primero se mira en orden de prioridad cada lista, si todas estan vacias se tira excepcion

		if (!listaGraves.empty()) {
			auto it = listaGraves.begin(); // Cojemos el primer paciente de la lista, que es el primero que entro
			sol = *it; // Lo ponemos como solucion
			mapaPacientes.erase(sol); // Lo borramos del mapa 
			listaGraves.pop_front(); //Lo borramos de la lista de su gravedad
		}
		else if (!listaMedios.empty()) {
			auto it = listaMedios.begin();
			sol = *it;
			mapaPacientes.erase(sol);
			listaMedios.pop_front();
 		}
		else if (!listaLeves.empty()) {
			auto it = listaLeves.begin();
			sol = *it;
			mapaPacientes.erase(sol);
			listaLeves.pop_front();
		}
		else
			throw domain_error("No hay pacientes");

		return sol;
	}

	void mejora(const paciente& p) { // O(log n) siendo n la cantidad elementos del set 

		if (!mapaPacientes.count(p))
			throw domain_error("Paciente inexistente");

		auto pac = mapaPacientes.find(p); 

		if (pac->second.first == 3) { // El primer second se refiere al valor del mapa, y el .first al primer elemento del par
			pac->second.first = 2; // Rebajamos su gravedad
			listaGraves.erase(pac->second.second); // Lo borramos de su lista anterior
			listaMedios.push_front(p); // Lo insertamos en su nueva lista por el principio, para que sea el mas prioritario
			pac->second.second = listaMedios.begin(); // Indicamos que su posicion en la nueva lista es la de primero
		}
		else if (pac->second.first == 2) {
			pac->second.first = 1;
			listaMedios.erase(pac->second.second);
			listaLeves.push_front(p);
			pac->second.second = listaLeves.begin();
		}
		else {
			listaLeves.erase(pac->second.second); // Lo borramos de su lista anterior
			mapaPacientes.erase(p); // Lo borramos del mapa
			rec.insert(p); 
			// Insertar en un set O(log n)
		}
	}

	vector<paciente> recuperados() const { // Pasamos el conjunto a un vector porque dice en el enunciado que se tiene que devolver un tipo lineal 
		auto it = rec.begin();
		vector<paciente> v(rec.size()); // O(n) siendo n el numero de elementos del conjunto
		for (int i = 0; i < (int)rec.size(); i++,++it) { 
			v[i] = *it;
		}
		return v;
	}
};
