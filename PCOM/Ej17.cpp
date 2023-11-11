// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

std::string T, P;
std::vector<int> b; // back table
int n, m; // n = length of T, m = length of P
void kmpPreprocess() { // before calling kmpSearch
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j])
            j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    string s;
    cin >> s;

    if (s == ".")
        return false;

    b.assign(s.size()+1, 0);
    P = s;
    T = s;

    if (s == "")
        cout << 0 << endl;

    n = s.size();
    m = n;

    kmpPreprocess();
    int l = n - b[b.size() - 1];

    if (n % l == 0) {
        cout << n / l << endl;;
    }
    else
        cout << 1 << endl;

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