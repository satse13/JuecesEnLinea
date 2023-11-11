// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

void escribir(vector<string> t) {
    for (string c : t) {
        cout << c;
    }
    cout << endl;
}

// funcioÌn que resuelve el problema
void resolver(int altura, int k,vector<string>& c) {

    const string colores[3] = { "azul ","rojo ","verde " };

    for (int i = 0; i < 3; i++) {

        c[k] = colores[i];
        if (k == altura - 1)
            escribir(c);
        else {
            resolver(altura, k + 1, c);
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int altura;

    cin >> altura;

    if (altura == 0)
        return false;

    vector<string> torre(altura);

    resolver(altura,0,torre);

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