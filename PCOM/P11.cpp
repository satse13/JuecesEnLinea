// Nombre del alumno ..... Daniela Vidal  y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj(100);
int cap[100][100];
bool visited[100];
int parent[100];

int problema = 0;

// funcioÌn que resuelve el problema
void bfs(int s, int t) {
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    q.push(s);
    parent[s] = -1; visited[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v] && (cap[u][v] > 0)) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int sendFlow(int s, int t) {
    // Intentamos llegar de s a t
    bfs(s, t);
    if (!visited[t])
        return 0; // No pudimos
        // Buscamos capacidad m´as peque˜na en el camino
    int flow = 100000000, v = t;
    while (v != s) {
        flow = min(cap[parent[v]][v], flow);
        v = parent[v];
    }
    // Mandamos flujo
    v = t;
    while (v != s) {
        cap[parent[v]][v] -= flow;
        cap[v][parent[v]] += flow; // INVERSA
        v = parent[v];
    }
    return flow;
}

int edmondsKarp(int s, int t) {
    int ret = 0;
    int flow = 0;
    do {
        flow = sendFlow(s, t);
        ret += flow;
    } while (flow > 0);
    return ret;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nodos;
    cin >> nodos;
    problema++;
    if (nodos == 0)
        return false;

    int origen, destino, con;
    cin >> origen >> destino >> con;

    memset(cap, 0, sizeof(cap));
    memset(parent, 0, sizeof(parent));
    adj.assign(nodos, {});

    int a, b, capa;

    for (int i = 0; i < con; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);

        cin >> capa;

        cap[a-1][b-1] += capa;
        cap[b-1][a-1] += capa;
    }
    int sol = edmondsKarp(origen-1, destino-1);
    cout << "Network " << problema << endl;
    cout << "The bandwidth is " << sol  << "." << endl;
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