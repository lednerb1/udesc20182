#include <bits/stdc++.h>

using namespace std;

class Fraction {

private:
	int up;
	int dw;

public:
	Fraction(int up,int dw);
	Fraction * add(Fraction& o);
	Fraction * add(int o);
	Fraction * sub(Fraction& o);
	Fraction * sub(int o);
	Fraction * mul(Fraction& o);
	Fraction * mul(int o);
	Fraction * div(Fraction& o);
	Fraction * div(int o);
	int getInt();
	float getFloat();
	double getDouble();
	string show();
	Fraction * operator+(Fraction& o);
	Fraction * operator+(int o);
	Fraction * operator-(Fraction& o);
	Fraction * operator-(int o);
	Fraction * operator*(Fraction& o);
	Fraction * operator*(int o);
	Fraction * operator/(Fraction& o);
	Fraction * operator/(int o);
};

