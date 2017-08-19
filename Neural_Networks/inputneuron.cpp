#include "inputneuron.h"
#include "activationfunction.h"

InputNeuron::InputNeuron() : Neuron(1)
{
    setActivationFunction(ActivationFunction(ActivationFunction::LINEAR,1));
    bias = 0.0;
}

void InputNeuron::init()
{
    weights.clear();
    weights[0] = 1.0;
    weights[1] = 0.0;
}
