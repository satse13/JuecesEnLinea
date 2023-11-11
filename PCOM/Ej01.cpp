#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>  
#include <stack>
#include <unordered_map>
using namespace std;


// función que resuelve el problema
void resolver() {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    string nums;
    getline(cin, nums);

    if (!cin)
        return false;


    bool matr = true;
    stack<int> pila;
    unordered_map<int, pair<int, int>> mapa; //nivel, valor, suma
    int level = -1;
    int num;
    stringstream ss(nums);

    while (ss >> num && matr) {
        if (pila.empty() && num > 0)
            matr = false;

        else if (num < 0) {
            pila.push(num);
            if (level != -1) {
                mapa[level].second += abs(num);
                if (abs(mapa[level].second) >= abs(mapa[level].first))
                    matr = false;
            }
            ++level;
            mapa[level] = { num, 0 };
        }
        else {
            if (abs(pila.top()) == num) {
                pila.pop();
                --level;
            }
            else
                matr = false;
        }
    }

    if (matr && pila.empty()) cout << ":-) Matrioshka!";
    else cout << ":-( Try again.";
    cout << '\n';


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