// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

pair<int, int> rey;
bool niPeter; // Significa que hemos llegado

bool noSale(int i, int j, const vector<vector<char>>& matriz);

// funcioÌn que resuelve el problema
int resolver(const pair<int,int>& rey,const vector<vector<char>>& matriz, vector<vector<bool>>& visited, vector<vector<int>>& dist) {
    niPeter = false;
    int mini = INT_MAX;
    queue<pair<int,int>> q;
    dist[rey.first][rey.second] = 0;
    visited[rey.first][rey.second] = true;
    q.push(rey);
    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (noSale(v.first+i,v.second+j,matriz) && !visited[v.first+i][v.second+j] && matriz[v.first+i][v.second+j] != 'Z') {
                    dist[v.first+i][v.second+j] = dist[v.first][v.second] + 1;
                    if (matriz[v.first+i][v.second+j] == 'B') {
                        mini = min(dist[v.first+i][v.second+j],mini);
                        niPeter = true;
                    }
                    visited[v.first+i][v.second+j] = true;
                    q.push({v.first+ i,v.second+j});
                }
            }
        }
    }
    if (!niPeter) return -1;

    return mini;
}

bool noSale(int i, int j, const vector<vector<char>>& matriz) {
    if (i >= matriz.size() || i < 0 || j >= matriz[i].size() || j < 0)
        return false;
    return true;
}

bool ok(int i, int j,const  vector<vector<char>>& matriz) {
    if (matriz[i][j] == 'A' || matriz[i][j] == 'B')
        return false;
    return true;
}

void colocar(int i, int j, vector<vector<char>>& matriz) {
    if(noSale(i - 1, j - 2,matriz) && ok(i - 1, j - 2, matriz))
        matriz[i - 1][j - 2] = 'Z';

    if (noSale(i - 2, j - 1, matriz) && ok(i - 2, j - 1, matriz))
        matriz[i - 2][j - 1] = 'Z';

    if (noSale(i - 2, j + 1, matriz) && ok(i - 2, j + 1, matriz))
        matriz[i - 2][j + 1] = 'Z';

    if (noSale(i - 1, j + 2, matriz) && ok(i - 1, j + 2, matriz))
        matriz[i - 1][j + 2] = 'Z';

    if (noSale(i + 1, j - 2, matriz) && ok(i + 1, j - 2, matriz))
        matriz[i + 1][j - 2] = 'Z';

    if (noSale(i + 2, j - 1, matriz) && ok(i + 2, j - 1, matriz))
        matriz[i + 2][j - 1] = 'Z';

    if (noSale(i + 2, j + 1, matriz) && ok(i + 2, j + 1, matriz))
        matriz[i + 2][j + 1] = 'Z';

    if (noSale(i + 1, j + 2, matriz) && ok(i + 1, j + 2, matriz))
        matriz[i + 1][j + 2] = 'Z';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int m, n;
    cin >> m >> n;
    char aux;
 
    vector<vector<int>> dist;
    vector<vector<char>> matriz;
    vector<vector<bool>> visited;


    matriz.resize(m, std::vector<char>(n, {}));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> aux;
            if(!(aux == '.' && matriz[i][j] == 'Z'))
                matriz[i][j] = aux;
            if (aux == 'A') rey = { i,j };
            if (aux == 'Z') {
                colocar(i, j, matriz);
            }
        }
    }
   
    dist.resize(m, std::vector<int>(n, 0));
    visited.resize(m, std::vector<bool>(n, false));

    int sol = resolver(rey,matriz,visited,dist);
    if (sol == -1)
        cout << "King Peter, you can't go now!" << endl;
    else
        cout << "Minimal possible length of a trip is " << sol << endl;
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