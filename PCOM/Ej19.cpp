// Nombre del alumno ..... Daniela Vidal León y Alejandro Tobías Ángeles
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include<cstring>
#include <vector>
using namespace std;

const int NO_VISTO = 0;
const int TOCADO = 1;
const int HUNDIDO = 2   ;

int estado[1001];

bool ciclo, sale;

// funcioÌn que resuelve el problema

pair<bool, bool> dfs(int u,const vector<vector<int>>& adj,const vector<char>& ins) {
    if (sale && ciclo) return { sale,ciclo };
    if (u == adj.size()) sale = true;
    else {
       
        if ((u == (adj.size() - 1) && (ins[u] == 'A' || ins[u] == 'C')))
            sale = true;

        estado[u] = TOCADO;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (estado[v] == TOCADO)
                ciclo = true;
            else if ((estado[v] == NO_VISTO) && dfs(v, adj, ins).second)
                ciclo = true;
        }
        estado[u] = HUNDIDO;
       
    }

   

    return { sale,ciclo};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int numIn;
    cin >> numIn;

    ciclo = false;
    sale = false;

    vector<vector<int>> adjList(numIn);
    memset(estado, 0, numIn*sizeof(estado[0]));

    vector<char> ins(numIn);
    
    char a;
    int b;
    for (int i = 0; i < numIn; i++) {
        cin >> a;
        if (a == 'C') {
            cin >> b;
            ins[i] = {a};
            adjList[i].push_back(i + 1);
            adjList[i].push_back(b-1);
        }
        else if (a == 'J') {
            cin >> b;
            ins[i] = {a};
            adjList[i].push_back(b-1);
        }
        else {
            ins[i] = {a};
            adjList[i].push_back(i + 1);
        }
    }

    dfs(0, adjList, ins);
    if (sale && ciclo)
        cout << "SOMETIMES" << endl;
    else if (sale && !ciclo)
        cout << "ALWAYS" << endl;
    else
        cout << "NEVER" << endl;



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