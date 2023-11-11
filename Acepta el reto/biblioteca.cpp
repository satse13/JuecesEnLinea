#include<iostream>
#include<string>
#include<fstream>
using namespace std;


typedef enum {Matematicas,Fisica,Informatica}tArea;



struct tLibro {

	tArea area;
	int numPag;
	string titulo;

};

struct tListaLibros {
	tLibro ListaLibros[100];
	int contador = 0;
};

struct tEstanteria {
	tArea areaEstanteria;
	tListaLibros ListaLibros;
	int capacidad;
	int espacioDis;

};

struct tBiblioteca {
	tEstanteria Estanterias[15];
	int contador = 0;
};


tArea strToArea(string str);
bool cargarEstanterias(tBiblioteca& biblioteca);
bool cargarLibros(tListaLibros& listaLibros);
void borrarLibro(tListaLibros& listaLibros, int indice);
tLibro mayor(tListaLibros& listaLibros);
int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro);
void asignar(tBiblioteca& biblioteca, tListaLibros& listaLibros, tListaLibros& sinColocar);
string areaToStr(tArea area);
void mostrarLibros(const tListaLibros& listaLibros);
void mostrarBiblioteca(const tBiblioteca& biblioteca);

int main() {

	tBiblioteca biblioteca;
	tListaLibros listalibros, sinColocar;

	if (cargarEstanterias(biblioteca)) {
		if (cargarLibros(listalibros)) {

			while (listalibros.contador != 0) {

				asignar(biblioteca, listalibros, sinColocar);
			}


		}
	}

	mostrarBiblioteca(biblioteca);
	cout << "Libros que no pudieron ser colocados..." << endl << endl;
	mostrarLibros(sinColocar);

	return 0;
}

tArea strToArea(string str){

	tArea aux;

	if (str == "Mat")
		aux = Matematicas;
	else if (str == "Fis")
		aux = Fisica;
	else
		aux = Informatica;

	return aux;
}

bool cargarEstanterias(tBiblioteca& biblioteca) {

	bool aux = false;
	string area;
	int numEstanterias;
	ifstream archivo;

	archivo.open("biblioteca.txt");

	if (archivo.is_open()) {
		aux = true;

		archivo >> numEstanterias;

		for (int i = 0; i < numEstanterias; i++) {

			archivo >> area;
			biblioteca.Estanterias[i].areaEstanteria = strToArea(area);
			archivo >> biblioteca.Estanterias[i].capacidad;
			biblioteca.Estanterias[i].espacioDis = biblioteca.Estanterias[i].capacidad;
			biblioteca.contador++;
		}

	}
	archivo.close();
	return aux;

}

bool cargarLibros(tListaLibros& listaLibros) {

	bool aux = false;
	int i = 0;
	string area;
	ifstream archivo;

	archivo.open("libros.txt");

	if (archivo.is_open()) {
		aux = true;

		archivo >> area;
		while (area != "XXX" && i < 100) {

			listaLibros.ListaLibros[i].area = strToArea(area);
			archivo >> listaLibros.ListaLibros[i].numPag;
			getline(archivo, listaLibros.ListaLibros[i].titulo);
			listaLibros.contador++;
			i++;

			archivo >> area;
		}
	}
	archivo.close();


	return aux;
}

void borrarLibro(tListaLibros& listaLibros, int indice) {
		
	for (int i = indice; i < listaLibros.contador; i++) {

		listaLibros.ListaLibros[i] = listaLibros.ListaLibros[i + 1];


	}
	listaLibros.contador--;
		
	
}

tLibro mayor(tListaLibros& listaLibros) {

	int mayor = 0, indice = 0;
	tLibro aux;
	
	for (int i = 0; i < listaLibros.contador; i++) {

		if (listaLibros.ListaLibros[i].numPag > mayor) {
			mayor = listaLibros.ListaLibros[i].numPag;
			aux = listaLibros.ListaLibros[i];
			indice = i;
		}
	}
	borrarLibro(listaLibros, indice);

	return aux;
}

int buscarEstanteria(const tBiblioteca& biblioteca, tLibro libro) {
	int aux = -1,i= 0;
	bool resultado = false;

	while(i < biblioteca.contador && !resultado){

		if (biblioteca.Estanterias[i].areaEstanteria == libro.area && libro.numPag <= biblioteca.Estanterias[i].espacioDis) {

			aux = i;
			resultado = true;
		}
		i++;
	}

	return aux;
}

void asignar(tBiblioteca& biblioteca, tListaLibros& listaLibros, tListaLibros& sinColocar) {

	tLibro libroAcolocar;
	int estanteria;

	libroAcolocar = mayor(listaLibros);
	estanteria = buscarEstanteria(biblioteca, libroAcolocar);


	if (estanteria != -1) {

		biblioteca.Estanterias[estanteria].ListaLibros.ListaLibros[biblioteca.Estanterias[estanteria].ListaLibros.contador] = libroAcolocar;
		biblioteca.Estanterias[estanteria].ListaLibros.contador++;
		biblioteca.Estanterias[estanteria].espacioDis = biblioteca.Estanterias[estanteria].espacioDis - libroAcolocar.numPag;

	}
	else {
		sinColocar.ListaLibros[sinColocar.contador] =libroAcolocar;
		sinColocar.contador++;
	}

}

string areaToStr(tArea area) {

	string aux;

	if (area == Matematicas)
		aux = "Matematicas";
	else if (area == Fisica)
		aux = "Fisica";
	else
		aux = "Informatica";

	return aux;

}

void mostrarLibros(const tListaLibros& listaLibros) {

	for (int i = 0; i < listaLibros.contador; i++) {

		cout << listaLibros.ListaLibros[i].titulo;
		cout << "  (" << listaLibros.ListaLibros[i].numPag << " paginas)" << endl;
	
	}

	cout << endl;

}

void mostrarBiblioteca(const tBiblioteca& biblioteca) {
	
	int indice;
	for (int i = 0; i < 3; i++) {
		indice = 1;
		for (int j = 0; j < biblioteca.contador; j++) {

			if (biblioteca.Estanterias[j].areaEstanteria == i) {
				cout << areaToStr(biblioteca.Estanterias[j].areaEstanteria) << " - " << indice << " (" << biblioteca.Estanterias[j].capacidad << "/" << biblioteca.Estanterias[j].espacioDis << ")" << endl << endl;
				mostrarLibros(biblioteca.Estanterias[j].ListaLibros);
				indice++;

			}

		}
	}

}
