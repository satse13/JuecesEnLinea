// Nombre del alumno ..... Alejandro Tobías Ángeles
// Usuario del Juez ...... A70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
 using namespace std;

 bool vocal(const char& x) {
     if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
         return true;
     if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
         return true;
     return false;
 }

 string resolverFinal(queue<char>& cifrado1) {
     string ret;
     stack<char> aux;
     while (!cifrado1.empty()) {
         if (!vocal(cifrado1.front())) {
             while (!cifrado1.empty() && !vocal(cifrado1.front())) {
                 aux.push(cifrado1.front()); 
                 cifrado1.pop();  
             }
             while (!aux.empty()) {
                 ret.push_back(aux.top());  
                 aux.pop();
             }
         }
         else if (vocal(cifrado1.front())) {
             ret.push_back(cifrado1.front());  
             cifrado1.pop();
         }
     }
     return ret;
 }

 queue<char> resolver(const string& mensaje) {
     queue<char> descifrado;
     queue<char> cola;
     stack<char> pila;
     int tamanio;

     for (int i = 0; i < mensaje.length(); i++) {
         if (i % 2 == 0)
             cola.push(mensaje[i]);  
         else if (i % 2 != 0)
             pila.push(mensaje[i]);  
     }
     tamanio = cola.size();  

     for (int i = 0; i < tamanio; i++) {
         descifrado.push(cola.front()); 
         cola.pop();
     }

     tamanio = pila.size();
     for (int i = 0; i < tamanio; i++) {
         descifrado.push(pila.top()); 
         pila.pop();
     }
     return descifrado;
 }

 // Resuelve un caso de prueba, leyendo de la entrada la
 // configuración, y escribiendo la respuesta
 bool resuelveCaso() {
     // leer los datos de la entrada
     string mensaje;
     getline(cin, mensaje);

     if (!std::cin)
         return false;

     queue<char> X2;
     string X1;
     X2 = resolver(mensaje);
     X1 = resolverFinal(X2);
     cout << X1 << '\n';

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