//seminari9.hxx: Class for fractions. Is a template for diferent types of numbers (int, long, etc). 

#include <iostream>
#include <string>


template <class elementType>
class Fraction{
private:
	elementType _numerador;
	elementType _denominador;

public:
	//Constructor
	Fraction(elementType numerador, elementType denominador ){
		_numerador = numerador;
		_denominador = denominador;
	}

	//Get Numerator
	elementType getNumerator(){
		return _numerador;
	}

	//Get denominator
	elementType getDenominator(){
		return _denominador;
	}

	//Computes maximum common denominator
	elementType mcd(elementType a, elementType b){
		

		if(a%b == 0){
			return b;
		}
		else if(a%b >0){
			mcd(b, a%b);
		}
		else{
			printf("Error computing mcd\n");
			return -1;
		}
	}

	//Function that simplifies the fractions
	void simplify(){

		elementType mcd;
		mcd = this->mcd(this->getNumerator(), this->getDenominator());



			_numerador = _numerador/mcd;
			_denominador = _denominador/mcd;

	}

	//Operator + for fractions
	Fraction operator+(Fraction anotherFraction){
		elementType numerador, denominador;
		numerador = (_numerador * anotherFraction.getDenominator()) + (_denominador * anotherFraction.getNumerator());
		denominador = _denominador * anotherFraction.getDenominator();
		Fraction res = Fraction(numerador, denominador);
		res.simplify();
		return res;
	}

	//Operator * for fractions
	Fraction operator*( Fraction  anotherFraction){
		elementType numerador, denominador;
		numerador = _numerador * anotherFraction.getNumerator();
		denominador = _denominador * anotherFraction.getDenominator();
		Fraction res = Fraction(numerador, denominador);
		res.simplify();
		return res;
	}

	//Function to print a fraction
	void printFraction() {
		std::cout << std::to_string(_numerador) << "/" << std::to_string(_denominador)<< "\n";
	}
	
};