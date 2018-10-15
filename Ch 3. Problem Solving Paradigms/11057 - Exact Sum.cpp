// Problem: 11057 - Exact Sum
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, money;
	string extra;
	while(cin >> n){
		long long books[n+5];
		for(long long i=0; i<n; i++)
			cin >> books[i];
		sort(books, books+n);
		cin >> money;
		long long i=0, j=n-1, ansI, ansJ;
		while(i<j){
			if(books[i]+books[j] < money){
				++i;
			}else if(books[i]+books[j] > money){
				--j;
			}else{
				ansI = i; ansJ = j;
				++i; --j;
			}
		}
		printf("Peter should buy books whose prices are %lld and %lld.\n\n", books[ansI], books[ansJ]);
		getline(cin, extra);
	}
	return 0;
}