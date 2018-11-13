#include <bits/stdc++.h>

using namespace std;

set< pair<double,double> > geraConjunto(int n){
  srand(time(NULL));

  set< pair<double,double> > temp;
  pair<double,double> p;
  int iterations=0;

  while(temp.size() < n){
    p = make_pair((double) (rand() % 101) / 100 , (double) (rand() % 101) / 100);
    temp.insert(p);
    iterations++;
  }

  if(temp.size() != n){
    cerr << "Conjunto gerado incorretamente, abortando\n";
    exit(EXIT_FAILURE);
  }

  return temp;
}

vector< pair<int, double> > getAdjacencias(int i, set< pair<double,double> >::iterator init, set< pair<double,double> >::iterator it){
  set< pair<double,int > > distancias;
  int j=0;
  do{
    if(j!=i)
      distancias.insert(make_pair( hypot(it->first - init->first, it->second - init->second), j ));
    j++;
    it++;
  }while(j < 1000);

  vector< pair<int, double> > temp;
  auto b = distancias.begin();
  temp.push_back(make_pair(b->second, b->first));b++;
  temp.push_back(make_pair(b->second, b->first));b++;
  temp.push_back(make_pair(b->second, b->first));

  return temp;

}

int main(int argc, const char * argv[]){

  // Gera um conjunto de pontos ordenados pelo eixo X usando Y como desempate.
  set< pair<double, double> > pontos;
  pontos = geraConjunto(1000);

  vector<pair<int, double>> grafo[1000];
  set< pair<double, double> >::iterator offset = pontos.begin();

  for(int i=0; i<1000; i++){
    // Encontra os 3 mais proximos no bruteforce mesmo xD
    grafo[i] = getAdjacencias(i, offset, pontos.begin());
    offset++;
  }

  /* A ideia era pegar os 3 mais proximos pra montar o grafo, mas sepa vai dar
   * trabalho desse jeito. Pensei em fazer numa matriz 1000x1000 mesmo,
   * a distancia de i pra j, nesse caso a gente so precisa preencher uma matriz
   * triangular, e os valores do outro j,i sao iguais aos valores do i,j.
   * Nao vou implementar agora, se tu ver antes de mim e quiser fazer mete bala.
   * Ou se pensar em outra ideia, acho que as minhas 2 solucoes sao bem ruins...
  */

  // for(int i=0; i<1000; i++){
  //   cout << i << " -> ";
  //   for(auto g : grafo[i]){
  //     cout << g.first << " ";
  //   }cout << endl;
  // }
  geraConjuntos(pontos.begin());

  return 0;
}
