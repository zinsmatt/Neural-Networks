#include "inputlayer.h"
#include "activationfunction.h"
#include "inputneuron.h"

using namespace std;

InputLayer::InputLayer(NeuralNet* _neuralNet, int _numberOfInputs) : Layer(_neuralNet,_numberOfInputs, Linear(1.0))
{
    previousLayer = NULL;
    numberOfInputs = _numberOfInputs;
    init();
}

void InputLayer::setNextLayer(Layer *next)
{
    nextLayer = next;
    if(nextLayer->getPreviousLayer() != this)
        nextLayer->setPreviousLayer(this);
}

void InputLayer::setPreviousLayer(Layer *prev)
{
    previousLayer = null;
}

void InputLayer::init()
{
    for(int iter=0; iter<numberOfInputs; iter++)
    {
        setNeuron(iter, new InputNeuron);
        getNeuron(iter)->setNeuralLayer(this);
        getNeuron(iter)->init();
    }
}

void InputLayer::setInputs(const std::vector<double> &_inputs)
{
    if(_inputs.size() == numberOfInputs)
        input = _inputs;
}

void InputLayer::calc()
{
    if(input.size()>0 && neurons.size()>0)
    {
        for(int iter=0; iter<numberOfNeuronsInLayer; iter++)
        {
            vector<double> in = {input[iter]};
            Neuron* n = getNeuron(iter);
            n->setInputs(in);
            n->calc();
            output[iter] = n->getOutput();
        }
    }
}
