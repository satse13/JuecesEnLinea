// Nombre del alumno - Alejandro Tobías Ángeles
// Usuario del Juez - A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema
long long int resolver(int& cantidad,const vector<int>& lista) {
    
    long long int suma = lista[0];
    int minimo = lista[0];
    int veces = 1;

    for (int i = 1; i < lista.size(); i++) {

        suma = suma + lista[i];

        if (lista[i] < minimo) {
            minimo = lista[i];
            veces = 1;
        }

        else if (minimo == lista[i])
            veces++;
    }

    suma = suma - (minimo * veces);
    cantidad = lista.size() - veces;

    return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

     int longitud,cantidad;

     cin >> longitud;
     vector<int> lista(longitud);

     for (int i = 0; i < longitud; i++)
         cin >> lista[i];

     long long int suma = resolver(cantidad,lista);


     cout << suma << " " << cantidad << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}