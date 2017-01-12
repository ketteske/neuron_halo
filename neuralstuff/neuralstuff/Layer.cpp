#include "Layer.h"


Layer::Layer(vector <Perceptron*> aConnections)
{
	Perceptrons = aConnections;
}


void Layer::forwardPropagation(){
	if (StimulatedPercetrons.size() == 0){
		cout << "\nERROR!! No stimulated perceptrons!\n";
	}
	else {
		vector<Connection*>::iterator contact;
		for (contact = Contacts.begin(); contact != Contacts.end(); contact++) {
			// (x*w)
			(*contact)->activateOutput();
		}

		vector<Perceptron*>::iterator perceptron;
		for (perceptron = StimulatedPercetrons.begin(); perceptron != StimulatedPercetrons.end(); perceptron++) {
			// function(sum(x*w))
			(*perceptron)->activatePerceptron();
		}
	}
	
}


void Layer::connectToLayer(vector <Perceptron*> aToPerceptrons){
	vector<Perceptron*>::iterator left;
	vector<Perceptron*>::iterator right;

	double random_weight = (rand() % 30) - 10;

	for (left = Perceptrons.begin(); left != Perceptrons.end(); left++) {
		for (right = aToPerceptrons.begin(); right != aToPerceptrons.end(); right++) {
			random_weight = ((rand() % 30) - 10)*0.1;
			//cout << random_weight << "; ";
			Contacts.push_back(new Connection((*left), (*right), random_weight));
		}
	}

	StimulatedPercetrons = aToPerceptrons;
}


void Layer::printOutPerceptronValues(){
	vector<Perceptron*>::iterator element;
	cout << endl;
	for (element = Perceptrons.begin(); element != Perceptrons.end(); element++){
		(*element)->toString();
	}
}


double Layer::sumActivation(Perceptron* aTarget){
	double output = 0;

	vector<Connection*>::iterator contact;
	for (contact = Contacts.begin(); contact != Contacts.end(); contact++){ 
		if ((*contact)->right == aTarget){
			output+=((*contact)->getWeight());
		}
	}
	return output;
}


void Layer::startBackPropagationRecursive(vector <double>* aDesiredOutput){

	double delta = 0;
	//cout << "\nStarting backpropagation!-----------------";
	// If there is no next layer, it is the output layer
	// delta = e_j * f'(v_j)
	for (int ii = 0; ii < Perceptrons.size(); ii++){
		delta = (aDesiredOutput->at(ii) - Perceptrons.at(ii)->getValue());
		delta *= Perceptrons.at(ii)->getDerivatedActivation();
		Perceptrons.at(ii)->setGradient(delta);
		//cout << "\nGrad: " << delta;
	}
	//cout << "\nFInished backpropagation! ----------------\n";

	if (previous == NULL)
	{	
		cout << "\nHouston, we have a problem...!\n";
	}
	else {
		previous->backPropagate();
	}
}


void Layer::backPropagate(){
	double delta = 0;
	double error = 0;
	
	vector<Connection*>::iterator contact;
	vector<Connection*>::iterator inside;

	// Calculate all gradients for the given percetron
	// delta_j = f'(v_j) * sum ( delta_k * w_kj )
	for (contact = Contacts.begin(); contact != Contacts.end(); contact++){
		for (inside = Contacts.begin(); inside != Contacts.end(); inside++){
			if ((*contact)->left == (*inside)->left){
				// sum delta_k * w_kj
				delta += (*inside)->right->getGradient();
				delta *= (*inside)->getWeight(); 
			}
		}
		// fi' * sum( delta_k * w_kj )
		delta *= (*contact)->left->getDerivatedActivation();
		(*contact)->left->setGradient(delta);
	}
	if (previous != NULL){
		previous->backPropagate();
	}
	//else {
	//	cout << "\nFinished an epoch! \n";
	//}
}


void Layer::updateWeightsRecursive()
{
	double delta_weight = 0;

	vector<Connection*>::iterator contact;
	for (contact = Contacts.begin(); contact != Contacts.end(); contact++){
		delta_weight = (*contact)->right->getGradient();
		//delta_weight *= ACTIVATION_FUNCTION((*contact)->right->getValue());
		delta_weight *= ((*contact)->right->getValue());
		delta_weight *= LEARNING_RATE;
		(*contact)->updateWeight(delta_weight);
	}
	
	//cout << "\nWeight updated by:" << delta_weight;
}


void Layer::changePerceptronsValue(vector <double>* aNewValues){
	for (int ii = 0; ii < Perceptrons.size(); ii++){
		Perceptrons.at(ii)->setValue(aNewValues->at(ii));
	}
}


Layer::~Layer()
{
}

void Layer::calculateError(Layer* aResults, vector<int> aExpectedR){

	vector <double> difference;
	//vector<Perceptron*>::iterator element; <<<<<<<?????????????

	for (int ii = 0; ii < Perceptrons.size(); ii++){
		difference.push_back(Perceptrons.at(ii)->getValue() - aExpectedR.at(ii));
	}

	//for (element = Perceptrons.begin(); element != Perceptrons.end(); element++){
	//	(*element)->getValue();
	//}
}
