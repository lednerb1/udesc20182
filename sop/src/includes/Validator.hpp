#include <cstdio>
#include <string>
#include <fstream>
#include <set>
#include "Queue.hpp"

class Validator {
private:
    static std::set<unsigned int> candidates;
    std::string arq; //Arquivo de votos !!
    void load(std::string arquivo);
public:
    Validator(std::string arquivo);
    Validator(std::string arquivo, std::string nthread);
    void work(Queue* & queue);
};
