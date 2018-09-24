//#include <bits/stdc++.h>
#include "includes/utils.hpp"
#include "includes/Contador.hpp"
#include "includes/Validator.hpp"
#include <pthread.h>
#include <cstdlib>
#include <vector>

using namespace std;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t emptyq = PTHREAD_COND_INITIALIZER;
pthread_barrier_t barrier;

int main(int argc, const char * args[]){

  unsigned int ithreads = 0x3f3f3f3f;
  const char * nthreads = NULL;
  const char * filename = NULL;
  vector<string> files;

  switch(argc){
    case 1:
    case 2:
    cerr << "Usage: $ " << args[0] << " num_threads path_to_files\nAborting\n";
    return 1;

    case 3:
    nthreads = args[1];
    filename = args[2];
    sscanf(nthreads, "%u", &ithreads);
    if(!getFiles(files, filename, nthreads, ithreads)){
      cerr << "Could not generate filenames properly\nAborting\n";
      return 2;
    }
    break;
  }

  if(ithreads == 0x3f3f3f3f or filename == NULL){
    cerr << "Error on reading arguments\nAborting\n";
    return 3;
  }

  for(auto s : files){
    cout << s << endl;
  }

  if(pthread_mutex_init(&mtx, NULL)){
      cerr << "Erro ao criar mutex\n";
      exit(1);
  }
  if(pthread_cond_init(&emptyq, NULL)){
    cerr << "Erro ao criar condq\n";
    exit(1);
  }
  if(pthread_barrier_init(&barrier), NULL, ithreads){
    cerr << "Erro ao criar barreira\n";
    exit(1);
  }
  /*
  Aqui deve ser inserido o codigo para iniciar as Threads
  Todas as Threads vao estar separadas executando seus pro
  prios metodos, inclusive o contador, entao nada roda na
  Main. A chamada do Validator(files[0]) serve para criar
  um static set com o numero de todos os possiveis candida
  tos. Desta maneira, todas as threads Validator tem aces
  so a esse set e conseguem fazer a validacao de um voto
  em O( LogN ) onde N = quantidade de candidatos.
  */
  Contador * contador = new Contador(files[0]);
  Validator * validator = new Validator(files[0]);
  delete validator;
  //Contador deve avisar as demais Threads que esta pronto;

  vector< pair<Validator*, int> > validators(ithreads);
  vector<pthread_t> threads(ithreads);

  for(int i=1; i<=ithreads; i++){
    cout << "Creating Validator " << files[i] << endl;
    validators[i-1].first = new Validator(files[i], i);
    validators[i-1].second = pthread_create(&threads[i], NULL, (void *)validators[i-1].first->work(), (void *) validators[i-1].first->work());
  }
  bool quebrou = false;
  for(int i=1; i<= threads; i++){
      if(validators[i-1].second == 0){
          cerr << "Erro na criação da thread " << i << endl;
          quebrou = true;
      }
  }
  if(quebrou) exit(1);

  while(!contador->queue->isEmpty()){
    contador->contabiliza_voto();
  }

  contador->listVotes();

  return 0;
}
