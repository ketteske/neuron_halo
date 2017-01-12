#pragma once

#include "Connection.h"
#include "Perceptron.h"
#include "Global_header.h"

class Layer
{
	vector <Connection*> Contacts;
	vector <Perceptron*> StimulatedPercetrons;

	double default_weight_value = 1;
	// Back propagate automaticly
	void backPropagate();

public:
	Layer(vector <Perceptron*> Perceptrons);

	// Store perceptrons in the layer TODO create getter
	vector <Perceptron*> Perceptrons;
	Layer * next;
	Layer * previous;

	// Propagete forward
	void forwardPropagation();
	// Connect all perceptrons in the layer to the one in parameter
	void connectToLayer(vector <Perceptron*> aPerceptrons);
	// Connect to  layers
	void connectLayerToLayer(Layer * prev, Layer * next);

	double sumActivation(Perceptron* Target);

	///BACK PROPAGATION
	// Calculate output error
	void calculateError(Layer* aResults, vector<int> aExpectedR);

	// Init the backpropagation algorithm
	void startBackPropagationRecursive(vector <double>* aDesiredOutput);
	// Update weight of the layers
	void updateWeightsRecursive();

	// Connect to perceptrons to each other
	void connectNeurons(Layer * L1);
	// Print out preceptron values
	void printOutPerceptronValues();
	// 
	void changePerceptronsValue(vector <double> *aNewValues);

	~Layer();
};

