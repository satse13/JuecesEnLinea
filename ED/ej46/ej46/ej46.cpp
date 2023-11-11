// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
     
    // Ver video https://www.youtube.com/watch?v=671ZZo2E80k

    int numCap;
    int cap;
    cin >> numCap;

    unordered_map<int, int> mapa;

    int maximo = 0; 
    int p = 0; // Inicio del segmento actual
    // i sera el final del segmento actual
    for (int i = 0; i < numCap; i++){
        cin >> cap;
        // Si el capitulo esta ya en el mapa y la ultima vez que aparecio es durante el segmento acutal 
        if (mapa.count(cap) && mapa[cap] >= p) { // rompe el ultimo tramo
            p = mapa[cap] + 1; // El segmento actual ahora comienza uno mas adelante del repetido 
        }
        maximo = max(maximo, i - p + 1);
        mapa[cap] = i;
    }
     
    // escribir sol
     cout << maximo << endl;

 }

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}