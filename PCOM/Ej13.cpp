// Nombre del alumno ..... Daniela Vidal Leon y Alejandro Tobias Angeles
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

using ii = pair<int,pair<int, int>>;
using vii = vector<ii>;
int df[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };

// funcioÌn que resuelve el problema
void resolver(pair<int,int> s, vector<vector<int>> &dist, vector<vector<int>> adjList) {
   
    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist[0].size(); j++)
            dist[i][j] = INT_MAX;
    }
  
    dist[s.first][s.second] = adjList[s.first][s.second];

    priority_queue<ii, vii, greater<ii>> pq;
    
    pq.push({ 0, s });

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first;
        pair<int,int> u = front.second;
        if (d > dist[u.first][u.second]) continue;
        for (int k = 0; k < 4;++k) {
            int ni = u.first + df[k], nj = u.second + dc[k];
            if (ni < adjList.size() && nj < adjList[0].size()) {
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
void resuelveCaso() {
    // leer los datos de la entrada
    int filas, col;
    cin >> filas >> col;

    vector<vector<int>> adjList(filas, vector<int> (col));
    vector<vector<int>> dist(filas, vector<int>(col));
    
    int aux;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < col; j++) {
            cin >> aux;
            adjList[i][j] = (aux);
        }
    }
    resolver({ 0,0 }, dist, adjList);
    cout << dist[filas - 1][col - 1] << endl;

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