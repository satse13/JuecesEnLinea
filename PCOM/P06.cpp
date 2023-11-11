// Nombre del alumno ..... Daniela Vidal Leon y Alejandro Tobias Angeles
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;
int caso = 0;
// funcioÌn que resuelve el problema
void resolver(int s,vector<int>& dist, vector<int>& camino, const vector<vector<pair<int, int>>>& adjList) {

    dist.assign(adjList.size(), INT_MAX);
    dist[s] = 0;
    priority_queue<ii,vii , greater<ii>> pq;
    pq.push({ 0, s });
    while (!pq.empty()) {

        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;

        if (d > dist[u]) continue;

        for (auto a : adjList[u]) {
            if (dist[u] + a.first < dist[a.second]) {
                dist[a.second] = dist[u] + a.first;
                pq.push({ dist[a.second], a.second });
                camino[a.second] = u;
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nodos;
    cin >> nodos;
    if (nodos == 0)
        return false;
    caso++;
    vector<vii> adjList(nodos);
    vector<int> dist(nodos);
    vector<int> camino(nodos);
    camino.assign(nodos, -1);

    int carr, dest, delay;
    for (int i = 0; i < nodos; i++) {
        cin >> carr;
        for (int j = 0; j < carr; j++) {
            cin >> dest >> delay;
            adjList[i].push_back({delay,dest-1});
        }
    }
    int org, fin;
    cin >> org >> fin;

    resolver(org - 1, dist, camino, adjList);
    cout << "Case " << caso << ": Path =";

    vector<int> aux;

    int k = fin-1;
    aux.push_back(fin-1);
    for (int i = camino.size() - 1; i >= 0; i--) {
        if (camino[k] != -1){
           aux.push_back(camino[k]);
           k = camino[k];
        }
    }
   

    for (int i = aux.size() - 1; i >= 0; i--)
        cout << " " << aux[i]+1;

    cout << "; " << dist[fin-1] << " second delay" << endl;
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