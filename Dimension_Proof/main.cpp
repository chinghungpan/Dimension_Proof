#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;
#include "RNNAlg.h"

#define DIMENSION	3
#define MAX_RANGE	1000
#define MAX_RANDOM	100.0
#define PI 3.14159265358979323846
//=================================================
vector<vector<double>> object;

vector<double> splitString(string line){
	vector<double> returnVector;
	unsigned int pos = line.find('	');
	unsigned int initialPos = 0;
	returnVector.clear();
	while( pos != std::string::npos ) {

		returnVector.push_back(atof( line.substr( initialPos, pos - initialPos + 1 ).c_str()) );
		initialPos = pos + 1;
		pos = line.find( '	', initialPos );
	}
	returnVector.push_back(atof( line.substr( initialPos, std::min( pos, line.size() ) - initialPos + 1 ).c_str() ));
	return returnVector;
}
void loadObect(){
	string line;
	int objectCount=0;
	//ÅªÀÉ¨Ãnew Node
	ifstream readFile ("D:\\RNNInput.txt");
	if (readFile.is_open())
	{
		while ( readFile.good() )
		{
			getline (readFile,line);
			if(line!=""){
				object.push_back(splitString(line));

			}
		}
		readFile.close();
	}
	else cout << "Unable to open file";
}
int main () {
	int dimension=DIMENSION;
	vector<double> query;// n dim query
	//===============
	//from "RNNInput.txt" load in "vector<vector<int>> object"
	//loadObect();
	double param;
	//test input
	//double pi=atan(1)*4;

	vector<double> temp;
	temp.push_back(1.0);
	temp.push_back(0.0);
	temp.push_back(0.0);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(-1.0);
	temp.push_back(0.0);
	temp.push_back(0.0);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(0.5);
	temp.push_back(0.866);
	temp.push_back(0.0);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(-0.5);
	temp.push_back(0.866);
	temp.push_back(0.0);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(-0.5);
	temp.push_back(-0.866);
	temp.push_back(0.0);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(0.5);
	temp.push_back(-0.866);
	temp.push_back(0.0);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(0.424264);
	temp.push_back(0.424264);
	temp.push_back(1.0392);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------
	temp.push_back(-0.424264);
	temp.push_back(-0.424264);
	temp.push_back(1.0392);
	object.push_back(temp);
	temp.clear();
	//-------------------------------------

	//create query

	int count=0;
	int countTime = 0;
	ofstream myfile;
	myfile.open("D:\\Max_RNN_Result.txt");
	while (count<10 && countTime<1){
		countTime++;
		srand (time(NULL));	
		query.clear();
		//for(int i=0;i<dimension;i++){
		//	query.push_back((double)(rand()%MAX_RANGE)/MAX_RANDOM);	
		//}
		query.push_back(0.0);
		query.push_back(0.0);
		query.push_back(0.0);
		//do RNN Alg
		RNNAlg RnnAlg;
		count=RnnAlg.doAlgorithm(query,object,DIMENSION);
		cout<<"==========="<<count<<endl;
		myfile << count << "\n";
	}

	//print query
	for(int i=0;i<dimension;i++){
		cout<<"query="<<query[i]<<" ";
	}
	cout<<endl;

	system("pause");

	return 0;
}