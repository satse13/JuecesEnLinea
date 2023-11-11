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
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    cin >> numElem;
    if (!std::cin)
        return false;

    unordered_map<int,int> mapa; // Mapa con el numero y su cantidad de apariciones
    vector<int> v; // Vector para guardar el orden inicial 

    for (int i = 0; i < numElem; i++) {
        int elem;
        cin >> elem;
        if (mapa.count(elem)) // Si el numero ya estaba guardado aumentas sus apariciones
             mapa[elem]++;

        else { // Si no lo estaba, pones que lleva una aparicion y lo metes en el vector que guarda el orden
             mapa[elem] = 1;
            v.push_back(elem); // Solo se mete en el else porque solo te interesa saber el orden sin que se repitan
        } 
    }
    for (int i : v) { // Se recorre el vector que tiene el orden y se muestra el valor correspondiente a cada clave en el mapa
       cout << i << " " << mapa[i] << endl;
    }
    cout << "---" << endl;
    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}