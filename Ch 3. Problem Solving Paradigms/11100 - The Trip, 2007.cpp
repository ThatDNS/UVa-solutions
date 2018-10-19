// Problem: 11100 - The Trip, 2007
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, temp, flag=0;
	vector<int> bags;
	while(cin >> n && n){
		if(flag==1) cout << endl;
		if(flag==0) flag=1;
		bags.clear();
		vector<vector<int> > results;
		for(int i=0; i<n; i++){
			cin >> temp;
			bags.push_back(temp);
		}
		sort(bags.begin(), bags.end());
		bool added=false;
		int minSizeWherePossible;
		for(int i=0; i<n; i++){
			added=false; minSizeWherePossible=-1;
			for(int j=0; j<results.size(); j++){
				vector<int> a = results[j];
				int max = results[j][a.size()-1];
				if(max < bags[i]){
					if(minSizeWherePossible < 0)
						minSizeWherePossible = j;
					else if(results[minSizeWherePossible].size() > a.size())
						minSizeWherePossible = j;
					added=true;
				}
			}
			if(added){
				results[minSizeWherePossible].push_back(bags[i]);
			}else{
				vector<int> a;
				a.push_back(bags[i]);
				results.push_back(a);
			}
		}
		cout << results.size() << endl;
		for(int i=0; i<results.size(); i++){
			for(int j=0; j<results[i].size(); j++){
				if(j!=results[i].size()-1)
					cout << results[i][j] << " ";
				else
					cout << results[i][j] << endl;
			}
		}
	}
	return 0;
}
