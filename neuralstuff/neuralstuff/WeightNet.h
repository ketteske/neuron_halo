#pragma once

#include "Global_header.h"
#include "Perceptron.h"

class WeightNet
{
	vector <vector<Perceptron*>> Neurons;

	int number_of_neurons;
	int number_of_layers;
	int INIT_VALUE = 1;

	void calculateInput(vector <Perceptron*> aCurrentLayer, vector <Perceptron*> *aNextLayer);

public:
	// Create new weight matrix, by adding the number of layers, and number of neurons
	WeightNet(int aNumberOfLayers, int aNumberOfNeurons);
	
	void forwardPropagation();
	void printMatrix();
	void printWeights();
	~WeightNet();
};

