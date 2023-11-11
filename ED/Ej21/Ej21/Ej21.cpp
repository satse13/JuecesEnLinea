
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "deque.h"

bool resuelveCaso() {
    int numValores, ventana;
    std::cin >> numValores >> ventana;
    if (!std::cin)
        return false;
    std::vector<int> valores(numValores);
    for (int& i : valores) {
        std::cin >> i;
    }
    deque<std::pair<int, int>> colaDoble;
    for (int i = 0; i < ventana; i++) {
        while (!colaDoble.empty() && valores[i] > colaDoble.back().first) {
            colaDoble.pop_back();
        }
        colaDoble.push_back({ valores[i], i });
    }
    std::cout << colaDoble.front().first;
    for (int i = ventana; i < numValores; i++) {
        if (i - colaDoble.front().second == ventana)
            colaDoble.pop_front();
        while (!colaDoble.empty() && valores[i] > colaDoble.back().first) {
            colaDoble.pop_back();
        }
        colaDoble.push_back({ valores[i], i });
        std::cout << ' ' << colaDoble.front().first;
    }
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto


#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif


    return 0;
}