// Nombre del alumno ..... 
// Usuario del Juez ......

 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <vector>
using namespace std;


int sx[] = { 1,-1,0,0,1,-1,-1,1 }, sy[] = { 0,0,1,-1,1,-1,1,-1 };

vector<bool> visited;

const int MAXN = 2;
class Trie {
public:
    int prefixes;
    int words;
    std::vector<Trie*> child;

    Trie() :prefixes(0), words(0), child(MAXN, nullptr) {}

    ~Trie() {
        for (int i = 0; i < MAXN; ++i)
            delete child[i];
    }

    void add(const vector<char>& v,int i) {
        if (v[i] == '\0') ++words;
        else {
            Trie* t;
            if (child[(int)v[i] - 48] == nullptr) {
                t = child[(int)v[i] - 48] = new Trie();
                t->prefixes = 1;
            }
            else {
                t = child[(int)v[i] - 48];
                t->prefixes++;
            }
            t->add(v,i + 1);
        }
    }

    //list<int>* search(string s){
    //    // If all characters of pattern have been processed,
    //    if (s.length() == 0)
    //        return indexes;

    //    // if there is an edge from the current node of suffix trie,
    //    // follow the edge.
    //    if (child[s.at(0)] != NULL)
    //        return (child[s.at(0)])->search(s.substr(1));

    //    // If there is no edge, pattern doesn’t exist in text
    //    else return NULL;
    //}

    //void Trie::search(string pat)
    //{
    //    // Let us call recursive search function for root of Trie.
    //    // We get a list of all indexes (where pat is present in text) in
    //    // variable 'result'
    //    int result = root.search(pat);

    //    // Check if the list of indexes is empty or not
    //    if (result == NULL)
    //        cout << "Pattern not found" << endl;
    //    else
    //    {
    //        list<int>::iterator i;
    //        int patLen = pat.length();
    //        for (i = result->begin(); i != result->end(); ++i)
    //            cout << "Pattern found at position " << i - patLen << endl;
    //    }
    //}



};

bool search(Trie* root, string key, int& sol){
    Trie* pCrawl = root;

    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->child[index])
            return false;

        pCrawl = pCrawl->child[index];
    }

    return true;
}

void f(int i, int j, const vector<vector<char>>& sopa, Trie& t) {

    vector<char> der;
    int derk = 0;
    int jder = j;
    while (jder < sopa[i].size()) {

        der.push_back(sopa[i][jder]);
        jder++;
    }

    der.push_back('\0');
    t.add(der,0);

    der.assign(0,0);

    jder = j;

    while (jder >= 0) {

        der.push_back(sopa[i][jder]);
        jder--;
    }

    der.push_back('\0');
    t.add(der,0);
}


void c(int i, int j, const vector<vector<char>>& sopa, Trie& t) {

    vector<char>arr;
    int ider = i;
    while (ider < sopa.size()) {

        arr.push_back(sopa[ider][j]);
        ider++;
    }

    arr.push_back('\0');
    t.add(arr, 0);

    ider = i;

    while (ider >= 0) {

        arr.push_back(sopa[ider][j]);
        ider--;
    }

    arr.push_back('\0');
    t.add(arr, 0);
}

void diagonales(int i, int j, const vector<vector<char>>& sopa, Trie& t) {

    vector<char>arrD;
    int ider = i;
    int jder = j;
    while (ider >= 0 && jder < sopa[i].size()) {

        arrD.push_back(sopa[ider][jder]);
        ider--;
        jder++;
    }
    arrD.push_back('\0');
    t.add(arrD, 0);

    ider = i;
    jder = j;
    while (ider >= 0 && jder >= 0) {

        arrD.push_back(sopa[ider][jder]);
        ider--;
        jder--;
    }
    arrD.push_back('\0');
    t.add(arrD, 0);

    ider = i;
    jder = j;
    while (ider < sopa.size()  && jder < sopa[i].size()) {

        arrD.push_back(sopa[ider][jder]);
        ider++;
        jder++;
    }
    arrD.push_back('\0');
    t.add(arrD, 0);

    ider = i;
    jder = j;
    while (ider < sopa.size() && jder >= 0) {

        arrD.push_back(sopa[ider][jder]);
        ider++;
        jder--;
    }
    arrD.push_back('\0');
    t.add(arrD, 0);
}


// funcioÌn que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌn, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int filas, columnas;
    cin >> filas;
    if (!std::cin)
        return false;

    Trie t;

    cin >> columnas;
    
    vector<vector<char>> sopa(filas,vector<char>(columnas));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> sopa[i][j];
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            f(i, j, sopa, t);
            c(i, j, sopa, t);
            diagonales(i, j, sopa, t);
        }
    }
        
    int x = 0; 

    int palabras;
    cin >> palabras;

    vector<string> pal;


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