//#include <bits/stdc++.h>
#include "includes/utils.hpp"
#include "includes/Contador.hpp"
#include <pthread.h>
#include <cstdlib>

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

  Contador * contador = new Contador(files[0]);
  for(int i=0; i<50; i++){
    if(random() % 2){
      contador->contabiliza_voto();
    }else{
      contador->beta_adiciona_voto(i);
    }
  }cout << endl;
  while(!contador->queue->isEmpty()){
    contador->contabiliza_voto();
  }

  contador->listVotes();
  return 0;
}
