// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funcioÌn que resuelve el problema

void escribirSolucion(vector<char>& palabra) {

    for (char c : palabra) {
        cout << c;
    }
    cout << endl;
}

void resolver(int m,int n,vector<char>&palabra,int k,vector<bool>&marcas) {

    for (int i = 'a'; i < 'a' + m; i++){
        palabra[k] = i;
        if (!marcas[i - 'a']) {
            marcas[i - 'a'] = true;
            if (k == n - 1) {
                escribirSolucion(palabra);
            }
            else {
                resolver(m, n, palabra, k + 1, marcas);
            }
            marcas[i - 'a'] = false;
        }   
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, m;
    cin >> m >> n;
   

    if (!std::cin)
        return false;

    vector<char>palabra(m);
    vector<bool> marcas(m, false);

    resolver(m,n,palabra,0,marcas);
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