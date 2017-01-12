#include "NNetwork.h"

Network::Network(int aNumberOfHiddenLayers, int aNumberOfNeurons,
	int aBatch, int aEpoch){

	this->numberOfHiddenLayers = aNumberOfHiddenLayers;
	this->numberOfNeurons = aNumberOfNeurons;
	this->batch = aBatch;
	this->epoch = aEpoch;

	InputMatrix = NULL;
	LabelMatrix = NULL;

	// Init the random generator used later on
	srand((unsigned)time(0));
}


void Network::init(vector<vector<double> >* aInputs, 
	vector<vector<double> >* aLabels){
	
	// Setting matrices for training
	InputMatrix = aInputs;
	LabelMatrix = aLabels;

	// Used to locally store a layer while it is not loaded
	vector <Perceptron*> Temp;


	// Load and create input vector and layer
	Temp.clear();
	for (int jj = 0; jj < aInputs->at(0).size(); jj++){
		Temp.push_back(new Perceptron(1, jj));
	}
	MyNetwork.push_back(new Layer(Temp));
	// Input layer to be accessed easily
	InputLayer = MyNetwork.at(0);


	// Uploading the network with random input values
	double random_init = (rand() % 30) - 10;


	// Init the network: load perceptrons with random values into layers
	for (int ii = 0; ii < numberOfHiddenLayers; ii++){
		Temp.clear();
		for (int jj = 0; jj < numberOfNeurons; jj++){
			random_init = ACTIVATION_FUNCTION(((rand() % 30) - 10)*0.1); 
			// random number for init value + index value
			Temp.push_back(new Perceptron(random_init, jj));
		}
		MyNetwork.push_back(new Layer(Temp));
	}


	// Create outputLayer
	Temp.clear();
	for (int jj = 0; jj < aLabels->at(0).size(); jj++){
		Temp.push_back(new Perceptron(1, jj));
	}
	OutputLayer = new Layer(Temp);
	MyNetwork.push_back(OutputLayer);

	
	
	// Connect all available layers (input + hiddens + out )
	connectLayers();
}

void Network::connectLayers(){
	// Connecting all layers
	vector<Layer*>::iterator element;
	Layer* previous_element = NULL;

	for (element = MyNetwork.begin(); element != MyNetwork.end(); element++){

		// Each layer gets the next layers perceptrons to connect to
		if (previous_element != NULL){
			previous_element->connectToLayer((*element)->Perceptrons);

			previous_element->next = (*element);
			(*element)->previous = previous_element;
		}
		// Store element as previous
		previous_element = (*element);
	}
	
}


void Network::trainNetwork(){
	// Load inputs
	printLayers();

	double defined_error_rate = 0.1;
	double error_rate = 1;

	int number_of_iteration = 0 ;

	// Used only for a cleaner view
	vector<double>* NewInputs;
	vector<double>* NewLabels;

	vector<Perceptron*>::iterator element;

	for (int cycle = 0; cycle < epoch; cycle++){
		for (int iteration = 0; iteration < InputMatrix->size(); iteration++){
				
				// Load input layer and labels
				NewInputs = &(InputMatrix->at(iteration));
				NewLabels = &(LabelMatrix->at(iteration));
				// Update inputs
				InputLayer->changePerceptronsValue(NewInputs);

				//InputLayer->printOutPerceptronValues();
				//cout << "Desired: " << NewLabels->at(0);

				// Propagate forward
				startForwardPropagation();
				int overload = 0;
				while ((defined_error_rate < error_rate) && (overload < 100)){
					error_rate = 0;
					
					// Propagate backwards, desired outputs on the end
					OutputLayer->startBackPropagationRecursive(NewLabels);
					updateWeightsInLayers();
					startForwardPropagation();

					overload++;

					for (int ii = 0; ii < NewLabels->size();ii++){
						error_rate += abs(NewLabels->at(ii) - OutputLayer->Perceptrons.at(ii)->getValue());
					}
					error_rate = floor(error_rate * 1000)*0.001;
				}
				//InputLayer->printOutPerceptronValues();

				if (iteration%batch == 0){
					// Update weights only with given batch
					//updateWeightsInLayers();
				}
		}
	}

	cout << "\nTraining finished! \n";
}

void Network::calculateOutput(vector<double>* aInputs){

	cout << endl;
	cout << "Inputs:  ";
	for (int ii = 0; ii < aInputs->size(); ii++){
		cout << aInputs->at(ii) << "; ";
	}
	cout << endl;

	InputLayer->changePerceptronsValue(aInputs);
	startForwardPropagation();

	cout << "\nResults: ";
	InputLayer->printOutPerceptronValues();
	OutputLayer->printOutPerceptronValues();
	cout << "\n-------------------------\n";
}


void Network::startForwardPropagation(){

	// Going through all layers, which are linked together (Intelligent layers)
	Layer* MyLayer = (*MyNetwork.begin());
	while (MyLayer->next != NULL)
	{
		MyLayer->forwardPropagation();
		MyLayer = MyLayer->next;
	}
}


void Network::updateWeightsInLayers(){
	vector<Layer*>::iterator element;
	for (element = MyNetwork.begin(); element != MyNetwork.end(); element++){
		(*element)->updateWeightsRecursive();
	}
}


void Network::printLayers(){
	cout << "\nPrinting layers: ------------------";
	vector<Layer*>::iterator element;

	for (element = MyNetwork.begin(); element != MyNetwork.end(); element++){
		(*element)->printOutPerceptronValues();
	}
	cout << "\n---------------------------- Done!\n\n";
}


