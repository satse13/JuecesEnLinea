// Nombre del alumno ..... Alejandro Tobias
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// funcioÌn que resuelve el problema
int noFinal(int numero,int cifra) {

    if (numero / 10 == 0)
        return numero == cifra;
    else
        return noFinal(numero / 10, cifra) + (numero % 10 == cifra);
}


int final(int numero, int cifra,int contador) {

    if (numero / 10 == 0)
        return contador + (cifra == numero);
    else
        return final(numero / 10, cifra, contador + (numero%10 == cifra));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int numero;
    int cifra;

    cin >> numero >> cifra;

    cout << noFinal(numero, cifra) <<  " " << final(numero, cifra,0) << endl;
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