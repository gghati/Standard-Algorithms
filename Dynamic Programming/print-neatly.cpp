/*
  Problem : Given a text of n words, and an integer M, the length in characters of a line, print the text neatly to minimize
  the number of extra spaces at the end of the lines.
*/
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;

void calculateCost(vector< vector<int> >&cost,vector<string> &input,int maxWidth){
	for(int k = 0; k < input.size(); k++){
		cost[k][k] = maxWidth-input[k].length();
		for(int r = k + 1; r < input.size(); r++){
			cost[k][r] = cost[k][r - 1] - input[r].length() - 1;
		}
	}
	for(int k = 0; k < input.size(); k++){
		for(int r = 0; r < input.size(); r++){
			cost[k][r]++;
			if(cost[k][r] < 0)
				cost[k][r] = INT_MAX;
			else
				cost[k][r] = pow(cost[k][r],2);
		}
	}
}

void print(vector< vector<int> >&cost,vector<string> &input){
	vector<int> minPenalty(cost.size(),0);
	vector<int> backtracking(cost.size(),0);
	for(int k=cost.size()-1;k>=0;k--){
		minPenalty[k]=cost[k][cost.size()-1];
		backtracking[k]=cost.size();
		for(int r=cost.size()-1;r>k;r--){
			if(cost[k][r-1]!=INT_MAX){
				if(minPenalty[k]>minPenalty[r]+cost[k][r-1]){
					minPenalty[k]=minPenalty[r]+cost[k][r-1];
					backtracking[k]=r;
				}
			}
		}
	}
	for(int k=0;k<backtracking.size();k++)
	{	
		if(k==0)
		{
			for(int r=0;r<backtracking[0];r++)
			{
				cout<<input[r]<<" ";
			}
			if(k+1<backtracking.size()){
				if(backtracking[0]!=backtracking[k+1])
					cout<<endl;
			}
		}
		else{
			for(int r=backtracking[k-1];r<backtracking[k];r++)
			{
				cout<<input[r]<<" ";
			}
			if(backtracking[k]!=backtracking[k-1])
			cout<<endl;
		}
	}
}


int main(){
	int inputSize;
	cin>>inputSize;
	vector<string> input(inputSize);
	int maxWidth;
	cin>>maxWidth;
	for(int k=0;k<inputSize;k++)
		cin>>input[k];
	vector< vector<int> > cost(inputSize, vector<int>(inputSize, 0));
	calculateCost(cost,input,maxWidth);
	print(cost,input);
}