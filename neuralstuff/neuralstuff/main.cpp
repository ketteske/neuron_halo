#include <iostream>
#include "NNetwork.h"
#include "reader.h"

using namespace std;


int main()
{
    cout << "Hello world!" << endl;

	vector<vector<double>>bigInput;
	vector<double> temporaly;

	vector<vector<double>>bigLabel;
	vector<double> temporaly2;


	// Inputs
	temporaly.push_back(-1);
	temporaly.push_back(-1);
	bigInput.push_back(temporaly);
	temporaly.clear();

	temporaly.push_back(1);
	temporaly.push_back(-1);
	bigInput.push_back(temporaly);
	temporaly.clear();

	temporaly.push_back(-1);
	temporaly.push_back(1);
	bigInput.push_back(temporaly);
	temporaly.clear();

	temporaly.push_back(1);
	temporaly.push_back(1);
	bigInput.push_back(temporaly);
	temporaly.clear();


	// Desired
	temporaly2.push_back(-1);
	bigLabel.push_back(temporaly2);
	temporaly2.clear();

	temporaly2.push_back(-1);
	bigLabel.push_back(temporaly2);
	temporaly2.clear();

	temporaly2.push_back(-1);
	bigLabel.push_back(temporaly2);
	temporaly2.clear();

	temporaly2.push_back(1);
	bigLabel.push_back(temporaly2);
	temporaly2.clear();

	
	vector<double>Example;
	Example.push_back(-1);
	Example.push_back(-1);

	vector<double>Example2;
	Example2.push_back(1);
	Example2.push_back(-1);

	vector<double>Example3;
	Example3.push_back(-1);
	Example3.push_back(1);

	vector<double>Example4;
	Example4.push_back(1);
	Example4.push_back(1);

	int numberOfHiddenLayers = 5;
	int numberOfNeurons = 3;
	int batch = 1;
	int epoch = 5;

	try{
		Network* MyNewNetwork = new Network(numberOfHiddenLayers, numberOfNeurons, batch, epoch);
		MyNewNetwork->init(&bigInput, &bigLabel);
		MyNewNetwork->trainNetwork();
		
		MyNewNetwork->calculateOutput(&Example);
		MyNewNetwork->calculateOutput(&Example2);
		MyNewNetwork->calculateOutput(&Example3);
		MyNewNetwork->calculateOutput(&Example4);
		
	}
	catch(...){
		cout << "Error there...";
	}
	
	//cout << "\nLoading files...";

	//string filename = "C:\\Users\\borda\\Documents\\visual studio 2013\\Projects\\neuralstuff\\neuralstuff\\mnist\\train-images.idx3-ubyte";
	//file_read_it_now(filename);
	cout << "\nDone!";
    return 0;

}

