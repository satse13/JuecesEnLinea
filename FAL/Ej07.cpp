// Nombre del alumno ..... Alejandro Tobias Angeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// funcioÌn que resuelve el problema
 void resolver(int anio1,int anio2,const vector<long long int>& lista,int preguntas) {

      int fecha1, fecha2;

    for (int i = 0; i < preguntas; i++) {

        cin >> fecha1 >> fecha2;

        if (fecha1 == anio1)
            cout << lista[fecha2 - anio1] << endl;

        else
            cout << (lista[fecha2 - anio1] - lista[fecha1 - anio1 - 1]) << endl;
     }

    cout << "---" << endl;
    
     
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int anio1 = 0, anio2 = 0;
   
    cin >> anio1 >> anio2;
    
    if (anio1 == 0 && anio2 == 0)
        return false;

    vector<long long int> lista2(anio2 - anio1 + 1);
    cin >> lista2[0];
    int elemento;
    
    for (int i = 1; i < lista2.size(); i++) {

        cin >> elemento;

        lista2[i] = lista2[i - 1] + elemento;
    }
    int preguntas;

    cin >> preguntas;

    resolver(anio1,anio2, lista2, preguntas);
  
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
 