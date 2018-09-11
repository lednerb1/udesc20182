#include <bits/stdc++.h>

using namespace std;

int ** criarAdj(int);
int ** criarInc(int,int);
void eraseNode(int***,int***,int,int*);
char nextStep(void);
void show(int **,int **,int,int);
pair<pair<int **, int**>,pair<int,int>> complemento(int**, int);
