#include <cstdlib>
#include <pthread.h>
#include <vector>
#include <map>
#include "Candidato.hpp"

typedef struct Node{
  unsigned int n;
  Node * next;
} Node;

class Queue {
private:
  static unsigned int size;
  static unsigned int maxSize;
  static Node ** last;
  Node * node;
public:
  Queue();
  unsigned int getNext();
  void add(unsigned int n);
  bool isEmpty();

};

class Contador {
private:
  std::map<int,int> votos;
  std::vector<Candidato> candidatos;
public:
  Queue * queue;
  Contador(std::string);
  void contabiliza_voto();
  void beta_adiciona_voto(unsigned int voto);
  void listVotes();
};
