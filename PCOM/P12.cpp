// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>

using namespace std;


int problema = 0;

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

    int getSum(int a, int b) {
        return getSum(b) - getSum(a - 1);
    }
    int getValue(int pos) {
        return getSum(pos) - getSum(pos - 1);
    }
    void setValue(int pos, int val) {
        add(pos, val - getValue(pos));
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    problema++;
    int n;
    cin >> n;

    if (n == 0)
        return false;

    FenwickTree arbol(n);
    int aux;

    for(int i = 1; i <= n;i++){
        cin >> aux;
        arbol.add(i, aux);
    }

    string consulta;
    cin >> consulta;
    int a, b;
    printf("Case %d:\n", problema);
    while (consulta != "END") {
        cin >> a >> b;

        if (consulta == "M") {
            printf("%d\n", arbol.getSum(a, b));
        }

        else if (consulta == "S")
            arbol.setValue(a, b);

        cin >> consulta;
    }

    printf("\n");

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