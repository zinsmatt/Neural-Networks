#include "hiddenlayer.h"

using namespace std;

HiddenLayer::HiddenLayer(NeuralNet *_neuralNet, int numberofneurons, ActivationFunction fnc, int numberofinputs):
    Layer(_neuralNet, numberofneurons, fnc)
{
    numberOfInputs = numberofinputs;
    init();
}

void HiddenLayer::setPreviousLayer(Layer *prev)
{
    previousLayer = prev;
    if(previousLayer->getNextLayer() != this)
        previousLayer->setNextLayer(this);
}

void HiddenLayer::setNextLayer(Layer *next)
{
    nextLayer = next;
    if(nextLayer->getPreviousLayer() != this)
        nextLayer->setPreviousLayer(this);
}
