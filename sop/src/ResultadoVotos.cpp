#include "includes/ResultadoVotos.hpp"


void ResultadoVotos::resultado(vector<Candidato> &candidatos, unsigned int lidos, unsigned int validos, unsigned int max, string arq, string nthread){

	string name = arq+"_saida_"+nthread;
	FILE * saida = fopen(name.c_str(), "w+");

	printf("Total de votos processados: %u\n", lidos);
	printf("Votos validos: %u (%.2f%%)\n", validos, ((double)validos/(double)lidos)*100.0);
	printf("Tamanho maximo da fila: %d nos\n\n", max);

	if(saida != NULL){
		fprintf(saida, "Total de votos processados: %u\n", lidos);
		fprintf(saida, "Votos validos: %u (%.2f%%)\n", validos, ((double)validos/(double)lidos)*100.0);
		fprintf(saida, "Tamanho maximo da fila: %d nos\n\n", max);
	}else{
		cout << "FILE NOT OPENED\n";
	}
	cout << fmtcabvoto;
	for(auto i : candidatos){
		printf(fmtvoto, i.getNumber(), i.getName().c_str(), i.getVotos(), (double)((double)i.getVotos()*100.0)/(double)validos);
		fprintf(saida ,fmtvoto, i.getNumber(), i.getName().c_str(), i.getVotos(), (double)((double)i.getVotos()*100.0)/(double)validos);
	}

	fclose(saida);

}
