#include "neuron.h"
#include <random>
#include <iostream>

using namespace std;

Neuron::Neuron()
{

}

Neuron::Neuron(int nbInputs) : numberOfInputs(nbInputs)
{
    weights.resize(numberOfInputs);
    input.resize(numberOfInputs);
}

Neuron::Neuron(int nbInputs, const ActivationFunction &af) : numberOfInputs(nbInputs), activationFunction(*af)
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
        uniform_real_distribution<double> distribution(0,1);
        for(int iter=0; iter<numberOfInputs; iter++)
            weights[iter] = distribution(generator);
    }

}

void Neuron::setInput(int i, double value)
{
    if(i>0 && i < inputs.size())
        inputs[i] = value;
    else
        cerr << "setInput: invalid index" << endl;
}

double Neuron::getInput(int i) const
{
    if(i>0 && i < inputs.size())
        return inputs[i];
    else
    {
        cerr << "neuron::getInput: invalid index" << endl;
        return 0;
    }
}

double Neuron::getWeight(int i) const
{
    if(i>0 && i<weight.size())
        return weight[i];
    else
    {
        cerr << "neuron::getWeight: invalid index" << endl;
        return 0;
    }
}

void Neuron::setWeight(int i, double value)
{
    if(i>0 && i<weights.size())
        weights[i] = value;
    else
        cerr << "neuron::updateWeights: invalid index" << endl;
}

void Neuron::calc()
{
    outputBeforeActivation = 0.0;
    if(numberOfInputs>0)
    {
        if(inputs.size() == numberOfInputs && weights.size()>0)
        {
            for(int iter = 0; iter < numberOfInputs; iter++)
            {
                outputBeforeActivation += inputs[i] * weight[i];
            }
            outputBeforeActivation += bias;
        }
    }
    output = activationFunction(outputBeforeActivation);    // call the activation function
    if(neuralLayer.getNeuralMode() == NeuralNet.NeuralNetMode.TRAINING)
        firstDerivative = activationFunctionderivative(outputBeforeActivation);     // if training, computes the derivative
}

double Neuron::calc(const vector<double> _inputs) const
{
    double temp_outputBeforeActivation = 0.0;
    if(numberOfInputs>0 && numberOfInputs == _inputs.size() && weights.size() == numberOfInputs)
    {
        for(int iter = 0; iter < numberOfInputs; iter++)
        {
            temp_outputBeforeActivation += _inputs[i] * weight[i];
        }
        temp_outputBeforeActivation += bias;
    }
    return activationFunction(temp_outputBeforeActivation);
}

double Neuron::derivative(const vector<double> &_inputs) const
{
    double temp_outputBeforeActivation = 0.0;
    if(numberOfInputs>0 && numberOfInputs == _inputs.size() && weights.size() == numberOfInputs)
    {
        for(int iter = 0; iter < numberOfInputs; iter++)
        {
            temp_outputBeforeActivation += _inputs[i] * weight[i];
        }
        temp_outputBeforeActivation += bias;
    }
    return activationFunction.derivative(temp_outputBeforeActivation);
}

vector<double> Neuron::calcBatch(const vector<vector<double> >& _inputs) const
{
    vector<double> results(0, _inputs.size());
    for(int iter=0; iter < results.size(); iter++)
    {
        results[iter] = this->calc(_inputs[iter]);
    }
    return results;
}

vector<double> Neuron::derivativeBatch(const vector<vector<double> > &_inputs) const
{
    vector<double> results(0, _inputs.size());
    for(int iter=0; iter < results.size(); iter++)
    {
        results[iter] = this->derivative(_inputs[iter]);
    }
    return results;
}
