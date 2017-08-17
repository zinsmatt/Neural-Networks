#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H
#include "layer.h"

class HiddenLayer : public Layer
{
public:
    HiddenLayer(NeuralNet* _neuralNet, int numberofneurons, ActivationFunction fnc, int numberofinputs);

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
};

#endif // HIDDENLAYER_H
