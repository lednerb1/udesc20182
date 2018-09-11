#include <bits/stdc++.h>

using namespace std;

#define ll long double

ll e = 2.718281828459045;

//FUNCAO

ll f(ll x){
	return powl(-e, -x) -1;
}

ll f1(ll x){
	return powl(e, -x);
}

string getF(){
	return "f(x) = -e^-x - 1\n";
}

string getF1(){
	return "f'(x) = e^-x\n";
}

ll calculate(ll& x){

	ll nextX = x - f(x)/f1(x);
	ll res = nextX - x;
	x = nextX;
	return res;
}

int main(){

	ll x, fx, e;
	cout << getF();
	cout << getF1() << endl;
	cout << "Enter x0: ";
	cin >> x;
	cout << "Enter £ : ";
	cin >> e;	
	cout << "\n------------------\n";
	ll count=0;
	while(calculate(x) < e)count++;

	cout << "Apx root = " << x << "\nFound after " << count << " iterations" << endl;
	return 0;
}