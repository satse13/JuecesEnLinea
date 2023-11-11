// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// funcioÌn que resuelve el problema
vector<int> resolver(const vector <int>& alturas,int altura) {

    vector<int> sol(2); // La posicion 0 es el inicio y la 1 el final, hago un vector para poder devolver 2 int
    int segmento = 0, max = 0;
   
    for (int i = 0; i < alturas.size(); i++) {

        if (alturas[i] > altura) {
            segmento++;
            if (segmento > max) {
                max = segmento;
                sol[1] = i;
            }
        }
        else
            segmento = 0;
    }

    sol[0] = sol[1] - max + 1;
   

    // El bucle se recorre una unica vez (coste O(n)) y dentro se realizan 
    // 8 operaciones (contando la comparacion de for y el i++) de O(1) ademas
    // de las declaraciones de un vector,dos variables y el return, tambien de orden O(1)
    // Por tanto el coste de la solucion es lineal: O(n)


    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numEdificios, altura;

    cin >> numEdificios >> altura;

    vector<int> alturas(numEdificios);

    for(int i = 0; i < numEdificios;i++){
        cin >> alturas[i];
    }

    vector<int> solucion(2);

    solucion = resolver(alturas, altura);
    // escribir sol

    cout << solucion[0] << " " << solucion[1] << endl;
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