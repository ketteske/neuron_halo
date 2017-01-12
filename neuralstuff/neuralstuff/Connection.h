#pragma once


#ifndef CONNECTION_H
#define CONNECTION_H

#include "Perceptron.h"

class Connection
{	//Getters laters!
	//Perceptron* connect_to;
	//Perceptron* connect_from;
	double weight;

public:
	Perceptron* left;
	Perceptron* right;

	// Constructor if layer are calculating the propagation
	Connection(Perceptron* aFrom, Perceptron* aTo, double w);

	// Update weight with the given delta weight
	void updateWeight(double aDeltaWeight);
	// Calculates the current connections output
	void activateOutput();
	// Shoot the perceptron effected
	void activateRightPerceptron();


	// Constuctor if neurons are connected calculating the propagation
	Connection(Perceptron* aTo, double w);
	// Return weight
	double getWeight();

	~Connection();
};

#endif 
