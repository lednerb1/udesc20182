#pragma once
#include "Candidato.hpp"
#include "Contador.hpp"
#include "utils.hpp"
#include "cstdio"

using namespace std;

class ResultadoVotos{

private:
	double votos;

public:
	void resultado(vector<Candidato>&, unsigned int, unsigned int, unsigned int, string, string);
};