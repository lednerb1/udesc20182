#include "includes/Contador.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int Queue::size = 0;
unsigned int Queue::maxSize = 0;
Queue * Queue::last = NULL;

Queue::Queue(unsigned int n){
  this->node = (Queue *)NULL;
  this->node->n = n;
  this->node->next = NULL;
  last = this->node;
  size++;
  maxSize = max(maxSize, size);
  cout << "a\n";
}

unsigned int Queue::getNext(){
  if(this->isEmpty()){
    return -1;
  }
  size--;
  unsigned int returner = this->node->n;
  Queue * nexter = this->node->next;
  delete this->node;
  this->node = nexter;

  return returner;
}

void Queue::add(unsigned int n){
  if(this->node == NULL)
    this->node = new Queue(n);
  else
    last->next = new Queue(n);
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
    //cerr << name << " " << number << endl;
    number = 0x3f3f3f3f;
    line = "";
    aux = "";
  }

  for(auto c : this->candidatos){
    cout << c.getName() << " " << c.getNumber() << endl;
  }

}

void Contador::contabiliza_voto(unsigned int voto){
  this->queue->add(voto);
}
