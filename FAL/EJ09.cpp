// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// funcioÌn que resuelve el problema
vector<int> resolver(const vector<int>& lista1,const vector <int> & lista2) {
   
    vector<int> solucion;

    int i = 0, j = 0;

    while (i < lista1.size() && j < lista2.size()) {

        if (lista1[i] == lista2[j]) {
            solucion.push_back(lista1[i]);
            i++;
            j++;
        }
        else if (lista1[i] > lista2[j])
            j++;
        else
            i++;
    }
    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    
    int elemento;
    cin >> elemento;

    vector<int> lista1;
    vector<int> lista2;

    while (elemento != 0) {

        lista1.push_back(elemento);
        cin >> elemento;
    }
    cin >> elemento;

    while (elemento != 0) {

        lista2.push_back(elemento);
        cin >> elemento;
    }

    sort(lista1.begin(), lista1.end());
    sort(lista2.begin(), lista2.end());

    vector<int> sol = resolver(lista1,lista2);
    
    for (int i = 0; i < sol.size(); i++) {
        
        cout << sol[i];

        if (i != sol.size() - 1)
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