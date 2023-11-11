// Nombre del alumno ..... Daniela Vidal y Alejandro Tobias
// Usuario del Juez ...... PC02


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

const int MAX_V = 100000;

class SegmentTree {
    vector<int> st;
    int tam; // N´umero de hojas que manejamos
    int* baseValues;
public:
    // Tama˜no m´aximo que podremos guardar
    // (n´umero de hojas).
    // Antes de las consultas, se necesita rellenar
    // con los datos iniciales usando build().
    SegmentTree(int maxN) {
        st.assign(4*maxN + 10,0);
    }

    int query(int a, int b) {
        if (a > b) swap(a, b);
        return query(1, 0, tam - 1, a, b);
    }
    int query(int vertex, int L, int R, int i, int j) {
        if (i > R || j < L) {
            return 0;
        }
        if (L >= i && R <= j)
            // Segmento completamente dentro de la consulta
            return st[vertex];
        int mitad = (L + R) / 2;

        int riz, rid;

        if (i <= mitad) 
            riz = query(2 * vertex, L, mitad, i, j);
        
        if(mitad < j)
            rid = query(2 * vertex + 1, mitad + 1, R, i, j);

        if (j <= mitad) return riz;

        if (mitad < i) return rid;

        if (baseValues[riz] < baseValues[rid])
            return riz;
        else
            return rid;
    }

    void build(int* values, int n) {
        tam = n;
        build(values, 1, 0, n - 1);
        baseValues = values;

    }
    void build(int* values, int p, int l, int r) {
        if (l == r) {
            st[p] = l;
            return;
        }
        int m = (l + r) / 2;
        build(values, 2 * p, l, m);
        build(values, 2 * p + 1, m + 1, r);
        if (values[st[2 * p]] < values[st[2 * p + 1]])
            st[p] = st[2 * p];
        else
            st[p] = st[2 * p + 1];
    }
};

vector<vector<pair<int,int>>> adj;
int idx; // Siguiente entrada en euler y prof
int euler[2 * MAX_V + 1];
int prof[2 * MAX_V + 1]; // Prof. del nodo en euler[] (RMQ sobre ´el)
int first[MAX_V]; // Primera aparici´on del nodo i en euler[]

long long int coste[MAX_V];

void eulerTour(int u, int parent, int d) { // d = depth
    first[u] = idx; euler[idx] = u; prof[idx] = d; ++idx;

    for (int i = 0; i < adj[u].size(); ++i) {

        pair<int,int> v = adj[u][i];

        if (v.second == parent) continue;

        coste[v.first] = coste[u] + v.second;
        eulerTour(v.second, u, d + 1);
        euler[idx] = u; prof[idx] = d; ++idx;
    }
}

int lca(int u, int v,SegmentTree& st) {
    return euler[st.query(first[u], first[v])];
}

// funcioÌn que resuelve el problema

using ii = pair<int, int>;
int n;
vector<ii> adj[MAX_V];

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    cin >> n;
    if (n == 0)
        return false;

    for (int i = 0; i < n; i++) adj[i].clear();


    adj.assign(n, {});
    
    SegmentTree st = SegmentTree(n);

    int nodo, dist;
    for (int i = 1; i < n; i++) {
        cin >> nodo >> dist;
        adj[i].push_back({dist, nodo});
        adj[nodo].push_back({dist, i});
    }

    coste[0] = 0;

    int q;
    cin >> q;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        vector<int> dist(n);
        int anc = lca(a, b,st);
        dijkstra(anc, dist);
        int ar = dist[a];
        int br = dist[b];

        cout << ar << br << " ";
    }
     cout << endl;

    

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