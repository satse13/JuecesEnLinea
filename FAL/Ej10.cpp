// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// funcioÌn que resuelve el problema
vector<int> resolver(const vector<int> & lista,int& maximo) {

    vector<int> aux(maximo);
    int max;
 
    for (int i = 0; i < lista.size(); i++)
        aux[lista[i] - 1]++;

    max = aux[0];

    for (int i = 1; i < aux.size(); i++) {
        if (aux[i] > max)
            max = aux[i];
    }
    
    vector<int> solucion;

    for (int i = 0; i < aux.size(); i++) {

        if (aux[i] == max)

            solucion.push_back(i + 1);

    }
   
     

    return solucion;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numElementos,maximo;

    cin >> numElementos;

    if (numElementos == -1)
        return false;

    cin >> maximo;

    vector <int> lista(numElementos);

    for (int i = 0; i < lista.size(); i++) {

        cin >> lista[i];

    } 
    vector <int> sol;

    sol = resolver(lista,maximo);


    for (int i = sol.size(); i > 0; i--) {
        cout << sol[i-1];
        if (i != 1)
            cout << " ";
    }

    cout << endl;


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