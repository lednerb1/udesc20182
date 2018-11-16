#include "oop/Grafo.hpp"

using namespace std;

int main(){
  int n; cin >> n;
  Grafo * graph = new Grafo(n);
  graph->setArestas();
  graph->printVerticesjs();
  // graph->bfs();
  // graph->directedBfs();
}
