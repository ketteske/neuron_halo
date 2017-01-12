#include "Perceptron.h"


Perceptron::Perceptron(double aValue, int aIndex)
{
	value = aValue;
	index = aIndex;
	bias = 1;

	clearSum();
	activation_value = 0;
	gradient = 0;
	increase_gradient = 0;

}

void Perceptron::calculateValue(double aSum){
	double temp = aSum + bias;
	value = ACTIVATION_FUNCTION(temp);

}

double Perceptron::getValue(){
	return value;
}


void Perceptron::increaseSum(double aSum){
	inputSum += aSum;
}

void Perceptron::clearSum(){
	inputSum = 0;
}

void Perceptron::activatePerceptron(){
	calculateValue(inputSum);
	activation_value = inputSum;
	clearSum();
}


void Perceptron::toString(){
	cout << getValue() << " ";
}

int Perceptron::getIndex(){
	return index;
}

double Perceptron::getGradient(){
	return gradient;
}

void Perceptron::setGradient(double aNewGradient){
		//increase_gradient++;
		gradient = aNewGradient;
}

double Perceptron::getActivationValue(){
	return activation_value;
}

double Perceptron::getDerivatedActivation(){
	double temp = DACTIVATION_FUNCTION(ACTIVATION_FUNCTION(getValue()));
	return temp;
}


void Perceptron::setValue(double aNewValue){
	value = aNewValue;
}

Perceptron::~Perceptron()
{
}



void Perceptron::connectTo(Perceptron* otherPerceptron, double weight){
	// Adding new connection
	//Connections.push_back(new Connection(otherPerceptron, weight));
}

void Perceptron::activateConnectedPerceptrons(){
	//vector<Connection*>::iterator connected;
	//double energy;
	//// Activating all connected perceptrons with amount energy
	//for (connected = Connections.begin(); connected != Connections.end(); connected++) {
	//// xi * wi
	//	energy = value * (*connected)->getWeight();
	//	(*connected)->right->increaseSum(energy);
	//}
}