#ifndef INPUTNEURON_H
#define INPUTNEURON_H
#include "neuron.h"

class InputNeuron : public Neuron
{
public:
    InputNeuron();

    /**
     * @brief init
     */
    virtual void init();
};

#endif // INPUTNEURON_H
