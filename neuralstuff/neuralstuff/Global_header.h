#pragma once

#include <iostream>
#include <vector>
using namespace std;

//#define ACTIVATION_FUNCTION(sum)	sum < 1 ? -1:1
//#define DACTIVATION_FUNCTION(sum)	sum < 1 ? -1:1
#define LEARNING_RATE	0.13

#define ACTIVATION_FUNCTION(MYVALUE)	(tanh(MYVALUE))
//#define DACTIVATION_FUNCTION(MYVALUE)	(1-(tanh(MYVALUE)*tanh(MYVALUE)))
#define DACTIVATION_FUNCTION(MYVALUE)	((1-MYVALUE)*(1+MYVALUE))

//#define ACTIVATION_FUNCTION(MYVALUE)	(1/(1+exp(-MYVALUE)))
//#define DACTIVATION_FUNCTION(MYVALUE)	(ACTIVATION_FUNCTION(MYVALUE)*(1 - ACTIVATION_FUNCTION(MYVALUE)))
//#define ACTIVATION_FUNCTION(MYVALUE)	activationFunction(MYVALUE)
double activationFunction(double input);
double dactivationFunction(double input);