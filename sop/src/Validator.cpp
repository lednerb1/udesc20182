#include "includes/Validator.hpp"
#include <cstdio>

using namespace std;

set<unsigned int> Validator::candidates;

Validator::Validator(string arq){

  fstream in(arq,ios::in);
  string line;

  while(true){

    unsigned int candidate = 0x3f3f3f3f;
    string aux;
    getline(in, line);

    if(!in.good())
      break;
    for(auto c : line){
      if(c == ' '){
        candidate = stoi(aux);
        break;
      }
      aux+=c;
    }

    if(candidate != 0x3f3f3f3f){
      candidates.insert(candidate);
    }else{
      cerr << "Couldnt load candidate correctly\n";
      exit(1);
    }

  }

}

Validator::Validator(string arq, string ntr){
    this->arq = arq+"-"+ntr;
    fstream in(this->arq,ios::in);
    //Sinaliza que esta pronto pra comecar a ler
}

void work(Queue* & queue){



}

bool isValid(){
  return false;
}
