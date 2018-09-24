#include "includes/Contador.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Contador::Contador(string filename){

  ifstream in(filename,ios::in);
  string line;
  string name;
  string aux;
  unsigned int number = 0x3f3f3f3f;

  if(!in.is_open()){
    cerr << "File not found\n";
    exit(1);
  }
  while(true){
    getline(in,line);
    if(!in.good())
      break;
    int sz = (int)line.size();
    //cout << "READ: " << line << endl;
    for(int i=0; i<sz; i++){
      if(line[i] == ' ' and number == 0x3f3f3f3f){
        while(line[i] == ' ')i++;
        //cout << "NUMBER: " << aux << endl;
        number = stoi(aux);
        aux = "";
      }
      if(line[i] == ' '){
        while(line[i] and line[i] == ' ')i++;
        if(line[i]){
          aux+=' ';
        }
      }
      aux+=line[i];
    }
    name = aux;

    this->candidatos.push_back(Candidato(name, number));
    this->votos.emplace(number,0);
    //cerr << name << " " << number << endl;
    number = 0x3f3f3f3f;
    line = "";
    aux = "";
  }

  for(auto c : this->candidatos){
    cout << c.getName() << " " << c.getNumber() << endl;
  }

  this->queue = new Queue();

}

void Contador::work(void *sla_meu_batman){
  while(true){
    int candidate;
    //Semaforo pra ver se tem elemento na fila
    pthread_mutex_lock(&mutex);
    if(this->queue->isEmpty()){
      pthread_cond_wait(&condq, &mutex);
    }
    candidate = this->queue->getNext();
    pthread_mutex_unlock(&mutex);
    this->contabiliza_voto(candidate);
  }

  pthread_exit(NULL);

}

void Contador::contabiliza_voto(int voto){

  if(candidate != -1){
    this->votos.find(candidate)->second++;
    cout << "Queue--\n";
  }else{
    cout << "Queue is empty, wait for more data\n";
  }

}

void Contador::beta_adiciona_voto(unsigned int voto){
  //cout << "Queue++\n";
  //this->queue->add(voto);
}

void Contador::listVotes(){
  for(auto& i : votos){
    cout << i.first << ": " << i.second << endl;
  }
}
