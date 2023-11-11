// Nombre del alumno - Alejandro Tobías Ángeles
// Usuario del Juez - A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include<vector>

using namespace std;


// funcioÌn que resuelve el problema
vector<long long int> resolver(const vector<long long int> & lista, const int& fecha1)  {

    vector<long long int>solucion(0);

    int maximo = lista[0];
    

    for (int i = 1; i < lista.size() ; i++) {

        if (lista[i] > maximo) {

            maximo = lista[i];
            solucion.push_back(fecha1 + i);

        }
    }
        
        
    
    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int fecha1, fecha2;

    cin >> fecha1 >> fecha2;
    vector<long long int> lista1(fecha2-fecha1 + 1);

    for (int i = 0; i < lista1.size(); i++)
        cin >> lista1[i];
     
    vector<long long int>solucion(0);

    solucion = resolver(lista1,fecha1);
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