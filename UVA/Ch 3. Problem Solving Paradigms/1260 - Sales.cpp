// Problem: 1260 - Sales
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	short int n;
	cin >> T;
	while(T--){
		cin >> n;
		long long arr[n+2], B[n+2], count=0;
		for(int i=0; i<n; i++)
			cin >> arr[i];
		for(int i=1; i<n; i++){
			count = 0;
			for(int j=0; j<i; j++){
				if(arr[j] <= arr[i])
					++count;
			}
			B[i-1] = count;
		}
		count=0;
		for(int i=0; i<n-1; i++)
			count += B[i];
		cout << count << endl;
	}
	return 0;
}