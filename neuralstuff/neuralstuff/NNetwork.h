/*
 * network.h
 *
 *      Author: Boross David
 */
#pragma once

#include "Layer.h"
#include <ctime> 
#include <random>


class Network{
public:
	// Weight matrix, containing all weights for each layer of neurons
	vector<vector<Perceptron*>> PerceptronMatrix;
	vector<Layer*> MyNetwork;

	// For training
	vector <vector<double>>* InputMatrix;
	vector <vector<double>>* LabelMatrix;

	//vector <Perceptron*> OutputLayer;
	Layer* InputLayer;
	Layer* OutputLayer;

	double default_perceptron_value = 1;
	int numberOfHiddenLayers;
	int numberOfNeurons;
	int batch;
	int epoch;
	//const int kNumberOf
	//Neurons = 10;
	//const int kNumberOfWeights = 10;

	// NumberOfHiddenLayers,  NumberOfNeurons,  Batch, Epoch
	Network(int aNumberOfHiddenLayers, int aNumberOfNeurons, int aBatch, 
		int aEpoch);
	~Network();

	// Connect all layers together
	void connectLayers();

	// Start something
	void init(vector<vector<double> >* aInputs, vector<vector<double>> *aDesiredOutput);

	// Forward propagation
	void startForwardPropagation();

	void printLayers();
	// Build up network

	void updateWeightsInLayers();

	void calculateOutput(vector<double>* aInputs);

	void trainNetwork();

};

