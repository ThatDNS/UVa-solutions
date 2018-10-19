// Problem: 10656 - Maximum Sum (II)
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	short int n;
	int temp;
	vector<int> nos, res;
	long long sum=0;
	while(cin >> n && n){
		sum=0; nos.clear(); res.clear();
		for(int i=0; i<n; i++){
			cin >> temp;
			nos.push_back(temp);
		}
		for(int i=0; i<n; i++){
			if(nos[i]+sum > sum){
				sum += nos[i];
				res.push_back(nos[i]);
			}
		}
		if(res.size()==0)
			res.push_back(nos[0]);
		for(int i=0; i<res.size(); i++){
			if(i==res.size()-1)
				cout << res[i] << endl;
			else
				cout << res[i] << " ";
		}
	}
	return 0;
}
