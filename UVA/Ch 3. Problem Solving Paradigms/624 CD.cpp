// Problem: 624 CD
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int N, tracks, netSum;
vector<int> result;
void selectTracks(vector<int> currPath, int sum, int n, int arr[]);
int main(){
	int sum=0;
	while(cin >> N >> tracks){
		sum=0; result.clear(); netSum=0;
		int arr[tracks+2];
		for(int i=0; i<tracks; i++)
			cin >> arr[i];

		for(int i=0; i<tracks; i++){
			vector<int> currPath;
			selectTracks(currPath, 0, i, arr);
		}

		for(int i: result)
			cout << i << " ";
		cout << "sum:" << netSum << endl;
		
	}
	return 0;
}

void selectTracks(vector<int> currPath, int sum, int n, int arr[]){
	sum += arr[n];
	currPath.push_back(arr[n]);
	if(sum > netSum || (sum==netSum && currPath.size() > result.size())){
		netSum = sum;
		result = currPath;
	}
	for(int i=n+1; i<tracks; i++){
		if(sum+arr[i] <= N)
			selectTracks(currPath, sum, i, arr);
	}
}