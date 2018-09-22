#include "includes/Candidatos.hpp"

Person::Person(std::string name, unsigned int number){
    this->name = name;
    this->number = number;
    this->votos = 0;
}

std::string Person::getName(){
    return this->name;
}

unsigned int Person::getNumber(){
    return this->number;
}
