#include <bits/stdc++.h>

using namespace std;

#define sz(x) sizeof(x)
#define mx 1001
int marcado[mx] = {0};
vector<int> lista[mx];
int cont = 0;


void busca(int u){
     vector <int>::iterator pont;
     marcado[u] = 1;
     for(pont = lista[u].begin(); pont!=lista[u].end(); pont++){
         // cout << u << " " << *pont << endl;
         // cout << "oi\n";
         if(!(marcado[*pont])){
            //  cout << u << " " << *pont << endl;
             busca(*pont);
         }
    }
}

int main(void){
    int nodes, edges;   cin >> nodes >> edges;
    int graph[nodes][nodes], dir1[edges][nodes], dir2[edges][nodes];
    memset(graph, 0, sz(graph));
    memset(dir1, 0, sz(dir1));
    memset(dir2, 0, sz(dir2));

    for(int i=0; i<edges; i++){
        int aux1, aux2; cin >> aux1 >> aux2;
        dir2[i][aux1-1] = graph[aux1-1][aux2-1] = graph[aux2-1][aux1-1] = dir1[i][aux2-1] = dir1[i][aux1-1] = 1;
        dir2[i][aux2-1] = -1;
        lista[aux1-1].push_back(aux2-1);
        lista[aux2-1].push_back(aux1-1);
    }

    int op; cin >> op;
    for(int i=0; i<edges; i++){
        for(int j=0; j<nodes; j++){
            cout << dir1[i][j] << " ";
        }
        cout << endl;
    }
    cont = 0;
    for(int i=0; i<nodes; i++){
        if(!marcado[i]){
            busca(i);
            cont++;

        }
    }
    cout << cont << endl;
    if(cont == 1) cout << "Conexo\n";
    else cout << "Desconexo com " << cont << " componentes\n";

    return 0;
}
