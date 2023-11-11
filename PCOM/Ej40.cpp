// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <math.h>
#include <climits>
using namespace std;




// funcioÌn que resuelve el problema
bitset<int(INT_MAX)> bs; // #include <bitset>
vector<long long int> primes; // unsigned int

void sieve() {
    bs.set(); // De momento, todos son primos
    bs[0] = bs[1] = 0; // El 0 y el 1 no lo son.
    for (long long int i = 2; i <= 46341; ++i) {
        if (bs[i]) {
            // El actual es primo. Tiramos sus m´ultiplos
            for (long long int j = i * i; j <= 46341; j += i)
                bs[j] = 0; // i*i en el for ¡Cuidado con el rango!
        } // if es primo
    } // for
} // sieve
 // unsigned int
void sieve(int a, int b) {
    primes.clear();
    for (long long int i = a; i <= b; ++i) {
        if (bs[i]) {
            // El actual es primo. Tiramos sus m´ultiplos
            for (long long int j = i * i; j <= b; j += i)
                bs[j] = 0; // i*i en el for ¡Cuidado con el rango!
            primes.push_back(i);
        } // if es primo
    } // for
} // sieve




struct elem {
    int a, b, dist;
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int a, b;
    cin >> a;

    if (!std::cin)
        return false;

    cin >> b;

    sieve(a, b);

    bool llegado = false;
    int i = 0;
    elem cerc, lej;
    cerc.dist = INT_MAX;
    lej.dist = 0;
    while (i < primes.size()-1 && primes[i + 1] <= b) {
        if (primes[i] >= a) {
            llegado = true;
        }
        if (llegado && primes[i+1] <=b) {
            int d = primes[i + 1] - primes[i];
            if (d < cerc.dist) {
                cerc.dist = d;
                cerc.a = primes[i];
                cerc.b = primes[i + 1];
            }
            if (d > lej.dist) {
                lej.dist = d;
                lej.a = primes[i];
                lej.b = primes[i + 1];
            }
        }
        ++i;
    }

    if (cerc.dist == INT_MAX && lej.dist == 0) {
        cout << "There are no adjacent primes.";
    }

    else {
        cout << cerc.a << "," << cerc.b << " are closest, " << lej.a << "," << lej.b << " are most distant.";
    }
    cout << endl;

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

    sieve();

    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}