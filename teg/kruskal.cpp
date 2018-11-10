#include <bits/stdc++.h>
#define MAXN 200001

using namespace std;

vector<pair<int, pair<int, int>>> grafo;
vector<int> krus[MAXN];
int parent[MAXN];
int ranke[MAXN];

bool my(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
  return a.second.second < b.second.second;
}

int total=0;
int sub=0;

int find(int x){
  if(x!=parent[x]){
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void merge(int x, int y){
  int px = find(x); int py = find(y);
  if(ranke[px] > ranke[py]){
    parent[py] = px;
  }else{
    parent[px] = py;
  }
  if(ranke[py] == ranke[px]){
    ranke[py]++;
  }
}

void kruskal(int v){
  int edges=0;
  cout << "Kruskal: \n";
  for(auto g : grafo){
    int set1, set2;
    set1 = find(g.first);
    set2 = find(g.second.first);
    if(set1!=set2){
      merge(set1,set2);
      sub += g.second.second;
      edges++;
      cout << g.first << " " << g.second.first << "\n";
      if(edges == v-1){
        break;
      }
    }
  }
  cout << "Peso inicial: " << total << endl;
  cout << "Peso desnecessario: " << sub << endl;
  cout << "Peso otimizado: " << total - sub << endl;
}

void solve(int v, int e){
  int a, b, w;
  for(int i=0; i<v; i++){
    parent[i] = i;
    ranke[i] = 0;
  }
  for(int i=0; i<e; i++){
    cin >> a >> b >> w;
    total += w;
    grafo.push_back({a, {b,w}});
  }

  sort(grafo.begin(), grafo.end(), my);
  kruskal(v);
  grafo.clear();

}

int main(){
  int n, m;
  while(cin >> n >> m and n+m){
    total = sub = 0;
    solve(n, m);
  }

  return 0;
}
