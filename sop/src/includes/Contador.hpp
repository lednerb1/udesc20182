#include <cstdlib>
#include <pthread.h>
#include <vector>
#include "Candidato.hpp"

class Queue {
private:
  static int size;
  static Queue * last;
  int n;
  Queue * next;
public:
  Queue(int n, NULL);
  int getNext();
  bool isEmpty();

};

class Contador {

private:
    Queue * que;
    std::vector<Candidato> candidatos;
    int maxSize=0;
public:
    Contador(std::string);
    void contabiliza_voto(unsigned int voto);
};
