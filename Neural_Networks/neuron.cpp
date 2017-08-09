#include "neuron.h"
#include <random>

using namespace std;

Neuron::Neuron()
{

}

Neuron::Neuron(int nbInputs) : numberOfInputs(nbInputs)
{
    weigths.resize(numberOfInputs);
    input.resize(numberOfInputs);
}

Neuron::Neuron(int nbInputs, ActivationFunction af) : numberOfInputs(nbInputs), activationFunction(af)
{
    weigths.resize(numberOfInputs);
    input.resize(numberOfInputs);
}

double Neuron::init()
{
    if(numberOfInputs>0)
    {
        random_device rd;
        default_random_engine generator(rd);
        uniform_real_distribution distribution(0,1);
        for(int iter=0; iter<numberOfInputs; iter++)
            weights[iter] = distribution(generator);
    }

}
