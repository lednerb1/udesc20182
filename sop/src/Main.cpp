//#include <bits/stdc++.h>
#include "includes/utils.hpp"
#include "includes/Contador.hpp"
#include "includes/Validator.hpp"
#include <pthread.h>
#include <cstdlib>
#include <vector>

using namespace std;

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

  vector<Validator*> v(ithreads);

  for(int i=1; i<=ithreads; i++){
    cout << "Creating Validator " << files[i] << endl;
    v[i-1] = new Validator(files[i], i);
  }

  for(auto& i : v){
    i->work(contador->queue);
  }

  while(!contador->queue->isEmpty()){
    contador->contabiliza_voto();
  }

  contador->listVotes();

  // for(int i=0; i<50; i++){
  //   if(random() % 2){
  //     contador->contabiliza_voto();
  //   }else{
  //     contador->beta_adiciona_voto(i);
  //   }
  // }cout << endl;
  // while(!contador->queue->isEmpty()){
  //   contador->contabiliza_voto();
  // }
  //
  // contador->listVotes();
  return 0;
}
