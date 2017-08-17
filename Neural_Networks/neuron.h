#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Layer;

class Neuron
{
    std::vector<double> weights;         // weights associated with this neuron
    std::vector<double> inputs;          // inputs of this neuron
    int numberOfInputs;             // number of inputs

    double output;                  // output of the neuron, generated by the activaion function
    double outputBeforeActivation;  // value passed to the activation function
    double firstDerivative;         // derivative of the neuron

    double bias;                            // bias of the neuron
    ActivationFunction activationFunction;  // activation function of this neuron

    Layer* neuralLayer;             // neural layer corresponding

public:
    Neuron();
    Neuron(int nbInputs);
    Neuron(int nbInputs, ActivationFunction af);


    void setNeuralLayer(Layer* layer) { neuralLayer = layer; }

    /**
     * @brief init: initialise the weights with random value
     */
    void init();

    /**
     * @brief setInputs Set a vector of double to the neuron input
     * @param values vector of values
     */
    void setInputs(const std::vector<double>& values) { inputs = values; }

    /**
     * @brief getArrayInputs
     * @return  array of inputs
     */
    const std::vector<double>& getInputs() const { return inputs; }

    /**
     * @brief setInput set the ith input value
     * @param i
     * @param value
     */
    void setInput(int i, double value);

    /**
     * @brief getInput
     * @param i
     * @return ith input value
     */
    double getInput(int i) const;

    /**
     * @brief getWeights
     * @return list of weights
     */
    const std::vector<double>& getWeights() const { return weights; }

    /**
     * @brief getWeight
     * @param i
     * @return the ith weight
     */
    double getWeight(int i) const;

    /**
     * @brief getBias
     * @return  the bias
     */
    double getBias() const { return bias; }

    /**
     * @brief setWeight updates the ith weight with value
     * @param i
     * @param value
     */
    void setWeight(int i, double value);

    /**
     * @brief getNumberOfInputs
     * @return the number of inputs
     */
    int getNumberOfInputs() const { return numberOfInputs; }

    /**
     * @brief getOutput
     * @return the output
     */
    double getOutput() const { return output; }

    /**
     * @brief calc calculate the output
     */
    void calc();

    /**
     * @brief calc calculate the output from _inputs
     * @param _inputs
     * @return the output
     */
    double calc(const std::vector<double>& _inputs) const;

    /**
     * @brief derivative from _inputs
     * @param _inputs
     * @return the derivative of the activation function
     */
    double derivative(const std::vector<double>& _inputs) const;

    /**
     * @brief calcBatch
     * @param _inputs
     * @return an array of outputs
     */
    std::vector<double> calcBatch(const std::vector<std::vector<double>>& _inputs) const;

    /**
     * @brief derivativeBatch
     * @param _inputs
     * @return an array of derivatives
     */
    std::vector<double> derivativeBatch(const std::vector<std::vector<double>>& _inputs) const;

    /**
     * @brief setActivationFunction
     * @param fct
     */
    void setActivationFunction(const ActivationFunction& fct) { activationFunction = fct; }

    /**
     * @brief getOutputBeforeActivation
     * @return
     */
    double getOutputBeforeActivation() const { return outputBeforeActivation; }

    /**
     * @brief getFirstDerivative
     * @return
     */
    double getFirstDerivative() const { return firstDerivative; }

    /**
     * @brief deactivateBias
     */
    void deactivateBias() { bias = 0.0; }

    /**
     * @brief activateBias
     */
    void activateBias() { bias = 1.0; }

    /**
     * @brief getBias
     * @return
     */
    double getBias() { return bias; }
};

#endif // NEURON_H
