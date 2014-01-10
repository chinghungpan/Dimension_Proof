#pragma once
#include<vector>
#include<string>
#include <math.h>
#include <fstream>
#include <iostream>
using namespace std;
class RNNAlg
{
public:
	RNNAlg(void);
	~RNNAlg(void);
	int doAlgorithm(vector<double>,vector<vector<double>>,int);
};

