/**
*
* Universidade do Estado de Santa Catarina - UDESC
* Campus CCT
* Departamento de Ciência da Computação
* Disciplina de Sistemas Operacionais
* Professor Rafael Obelheiro
*
* Apurador de Votos Multithreading
*
* @Authors
* Peter L. Brendel
* Guilherme M. Utiama
*
* Comentários dos autores:
*
* Nos arrependemos de ter feito em C++
* Algo que era para simplificar apenas
* nos trouxe mais dor e sofrimento.
*
* Estamos chorando, mas conseguimos.
*
*
**/

#include "includes/utils.hpp"
#include "includes/Contador.hpp"
#include "includes/Validator.hpp"
#include "includes/ResultadoVotos.hpp"
#include <pthread.h>
#include <cstdlib>
#include <vector>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t emptyq = PTHREAD_COND_INITIALIZER;
pthread_barrier_t barrier_init, barrier_end;

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
    exit(EXIT_FAILURE);

    case 3:
    nthreads = args[1];
    filename = args[2];
    if(!isNumber(nthreads)){
      cerr << "First argument must be a number\nAborting\n";
      exit(EXIT_FAILURE);
    }
    sscanf(nthreads, "%u", &ithreads);
    if(!getFiles(files, filename, nthreads, ithreads)){
      cerr << "Could not generate filenames properly\nAborting\n";
      exit(EXIT_FAILURE);
    }
    break;
  }

  if(ithreads == 0x3f3f3f3f or filename == NULL){
    cerr << "Error on reading arguments\nAborting\n";
    exit(EXIT_FAILURE);
  }

  for(auto s : files){
    cout << s << endl;
  }

  if(pthread_mutex_init(&mtx, NULL)){
      cerr << "Erro ao criar mutex\n";
      exit(EXIT_FAILURE);
  }
  if(pthread_cond_init(&emptyq, NULL)){
    cerr << "Erro ao criar condq\n";
    exit(EXIT_FAILURE);
  }
  if(pthread_barrier_init(&barrier_init, NULL, ithreads+1)){
    cerr << "Erro ao criar barreira_init\n";
    exit(EXIT_FAILURE);
  }
  if(pthread_barrier_init(&barrier_end, NULL, ithreads)){
    cerr << "Erro ao criar barreira_end\n";
    exit(EXIT_FAILURE);
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



  vector< pair<Validator*, int> > validators(ithreads+1);
  vector<pthread_t> threads(ithreads+1);

  validators[0].second = pthread_create(&threads[0], NULL, Contador::work, NULL);

  for(unsigned int i=1; i<=ithreads; i++){
    printf("Creating Validator %s\n", files[i].c_str());
    // cout << "Creating Validator " << files[i] << endl;
    validators[i].first = new Validator(files[i], i);

    Data * data = new Data();
    data->queue = &contador->queue;
    data->file = validators[i].first->getArq();
    validators[i].second = pthread_create(&threads[i], NULL, Validator::work, data);
    if(validators[i].second){
      cerr << "Erro na criação da thread " << i << endl;
      exit(1);
    }

  }

  for(unsigned int i=0; i<=ithreads; i++){
    pthread_join(threads[i], NULL);
  }
  // cout << "Tamanho maximo da fila " << contador->queue->getMax() << endl;
  vector<Candidato> temp = contador->apura();
  ResultadoVotos * resultados = new ResultadoVotos();
  unsigned int lidos, validos, max;
  lidos = Validator::lidos;
  validos = Validator::validos;
  max = Queue::getMax();

  system("clear");
  resultados->resultado(temp, lidos, validos, max, files[0], nthreads);


  cout << "\nCalculo finalizado com sucesso\nVerifique a saida gerada em " << files[0] << "_saida_" << nthreads << endl;
  cout << "Pressione qualquer botao para continuar.\n";
  getchar();
  return 0;
}
