#include "includes.hpp"

Matrix::Matrix(int r, int c){
	this->r = r; this->c = c;
	this->matrix = (vector<Fraction*>*)malloc(sizeof(vector<Fraction*>) * r);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			matrix[i].push_back(new Fraction(1,1));
		}
	}
}

void Matrix::show(){
	for(int i=0; i<this->r; i++){
		for(auto j : matrix[i]){
			cout << j->show() << " ";
		}
		cout << endl;
	}
}

void Matrix::insertData(Fraction* data, int i, int j){
	this->matrix[i][j] = data;
}

