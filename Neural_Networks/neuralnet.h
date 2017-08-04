#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>

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

public:
    NeuralNet();

    void initNet();
    void printNet() const;
};

#endif // NEURALNET_H
