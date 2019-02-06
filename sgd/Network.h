#pragma once
#include "Layer.h"
//#include "Timer.h"
using namespace std;

class Network
{
private:
	Layer** _hiddenlayers;
	float _learningRate;
	int _numberOfLayers;
	int* _sizesOfLayers;
	NodeType* _layersTypes;

	int* _inputIDs;
	int _BatchSize, _currentBatchSize;


public:
	Network(int* sizesOfLayers, NodeType* layersTypes, int noOfLayers, int batchsize, Timer *time);
	Layer* getLayer(int LayerID);
	float* predictProb(int * inputIndices, float * inputValue, int length);
    int predictClass(int ** inputIndices, float ** inputValues, int * length, int * labels, int batchsize);
	int ProcessInput(int** inputIndices, float** inputValues, int* lengths, int* label, int batchsize, float lrFactor);
	~Network();
};
