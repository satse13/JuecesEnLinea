// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> ft;
public:
    FenwickTree(int n) { ft.assign(n + 1, 0); }

    int getSum(int b) {
        int ret = 0;
        while (b) {
            ret += ft[b]; b -= (b & -b);
        }
        return ret;
    }
    void add(int pos, int val) {
        while (pos < ft.size()) {
            ft[pos] += val; pos += (pos & -pos);
        }
    }

    void addRange(int a, int b, int val) {
        add(a, val);
        add(b + 1, -val);
    }

    int getSum(int a, int b) {
        return getSum(b) - getSum(a - 1);
    }
    int getValue(int pos) {
        return getSum(pos);
    }
    void setValue(int pos, int val) {
        add(pos, val - getValue(pos));
    }
};


// funcioÌn que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int t;
    cin >> t;
    if (t == 0)
        return false;

    FenwickTree arbol(100000);


    char opcion;

    for (int i = 0; i < t; i++) {
        cin >> opcion;

        if (opcion == 'B') {
            int a, b, y;
            cin >> a >> b >> y;
            arbol.addRange(a, b, y);
        }
        else if (opcion == 'Q') {
            int a;
            cin >> a;
            cout << arbol.getValue(a) << endl;
        }
    }


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