// Nombre del alumno ..... Aelejandro Tobias 
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


// funcioÌn que resuelve el problema
int resolver(int numero) {

    int solucion = numero;

    if (solucion == 0)
        return 0;

    else {

        return resolver(solucion / 10) + (solucion % 10);
    }
}

 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta

void resuelveCaso() {
    // leer los datos de la entrada

    int num;
    int suma;
    int valor;
    int solucion;
    int comparacion;

    cin >> num;
    cin >> suma;

    comparacion = resolver(suma);

    for (int i= 0; i < num; i++) {
        cin >> valor;
        solucion = resolver(valor);
        if (solucion == comparacion) {
            cout << valor;
            if (i != num - 1)
                cout << " ";
        }
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