// Problem: 11413 - Fill the Containers
// Really great question.
// This article helped: https://www.redgreencode.com/binary-search-answer-uva-11413-uva-12032/
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
#define EPS 1e-9 // very small value
using namespace std;
bool tryCapacity(int maxCap);
vector<long long> vessels;
short int n;
long long m, temp;
int main(){
	while(cin >> n >> m){
		vessels.clear();
		long long high=0, low=0, chosen;
		for(int i=0; i<n; i++){
			cin >> temp;
			vessels.push_back(temp);
			high+=temp;
		}
		while(low <= high){
			long long mid = (low+high)/2;
			if(tryCapacity(mid)){
				chosen = mid;
				high = mid-1;
			}else{
				low = mid+1;
			}
		}
		cout << chosen << endl;
	}
	return 0;
}

bool tryCapacity(int maxCap){
	int curConSize=0, noOfCon=0;
	for(int i=0; i<n; i++){
		if(vessels[i] > maxCap)
			return false;
		if(curConSize+vessels[i] > maxCap){
			curConSize=0;
		}
		if(curConSize == 0){
			noOfCon++;
		}
		if(noOfCon > m)
			return false;
		curConSize += vessels[i];
	}
	return true;
}