#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include "activationfunction.h"

class Neuron;
class NeuralNet;

class Layer
{

protected:

    int numberOfNeuronsInLayer;         // number of neurons in the layer
    std::vector<Neuron*> neurons;       // list of the neurons
    ActivationFunction activationFnc;   // activation function in this layer
    Layer* previousLayer;               // previous layer
    Layer* nextLayer;                   // next layer

    std::vector<double> input;          // input values fed to this layer
    std::vector<double> output;         // output values produced
    int numberOfInputs;                 // number of inputs
    NeuralNet* neuralNet;               // neural net of the layer


public:

    Layer(NeuralNet* _neuralNet, int nbNeurons);
    Layer(NeuralNet* _neuralNet, int nbNeurons, const ActivationFunction& fnc);

    /**
     * @brief getNumberOfNeuronsInLayer
     * @return the number of neurons in the layer
     */
    int getNumberOfNeuronsInLayer() const { return numberOfNeuronsInLayer; }

    /**
     * @brief getListOfNeurons
     * @return a vector of neuron pointers
     */
    const std::vector<Neuron*>& getListOfNeurons() const { return listOfNeurons; }

    /**
     * @brief getPreviousLayer
     * @return a pointer to the previous layer
     */
    Layer* getPreviousLayer() const { return previousLayer; }

    /**
     * @brief getNExtLayer
     * @return a poniter to the next layer
     */
    Layer* getNextLayer() const { return nextLayer; }

    /**
     * @brief getNeuron
     * @param i
     * @return a pointer to the neuron or NULL if does not exist
     */
    Neuron* getNeuron(int i) const;

    /**
     * @brief getWeight
     * @param weightIndex
     * @param neuronIndex
     * @return
     */
    double getWeight(int weightIndex, int neuronIndex) const;

    /**
     * @brief getInputs
     * @return the list of inputs
     */
    const std::vector<double>& getInputs() const { return input; }

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
    bool isBiasActive() const;

    /**
     * @brief setPreviousLayer
     * @param prev
     */
    virtual void setPreviousLayer(Layer* prev);

    /**
     * @brief setNextLayer
     * @param next
     */
    virtual void setNextLayer(Layer* next);

    /**
     * @brief init all the neurons of this layer
     */
    virtual void init();

    /**
     * @brief setInputs
     * @param inputs
     */
    virtual void setInputs(const std::vector<double>& _inputs);

    /**
     * @brief calc
     */
    virtual void calc();

    /**
     * @brief getOutputs
     * @return a vector with all the output values
     */
    virtual const std::vector<double>& getOutputs() const;

    /**
     * @brief setNeuron set the neuron at place i or append it
     * @param i
     * @param _neuron
     */
    virtual void setNeuron(int i, Neuron* _neuron);

};

#endif // LAYER_H
