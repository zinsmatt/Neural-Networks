#include "outputlayer.h"

OutputLayer::OutputLayer(NeuralNet *_neuralnet, int numberofneurons, ActivationFunction fnc, int numberofinputs) :
    Layer(_neuralnet, numberofneurons, fnc), numberOfInputs(numberofinputs)
{
    nextLayer = NULL;
    init();
}


OutputLayer::OutputLayer(NeuralNet *_neuralnet, int numberofneurons, ActivationFunction fnc, Layer* prev) :
    Layer(_neuralnet, numberofneurons, fnc)
{
    setPreviousLayer(prev);
    nextLayer = NULL;
    numberOfInputs = previousLayer->getNumberOfNeuronsInLayer();
    init();
}

void OutputLayer::setNextLayer(Layer *next)
{
    nextLayer = NULL;
}

void OutputLayer::setPreviousLayer(Layer *prev)
{
    previousLayer = prev;
    prev->setNextLayer(this);
}
