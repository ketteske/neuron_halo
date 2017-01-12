#pragma once
/*
This file contains the class object definition of a single
perceptron.
*/
#include "Global_header.h"



/*
class MyConnectifaon{
	Perceptron * connected_perceptron;
	double weight;
};
*/

class Perceptron
{
	// The neurons value 
	double value;
	// Other perceptrons effect on this perceptron
	double inputSum;
	// Connected neurons
	//vector <Connection*> Connections;

	// Bias value
	double bias;

	//
	int index;

	// Gradient used for calculatin back propagation (fi)
	double gradient;
	int increase_gradient;

	// Used also for back propagation (v_i)
	double activation_value;

	// Calculate final value
	void calculateValue(double aSum);

	// Clear inputSum
	//void clearSum();

public:
	Perceptron(double aValue, int aIndex);
	~Perceptron();

	// Get the perceptrons value
	double getValue();
	// Clear inputSum
	void clearSum();
	// Increase perceptron input
	void increaseSum(double inc);
	// Activate perceptron (calculate value) in base of inputSum
	void activatePerceptron();

	// USED ONL IF PERCEPTRONS ARE CONTAINING CONNECTIONS
	// Create a connection to an other perceptron
	void connectTo(Perceptron* otherPerceptron, double weight);
	// Active connected neuron
	void activateConnectedPerceptrons();

	// Get and set gradient
	double getGradient();
	void setGradient(double aNewGradient);

	// Get stored activation value
	double getActivationValue();
	// Derivative of the activation function, return the G(v)
	double getDerivatedActivation();
	// Update weights
	void updateWeights(double aDeltaWeight);
	// Prints the perceptrons value
	void toString();
	// Get index 
	int getIndex();
	// set perceptrons value
	void setValue(double aNewValue);

	/*
	double getWeightenedValue(int aNextPerceptron);
	void connectTo(Perceptron* aPerceptron);
	void addWeight(double aWeightValue, int aPerceptronIndex);
	*/
};

