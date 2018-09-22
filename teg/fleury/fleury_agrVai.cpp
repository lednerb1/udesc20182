#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int **matriz, nodes, edges, qtdVert;
int visitados[1005], grauNo[1005];


void adjacente();
void fleury();
void dfs(int i); 

int main(){
  fleury();
}

void fleury(){

    int i, j; 
    // int menorCaminhoMax = 200, medianaGrafo = 200, verticeMedio; //menor caminho maximo percorrido por um vertice
    
    int conexo = 1, grauImpar = 0, fail = 1;
    int primeiroI, segundoI;

    cin >> nodes >> edges;

    memset(visitados, 0, sizeof(visitados));

    matriz = (int**)malloc(sizeof(int*) * nodes);  
    for(i = 0; i < nodes; i++){
        matriz[i] = (int*)malloc(sizeof(int) * nodes);  
        for(j = 0; j < nodes; j++){
            matriz[i][j] = 0;    
        }
    }

    memset(grauNo, 0, sizeof(grauNo));


    adjacente();  //monta a matriz adjacente

    qtdVert = 0;
    for(i = 0; i < nodes; i++){
        dfs(i);
        if(qtdVert != nodes - 1)       conexo = 0;                              

        memset(visitados, 0, sizeof(visitados));
        qtdVert = 0;
    }

    //verificaçao de todos os graus
    for(i = 0; i < nodes; i++){
        if(grauNo[i] % 2 != 0){ //se o grau for impar
            grauImpar++; //sinaliza que encontrou um no com grau impar

            if(grauImpar % 2 != 0){
                primeiroI = i; //armazena o primeiro no com grau impar
                fail = 0;
            }

            if(grauImpar % 2 == 0){ //se encontrou uma dupla de nos com grau par
                segundoI = i;  //armazena o segundo no com grau impar
                //if(matriz[primeiroI][segundoI] != 0 && (grauNo[primeiroI] % 2 != 0) && (grauNo[segundoI] % 2 != 0))
                if(matriz[primeiroI][segundoI] != 0){ //se os dois nos com grau impar possuem ligaçao

                    matriz[primeiroI][segundoI]--;//retira essa aresta, para verificar se a aresta é uma ponte (verificando se o grafo continua sendo conexo)

                    //verificar se o grafo continua sendo conexo

                    memset(visitados, 0, sizeof(visitados));
                    qtdVert = 0;

                    for(i = 0; i < nodes; i++){

                        dfs(i);

                        if(qtdVert != nodes - 1){ //se encontrar um vertice que nao tem acesso a todos os outros
                            conexo = 0;                              //sinaliza que o grafo nao é conexo
                        }
                        memset(visitados, 0, sizeof(visitados));
                        qtdVert = 0;
                    }

                    matriz[primeiroI][segundoI]++; //restaura a aresta que foi testada

                    if(conexo == 1){ //se nao for uma aresta ponte
                        fail = 1;  //sinaliza que eles tem ligaçao e nao formam ponte, entao está apto a ter ciclo euleriano
                        grauImpar = 0; //reinicia grauImpar para caso tenha mais uma dupla de vertices vizinhos com grau impar
                    }else{//se for uma aresta ponte
                        printf("\n\n    O grafo possui uma ponte entre os vertices %d e %d!", primeiroI+1, segundoI+1);
                        cout << "\n\n    O grafo NAO POSSUI um ciclo Euleriano!\n\n    ";
                        
                        // system("pause");
                        exit(1);
                    }
                }
            }
        }
    }

    if(conexo == 0) cout << "\nNao e conexo\n";
        
    if(grauImpar % 2 == 0 && fail){ //se nao tiver vertice com grau impar, ou se tiver dois nos com grau impar porém vizinhos e nao ponte
        cout << "\n\n    Requisito de grau de vertices SATISFEITO!";
    }else
        printf("\n\n    Requisito de graus INSATISFEITO, vertice %d possui grau impar = %d!", primeiroI+1, grauNo[primeiroI]);

    if(conexo && fail) //se for conexo e todos os nos tem grau par com exceção de pares de vizinhos com grau impar que nao formam ponte
        cout << "\n\n\n    O grafo POSSUI um ciclo Euleriano!";
    else
        cout << "\n\n\n    O grafo nao possui um ciclo Euleriano!";

    cout << "\n\n\n";

    free(matriz);
}

void adjacente(){
    int x, y;

    for(int i=0; i<edges; i++){
        cin >> x >> y;
        matriz[y-1][x-1]++;  //e aumenta o numero de arestas entre cada vertice
    }

    for(x = 0; x < nodes; x++){
        for(y = 0; y < nodes; y++){
            if(x > y)
                matriz[y][x] = matriz[x][y];
        }
    }

    for(x = 0; x < nodes; x++){
        grauNo[x] = 0;
        for(y = 0; y < nodes; y++){
            grauNo[x] += matriz[y][x];
        }
    }
}

void dfs(int i){
    int j;
    visitados[i] = 1;

    for(j = 0; j < nodes; j++){
        if(!visitados[j] && matriz[i][j] != 0){ 
            qtdVert++; //incrementa a quantidade de vertices visitados a partir do vertice i
            dfs(j);
        }
    }
}