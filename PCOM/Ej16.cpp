// Nombre del alumno ..... Daniela Vidal Leon y Alejandro Tobias Angeles
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int matriz[20][20];
bool visited[20][20][3];
int dist[20][20][3];

struct nodo{
    int x;
    int y;
    int op;
};

pair<int, int> next(int i, int x, int y,int n) {
    switch (i) {
    // K
    case 0:
        return{ x - 1, y - 2 };
    case 1: 
        return{ x - 2, y - 1 };
    case 2:
        return{ x - 2, y + 1 };
    case 3:
        return{ x - 1, y + 2 };
    case 4:
        return{ x + 1, y + 2 };
    case 5:
        return { x + 2, y + 1 };
    case 6:
        return { x + 2, y - 1 };
    case 7:
        return { x + 1, y - 2 };
     // B

    case 8: 
        return { x -2,y - 2 };
    case 9:
        return { x - 2,y + 2 };
    case 10:
        return { x + 2,y + 2 };
    case 11:
        return{ x + 2,y - 2 };
    // T

    case 12:
        if (y >= n)
            return { x,n-(y-n)-1};
        else
            return { x,n + (n-y)-1};
    case 13:

        if (i >= n)
            return { n - (x -n )-1,y };
        else
            return { n + (x - n) - 1,y };
    }
}

bool noSale(int x, int y, int n) {
    return !(x < 0 || x >=  2*n || y < 0 || y >= 2*n);
}


// funcioÌn que resuelve el problema
int bfs(pair<int,int> s, pair<int,int> dst,int n)  {
    queue<nodo> q;
    for (int i = 0; i < 14; i++) {
        dist[s.first][s.second][i] = 0;
        visited[s.first][s.second][i] = true;
    }
    for (int i = 0; i < 14; i++) {
        q.push({ s.first,s.second,i });
    }
    while (!q.empty()) {
       nodo v = q.front(); q.pop();
        for (int i = 0; i < 14; ++i) {
            pair<int,int> nex = next(i,v.x,v.y,n);
            nodo w = { nex.first,nex.second,i };
            
            if (noSale(w.x,w.y, n) && matriz[w.x][w.y] != -1 && v.op != i) {

                if (w.x == dst.first && w.y == dst.second) {
                    return dist[v.x][v.y][i] + 1;
                }
                if (!visited[w.x][w.y][i]) {
                    dist[w.x][w.y][i] = dist[v.x][v.y][i] + 1;
                    visited[w.x][w.y][i] = true;
                    q.push(w);
                }
            }
        }
    }
    return -1;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    memset(matriz, 0, sizeof(matriz));
    memset(dist, INT_MAX, sizeof(dist));
    memset(visited, false, sizeof(visited));
    
    pair<int, int> origen,destino,aux;
    cin >> origen.first >> origen.second;
    cin >> destino.first >> destino.second;

    cin >> aux.first >> aux.second;

    origen.first--; origen.second--;
    destino.first--; destino.second--;

    while (aux.first != 0 && aux.second != 0){
        matriz[aux.first - 1][aux.second - 1] = -1;
        cin >> aux.first >> aux.second;
    }

    if (origen != destino) {
        int sol = bfs(origen, destino, n);

        if (sol == -1)
            cout << "Solution doesn't exist";
        else
            cout << "Result : " << sol;
    }
    else
        cout << "Result : " << 0;
    // escribir sol
    cout << endl;
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