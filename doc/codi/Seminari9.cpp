// Seminari9.cpp: Main class for testing the template class.
//

#include "stdafx.h"
#include "seminari9.hxx"


int main()
{
	printf("<<Initializing app>>\n \n");

	printf("Testing unsigned int type with sum....\n");
	Fraction<unsigned int> f1 = Fraction<unsigned int>(1, 4); // Here define the first fraction
	Fraction<unsigned int> f2 = Fraction<unsigned int>(1, 4); // Here define the second fraction

	Fraction<unsigned int> f3 = f1 + f2; //Here the operation to sum the fractions
	printf("Fraction 1: ");
	f1.printFraction();
	printf(" Fraction 2: ");
	f2.printFraction();
	printf("\n Result: ");
	f3.printFraction();
	printf("\n");

	printf("Testing long int type with multiplication\n");
	Fraction<long> f4 = Fraction<long>(5, 2); // Here define the first fraction
	Fraction<long> f5 = Fraction<long>(1, 9); // Here define the second fraction

	Fraction<long> f6 = f4 * f5; //Here the operation to multiply the fractions
	printf("Fraction 1: ");
	f4.printFraction();
	printf(" Fraction 2: ");
	f5.printFraction();
	printf("\n Result: ");
	f6.printFraction();
	printf("\n");
	printf("<<Closing app>>");
	

}

