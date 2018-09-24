#include <cstdlib>
#include <vector>
#include <map>
#include "Queue.hpp"
#include "Candidato.hpp"

class Contador {
private:
  static std::map<int,int> votos;
  std::vector<Candidato> candidatos;
  static bool done;
public:
  static Queue * queue;
  Contador(std::string);
  static void contabiliza_voto(unsigned int);
  void beta_adiciona_voto(unsigned int voto);
  void listVotes();
  static void * work(void*);
  static void setDone(bool);
  static bool isDone();

};
