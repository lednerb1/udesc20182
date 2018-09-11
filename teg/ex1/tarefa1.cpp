#include "funcoes.hpp"

using namespace std;

int main(void){

  int a, b;
  int nodes, edges; cin >> nodes >> edges;
  int ** adj = criarAdj(nodes);
  int ** inc = criarInc(edges, nodes);
  pair<pair<int **, int**>,pair<int,int>> com;

  for(int i=0; i < edges; i++){
    cin >> a >> b; a--, b--;
    adj[a][b] = adj[b][a] = inc[i][a] = inc[i][b] = 1;
    adj[a][nodes]++;
    adj[b][nodes]++;
  }

  cout << "Matriz de adjacencia" << endl << endl;
  for(int i=0; i<nodes; i++){
    for(int j=0; j<nodes; j++){
      cout << " " << adj[i][j];
    }
    cout << " grau -> " << adj[i][nodes] << endl;
  }

  cout << "\nMatriz de Incidencia" << endl << endl;
  for(int i=0; i<edges; i++){
    for(int j=0; j<nodes; j++){
      cout << " " << inc[i][j];
    }
    cout << endl;
  }

  char next;

  do{

      next = nextStep();
      cout << next;

      switch(next){
			
	      case '1':
		  cout << "\ncriando grafo complementar\n";
		  com = complemento(adj, nodes);
		  break;		  
			
          case '2':
          cout << "\nremover no\n";
          eraseNode(&adj, &inc, nodes, &edges);
          break;

          case '3':
          cout << "\nMostrar Matriz\n";
          show(adj, inc, nodes, edges);
		  break;

		  case '4':
		  cout << "\nMostrar Complemento\n";
		  show(com.first.first, com.first.second, com.second.first, com.second.second);
		  break;
      }

  }while(next != 0);

  return 0;
}
