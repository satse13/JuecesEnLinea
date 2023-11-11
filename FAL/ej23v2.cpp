// Nombre del alumno: Alejandro Tobías Ángeles
// Usuario del Juez: A64


// ESTE EJERCICIO ESTÁ EXPLICADO EN EL VIDEO: https://youtu.be/WxjYE4_agbo Y ESTE https://youtu.be/siaRlAtip9I
// Y ESTE https://youtu.be/_Lf1looyJMU

// PARA INVESTIGAR, BUSCAR EN YOUTUBE MAXIMUN SUBMATRIX 

// ESTUDIAR BIEN ESTE EJERCICIO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using tMatriz = vector<vector<int>>;

// funcioÌn que resuelve el problema
int resolver(tMatriz matriz, int tamanio, int cuadrantes) {

      int maximo = 0;
      tMatriz aux(cuadrantes+1, vector <int>(cuadrantes+1));
 
      for (int i = 1; i < cuadrantes+1; i++) {
          for (int j = 1; j < cuadrantes+1; j++) {
              aux[i][j] = matriz[i - 1][j - 1] + aux[i - 1][j] + aux[i][j - 1] - aux[i - 1][j - 1];
          }
      }

      for (int i = 1; i < cuadrantes+1; i++) {
          for (int j = 1; j < cuadrantes+1; j++) {
              int sum = 0;
              if (i - tamanio >= 0 && j - tamanio >= 0) {
                  sum = aux[i][j] - aux[i - tamanio][j] - aux[i][j - tamanio] + aux[i - tamanio][j - tamanio];
                  if (sum > maximo)
                      maximo = sum;
              }
          }
      }
      return maximo;
      
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int cuadrantes, tamanio;
    cin >> cuadrantes >> tamanio;
    using tMatriz = vector<vector<int>>;
  
    if (!std::cin)
        return false;
    tMatriz matriz(cuadrantes,vector <int>(cuadrantes));
     for (int i = 0; i < cuadrantes; i++) {
        for (int j = 0; j < cuadrantes; j++) {
            cin >> matriz[i][j];
        }
    }
    int sol = resolver(matriz, tamanio, cuadrantes);
    cout << sol << endl;
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