#include "fract.hpp"

int main(){
	Fraction * a = new Fraction(1, 3);
	Fraction * b = new Fraction(4, 6);
	Fraction aa = *a;
	Fraction bb = *b;
	/*cout << a->mul(*b)->show() << endl;
	cout << a->add(*b)->show() << endl;
	cout << a->sub(*b)->show() << endl;
	*/
	cout << (aa*bb)->show() << endl;
	cout << (aa+bb)->show() << endl;
	cout << (bb+5)->show() << endl;
	cout << (*(aa*bb)+5)->show() << endl;
}