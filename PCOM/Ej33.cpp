// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;


using arista = pair<int, pair<int, int>>;
vector<bool> visited;
vector<vector<pair<int, int>>> adjList;
vector<int> maximos;
vector<int> dist;
int problema = 0;

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

int bfs(int s, int t) {
    queue<int> q;
    dist[s] = 0; visited[s] = true;
    maximos.assign(3000, 0);
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (pair<int, int> w : adjList[v]) {
            int r = w.first;
            if (!visited[r]) {
                dist[r] = dist[v] + w.second;
                maximos[r] = max(maximos[v], w.second);
                visited[r] = 1;
                q.push(w.first);
                if (r == t) break;
            }
        }
    }
    return maximos[t];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    problema++;
    int ver, ar;
    cin >> ver >> ar;

    int valor;

    vector<arista> aristas;
    adjList.clear();
    adjList.resize(ver); 
    

    int a, b;
    for (int i = 0; i < ar; i++) {
        cin >> a >> b >> valor;
        aristas.push_back({ valor, { a-1,b-1 } });
    }
    
    sort(aristas.begin(), aristas.end());
    UFDS uf(ver);
    int coste = 0;
    int numVer = 0;
    for (auto ar : aristas) {
        if (uf.find(ar.second.first) != uf.find(ar.second.second)) {
            uf.merge(ar.second.first, ar.second.second);
            coste += ar.first;
            adjList[ar.second.first].push_back({ ar.second.second,ar.first });
            adjList[ar.second.second].push_back({ ar.second.first,ar.first });
            numVer++;
            if (uf.numSets == 1) break;
        }
    }

    

    int quer;
    cin >> quer;
    vector<int> sol;
    for (int i = 0; i < quer; i++) {
        visited.clear(); visited.resize(numVer + 1);
        dist.resize(numVer + 1);
        cin >> a >> b;
        int solu = bfs(a-1,b-1);
        sol.push_back(solu);
    }

    cout << "Case " << problema << endl;
    for (int i = 0; i < quer; i++) {
        cout << sol[i] << endl;
    }

    cout << endl;

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