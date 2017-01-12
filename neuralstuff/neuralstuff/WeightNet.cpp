#include "WeightNet.h"


WeightNet::WeightNet(int aNumberOfLayers, int aNumberOfNeurons)
{
	number_of_layers = aNumberOfLayers;
	number_of_neurons = aNumberOfNeurons;

	// Init the neuron array
	Neurons.resize(aNumberOfNeurons);
	int temp = 1;


	/*
	for (int ii = 0; ii < number_of_neurons; ii++){
		for (int jj = 0; jj < number_of_neurons; jj++){
			Neurons.at(ii).push_back(new Perceptron(INIT_VALUE+temp++,number_of_neurons));
		}
	}

	for (int ii = 0; ii < number_of_neurons; ii++){
		for (int jj = 0; jj < number_of_neurons; jj++){
			Temporal.push_back(new Perceptron(INIT_VALUE + temp++, number_of_neurons));
		}

		Neurons.push_back(Temporal);
		Temporal.clear();
	}
	*/

}

void WeightNet::forwardPropagation()
{
	// Evaluate through layers
	for (int ii = 0; ii < number_of_layers-1; ii++){
		calculateInput(Neurons.at(ii), &Neurons.at(ii++));
	}
}

void WeightNet::calculateInput(vector <Perceptron*> aCurrentlayer, vector <Perceptron*>* aNextLayer)
{
	double sum;
	
	// Going throgh all the neurons on the current layer
	for (int ii = 0; ii < number_of_neurons; ii++){
		sum = 0;

		// Generate sum for the current neuron 
		for (int jj = 0; jj < number_of_neurons; jj++){
			sum += 0; // aCurrentlayer.at(jj)->getWeightenedValue(jj);
		}

		// Limit the value of the neuron
		//aNextLayer->at(ii)->calculateValue(sum);
	}

}

void WeightNet::printMatrix(){
	cout << "Welcome, to the matrix!" << endl;
	
	vector< vector<Perceptron*> >::iterator row;
	vector<Perceptron*>::iterator col;
	for (row = Neurons.begin(); row != Neurons.end(); row++) {
		cout << endl;

		for (col = row->begin(); col != row->end(); col++) {
			cout << (*col)->getValue() << "  ";
		}
	}

#if 0
	for (int ii = 0; ii < number_of_neurons; ii++){
		cout << "----------------------------" << endl;
		for (int jj = 0; jj < number_of_neurons; jj++){
			cout << Neurons.at(jj).at(ii)->getValue() << " ";
		}
		cout << endl;
	}
#endif // 0

}

void WeightNet::printWeights(){
	cout << "Welcome, to the wheight!" << endl;

	for (int ii = 0; ii < number_of_neurons; ii++){

		for (int jj = 0; jj < number_of_neurons; jj++){
			cout << "";// Neurons.at(ii).at(jj)->getWeightenedValue(jj) << " ";
		}
		cout << endl;
	}
}

WeightNet::~WeightNet()
{
}
