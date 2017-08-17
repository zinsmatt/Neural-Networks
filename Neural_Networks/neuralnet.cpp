#include "neuralnet.h"
#include <iostream>
#include "layer.h"
#include "hiddenlayer.h"
#include "outputlayer.h"
#include "inputlayer.h"

using namespace std;

NeuralNet::NeuralNet(int numberofinputs, int numberofoutputs, const std::vector<int>& nbInHiddenLayers,
          const std::vector<ActivationFunction*> hiddenAcFnc, ActivationFunction outputAcFnc) :
    numberOfHiddenLayers(nbInHiddenLayers.size()), numberOfInputs(numberofinputs), numberOfOutputs(numberofoutputs)
{
    numberOfNeuronsInHiddenLayers.resize(numberOfHiddenLayers+1);
    indexesWeightPerLayer.resize(numberOfHiddenLayers+2);

    numberOfNeuronsInHiddenLayers[numberOfHiddenLayers] = numberOfOutputs;
    indexesWeightPerLayer[0] = 0;
    for(int iter=0; iter<=numberOfHiddenLayers; iter++)
    {
        if(iter<numberOfHiddenLayers)
            numberOfNeuronsInHiddenLayers[iter] = nbInHiddenLayers[iter];
        if(iter>0)
        {
            if(iter==1)
            {
                indexesWeightPerLayer[iter] = numberOfNeuronsInHiddenLayers[0]*(numberOfInputs+1);
            }else
            {
                indexesWeightPerLayer[iter] = indexesWeightPerLayer[iter-1] + numberOfNeuronsInHiddenLayers[iter-1] *
                        (numberOfNeuronsInHiddenLayers[i-2]+1);
            }
        }
    }

    if(numberOfHiddenLayers>0)
    {
        indexesWeightPerLayer[numberOfHiddenLayers+1] = indexesWeightPerLayer[numberOfHiddenLayers] +
                numberOfNeuronsInHiddenLayers[numberOfHiddenLayers] * (numberOfNeuronsInHiddenLayers[numberOfHiddenLayers-1] + 1);
    }else
    {
        indexesWeightPerLayer[numberOfHiddenLayers+1] = indexesWeightPerLayer[numberOfHiddenLayers] +
                numberOfNeuronsInHiddenLayers[numberOfHiddenLayers] * (numberOfInputs + 1);
    }

    // construct the neural net
    if(numberOfHiddenLayers == hiddenAcFnc.size())
    {
        input.resize(numberOfInputs);
        inputLayer = new InputLayer(this, numberOfInputs);
        hiddenLayers.resize(numberOfHiddenLayers);

        for(int iter=0; iter<numberOfHiddenLayers; iter++)
        {
            if(iter == 0)
            {
                hiddenLayers[iter] = new HiddenLayer(this, numberOfNeuronsInHiddenLayers[iter], hiddenAcFnc[iter],
                                                     numberOfInputs);
                inputLayer->setNextLayer(hiddenLayers[0]);
            }else
            {
                hiddenLayers[iter] = new HiddenLayer(this, numberOfNeuronsInHiddenLayers[iter], hiddenAcFnc[iter],
                                                     numberOfNeuronsInHiddenLayers[iter-1]);
                hiddenLayers[iter-1]->setNextLayer(hiddenLayers[iter]);
            }
        }

        if(numberOfHiddenLayers>0)
        {
            outputLayer = new OutputLayer(this, numberOfOutputs, outputAcFnc,
                                          numberOfNeuronsInHiddenLayers[numberOfHiddenLayers-1]);
            hiddenLayers[numberOfHiddenLayers-1]->setNextLayer(outputLayer);
        }else
        {
            outputLayer = new OutputLayer(this, numberOfOutputs, outputAcFnc,
                                          numberOfInputs);
            inputLayer->setNextLayer(outputLayer);
        }
    }
    setNeuralNetMode(RUN);
}

NeuralNet::NeuralNet(int numberofinputs, int numberofoutputs, ActivationFunction outputAcFnc):
    NeuralNet(numberofinputs, numberofoutputs, vector<int>(), vector<ActivationFunction*>(), outputAcFnc)
{

}


double NeuralNet::getOutput(int idx) const
{
    if(idx>0 && idx<output.size())
        return output[idx];
    else
    {
        cerr << "NeuralNet::getOutput(int): invalid index" << endl;
        return 0.0;
    }
}

void NeuralNet::print() const
{
    cout << "Neural Network: " << endl;
    cout << "\tInputs: " << numberOfInputs << endl;
    cout << "\tOutputs: " << numberOfOutputs << endl;
    cout << "\tHidden Layers: " << numberOfHiddenLayers << endl;
    for(int iter=0; iter<numberOfHiddenLayers; iter++)
    {
        cout << "\t\tHidden Layer " << iter << ": " << hiddenLayers[iter]->getNumberOfNeuronsInLayer() << " Neurons" << endl;
    }
}

HiddenLayer *NeuralNet::getHiddenLayer(int idx) const
{
    if(idx>0 && idx<hiddenLayers.size())
        return hiddenLayers[idx];
    else
    {
        cerr << "NeuralNet::getHiddenLayer(int): invalid index" << endl;
        return NULL;
    }
}

void NeuralNet::deactivateBias()
{
    for(HiddenLayer* pt : hiddenLayers)
    {
        pt->deactivateBias();
    }
    outputLayer->deactivateBias();
    activeBias = false;
}

void NeuralNet::activateBias()
{
    for(HiddenLayer* pt : hiddenLayers)
    {
        pt->activateBias();
    }
    outputLayer->activateBias();
    activeBias = true;
}
