// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
using namespace std;

using ii = pair<int, int>;

using Nodo = pair<char, ii>;

int df[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };

int dist[51][51];
char matriz[51][51];
int solMejor;
int h, w;

// funcioÌn que resuelve el problema

bool nativos(int x, int y) {
    if (matriz[x - 1][y - 1] == '*')
        return true;
    if (matriz[x - 1][y] == '*')
        return true;
    if (matriz[x - 1][y + 1] == '*')
        return true;
    if (matriz[x][y - 1] == '*')
        return true;
    if (matriz[x][y + 1] == '*')
        return true;
    if (matriz[x + 1][y - 1] == '*')
        return true;
    if (matriz[x + 1][y] == '*')
        return true;
    if (matriz[x + 1][y + 1] == '*')
        return true;
}

void dijkstra(Nodo s, set<ii> tesoros) {
    solMejor = INT_MAX;
    dist[s.second.first][s.second.second] = 0;

    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;

    pq.push({0, {s.second.first,s.second.second}});

    while (!pq.empty()) {
        pair<int,ii> front = pq.top(); pq.pop();
        int d = front.first;
        ii u = front.second;
        if (d > dist[u.first][u.second]) continue;
        for (int k = 0; k < 4; ++k) {
            int ni = u.first + df[k], nj = u.second + dc[k];
            if (ni < h && nj < w && ni >= 0 && nj >= 0 && matriz[ni][nj] != '#' && !nativos(ni,nj)) {
                if (dist[u.first][u.second] + adjList[ni][nj] < dist[ni][nj]) {
                    dist[ni][nj] = dist[u.first][u.second] + adjList[ni][nj];
                    pq.push({ dist[ni][nj],{ni,nj} });
                }
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    cin >> h >> w;

    if (h == 0 && w == 0)
        return false;

    memset(matriz, '_', h * sizeof(matriz[0]));
    memset(matriz[0], '_', w * sizeof(matriz[0][0]));
    memset(dist, 1000000, INT_MAX * sizeof(dist[0]));

    char aux;
    set<pair<int, int>> set;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> aux;
            matriz[i][j] = aux;
            if (aux == '!')
                set.insert({ i,j });
        }
    }

    dijkstra();

    cout << solMejor << endl;

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