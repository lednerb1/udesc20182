#include "includes/Contador.hpp"
#include <fstream>

using namespace std;

Contador::Contador(string filename){

  ifstream in(filename);
  string name;
  unsigned int number;

  while(!in.eof()){
    in >> name >> number;
    this->candidatos.push_back(Candidato(name, number));
  }

  for(auto c : this->candidatos){
    cout << c.getName() << " " << g.getNumber() << endl;
  }

}
