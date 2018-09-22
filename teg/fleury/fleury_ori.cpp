#include <bits/stdc++.h>

#define pb push_back
#define mx 100



using namespace std;

int nodes, edges;
list<int>adj[mx];

int dfs(int x, bool visita[]){
	cout << 4 << endl;
	visita[x] = true;
	int cont = 1;

	list<int>::iterator it;
	for(it = adj[x].begin(); it != adj[x].end(); it++){
		if(*it != -1 and !visita[*it])	cont += dfs(*it, visita);
	}

	return cont;
}

void remove(int x, int aux){
	list<int>::iterator i1 = find(adj[x].begin(), adj[x].end(), aux);
	*i1 = -1;
	list<int>::iterator i2 = find(adj[aux].begin(), adj[aux].end(), x);
	*i2 = -1;

}

bool valido(int x, int aux){
	cout << 3 << endl;
	int cont = 0;
	list<int>::iterator it;
	for(it = adj[x].begin(); it != adj[x].end(); it++){
		if(*it != -1)	cont++;
	}
	if(cont == 1)	//quer dizer que encontrou 1;
		return true;
	bool visitas[edges];
	memset(visitas,false,sizeof(visitas));
	int cont1 = dfs(x, visitas);
	remove(x,aux);
	memset(visitas,false,sizeof(visitas));
	int cont2 = dfs(x, visitas);
	adj[x].pb(aux);
	adj[aux].pb(x);

	return (cont1 > cont2)? false : true;
}


void eulerUtil(int x){
	cout << 2 << endl;
	list<int>::iterator it;
	for(it = adj[x].begin(); it != adj[x].end(); it++){
		int aux = *it;
		if(aux != -1 and valido(x,aux)){
			cout << x << " - " << aux << " ";
			remove(x,aux);
			eulerUtil(aux);
		}
	}
}

void euler(){
	int x = 0;
	cout << 1 << endl;
	for(int i=0; i<edges; i++){
		if(adj[i].size() & 1){
			x = i;
			break;
		}
	}
	eulerUtil(x);
}


int main(void){
	cin >> nodes >> edges;
	
	for(int i=0; i<edges; i++){
		int no1,no2;	cin >> no1 >> no2;
		no1--, no2--;
		adj[no1].pb(no2);
		adj[no2].pb(no1);
	}
	// graph = adj;
	euler();

	return 0;
}