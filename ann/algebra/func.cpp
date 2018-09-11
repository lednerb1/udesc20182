#include "includes.hpp"

int getInt(string a){
	int ret=0;
	int negate = 1;
	int i=0;
	if(a[0] == '-'){
		negate = -1;
		i=1;
	}
	for(;i<a.size();i++){
		ret += (a[i]-'0')*pow(10,a.size()-i-1);
	}
	return ret*negate;
}

Fraction * parseInput(){
	Fraction * ret;
	vector<int> parts;
	vector<string> splits;
	string input;
	cout << "aqui\n";
	cin >> input;
	cout << 'a';
	int i=0;
	int d=0;

	splits.push_back("");

	for(auto c : input){
		
		if(c == '/'){
			d++;
			splits.push_back("");
		}else{
			splits[d] += c;
		}
		i++;
	}


	if(splits.empty()){
		return new Fraction(getInt(input), 1);
	}
	string saida;
	sscanf(splits[0].c_str(), "%[^/]s", saida);
	cout << saida << " teste\n";

	return ret;

}