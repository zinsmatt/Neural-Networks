#include "training.h"
#include "neuralnet.h"
#include <exception>

using namespace std;

Training::Training()
{

}

double Training::calcNewWeight(TrainingTypes trainType, double inputWeightOld, const NeuralNet& net, double error, double trainSample, double netValue)
{
    switch(trainType)
    {
    case PERCEPTRON:
        return inputWeightOld + net.getLearningRate() * error * trainSample;
    case ADALINE:
        return inputWeightOld + net.getLearningRate() * error * trainSample * derivativeActivationFnc(net.getActivationFnc(), netValue);
    default:
        throw invalid_argument("unknown training type");
    }
}


double Training::activationFnc(ActivationFnc fnc, double value) const
{
    switch (fnc)
    {
    case STEP:
        return fncStep(value);
    case SIGLOG:
        return fncSigLog(value);
    case LINEAR:
        return fncLinear(value);
    case HYPERTRAIN:
        return fncHyperTan(value);
    default:
        throw invalid_argument("unknown activation function");
    }
}

double Training::derivativeActivationFnc(ActivationFnc fnc, double value) const
{
    switch (fnc)
    {
    case STEP:
        return derivativeFncStep(value);
    case SIGLOG:
        return derivativeFncSigLog(value);
    case LINEAR:
        return derivativeFncLinear(value);
    case HYPERTRAIN:
        return derivativeFncHyperTan(value);
    default:
        throw invalid_argument("unknown derivative activation function");
    }
}
