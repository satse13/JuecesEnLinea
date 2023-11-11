// Nombre del alumno ..... Alejandro TobÌas ¡ngeles
// Usuario del Juez ...... A64


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// funcioÃÅn que resuelve el problema
int resolver(vector<int>& v,int L) {
    int sol = 0;
    int max = v[0];
    int sumaActual = 0;
    int maxSum = 0;
    int aux = 0;
    int cont = 0;
     for (int i = 0; i < L; ++i) {  // Primer intervalo: Lo de siempre, adem·s se busca el m·ximo y se pone contador a L en 
        sumaActual += v[i];         // el momento en el que lo encuentra
        if (v[i] >= max) {
            max = v[i];
            cont = L;
        }
        else
            cont--;  // Cada vez que no es un maximo contador vale uno menos, asi sabemos cuando estamos en intervalo valido y cuando no
    }
    maxSum = sumaActual; sol = 0;
    for (int i = L; i < v.size(); ++i) {
        sumaActual -= v[i - L];
        sumaActual += v[i];
        if (v[i] == max) {
            cont = L;
        }
        else if (v[i] > max) {
            cont = L;
            max = v[i];
            sol = i - L + 1;
            maxSum = sumaActual;
        }
        else
            cont--;
        if (sumaActual >= maxSum && cont > 0) {
            maxSum = sumaActual;
            sol = i - L + 1;
        }
 
    }

    return sol;
}
// Resto del vector



 

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÃÅn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int numP, leer;
    cin >> numP >> leer;

    if (numP == 0 && leer == 0)
        return false;
    vector<int> v(numP);
    for (int &i : v)
        cin >> i;
    int sol = resolver(v,leer);
    cout << sol << endl;

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
 


    while (resuelveCaso())
        ;

    // Para restablecer entrada. Comentar para acepta el reto
 

    return 0;
}