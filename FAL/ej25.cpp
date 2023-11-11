// Nombre del alumno ..... Alejandro tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tEdificio {
    string nombre;
    int alturaE; 
    int alturaPiso;
    
};
// funcioÌn que resuelve el problema
vector<string> resolver(const vector<tEdificio>& v) {
    vector<string> a;

    int maxAltura = v[v.size() - 1].alturaE;
    if (v[v.size() - 1].alturaPiso >= 0) {
        a.push_back(v[v.size() - 1].nombre);
    } 
    for (int i = v.size() - 2; i >= 0; --i) {
        if (v[i].alturaPiso >= 0) {
            if (v[i].alturaPiso > maxAltura) {
                a.push_back(v[i].nombre);
            }
        }
        if (v[i].alturaE > maxAltura) {  // Es importante saber la altura máxima porque a lo mejor el edificio que bloquea la vista 
            maxAltura = v[i].alturaE;   // no es justo el siguiente, este caso no esta entre los casos de prueba
        }
    }
    return a;
    return a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int edificios;
  
    cin >> edificios;

    if (edificios == 0)
        return false;
    vector<tEdificio> lista(edificios);

    for (int i = 0; i < lista.size();i++) {
        cin >> lista[i].nombre;
        cin >> lista[i].alturaE;
        cin >> lista[i].alturaPiso;
        
    }
    vector<string> sol = resolver(lista);
    if (sol.size() > 0) {
        cout << sol.size() << endl;
        for (string i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    else
        cout << "Ninguno" << endl;
   
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