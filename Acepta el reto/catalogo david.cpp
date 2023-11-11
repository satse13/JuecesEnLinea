// Examen Coches 2020 programacion.cpp : Este archivo contiene la funciÃ³n "main". La ejecuciÃ³n del programa comienza y termina ahÃ­.
//

#include <iostream>
#include<fstream>

using namespace std;

const int MAX_OFERTAS = 10;
const int NUM_PREFERENCIAS = 3;

struct tCoches {
	string modelo;
	int numeroVehiculos, precio, tipoCompra;
};
struct tLista {
	tCoches coches[MAX_OFERTAS];
	int contador = 0;
};

bool cargarCatalogo(tLista& lista);
void mostrarCoche(const tCoches& coche);
void mostrarOfertasEnPresupuesto(const tLista& lista, int presupuesto);
string intATipo(int tipo);
void leerPreferencias(tLista& lista);
int buscarOferta(const tLista& lista, string modelo, int presupuesto);
void guardarCatalogo(const tLista& lista);
bool hacerVenta(tLista& listaOfertas, const tLista& preferencias, int presupuesto);

int main() {
	tLista catalogo, preferencias;
	int presupuesto;
	int seguir = 1;

	if (cargarCatalogo(catalogo)) {

		cout << "Dame tu presupuesto: "; cin >> presupuesto;
		mostrarOfertasEnPresupuesto(catalogo, presupuesto);
		leerPreferencias(preferencias);
		if (hacerVenta(catalogo, preferencias, presupuesto)) {
			guardarCatalogo(catalogo);
		}
	}

	return 0;
}

bool cargarCatalogo(tLista& lista) {
	ifstream archivo;
	int i = 0;
	bool aux = false;

	archivo.open("catalogoOfertas.txt");
	if (archivo.is_open()) {
		aux = true;
		string modelo;

		archivo >> modelo;
		while (modelo != "XXX" && i < MAX_OFERTAS) {

			lista.coches[i].modelo = modelo;
			archivo >> lista.coches[i].numeroVehiculos >> lista.coches[i].precio >> lista.coches[i].tipoCompra;
			lista.contador++;
			i++;
			archivo >> modelo;
		}

	}
	archivo.close();

	return aux;
}
void mostrarOfertasEnPresupuesto(const tLista& lista, int presupuesto) {

	cout << "Ofertas que puedes permitirte: " << endl;
	for (int i = 0; i < lista.contador; i++) {
		if (lista.coches[i].tipoCompra == 1 || (lista.coches[i].precio <= presupuesto && lista.coches[i].tipoCompra == 0)) {
			mostrarCoche(lista.coches[i]);
		}
	}


}
void mostrarCoche(const tCoches& coche) {
	cout << "Modelo: " << coche.modelo << "; " << "disponibles: " << coche.numeroVehiculos << "; " << "precio: " << coche.precio << "; "
		<< "modo: " << intATipo(coche.tipoCompra) << endl;
}
void guardarCatalogo(const tLista& lista) {
	ofstream archivo;

	archivo.open("catalogoOfertas.txt");
	if (archivo.is_open()) {
		for (int i = 0; i < lista.contador; i++) {
			archivo << lista.coches[i].modelo << " "
				<< lista.coches[i].numeroVehiculos << " "
				<< lista.coches[i].precio << " "
				<< lista.coches[i].tipoCompra << endl;
		}
		archivo << "XXX" << endl;
	}
	archivo.close();
}
string intATipo(int tipo) {
	string aux;

	if (tipo == 1)
		aux = "A plazos";
	else
		aux = "Al contado";
	return aux;
}
void leerPreferencias(tLista& lista) {

	cout << "Escribe tus modelos por orden de preferencia (de mayor a menor)" << endl;
	for (int i = 0; i < NUM_PREFERENCIAS; i++) {
		cout << "Modelo " << i + 1 << ": "; cin >> lista.coches[i].modelo;
		lista.contador++;
	}

}
int buscarOferta(const tLista& lista, string modelo, int presupuesto) {
	int i = 0, aux = -1;
	bool seguir = true;

	while (i < lista.contador && seguir) {
		if ((lista.coches[i].modelo == modelo && lista.coches[i].numeroVehiculos != 0 && lista.coches[i].precio <= presupuesto) || (lista.coches[i].modelo == modelo && lista.coches[i].tipoCompra == 1)) {
			seguir = false;
			aux = i;
		}
		i++;
	}

	return aux;
}
bool hacerVenta(tLista& listaOfertas, const tLista& preferencias, int presupuesto) {
	bool aux = false, seguir = true;
	int i = 0, j = 0, auxInt;

	while (seguir && i < preferencias.contador) {

		//preferencias.coches[i].modelo == listaOfertas.coches[j].modelo && listaOfertas.coches[j].precio <= presupuesto && listaOfertas.coches[j].numeroVehiculos > 0
		auxInt = buscarOferta(listaOfertas, preferencias.coches[i].modelo, presupuesto);
		if (auxInt != -1) {
			listaOfertas.coches[auxInt].numeroVehiculos--;
			seguir = false;
			aux = true;
			cout << "Modelo vendido: " << listaOfertas.coches[auxInt].modelo << endl;
		}
		i++;
	}

	return aux;
}