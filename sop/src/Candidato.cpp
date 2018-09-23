#include "includes/Candidato.hpp"

Candidato::Candidato(std::string name, unsigned int number){
    this->name = name;
    this->number = number;
}

std::string Candidato::getName(){
    return this->name;
}

unsigned int Candidato::getNumber(){
    return this->number;
}
