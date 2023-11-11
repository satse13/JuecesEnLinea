// Nombre del alumno - Alejandro Tobías Ángeles
// Usuario del Juez - A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema
vector<int> resolver(const vector<int>& lista1,const vector <int>&lista2){

    vector<int> solucion(0);

    int i = 0;
    int j = 0;

    while (i < lista1.size() && j < lista2.size()) {

        if (lista1[i] < lista2[j]) {

            solucion.push_back(lista1[i]);
            i++;
        }

        else {
            solucion.push_back(lista2[j]);
            j++;

        }
    }



    while (i < lista1.size()) {

        solucion.push_back(lista1[i]);

        i++;
    }

    while (j < lista2.size()) {

        solucion.push_back(lista2[j]);

        j++;
    }


    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int cantidad1, cantidad2;

    cin >> cantidad1 >> cantidad2;

    vector<int> lista1(cantidad1);
    vector<int> lista2(cantidad2);

    for (int i = 0; i < cantidad1; i++)
        cin >> lista1[i];

    for (int i = 0; i < cantidad2; i++)
        cin >> lista2[i];

    vector<int> solucion(0);

    solucion = resolver(lista1,lista2);
    // escribir sol

    for (int i = 0; i < solucion.size(); i++) {
        
        cout << solucion[i];

        if (i != solucion.size() - 1)
            cout << " ";
    
    
    }

    cout << endl;
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