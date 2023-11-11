// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct sol {
    bool cruce = false;
    int principio = 0;
    int fin = 0;
};

// funcioÌn que resuelve el problema
sol resolver(const vector<int>& v,const vector<int>& l,int ini,int fin) {
   /* sol ret;
    
    if (ini + 1 == fin) { // un elemento
        ret.cruce = false;
        ret.principio = ini;
        ret.fin = ini + 1;
        return ret;
    } 
    else if (ini >= fin) {
        ret.cruce = false;
        ret.principio = ini;
        ret.fin = ini + 1;
        return ret;
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] == l[mitad]) {
            ret.cruce = true;
            ret.principio = mitad;
            return ret;
        }
        else if (v[mitad] > l[mitad]){
            return resolver(v, l, ini, mitad + 1);
        }
        else  {
            return resolver(v, l, mitad+1 , fin);
        }
    }*/

    if (ini + 1 == fin) {
        if (v[ini] == l[ini])
            return { true,ini,fin };
        else
            return{ false,ini,fin };
    }
    else {
        int mitad = (ini + fin - 1) / 2;
        if (v[mitad] == l[mitad]) {
          
            return { true,mitad,mitad + 1 };
        }
        else if (v[mitad] > l[mitad]) {
            return resolver(v, l, ini, mitad + 1);
        }
        else {
            return resolver(v, l, mitad + 1, fin);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numeros;
    cin >> numeros;

    if (numeros == 0)
        return false;
    vector<int> v(numeros);
    vector<int> l(numeros);
    

    for (int i = 0; i < numeros; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < numeros; i++) {
        cin >> l[i];
    }

    sol solucion = resolver(v, l, 0, v.size());

    if (l[0] < v[0])
        cout << "NO " << -1 << " " << 0 << endl;

    else if (solucion.cruce)
        cout << "SI " << solucion.principio << endl;
    else if (v[0] < l[0] && v[numeros - 1] < l[numeros - 1])
        cout << "NO " << numeros - 1 << " " << numeros << endl;
    else
        cout  << "NO"  <<" " << solucion.principio - 1 << " " << solucion.fin - 1 << endl;

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