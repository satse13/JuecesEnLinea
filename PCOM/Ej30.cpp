// Nombre del alumno Daniela Vidal y Alejandro Tobías
// Usuario del Juez PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <climits>
#include <cstring>
#include <map>

int df[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };

using namespace std;
bool visited[1802];
vector<vector<int>> adj;
int parent[1802];
int cap[1802][1802];
int x, y;
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
    int flow = INT_MAX, v = t;
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
int out(int nodo) {
    return nodo + (x * y) + 1;
}
bool resuelveCaso() {
    int p;
    cin >> x >> y >> p;

    if (!std::cin)
        return false;

    memset(cap, 0, sizeof(cap));
    int tam = x * y * 2 + 2;
    adj.assign(tam, {});
    char aux;
    map<pair<int, int>, int> nodos;
    vector<vector<char>> cosas(x, vector<char>(y));
    int cont = 1;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> aux;
            if (!nodos.count({ i, j })) {
                nodos[{i, j}] = cont;
                ++cont;
            }
            cosas[i][j] = aux;
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            char aux = cosas[i][j];
            if (aux == '*') {
                adj[0].push_back(nodos[{i, j}]);
                adj[nodos[{i, j}]].push_back(0);
                cap[0][nodos[{i, j}]] = 1;
                cap[nodos[{i, j}]][0] = 0;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + df[k], nj = j + dc[k];
                    if (ni < x && nj < y && ni >= 0 && nj >= 0) {
                        if (cosas[ni][nj] != '~' && cosas[ni][nj] != '*') {
                            adj[nodos[{i, j}]].push_back(nodos[{ni, nj}]);
                            cap[nodos[{i, j}]][(nodos[{ni, nj}])] = 1;
                            adj[nodos[{ni, nj}]].push_back(nodos[{i, j}]);
                            cap[nodos[{ni, nj}]][nodos[{i, j}]] = 1;
                            
                        }
                    }
                }
            }
            else if (aux == '#') {
                adj[x * y + 1].push_back(nodos[{i, j}]);
                adj[nodos[{i, j}]].push_back(x * y + 1);
                cap[nodos[{i, j}]][x * y + 1] = p;
                cap[x * y + 1][nodos[{i, j}]] = 0;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + df[k], nj = j + dc[k];
                    if (ni < x && nj < y && ni >= 0 && nj >= 0) {
                        if (cosas[ni][nj] != '~' && cosas[ni][nj] != '*') {
                            adj[nodos[{i, j}]].push_back(nodos[{ni, nj}]);
                            cap[nodos[{i, j}]][(nodos[{ni, nj}])] = INT_MAX;
                        }
                    }
                }
            }
            else if (aux == '@') {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + df[k], nj = j + dc[k];
                    if (ni < x && nj < y && ni >= 0 && nj >= 0) {
                        if (cosas[ni][nj] != '~' && cosas[ni][nj] != '*') {
                            adj[nodos[{i, j}]].push_back(nodos[{ni, nj}]);
                            cap[nodos[{i, j}]][(nodos[{ni, nj}])] = 100000;
                        }
                    }
                }
            }
            else if (aux == '.') {
                adj[out(nodos[{i, j}])].push_back(nodos[{i, j}]);
                adj[nodos[{i, j}]].push_back(out(nodos[{i, j}]));
                cap[nodos[{i, j}]][out(nodos[{i, j}])] = 1;

                for (int k = 0; k < 4; ++k) {
                    int ni = i + df[k], nj = j + dc[k];
                    if (ni < x && nj < y && ni >= 0 && nj >= 0) {
                        if (cosas[ni][nj] != '~' && cosas[ni][nj] != '*') {
                            adj[out(nodos[{i, j}])].push_back(nodos[{ni, nj}]);
                            cap[out(nodos[{i, j}])][nodos[{ni, nj}]] = 1;
                        }
                    }
                }
            }
        }
    }

    int sol = edmondsKarp(0, x * y + 1);

    cout << sol << '\n';

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