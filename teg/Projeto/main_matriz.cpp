#include <bits/stdc++.h>

using namespace std;

int main(){
  srand(time(NULL));

  pair<double,double> posicoes[100][100];

  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
      posicoes[i][j] = make_pair((double)(rand() % 1001) / 100, (double)(rand() % 1001) / 100);
    }
  }

  for(int i=0; i<100; i++){
    for(int j=0; j<100; j++){
      cout << "( " << posicoes[i][j].first << " , " << posicoes[i][j].second << " ) : ";
    }
  }cout << endl;

}
