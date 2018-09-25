#include "includes/ResultadoVotos.hpp"


void ResultadoVotos::resultado(vector<Candidato> &candidatos){

	cout << "Resultado final:\n";
	cout << fmtcabvoto;
	unsigned int quantTotal=0;

	for(auto i : candidatos){
		quantTotal += i.getVotos();
	}

	for(auto i : candidatos){
		printf(fmtvoto, i.getNumber(), i.getName().c_str(), i.getVotos(), (double)((double)i.getVotos()*100.0)/(double)quantTotal);
	}
	// cout << candidatos[i].number << "\t";
	// cout << candidatos[i].name << "\t\t";
	// cout << candidatos[i].votos << "\t";
	// cout << (candidatos[i].votos*100)/quantTotal << endl;
}
