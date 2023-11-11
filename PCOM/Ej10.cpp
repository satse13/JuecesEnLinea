#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

using vi = vector<string>;
using vvi = vector<vi>;
vvi adjList;
bool si;

unordered_map<string,string> bfs(string s, string dst, vector<bool>& visited, const unordered_map<string, int>& mapa) {
    queue<string> q;
    visited[mapa.at(s)] = true;
    vector<int> dist(mapa.size());
    dist[mapa.at(s)] = 0;
    int mini = INT_MAX;
   
    unordered_map<string,string> sol;
    sol[s] = s;
    q.push(s);
    while (!q.empty()) {
        string v = q.front(); q.pop();
        string ult;
        for (string w : adjList[mapa.at(v)]) {
            if (!visited[mapa.at(w)]) {
                dist[mapa.at(w)] = dist[mapa.at(v)] + 1;
                sol[w] = v;
                if (w == dst) {
                    si = true;
                    return sol;
                }
                visited[mapa.at(w)] = 1;
                q.push(w);
            }
        }
    }
    return sol;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    cin >> n;

    if (!std::cin)
        return false;

    unordered_map<string, int> mapa;
    int cont = 0;
    si = false;
    adjList.assign(n * 2, {});
    string v1, v2;
    for (int i = 0; i < n; ++i) {
        cin >> v1 >> v2;
        if (!mapa.count(v1)) {
            mapa[v1] = cont;
            cont++;
        }
        if (!mapa.count(v2)) {
            mapa[v2] = cont;
            cont++;
        }
        adjList[mapa[v1]].push_back(v2);
        adjList[mapa[v2]].push_back(v1);
    }

    cin >> v1 >> v2; //request

    vector<bool> visitados(n * 2);

    unordered_map<string, string> sol;
    if(mapa.count(v1) && mapa.count(v2))
        sol = bfs(v1, v2, visitados, mapa);

    if (si) {

        vector<string> aux;
        string k = v2;
        aux.push_back(v2);
        for (int i = sol.size() - 1; i >= 0 && sol[k] != v1; i--) {
            aux.push_back(sol[k]);
            k = sol[k];
        }
        aux.push_back(v1);

        int i = aux.size() - 1;
        cout << aux[i];
        i--;
        while (i > 0) {

            cout << " " << aux[i] << endl << aux[i];
            i--;
        }
        cout << " " << aux[0] << endl;
    }
    else
        cout << "No route\n";
    cout << '\n';


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