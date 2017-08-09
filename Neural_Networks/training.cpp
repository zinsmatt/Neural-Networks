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


void Training::train(NeuralNet &n)
{
    vector<double> inputWeightIn;
    int rows = n.getTrainSet().length();
    int cols = n.getTrainSet()[0].length();

    while(epochs < n.getMaxEpochs())
    {
        double estimatedOutput = 0.0;
        double realOutput = 0.0;

        for(int i=0;i<rows;i++)
        {
            double netValue = 0.0;

            for(int j=0;j<cols;j++)
            {
                inputWeightIn = n.getInputLayer().getListOfNeurons().get(j).getListOfWeightIn();
                double inputWeight = inputWeightIn.get(0);
                netValue = netValue + inputWeight * n.getTrainSet()[i][j];
            }

            estimatedOutput = activationFnc(n.getActivationFnc(), netValue);
            realOutput = n.getRealOutputSet()[i];

            error = realOutput - estimatedOutput;

            if(abs(error) > n.getTargetError)
            {
                InputLayer inputLayer
            }
        }

    }

}
