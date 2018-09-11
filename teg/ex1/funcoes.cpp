#include "funcoes.hpp"

int ** criarAdj(int n){
  int ** tmp = (int**) malloc(sizeof(int*)*(n+1));
  for(int i=0; i<n; i++){
    tmp[i] = (int*) malloc(sizeof(int)*n);
	for(int j=0; j<n; j++)
		tmp[i][j] = 0;
  }
  tmp[n] = (int*)malloc(sizeof(int));
  for(int i=0; i<n; i++){
      tmp[i][n] = 0;
  }
  return tmp;
}

int ** criarInc(int n, int m){
    int ** tmp = (int**) malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
      tmp[i] = (int*) malloc(sizeof(int)*m);
	  for(int j=0; j<m; j++)
	    tmp[i][j] = 0; 
    }
    return tmp;
}

void eraseNode(int *** adj, int *** inc, int nodes, int * edges){

    int vitima;
    cout << "Numero do vertice a ser removido: "; cin >> vitima;
    int ** ad = *adj;
    int ** in = *inc;

    for(int i=0; i<nodes; i++){
        ad[i][vitima-1] = -2;
        ad[vitima-1][i] = -2;
    }

    for(int i=(*edges)-1; i>=0; i--){
        if(in[i][vitima-1]){
            for(int j=i; j<(*edges); j++){
                in[j] = in[j+1];
				//cout << "movendo";
            }
            //cout << "apagando:\n";
            free(in[(*edges)-1]);
            (*edges)--;
        }else{
			//cout << "ignorando\n";
		}
    }

}

char nextStep(void){
		 
    cout << "\nO que fazer:\n1 -> Calcular Complemento\n2 -> remover No\n3 -> Mostrar matrizes\n4 -> Mostrar Complemento\n\nAcao: ";
	   
	char r; cin >> r;
    return r;
}

void show(int ** adj, int ** inc,  int n, int e){

    cout << "adjacencia\n";
    for(int i=0; i<n; i++){
		if(adj[i][0] == -2)continue;        
		for(int j=0; j<n; j++){
			if(adj[i][j] != -2)
	            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\nincidencia\n";
    for(int i=0; i<e; i++){
        for(int j=0; j<n; j++){
            cout << inc[i][j] << " ";
        }
        cout << "\n";
    }
	
	return;

}

pair<pair<int **, int**>,pair<int,int>> complemento(int ** adj, int nodes){

	vector<pair<int,int>> inputs;
	
	for(int i=0; i<nodes; i++){
		for(int j=0; j<nodes; j++){
			if(adj[i][j] != 1) inputs.push_back({i,j});
		}
	}

	int ** adjT = criarAdj(nodes);
	int ** incT = criarInc(inputs.size(), nodes);
	int e=0;

	for(auto i : inputs){
		int a = i.first, b = i.second;		
		adjT[a][b] = adjT[b][a] = incT[e][a] = incT[e][b] = 1;
		adjT[a][nodes]++;
		adjT[b][nodes]++;
		e++;
	}

	return make_pair(make_pair(adjT,incT), make_pair(nodes, inputs.size()));

}












