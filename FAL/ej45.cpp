// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using tMatriz = vector<vector<int>>;

struct solucion {
    int suma = 0;
    bool sol = true;
};

// funcioÌn que resuelve el problema
/*bool resolver(const vector<int>& v, int ini, int fin) {
     if(ini + 2 == fin)
        return v[ini] < v[fin -1]
    else {
        int mitad = (ini + fin - 1) / 2;
        int sumaIzq = 0;
        int sumaDer = 0;
        for (int i = ini i < mitad + 1; i++) {
            sumaIzq += v[i];
        }
        for (int i = mitad + 1; i < fin; i++) {
            sumaDer += v[i];
        }

        if (sumaIzq >= sumaDer) {
            return false;
        }
        bool iz = resolver(v,ini,mitad+1);
        bool der = resolver(v,mitad+1,fin);
        return iz && der;
    }
}  */

pair<bool, int> resolver(const vector<int>& v, int ini, int fin) {
    if (ini + 2 == fin) return { v[ini] < v[fin - 1] , v[ini] + v[fin - 1] };
    else if (ini + 1 == fin) return { true, 0 }; // creo que este caso base se puede quitar sin problemas, porque nunca llegas a este sin pasar por el anterior
    else {
        int mitad = (ini + fin) / 2;
        pair<bool, int> iz = resolver(v, ini, mitad);
        pair<bool, int> dc = resolver(v, mitad, fin);

        return { iz.first && iz.second && iz.second < dc.second, iz.second + dc.second };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int filas;
    int columnas;
    cin >> filas;
    cin >> columnas;

    if (!std::cin)
        return false;

    tMatriz matriz(filas, vector <int>(columnas));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }
    // escribir sol
    int i = 0;
    pair<bool, int> si = { true,0 };
    while (i < filas && si.first) {
        si = resolver(matriz[i], 0, matriz[i].size());
        i++;
    }

    if (si.first)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
    
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