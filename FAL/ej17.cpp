// Nombre del alumno Alejandro Tobias Angeles
// Usuario del Juez ...... A64
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct per {
    string nombre;
    int altura;
};

bool operator <(per per1, per per2) {
    return per1.nombre < per2.nombre;
}

// funcioÌn que resuelve el problema
int resolver(vector<per>& lista,const int & altura) {
    int i = 0;
    int j = lista.size() - 1;

    while (i <= j) {
        if (lista[i].altura <= altura)
            i++;
        else if (lista[j].altura > altura)
            j--;
        else {
            swap(lista[i], lista[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int personas, altura;

    cin >> personas;

    if (!std::cin)
        return false;

    cin >> altura;

    vector<per>lista(personas);

    for (int i = 0; i < personas; i++) {
        cin >> lista[i].nombre;
        cin >> lista[i].altura;
    }
    
    int sol = resolver(lista,altura);

    sort(lista.begin(), lista.begin()+ sol);
    sort(lista.begin() + sol,lista.end());

    cout << "Bajos:";

    for (int i = 0; i < sol; i++) {
        cout << " " << lista[i].nombre;
    }

    cout << endl;

    cout << "Altos:";

    for (int i = sol; i < lista.size(); i++) {
        cout << " " << lista[i].nombre;
    }

    cout << endl;

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