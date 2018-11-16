#include "Grafo.hpp"

Grafo::Grafo(int v){
  this->v = v;
  string aux = to_string((int)ceil(log10(v)));
  this->printArgVer = "%"  + aux + "d,%.3lf,%.3lf";
  this->printArgAdj = ",%" + aux + "d,%.3lf";
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
    }
  }

Grafo::printVerticesjs(){
  FILE * output = fopen("../graph.csv", "w");
  fprintf(output,"nodeIndex,nodeX,nodeY,adj1,dist1,adj2,dist2,adj3,dist3\n");
  for(auto v : this->vertices){
    fprintf(output,this->printArgVer.c_str(), v.idx, v.x, v.y);
    for(auto a : v.adj){
      fprintf(output,this->printArgAdj.c_str(), a.second, a.first);
      // if(v.adj.find(a) != (--v.adj.end())){
      //   printf(", ");
      // }
    }
    fprintf(output,"\n");
  }
  fclose(output);
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

Grafo::bfs(){
  srand(time(NULL));
  int i = rand() % this->v;
  queue<int> q;
  q.push(i);
  int see[this->v+10];
  int seen=0;
  int k=0;
  memset(see, 0, sizeof see);
  while(seen < this->v){
    while(!q.empty()){
      int i = q.front(); q.pop();
      see[i] = 1;
      seen++;
      printf("%d : ", i);
      for(auto v : this->vertices[i].adj){
        if(!see[v.second]){
          printf("- %d ", v.second);
          q.push(v.second);
          see[v.second] = 1;
        }
      }cout << endl;
    }
    for(; k<this->v; k++){
        if(!see[k]){
          cout << "\nNew component\n";
          q.push(k);
          break;
        }
    }
  }

}
