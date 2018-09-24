#include "includes/Validator.hpp"
#include <pthread.h>
#include <cstdio>

using namespace std;

set<unsigned int> Validator::candidates;

Validator::Validator(string arq){

  fstream in(arq,ios::in);

  while(true){
    string line;
    unsigned int candidate = 0x3f3f3f3f;
    string aux;
    getline(in, line);
    // cerr << line;
    if(!in.good())
      break;
    for(auto c : line){
      if(c == ' '){
        candidate = (unsigned int)stoi(aux);
        break;
      }
      aux+=c;
    }
    // cout << " = " << candidate << endl;
    if(candidate != 0x3f3f3f3f){
      candidates.insert(candidate);
      cout << "insert: " << candidate << endl;
    }else{
      break;
    }

  }

}

Validator::Validator(string arq, unsigned int ntr){
    this->arq = arq;
    this->threadId = ntr;
}

bool Validator::isValid(unsigned int n){
  return (this->candidates.find(n) != this->candidates.end());
}

void Validator::work(void* &queue){
  ifstream in(this->arq, ios::in);
  queue = (Queue*)queue; // aqui pode dar merda

  //Avisa as demais Threads que esta pronto
  cout << this->arq << " Ready\n";
  //Aguarda as demais Threads se necessario

  while(true){
    unsigned int n;
    string line;

    getline(in,line);

    if(!in.good())
      break;

    n = (unsigned int)stoi(line);
    if(this->isValid(n)){
      pthread_mutex_lock(&mtx);
      queue->add(n);
      if(queue->getSize() == 1){
        pthread_cond_signal(&condq);
      }
      pthread_mutex_unlock(&mtx);
    }

  }

  pthread_barrier_wait(&barrier);
  //Avisa as demais Threads que terminou de
  //validar os votos referentes a seu arquivo


}
