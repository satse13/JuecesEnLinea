// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <cstring>
#include <set>
#include <fstream>
#include <vector>
using namespace std;

string a, b;

#define MAX_N 100010
std::string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
void countingSort(int k) {
    int i, sum, maxi = std::max(300, n); // up to 255 ASCII
    memset(c, 0, sizeof c);
    for (i = 0; i < n; ++i)
        ++c[i + k < n ? RA[i + k] : 0];
    for (i = sum = 0; i < maxi; ++i) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; ++i)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; ++i)
        SA[i] = tempSA[i];
}

void constructSA() {
    int i, k, r;
    for (i = 0; i < n; ++i) RA[i] = T[i];
    for (i = 0; i < n; ++i) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; ++i)
            tempRA[SA[i]] =
            (RA[SA[i]] == RA[SA[i - 1]] &&
                RA[SA[i] + k] == RA[SA[i - 1] + k]) ?
            r : ++r;
        for (i = 0; i < n; ++i)
            RA[i] = tempRA[i];
        if (RA[SA[n - 1]] == n - 1) break;
    }
}

int LCP[MAX_N];
void computeLCP() {
    int Phi[MAX_N];
    int PLCP[MAX_N];
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; ++i)
        Phi[SA[i]] = SA[i - 1];
    for (i = L = 0; i < n; ++i) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }
        while (T[i + L] == T[Phi[i] + L]) ++L;
        PLCP[i] = L;
        L = std::max(L - 1, 0);
    }
    for (i = 0; i < n; ++i)
        LCP[i] = PLCP[SA[i]];
}

int palabra(int i) { return (i < n - b.size() - 1) ? 1 : 2; }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    cin >> a >> b;
    if (!std::cin)
        return false;

    a.push_back('$');
    b.push_back('#');

    string aux = a + b; 
    
    n = aux.size();
    T = aux;

    constructSA();
    computeLCP();

    int maxi = -1;

    set<string> s;


    for (int i = 1; i < n; i++) {
        if ((LCP[i] >= maxi) && (SA[i] >= a.size() && SA[i - 1] < a.size() || SA[i] < a.size() && SA[i - 1] >= a.size())) {

            if (LCP[i] > maxi) {
                maxi = LCP[i];
                s.clear();
            }
            if(maxi > 0)
             s.insert(T.substr(SA[i],maxi));
        }
        // SA[i] + maxi-1
    }
    if (s.size() == 0)
        cout << "No common sequence." << endl;
    else {
        for (string sa : s)
            cout << sa << endl;
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


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}