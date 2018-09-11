#include <bits/stdc++.h>

using namespace std;

#define ll long double

ll f(ll x){
	return (ll)cos(x)+1;
}

int main(){

	ll x0, x1, x2;
	cin >> x0 >> x1;

	for(int i=0; abs(x1-x0) <= 1e-3L; i++){
		ll fx0 = f(x0);
		ll fx1 = f(x1);
		x2 = (x1*fx0 - x0*fx1) / (fx0 - fx1);
		x0 = x1;
		x1 = x2;
	}

	cout << x2 << endl;

}