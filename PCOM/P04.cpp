// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
vii adjList;
vector<bool> visited;
vector<bool> color;

// funcioÌn que resuelve el problema

bool resolver(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : adjList[v]) {
            if (!visited[w]) {
                color[w] = !color[v];
                visited[w] = true;
                q.push(w);
            }
            else {
                if (color[w] == color[v])
                    return false;
            }
        }
    }
  
    return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    int l;
    cin >> l;
    adjList.assign(n, {});
    visited.assign(n, false);
    color.assign(n, false);
    int aux1,aux2;
    for (int i = 0; i < l; i++) {
        cin >> aux1 >> aux2;
        adjList[aux1].push_back(aux2);
        adjList[aux2].push_back(aux1);
    }
    
    bool sol = resolver(0);
    // escribir sol
    if (sol)
        cout << "BICOLORABLE." << endl;
    else
        cout << "NOT BICOLORABLE." << endl;
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