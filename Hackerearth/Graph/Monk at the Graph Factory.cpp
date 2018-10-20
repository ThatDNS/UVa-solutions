// Problem: Monk at the Graph Factory
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
#define EPS 1e-9 // very small value
using namespace std;
int main(){
	short int n, temp;
	cin >> n;
	int sum=0;
	for(int i=0; i<n; i++){
		cin >> temp;
		sum+=temp;
	}
	if(sum == 2*(n-1))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
