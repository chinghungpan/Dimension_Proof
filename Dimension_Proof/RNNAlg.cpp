#include "RNNAlg.h"
#define MAX_VALUE 10000.0

RNNAlg::RNNAlg(void)
{
}


RNNAlg::~RNNAlg(void)
{
}
int RNNAlg::doAlgorithm(vector<double> query,vector<vector<double>> object,int dimension){
	vector<vector<double>> result;
	ofstream myfile;
	myfile.open ("D:\\Result.txt");
	double candidateToQueryDistance=0;
	double candidateToObjectDistance=0;
	double smallest=MAX_VALUE;
	bool isRNN=true;

	for(int i=0;i< object.size();i++){
		cout<<i<<endl;
		candidateToQueryDistance=0;
		candidateToObjectDistance=0;
		isRNN=true;
		smallest=MAX_VALUE;
	//計算candidate 到 query 距離
			for(int k=0;k<dimension;k++){
				candidateToQueryDistance+=pow(abs(query[k]-object[i][k]),2.0);		
			}
		candidateToQueryDistance=sqrt(candidateToQueryDistance);
	//=======================	
	//計算candidate 到 其他物件 距離
		for(int j=0;j< object.size();j++){
		candidateToObjectDistance=0;
			for(int k=0;k<dimension;k++){
				candidateToObjectDistance+=pow(abs(object[i][k]-object[j][k]),2.0);	
			}
			candidateToObjectDistance=sqrt(candidateToObjectDistance);
	//====================
			if(candidateToObjectDistance!=0&&candidateToObjectDistance<smallest){
				smallest=candidateToObjectDistance;
////				if(smallest<candidateToQueryDistance){
////					isRNN=false;
////					break;
////				}
			}
		}
		//if(smallest>=candidateToQueryDistance&&isRNN!=false){
		if(smallest>=(candidateToQueryDistance-0.0001)){
			result.push_back(object[i]);
			myfile <<candidateToQueryDistance<<" :: ";
			for(int k=0;k<dimension;k++){
				myfile <<object[i][k]<<" ";				
			}
			
			myfile <<" :: "<<smallest<<"\n";
		}	

	}
	//bool same=true;
	//for(int i=0;i<result.size();i++){		
	//	for(int j=i;j<result.size();){
	//		same=true;
	//		for(int k=0;k<dimension;k++){
	//			if(result[i][k]!=result[j][k]){
	//				same=false;
	//				break;
	//			}
	//		}
	//		if(same==true)
	//			result.erase(result.begin()+j);			
	//		else
	//			j++;
	//	}
	//}
	
	myfile.close();
	
	return result.size();
}