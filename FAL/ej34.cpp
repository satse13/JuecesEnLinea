// Nombre del alumno ..... Alejandro Tobias 
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema

// ME FALTA POR HACER LA NO FINAL
 
int final(int n1,int n2) {

    if (n1 == 0)
        return n2;
    else if (n2 == 0)
        return n1;
    else {
        return final(n1 / 10, n2 / 10)*10  + (n1 + n2) % 10;
    }
}
 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    
    int num1, num2;

    cin >> num1 >> num2;

    int  sol = final(num1,num2);
     
    cout << sol << " " << sol << endl;

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