#include <cstdio>
#include <string>
#include <fstream>
#include <set>
#include "Queue.hpp"

class Validator {
private:
    static std::set<unsigned int> candidates;
    unsigned int threadId;
    std::string arq; //Arquivo de votos !!
public:
    Validator(std::string arquivo);
    Validator(std::string arquivo, unsigned int ithread);
    bool isValid(unsigned int n);
    void work((void*) &queue);
};
