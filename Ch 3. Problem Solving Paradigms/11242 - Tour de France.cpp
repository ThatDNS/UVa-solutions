// Problem: 11242 - Tour de France
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int f, r;
	vector<double> dRatios;
	double temp;
	while(cin >> f && f != 0){
		cin >> r;
		dRatios.clear();
		int front[f+2], rear[r+2];
		for(int i=0; i<f; i++)
			cin >> front[i];
		for(int i=0; i<r; i++)
			cin >> rear[i];
		for(int i=0; i<f; i++){
			for(int j=0; j<r; j++){
				dRatios.push_back(double(rear[j])/front[i]);
			}
		}
		sort(dRatios.begin(), dRatios.end());
		temp = dRatios[1]/dRatios[0];
		for(int i=2; i<dRatios.size(); i++){
			if(dRatios[i]/dRatios[i-1] > temp)
				temp = dRatios[i]/dRatios[i-1];
		}
		printf("%.2f\n", temp);
	}
	return 0;
}
