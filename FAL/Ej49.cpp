#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tEspacio {
    int ini;
    int fin;
};

tEspacio generaEspacio(const vector<int>& v) {
    int min = v[0]; //minimo del camion maximo del espacio
    int max = v[0]; //suma de todos
    for (int i = 1; i < (int)v.size(); i++) {
        if (v[i] > min)
            min = v[i];
        max += v[i];
    }
    return{ min, max + 1 };
}

bool esValido(const vector<int>& v, int viajes, int fur) {
    int nViajes = 1;
    int suma = 0;
    for (int i = 0; i < (int)v.size(); ++i) {
        suma += v[i];
        if (suma > fur) {
            suma = v[i];
            nViajes++;
        }
    }
    return nViajes <= viajes;
}

// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin, int viajes) {
    if (ini + 1 == fin) return ini;
    else {
        int m = (ini + fin - 1) / 2;
        if (esValido(v, viajes, m))
            return resolver(v, ini, m + 1, viajes);
        else
            return resolver(v, m + 1, fin, viajes);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int obras, viajes;
    cin >> obras >> viajes;
    if (obras == 0 && viajes == 0)
        return false;
    vector <int > pesos(obras);
    for (int& x : pesos) cin >> x;

    tEspacio espacio = generaEspacio(pesos);
    int sol = resolver(pesos, espacio.ini, espacio.fin, viajes);

    // escribir sol
    cout << sol << '\n';

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