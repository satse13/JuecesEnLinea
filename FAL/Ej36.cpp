// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


// funcioÌn que resuelve el problema
string resolver(int num) {
    if (num == 2)
        return "10";
    else if (num == 1)
        return "1";
    else if (num == 0)
        return "0";
    else {
        string sol = resolver(num / 2);

        if (num % 2 == 0) {
            return sol + "0";
        }
        else
            return sol + "1";
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int num;
    cin >> num;
    cout << resolver(num) << endl;
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