#include "Global_header.h"

double activationFunction(double input){
	double temp = tanh(input);
	cout << "here i am  ";
	cout << temp;
	return temp;
}

double dactivationFunction(double input){
	double temp = 1 / (1 + exp(-input));
	return temp;
}