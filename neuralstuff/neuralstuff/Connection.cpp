#include "Connection.h"


#include <cstdlib>
#include <iostream>
#include <ctime>


Connection::Connection(Perceptron* aFrom, Perceptron* aTo, double aWeight)
{
	left = aFrom;
	right = aTo;

	weight = aWeight;
}


Connection::Connection(Perceptron* aTo, double aWeight)
{
	left = NULL;
	right = aTo;
	weight = aWeight;
}

void Connection::updateWeight(double aDeltaWeight){
	weight -= aDeltaWeight;
}

void Connection::activateOutput(){
	double activation = (left->getValue() * weight);
	right->increaseSum(activation);
}


void Connection::activateRightPerceptron(){
	right->activatePerceptron();
}

double Connection::getWeight(){
	return weight;
}

Connection::~Connection()
{
}
