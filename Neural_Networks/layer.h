#ifndef LAYER_H
#define LAYER_H
#include <vector>

class Neuron;

class Layer
{
    vector<Neuron*> listOfNeurons;
    int numberOfNeuronsInLayer;
public:
    Layer();

    void setListOfNeurons(const vector<Neuron*>& list) { listOfNeurons = list; }
    vector<Neuron*>& getListOfNeurons() { return listOfNeurons; }

    void setNumberOfNeuronsInLayer(int n) { numberOfNeuronsInLayer = n; }
    int getNumberOfNeuronsInLayer() { return numberOfNeuronsInLayer; }
};

#endif // LAYER_H
