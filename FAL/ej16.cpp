// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema
void resolver(vector<int long long>& lista) {

    int contador = 0;

    for (int i = 0; i < lista.size(); i++) {

        if (lista[i] % 2 == 0) {
            lista[contador] = lista[i];
            contador++;

        }
    }

    lista.resize(contador);
    
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int numElementos;
    int contador;
    cin >> numElementos;

    vector <long long int> lista(numElementos);

    for (int i = 0; i < numElementos; i++) {
        cin >> lista[i];
    }
    
     resolver(lista);

    for (int i = 0; i < lista.size(); i++) {

        cout << lista[i];

        if (i != lista.size() - 1)
            cout << " ";

    }

    cout << endl;




    // escribir sol


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