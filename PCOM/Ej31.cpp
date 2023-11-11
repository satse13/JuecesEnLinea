// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias 
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int problema = 0;

using arista = pair<int, pair<int, int>>;

struct UFDS {
    vector<int> p;
    int numSets;
    UFDS(int n) : p(n, 0), numSets(n) {
        for (int i = 0; i < n; ++i) p[i] = i;
    }
    int find(int x) {
        return (p[x] == x) ? x : p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        int i = find(x), j = find(y);
        if (i == j) return;
        p[i] = j;
        --numSets;
    }
};

class Ord {
public :
    bool operator()(arista a, arista b) {
        return a.first > b.first;
    }
};

// funcioÌn que resuelve el problema
int kruskal(vector<arista>& aristas) {

    sort(aristas.begin(), aristas.end(),Ord());
    UFDS uf(n);
    int coste = 0;
    int ret = INT_MAX;
    for (auto ar : aristas){
        if (uf.find(ar.second.first) != uf.find(ar.second.second)) {
            uf.merge(ar.second.first, ar.second.second);
            ret = min(ret, ar.first);
            coste += ar.first;  
            if (uf.numSets == 1) break;
        }
    }
    return ret;
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    cin >> n >> m;
    vector<arista> aristas(m);
    problema++;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        aristas[i] = { c, { a,b } };
    }

    int sol = kruskal(aristas);

    cout << "Case #" << problema << ": " << sol << endl;
    //TipoSolucion sol = resolver(datos);
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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}