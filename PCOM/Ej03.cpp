// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;

struct med {
    string nombre;
    int freq;
    int prio;
    int freqOrig;
};

class ord {
public:
    bool operator () (med const& a, med const& b) {
        if (a.freq < b.freq) return false;
        else if (a.freq > b.freq) return true;
        else return a.prio > b.prio;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int nmed, k;
    cin >> nmed >> k;

    priority_queue<med, vector<med>,ord> cola;

    med aux;

    for(int i = 0; i < nmed;i++){
        cin >> aux.nombre >> aux.freq;
        aux.prio = i;
        aux.freqOrig = aux.freq;
        cola.push(aux);
    }
    // escribir sol
    for (int i = 0; i < k; i++) {
        aux = cola.top();
        cout << aux.freq << " " << aux.nombre << endl;
        cola.pop();
        aux.freq += aux.freqOrig;
        cola.push(aux);
    }

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
