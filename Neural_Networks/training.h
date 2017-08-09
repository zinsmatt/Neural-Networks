#ifndef TRAINING_H
#define TRAINING_H
#include <cmath>

class NeuralNet;

class Training
{
    int epochs;
    double error;
    double mse;

    double calcNewWeight(TrainingTypes trainType, double inputWeightOld, const NeuralNet& net, double error, double trainSample, double netValue);



    // Activation functions
    double fncStep(double val) {
        if(val<0)
            return 0;
        else if(val>=1)
            return 1;
        else
            return val;
    }

    double fncLinear(double val) {
        return val;
    }

    double fncSigLog(double val) {
        return 1/(1+exp(-val));
    }

    double fncHyperTan(double val) {
        return (1-exp(-val))/(1+exp(-val));
    }

    // Derivative of activation functions
    double derivativeFncStep(double val) {
        if(val < 0 || val >= 1)
            return 0;
        else
            return 1;
    }

    double derivativeFncLinear(double val) {
        return 1;
    }

    double derivativeFncSigLog(double val) {
        return exp(-val)/pow(1+exp(-val),2);
    }

    double derivativeFncHyperTan(double val) {
        return 2*exp(-val) / pow(1+exp(-val),2);
    }

public:
    Training();

    enum TrainingTypes{
        PERCEPTRON, ADALINE
    };

    enum ActivationFnc{
        STEP, LINEAR, SIGLOG, HYPERTRAIN
    };

    double activationFnc(ActivationFnc fnc, double value) const;
    double derivativeActivationFnc(ActivationFnc fnc, double value) const;

    void train(NeuralNet& n);
    void teachNeuronsOfLayer(int numberOfInputNeurons, int line, const NeuralNet& net, double netValue);


    void printTrainedNetResult(const NeuralNet& trainedNet);
    int getEpochs() const { return epochs; }
    void setEpochs(int e) { epochs = e; }
    double getError() const { return error; }
    void setError(double err) { error = err; }
    double getMSE() const { return mse; }
    double setMSE(double m) { mse = m; }

};

#endif // TRAINING_H
