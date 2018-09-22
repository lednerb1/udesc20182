#include <cstdlib>
#include <pthread.h>
#include <vector>
#include "Candidato.hpp"

class Queue {
private:
  static unsigned int size;
  static unsigned int maxSize;
  static Queue * last;
  unsigned int n;
  Queue * node;
  Queue * next;
  Queue(unsigned int n);
public:
  unsigned int getNext();
  void add(unsigned int n);
  bool isEmpty();

};

class Contador {

private:
    Queue * queue;
    std::vector<Candidato> candidatos;
public:
    Contador(std::string);
    void contabiliza_voto(unsigned int voto);
};
