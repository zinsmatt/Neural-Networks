#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include "training.h"

class InputLayer;
class OutputLayer;
class HiddenLayer;

class NeuralNet
{
    InputLayer* inputLayer;
    OutputLayer* outputLayer;
    HiddenLayer* hiddenLayer;
    vector<HiddenLayer*> listOfHiddenLayer;
    int numberOfHiddenLayers;

    double learningRate;
    Training::ActivationFnc activationFnc;


public:
    NeuralNet();

    void initNet();
    void printNet() const;

    void setLearningRate(double rat) { learningRate = rate; }
    double getLearningRate() const { return learningRate; }

    void setActivationFnc(Training::ActivationFnc fnc) { activationFnc = fnc; }
    Training::ActivationFnc getActivationFnc() const { return activationFnc; }
};

#endif // NEURALNET_H
