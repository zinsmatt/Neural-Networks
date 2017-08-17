#ifndef INPUTLAYER_H
#define INPUTLAYER_H
#include "layer.h"
#include <vector>

class NeuralNet;


class InputLayer : public Layer
{
public:
    InputLayer(NeuralNet* _neuralNet, int _numberOfInputs);

    /**
     * @brief setNextLayer set the next layer and set this as previous of next
     * @param next
     */
    virtual void setNextLayer(Layer* next);

    /**
     * @brief setPreviousLayer
     * @param prev
     */
    virtual void setPreviousLayer(Layer* prev);

    /**
     * @brief init
     */
    virtual void init();

    /**
     * @brief setInputs
     * @param _inputs
     */
    virtual void setInputs(const std::vector<double>& _inputs);

    /**
     * @brief calc
     */
    virtual void calc();
};

#endif // INPUTLAYER_H
