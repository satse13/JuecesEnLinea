// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int n; 
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> v(n);
    for (int& i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end(),greater<int>());

    int ahorro = 0;
    int cont = 0;

    for (int i = 0; i < v.size(); i++) {
        cont++;
        if (cont == 3) {
            cont = 0;
            ahorro += v[i];
        }
    }
    cout << ahorro << endl;

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