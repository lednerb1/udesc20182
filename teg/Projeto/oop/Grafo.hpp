#include <bits/stdc++.h>

using namespace std;

typedef struct Vertice {
  int idx;
  int connections;
  double x;
  double y;
  set<pair<double, int>> adj; // Set de adjacencias pra nao precisar dar sort.
                            // A menor distancia sempre vai ser adj[0];
  double operator^(struct Vertice& other){
    return hypot(this->x - other.x, this->y - other.y);
  }
} Vertice;

class Grafo {

private:
  int v;
  int maxA;
  vector<Vertice> vertices;
  string printArgVer;
  string printArgAdj;

public:

  Grafo(int v);
  printVertices();
  printVerticesjs();
  setArestas();
  bfs();
};
