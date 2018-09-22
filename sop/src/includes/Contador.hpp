#include <cstdlib>
#include <pthread.h>
#include <vector>
#include "Candidato.hpp"

typedef struct q {
    int n;
    struct q * next;
} Queue;

class Contador {

private:
    Queue * que;
    std::vector<Candidato> candidatos;
    int maxSize=0;
public:
    Contador(std::string);
    void contabiliza_voto(unsigned int voto);
};
