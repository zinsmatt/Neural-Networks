#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include "training.h"
#include "activationfunction.h"

class Layer;
class InputLayer;
class OutputLayer;
class HiddenLayer;

class NeuralNet
{

protected:
    InputLayer* inputLayer;
    std::vector<HiddenLayer*> hiddenLayers;
    OutputLayer* outputLayer;

    int numberOfHiddenLayers;
    int numberOfInputs;
    int numberOfOutputs;

    std::vector<double> input;
    std::vector<double> output;
    std::vector<int> numberOfNeuronsInHiddenLayers;
    std::vector<int> indexesWeightPerLayer;
    bool activeBias;

public:
    enum NeuralNetModeENUM {
        BUILD, TRAINING, RUN
    };

protected:
    NeuralNetModeENUM neuralNetMode = BUILD;

    double learningRate;
    Training::ActivationFnc activationFnc;

public:
    NeuralNet(int numberofinputs, int numberofoutputs, const std::vector<int>& nbInHiddenLayers,
              const std::vector<ActivationFunction*> hiddenAcFnc, ActivationFunction outputAcFnc);

    NeuralNet(int numberofinputs, int numberofoutputs, ActivationFunction outputAcFnc);

protected:
    NeuralNet() : activeBias(true) {}

public:

    /**
     * @brief setInputs
     * @param _inputs
     */
    void setInputs(const std::vector<double>& _inputs) { input = _inputs; }

    /**
     * @brief getInputs
     * @return
     */
    const std::vector<double>& getInputs() const { return input; }

    /**
     * @brief getOutputs
     * @return
     */
    const std::vector<double>& getOutputs() const { return output; }

    /**
     * @brief getOutput
     * @param idx
     * @return
     */
    double getOutput(int idx) const;

    /**
     * @brief print
     */
    void print() const;

    /**
     * @brief getNumberOfHiddenLayers
     * @return
     */
    int getNumberOfHiddenLayers() const { return numberOfHiddenLayers; }

    /**
     * @brief getNumberOfInputs
     * @return
     */
    int getNumberOfInputs() const { return numberOfInputs; }

    /**
     * @brief getNumberOfOutputs
     * @return
     */
    int getNumberOfOutputs() const { return numberOfOutputs; }

    /**
     * @brief getInputLayer
     * @return
     */
    InputLayer* getInputLayer() const { return inputlayer; }

    /**
     * @brief getOutputLayer
     * @return
     */
    OutputLayer* getOutputLayer() const { return outputLayer; }

    /**
     * @brief getHiddenLayers
     * @return a vector of pointers to the hidden layers
     */
    const std::vector<HiddenLayer*>& getHiddenLayers() const { return hiddenLayers; }

    /**
     * @brief getHiddenLayer
     * @param idx
     * @return
     */
    HiddenLayer* getHiddenLayer(int idx) const;

    /**
     * @brief deactivateBias
     */
    void deactivateBias();

    /**
     * @brief activateBias
     */
    void activateBias();

    /**
     * @brief isBiasActive
     * @return
     */
    bool isBiasActive() const { return activeBias; }

    /**
     * @brief setNeuralNetMode
     * @param _mode
     */
    void setNeuralNetMode(NeuralNetModeENUM _mode) { neuralNetMode = _mode; }

    /**
     * @brief getNeuralNetMode
     * @return
     */
    NeuralNetModeENUM getNeuralNetMode() const { return neuralNetMode; }



    void initNet();
    void printNet() const;

    void setLearningRate(double rat) { learningRate = rate; }
    double getLearningRate() const { return learningRate; }

    void setActivationFnc(Training::ActivationFnc fnc) { activationFnc = fnc; }
    Training::ActivationFnc getActivationFnc() const { return activationFnc; }
};

#endif // NEURALNET_H
