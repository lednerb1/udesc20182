#pragma once
#include <bits/stdc++.h>
#include "fract.hpp"
using namespace std;

class Matrix {
	
private:
	int r;
	int c;
	vector<Fraction*> * matrix;
public:
	Matrix(int r, int c);
	void show();
	void insertData(Fraction* f, int i,int j);
	Fraction * getData(int i, int j);
	void scal();
};