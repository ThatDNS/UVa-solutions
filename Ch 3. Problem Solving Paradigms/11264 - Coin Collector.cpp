// Problem: 11264 - Coin Collector
// This was nice.
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	short int n;
	vector<long long> coins, results;
	long long temp, sum=0, chosen, count=0;
	cin >> T;
	while(T--){
		cin >> n;
		sum=0; coins.clear(); count=0;
		bool gotIt[n];
		for(int i=0; i<n; i++){
			cin >> temp;
			coins.push_back(temp);
		}
		count=1;
		sum = coins[0];
		for(int i=1; i<n; i++){
			if(sum < coins[i]){
				sum += coins[i];
				count++;
			}else{
				sum -= coins[i-1];
				count--;
				if(sum < coins[i]){
					sum += coins[i];
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}