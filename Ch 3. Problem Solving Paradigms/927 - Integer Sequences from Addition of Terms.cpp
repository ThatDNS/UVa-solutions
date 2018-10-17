// Problem: 927 - Integer Sequences from Addition of Terms
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long c, temp, d, k, count, ans, max;
	char cc;
	vector<long long> An;
	cin >> c;
	while(c--){
		An.clear();
		cin >> max;
		for(long long i=0; i<=max; i++){
			cin >> temp;
			An.push_back(temp);
		}
		cin >> d;
		cin >> k;
		count = 1;
		temp = 0;
		while(temp < k){
			temp += count*d;
			count++;
		}
		--count;
		ans=0;
		for(long long i=0; i<An.size(); i++){
			ans += An[i]*(pow(count, i));
		}
		cout << ans << endl;
	}
	return 0;
}
