#include "include/resultadoVotos.hpp"

resultadoVotos::resultadoVotos(){

}

void resultadoVotos::resultado(unsigned int number, vector<Candidato> &candidatos){

	cout << "Resultado final:\n";
	cout << fmtcabvoto;
	unsigned int quantTotal=0;

	for(auto i : candidatos){
		quantTotal += i->votos;
	}

	printf(fmtvoto, i.number, i.name, i.votos, (i.votos*100)/quantTotal);
	cout << candidatos[i].number << "\t";
	cout << candidatos[i].name << "\t\t";
	cout << candidatos[i].votos << "\t";
	cout << (candidatos[i].votos*100)/quantTotal << endl;

	}
}
