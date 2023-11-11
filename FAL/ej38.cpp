// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// funcioÌn que resuelve el problema
 int resolver(const vector<char>& v,int ini, int fin,char primera){ // devuelve la posición del elemento siguiente al no consecutivo 
     if (ini >= fin)                                                // si el primero no consecutivo es ultima, y ultima no esta en el vector
         return ini;                                                // entonces devuelve la posicion del ultimo elemento del array v.size - 1
     else if (ini + 1 == fin)
         return ini;
     else {

         int mitad = (ini + fin - 1) / 2;

         if (mitad == v[mitad] - primera)
             return resolver(v, mitad+1, fin,primera);
         else
             return resolver(v,ini,mitad +1,primera);
     }
 }


 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    char primera, ultima,letra;
    cin >> primera >> ultima;
    vector<char>lista(0);
    for (int i = 0; i < (ultima - primera); i++) {
        cin >> letra;
        lista.push_back(letra);
    }
    int sol = resolver(lista, 0, lista.size(),primera);
    
    if (!(sol == lista[sol] - primera))
        cout << --lista[sol] << endl;
    else
        cout << ultima << endl;
   
    // En un principio hice que la funcion de vuelta atras devolviese el caracter anterior al primero que falta, pero luego decidi cambiarlo para
    // que devolviese la posicion del mismo. Esto me permite comprobar si el caracter correspondiente a la solucion que tengo corresponde 
    // a la posicion en la que esta. 
    //  
    // Si al final el caracter coorresponde con la posicion que obtengo quiere decir que la solucion es el elemento siguiente al ultimo del array, es 
    // decir, ultima. Pero si no coincide quiere decir que se ha encontrado la solución dentro del vector, con lo cual la escribimos el anterior sin mas
    // 
    //


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