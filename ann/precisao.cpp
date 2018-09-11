#include <bits/stdc++.h>

using namespace std;

long double dpow[1000];
long double dpat[1000];

long double fat(long exp){
	if(exp == 0 or exp == 1) return 1;
	return exp * fat(exp-1);
	if(dpat[exp] != -1) return dpat[exp];

	dpat[exp] = exp * fat(exp-1);

	cout << "fat>" << dpat[exp] << endl;

	return dpat[exp];
}

long double lpow(long double x, long exp){
	if(exp == 0) return 1;
	return x * lpow(x, exp-1);
	if(dpow[exp] != -1) return dpow[exp];
	dpow[exp] = x * lpow(x, exp-1);
	return dpow[exp];
}

long double calc(long double x, long exp){
	if(exp == 10) return 0;
	cout << "calc(" << x << "," << exp << ")" << endl;
	long double l = lpow(x, exp);
	long double f = fat(exp);
	cout << "l/f = " << l << " / " << f << " = ";
	long double res = (l / f);
	cout << res << endl;
	return res + calc(x, exp+1);

}

int main(void){
	memset(dpow, -1, sizeof(dpow));
	memset(dpat, -1, sizeof(dpat));
	float f = 0;
	long double d = 0;

	for(int i=0; i<1000; i++){
		f += 0.001f;
		d += 0.001;
	}
	cout << "somando 0.001" << endl;
	cout << "Precisao simples: " << f << endl;
	cout << "Precisao dupla: " << d << endl;

	f = 0;
	d = 0;

	for(int i=0; i<1000; i++){
		f += 0.0625f;
		d += 0.0625;
	}
	cout << "somando 0.0625" << endl;
	cout << "Precisao simples: " << f << endl;
	cout << "Precisao dupla: " << d << endl;

	cout << endl << endl;

	cout << 1.0/calc(5.0,0) << endl;

	return 0;

}