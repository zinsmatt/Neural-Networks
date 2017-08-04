#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron
{
    vector<double> listOfWeightIn;
    vector<double> listOfWeightOut;
public:
    Neuron();

    double initNeuron();

    void setListWeightIn(const vector<double>& list) { listOfWeightIn = list; }
    void setListWeightOut(const vector<double>& list) { listOfWeightOut = list; }

    vector<double>& getListWeightIn() { return listOfWeightIn; }
    vector<double>& getListWeightOut() { return listOfWeightOut; }
};

#endif // NEURON_H
