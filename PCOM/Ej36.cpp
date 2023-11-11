// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
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

    void addRange(int a, int b, int val) {
        add(a, val);
        add(b + 1, -val);
    }

    int getSum(int a, int b) {
        return getSum(b) - getSum(a - 1);
    }
    int getValue(int pos) {
        return getSum(pos) - getSum(pos-1);
    }
    void setValue(int pos, int val) {
        add(pos, val - getValue(pos));
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int pares;
    cin >> pares;
    vector<int> vector;
    int a; 
    string b;
    problema++;
    for(int i = 0; i < pares;i++){

        cin >> a >> b;
        char aux;

        for (int j = 0; j < a; j++) {
            stringstream ss(b);
            while (ss >> aux) {
                vector.push_back(int(aux)-48);
            }
        }
    }

    FenwickTree arbol(vector.size());

    for(int i = 1; i <= vector.size();i++){
        arbol.add(i,vector[i - 1]);
    }

    int q; 
    cin >> q;
    int quer = 0;

    cout << "Case " << problema << ":" << endl;

    for (int i = 0; i < q; i++) {
        char a1;
        int a2, a3;
        cin >> a1 >> a2 >> a3;
        a2++;
        a3++;
        if (a1 == 'F') {
            int cont = (a3-a2+1) - arbol.getSum(a2, a3);
            arbol.addRange(a2, a3, cont);
        }
        else if (a1 == 'E') {
            int cont = arbol.getSum(a2, a3);
            arbol.addRange(a2, a3, -cont);
        }

        else if (a1 == 'I') {
             int cont1 = 0;
            int cont0 = 0;
            cont1 = arbol.getSum(a2, a3);
            cont0 = (a3 - a2 + 1) - cont1;
            arbol.addRange(a2, a3, -cont1);
            arbol.addRange(a2, a3, cont0);

        }

        else {
            quer++;
            cout << "Q" << quer << ": " << arbol.getSum(a2, a3) << endl;
        }
    }


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