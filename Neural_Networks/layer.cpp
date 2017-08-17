#include "layer.h"
#include <iostream>

#include "neuron.h"
#include "neuralnet.h"

using namespace std;

Layer::Layer(NeuralNet *_neuralNet, int nbNeurons) : neuralNet(_neuralNet), numberOfNeuronsInLayer(nbNeurons)
{
    neurons.resize(numberOfNeuronsInLayer);
    output.resize(numberOfNeuronsInLayer);
}

Layer::Layer(NeuralNet *_neuralNet, int nbNeurons, const ActivationFunction &fnc) :
    neuralNet(_neuralNet), numberOfNeuronsInLayer(nbNeurons), activationFnc(fnc)
{
    neurons.resize(numberOfNeuronsInLayer);
    output.resize(numberOfNeuronsInLayer);

}

Neuron* Layer::getNeuron(int i) const
{
    if(i>0 && i<neurons.size())
        return neurons[i];
    else
        return NULL;
}

void Layer::setNeuron(int i, Neuron *_neuron)
{
    if(i>0 && i<neurons.size())
    {
        neurons.insert(neurons.begin()+i, _neuron);
    }else
    {
        neurons.push_back(_neuron);
    }
    numberOfNeuronsInLayer++;   // not sure
}

void Layer::init()
{
    for(int iter=0; iter<numberOfNeuronsInLayer; iter++)
    {
        neurons[iter]->setActivationFunction(activationFnc);
        neurons[iter]->setNeuralLayer(this);
        neurons[iter]->init();
    }
}

void Layer::setInputs(const std::vector<double>& _inputs)
{
    input = _inputs;
    numberOfInputs = input.size();
}

void Layer::calc()
{
    if(input.size()>0 && neurons.size()>0)
    {
        for(int iter=0; iter < numberOfNeuronsInLayer; iter++)
        {
            neurons[iter]->setInputs(input);
            neurons[iter]->calc();
            output[iter] = neurons[iter]->getOutput();
        }
    }
}

double Layer::getWeight(int weightIndex, int neuronIndex) const
{
    if(neuronIndex>0 && neuronIndex<neurons.size())
    {
        return neurons[neuronIndex]->getWeight(weightIndex);
    }else
    {
        cerr << "Layer::getWeight: invalid neuron index" << endl;
        return 0;
    }
}

void Layer::deactivateBias()
{
    for(Neuron* pt : neurons)
        pt->deactivateBias();
}

void Layer::activateBias()
{
    for(Neuron* pt : neurons)
        pt->activateBias();
}

bool Layer::isBiasActive() const
{
    if(neurons.size()>0)
        return neurons[0]->getBias() == 1.0;
    else
        return false;
}
