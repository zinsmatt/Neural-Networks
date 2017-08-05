#ifndef TRAINING_H
#define TRAINING_H
#include <cmath>

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
};

#endif // TRAINING_H
