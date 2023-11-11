// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A70


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// funcioÌn que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    map<string, int> mapa1;
    map<string, int> mapa2;
    string linea;
    
    getline(cin, linea);
    stringstream ss(linea);
    string palabra;
    int entero;
     while (ss >> palabra) {
        ss >> entero;
        mapa1.insert({ palabra,entero });
     }

     getline(cin, linea);
     stringstream as(linea);
     
     while (as >> palabra) {
         as >> entero;
         mapa2.insert({ palabra,entero });
     }
    
     vector<string> add, elim, mod;

     auto it1 = mapa1.begin();
     auto it2 = mapa2.begin();

     while (it1 != mapa1.end() && it2 != mapa2.end()) {
         if (it1->first < it2->first) {
             elim.push_back(it1->first);
             ++it1;
         }
         else if (it1->first > it2->first) {
             add.push_back(it2->first);
             ++it2;
         }
         else {
             if (it1->second != it2->second) {
                 mod.push_back(it1->first);
             }
             ++it1;
             ++it2;
         }
     }

     while (it1 != mapa1.end()) {
         elim.push_back(it1->first);
         ++it1;
     }

     while (it2 != mapa2.end()) {
         add.push_back(it2->first);
         ++it2;
     }
     while (it1 != mapa1.end()) {
         elim.push_back(it1->first);
         ++it1;
     }

     while (it2 != mapa2.end()) {
         add.push_back(it2->first);
         ++it2;
     }

     if (add.empty() && elim.empty() && mod.empty()) {
         cout << "Sin cambios\n";
     }
     else {
         if (!add.empty()) {
             cout << "+";
             for (string e : add) {
                 cout << " " << e;
             }
             cout << "\n";
         }

         if (!elim.empty()) {
             cout << "-";
             for (string e : elim) {
                 cout << " " << e;
             }
             cout << "\n";
         }

         if (!mod.empty()) {
             cout << "*";
             for (string e : mod) {
                 cout << " " << e;
             }
             cout << "\n";
         }
     }

     cout << "---" << endl;
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
    cin.get();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}