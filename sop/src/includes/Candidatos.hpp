#include <string>

class Person {
private:
    std::string name;
    unsigned int number;
    unsigned int votos;
public:
    Person(std::string name, unsigned int number);
    std::string getName();
    unsigned int getNumber();
};
