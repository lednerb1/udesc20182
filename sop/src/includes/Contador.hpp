#include <cstdlib>
#include <pthread.h>
#include <vector>
#include <map>
#include "Queue.hpp"
#include "Candidato.hpp"

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
