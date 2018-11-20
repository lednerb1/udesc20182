#include "Grafo.hpp"

Grafo::Grafo(int v){
  this->v = v;
  string aux = to_string((int)ceil(log10(v)));
  this->printArgVer = "%"  + aux + "d,%.3lf,%.3lf";
  this->printArgAdj = ",%" + aux + "d,%.3lf";
  Vertice vert;
  this->maxA = (int) ceil(log2(v));
  cout << "maxA = " << this->maxA << endl;

  set<pair<double,int>> temp;
  for(int i=0; i<this->maxA; i++){
    temp.insert({3+i, -1});
  }
  vert.adj = temp;
  vert.connections = 0;
  srand(time(NULL));
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
  FILE * output = fopen("graph.csv", "w");
  fprintf(output,"nodeIndex,nodeX,nodeY");
  for(int i=1; i<=this->maxA; i++){
    fprintf(output,",adj%d,dist%d", i, i);
  }
  fprintf(output,"\n");
  for(auto v : this->vertices){
    fprintf(output,this->printArgVer.c_str(), v.idx, v.x, v.y);
    set<pair<double,int>>::iterator it = v.adj.begin();
    for(int i=0; i<this->maxA; i++){
      fprintf(output,this->printArgAdj.c_str(), it->second, it->first);
      it++;
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
    if(v.connections == this->maxA) continue;
    set<pair<double, int>> aux;
    for(int i=0; i<this->maxA-v.connections; i++){
      aux.insert({10+i, -1});
    }
    for(auto& vv : this->vertices){
      if(&v != &vv){
        if(vv.connections == this->maxA) continue;
        // cout << v.idx << " " << vv.idx << " : ";
        double distancia = v ^ vv;         // Operador de Vertices que calcula a distancia.
        aux.insert({distancia, vv.idx}); // Inserimos de maneira ordenada pelo set.
        aux.erase(--aux.end());        // Como o maior elemento sempre vai na ultima posicao, removemos ele.
      }
    }
    // cout << endl;
    for(auto& a : aux){
      if(a.second == -1) continue;
      v.adj.insert(a);
      v.connections++;
      this->vertices[a.second].adj.insert({a.first, v.idx});
      this->vertices[a.second].adj.erase(--this->vertices[a.second].adj.end());
      this->vertices[a.second].connections++;
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
