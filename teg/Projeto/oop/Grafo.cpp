#include "Grafo.hpp"

Grafo::Grafo(int v){
  this->v = v;
  string aux = to_string((int)ceil(log10(v)));
  this->printArgAdj = "(%" + aux + "d,%.3lf)";
  this->printArgVer = "%"  + aux + "d: (%.3lf,%.3lf) -> [";
  Vertice vert;

  set<pair<double,int>> temp;
  temp.insert({3, -1}); temp.insert({4, -1}); temp.insert({2, -1});
  vert.adj = temp;

  for(int i=0; i<v; i++){
    vert.idx = i;
    vert.x = (double)(rand() % 1001) / 1000;
    vert.y = (double)(rand() % 1001) / 1000;
    this->vertices.push_back(vert);
  }
}

Grafo::printVertices(){
  for(auto v : this->vertices){
    printf(this->printArgVer.c_str(), v.idx, v.x, v.y);
    for(auto a : v.adj){
      printf(this->printArgAdj.c_str(), a.second, a.first);
      }
      printf("]\n");
    }
  }

Grafo::printVerticesjs(){
  for(auto v : this->vertices){
    printf(this->printArgVer.c_str(), v.idx, v.x, v.y);
    for(auto a : v.adj){
      printf(this->printArgAdj.c_str(), a.second, a.first);
      if(v.adj.find(a) != (--v.adj.end())){
        printf(", ");
      }
    }
    printf("]\n");
  }
}

Grafo::setArestas(){
  for(auto& v : this->vertices){
    for(auto& vv : this->vertices){
      if(&v != &vv){
        double distancia = v ^ vv;         // Operador de Vertices que calcula a distancia.
        v.adj.insert({distancia, vv.idx}); // Inserimos de maneira ordenada pelo set.
        v.adj.erase(--v.adj.end());        // Como o maior elemento sempre vai na ultima posicao, removemos ele.
      }
    }
  }
}
