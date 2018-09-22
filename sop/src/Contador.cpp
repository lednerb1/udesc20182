#include "includes/Contador.hpp"
#include <fstream>
#include <iostream>

using namespace std;

Contador::Contador(string filename){

  ifstream in(filename,ios::in);
  string line;
  string name;
  string aux;
  unsigned int number = 0x3f3f3f3f;

  if(!in.is_open()){
    cerr << "File not found\n";
    exit(1);
  }
  while(true){
    getline(in,line);
    if(!in.good())
      break;
    //cout << "READ: " << line << endl;
    for(int i=0; i<line.size(); i++){
      if(line[i] == ' ' and number == 0x3f3f3f3f){
        while(line[i] == ' ')i++;
        //cout << "NUMBER: " << aux << endl;
        number = stoi(aux);
        aux = "";
      }
      if(line[i] == ' '){
        while(line[i] and line[i] == ' ')i++;
        if(line[i]){
          aux+=' ';
        }
      }
      aux+=line[i];
    }
    name = aux;

    this->candidatos.push_back(Candidato(name, number));
    //cerr << name << " " << number << endl;
    number = 0x3f3f3f3f;
    line = "";
    aux = "";
  }

  for(auto c : this->candidatos){
    cout << c.getName() << " " << c.getNumber() << endl;
  }

}
