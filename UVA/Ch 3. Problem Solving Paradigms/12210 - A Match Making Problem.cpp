// Problem: 12210 - A Match Making Problem
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int b, s, temp, cases=0;
	vector<int> bache;
	vector<int> spins;
	while(cin >> b >> s && (b!=0 && s!=0)){
		bache.clear(); spins.clear();
		for(int i=0; i<b; i++){
			cin >> temp;
			bache.push_back(temp);
		}
		for(int i=0; i<s; i++){
			cin >> temp;
			spins.push_back(temp);
		}
		sort(bache.begin(), bache.end());
		if(b <= s)
			printf("Case %d: 0\n", ++cases);
		else
			printf("Case %d: %d %d\n", ++cases, b-s, bache[0]);
	}
	return 0;
}
