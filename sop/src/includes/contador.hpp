#include <cstdlib>

typedef struct q {
    int n;
    struct q * next;
} Queue;

class Contador {
private:
    Queue * que;
public:
    void pontua();
};
