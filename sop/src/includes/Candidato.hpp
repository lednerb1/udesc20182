#include <string>

class Candidato {
private:
    std::string name;
    unsigned int number;
public:
    Candidato(std::string name, unsigned int number);
    std::string getName();
    unsigned int getNumber();
};
