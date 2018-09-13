#include "matrix.hpp"

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
			printf("%4s ", j->show().c_str());
		}
		cout << endl;
	}
}

void Matrix::insertData(Fraction* data, int i, int j){
	free(this->matrix[i][j]);
	this->matrix[i][j] = data;
}

Fraction * Matrix::getData(int i, int j){
	return this->matrix[i][j];
}

void Matrix::scal(){
	//Ln <- Ln - num/den * Lm
	for(int j=0; j<r-1; j++){
		Fraction * den = this->getData(j,j);
		cout << "forward\n";
		for(int i=j+1; i<r; i++){

			Fraction * num = this->getData(i,j);
			Fraction * nude = new Fraction(num, den);
			for(int k=j; k<c; k++){
				Fraction * tnude = nude;
				Fraction * temp = this->getData(i,k);
				cout << "OP: " << temp->show() << " - " << tnude->show() << "*" << this->getData(j,k)->show() << endl;  
				tnude = tnude->mul(*this->getData(j,k));
				temp = temp->sub(*tnude);
				cout << "M: ";
				cout << this->getData(i,k)->show() << " ";
				this->insertData(temp,i,k); //(*(*this->matrix[i][k] - *nude))*(*this->matrix[j][k]);
				cout << this->getData(i,k)->show() << endl;
			}
			this->show(); cout << endl;

		}

	}

}