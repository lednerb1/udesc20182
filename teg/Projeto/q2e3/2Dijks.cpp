#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;

vii *graph;
vi dist;
int nodes, edges;

void dijk(int ini, int fim){
	priority_queue<pii, vii> pq;
	dist.assign(nodes, inf);
	dist[ini] = 0;
	pq.push( {0, ini} );
	bool flag = false;
	int a,b;
	while(!pq.empty()){
		int aux;
		aux = pq.top().second; // inicio
		flag = true;
		pq.pop();

		for(auto &k : graph[aux]){
			int a,b;
			a = k.first;
			b = k.second;
			// cout << " ----- " << aux << " " << a  << " " << b << endl;
			// cout << a << " " << fim << endl;
			if(dist[a] > dist[aux]+b){
				dist[a] = dist[aux]+b;
				pq.push( {dist[a], a} );
			}
			if(a == fim){
			flag = false;
			aux = ini;
			break;
		}
		}
	}

}

int main(void){
	int ini, fim;
	cout << "Questa 2:\n\n";
	cin >> nodes >> edges;
	graph = new vii[nodes];
	for(int i=0; i<edges; i++){
		int n1, n2, c;
		cin >> n1 >> n2 >> c;
		graph[n1].push_back({n2,c});
		graph[n2].push_back({n1,c});
	}
	cin >> ini >> fim; // leitura do no inicio e fim
	dijk(ini, fim);
	cout << "Nó de inicio escolhido " << ini+1 << ", nó escolhido para chegada: " << fim + 1 << endl << endl;
	cout << "Custo de: ";
	cout << ini+1 << " para "<< fim+1 << " - custo:  " << dist[fim] << endl << endl;

	///////////////////////// Questao 3 ///////////////////////

	cout << "Quest 3\n\n";

	cin >> fim; // obs: na leitura tem que ter so o nodo que tu quer chegar

	cout << "Nó escolhido para chegada: " << fim+1 << endl << endl;
	for(int i=0; i<nodes; i++){
		dijk(i, fim);
		cout << "Custo de: ";
		cout << i+1 << " para "<< fim+1 << " - custo:  " << dist[fim] << endl << endl;
	}


	return 0;
}
