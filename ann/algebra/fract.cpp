#include "includes.hpp"

Fraction::Fraction(int up, int dw){
	if(dw == 0 or up == 0) dw = 1;
	for(int i = min(abs(up),abs(dw)); i>0; i--){
		if(up % i == 0 and dw % i == 0){
			up /= i; dw /= i;
			break;
		}
	}
	if(up < 0 and dw < 0){
		up *= -1;
		dw *= -1;
	}
	this->up = up;
	this->dw = dw;
}

Fraction::Fraction(Fraction * a, Fraction * b){
	cout << "Created : " << a->show() << " / " << b->show() << endl;
	Fraction * tmp = *a / *b;
	this->up = tmp->up;
	this->dw = tmp->dw;
	free(tmp);
}

Fraction * Fraction::add(Fraction& o){
	int tdw = this->dw;
	int odw = o.dw;
	
	if(tdw == odw){
		return new Fraction(this->up+o.up, this->dw);
	}

	int up = this->up*o.dw;
	int dw = this->dw*o.dw;
	up += o.up*this->dw;

	return new Fraction(up, dw);
}

Fraction * Fraction::add(int o){
	return new Fraction(this->up+o*this->dw, this->dw);
}

Fraction * Fraction::sub(Fraction& o){
	int tdw = this->dw;
	int odw = o.dw;
	
	if(tdw == odw){
		return new Fraction(this->up-o.up, this->dw);
	}

	int up = this->up*o.dw;
	int dw = this->dw*o.dw;
	up -= o.up*this->dw;

	return new Fraction(up, dw);
}

Fraction * Fraction::sub(int o){
	return new Fraction(this->up-o*this->dw, this->dw);
}

Fraction * Fraction::mul(Fraction& o){
	return new Fraction(this->up*o.up, this->dw*o.dw);
}

Fraction * Fraction::mul(int o){
	return new Fraction(this->up*o, this->dw);
}

Fraction * Fraction::div(Fraction& o){
	//if(this->dw == 1 and o.dw == 1){
	//	return new Fraction(this->up, o->up);
	//}
	return new Fraction(this->up*o.dw, this->dw*o.up);
}

Fraction * Fraction::div(int o){
	return new Fraction(this->up/o, this->dw);
}

int Fraction::getInt(){
	return (int)this->up/this->dw;
}

float Fraction::getFloat(){
	return (float)this->up/this->dw;
}

double Fraction::getDouble(){
	return (double)this->up/this->dw;
}

string Fraction::show(){
	if(this->up == this->dw) return "1";
	if(this->dw == 1) return to_string(this->up);
	return (to_string(this->up) + "/" + to_string(this->dw));
}

Fraction * Fraction::operator+(Fraction& o){
	return this->add(o);
}

Fraction * Fraction::operator+(int o){
	return this->add(o);
}

Fraction * Fraction::operator-(Fraction& o){
	return this->sub(o);
}

Fraction * Fraction::operator-(int o){
	return this->sub(o);
}

Fraction * Fraction::operator*(Fraction& o){
	return this->mul(o);
}

Fraction * Fraction::operator*(int o){
	return this->mul(o);
}

Fraction * Fraction::operator/(Fraction& o){
	return this->div(o);
}

Fraction * Fraction::operator/(int o){
	return this->div(o);
}
