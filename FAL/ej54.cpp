// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void escribe(vector<char>& palabra) {
    for (char c : palabra) {
        cout << c;
    }
    cout << endl;
}

// funcioÌn que resuelve el problema
void resolver(int n,int m,vector<char>& palabra,int k) {

    for (int i = 'a'; i < 'a' + m; i++) {
        palabra[k] = i;

        if (k == n - 1) {
            escribe(palabra);
        }
        else {
            resolver(n, m, palabra, k + 1);
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
    
    vector<char>palabra(n);
    resolver(n, m, palabra,0);
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