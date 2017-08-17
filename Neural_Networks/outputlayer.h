#ifndef OUTPUTLAYER_H
#define OUTPUTLAYER_H
#include "layer.h"

class OutputLayer : public Layer
{
public:
    OutputLayer(NeuralNet* _neuralnet, int numberofneurons, ActivationFunction fnc, int numberofinputs);

    OutputLayer(NeuralNet *_neuralnet, int numberofneurons, ActivationFunction fnc, Layer* prev);

    /**
     * @brief setNextLayer
     * @param next
     */
    virtual void setNextLayer(Layer* next);

    /**
     * @brief setPreviousLayer
     * @param prev
     */
    virtual void setPreviousLayer(Layer* prev);
};

#endif // OUTPUTLAYER_H
