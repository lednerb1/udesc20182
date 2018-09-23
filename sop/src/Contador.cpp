#include "includes/Contador.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int Queue::size = 0;
unsigned int Queue::maxSize = 0;
Node ** Queue::last;

Queue::Queue(){
  this->node = NULL;
  last = &this->node;
  cerr << "Lived, still oK\n";
}

unsigned int Queue::getNext(){
  if(this->isEmpty()){
    return -1;
  }
  size--;
  unsigned int returner = this->node->n;
  Node * nexter = this->node->next;
  delete this->node;
  this->node = nexter;

  return returner;
}

void Queue::add(unsigned int n){
  //cerr << "add\n";
  if(this->isEmpty()){
    // cerr << "node is null\n";
    this->node = new Node();
    this->node->n = n;
    this->node->next = NULL;
    last = &this->node->next;
    size++;
  }
  else{
    // cerr << "Why you here\n";
    *last = new Node();
    (*last)->n = n;
    (*last)->next = NULL;
    last = &((*last)->next);
    size++;
  }
  // cerr << "hmm\n";
}

bool Queue::isEmpty(){
  return size == 0;
}

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

void Contador::contabiliza_voto(){
  // cerr << "here\n";
  int candidate = this->queue->getNext();
  if(candidate != -1){
    this->votos.find(candidate)->second++;
    cout << "Queue--\n";
    }
  else
    cout << "Queue is empty, wait for more data\n";
  // cerr << "passed\n";
}

void Contador::beta_adiciona_voto(unsigned int voto){
  cout << "Queue++\n";
  this->queue->add(voto);
}

void Contador::listVotes(){
  for(auto& i : votos){
    cout << i.first << i.second << endl;
  }
}
