// Problem: 10976 - Fractions Again?!
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long k, x, y, count = 0;
	vector<long long> X, Y;
	while(cin >> k){
		count = 0; X.clear(); Y.clear();
		for(y=k+1; y<=2*k; y++){
			if((y*k)%(y-k)==0){
				x = (y*k)/(y-k);
				X.push_back(x);
				Y.push_back(y);
				++count;
			}
		}
		cout << count << endl;
		for(int i=0; i<count; i++){
			printf("1/%lld = 1/%lld + 1/%lld\n", k, X[i], Y[i]);
		}
	}
	return 0;
}