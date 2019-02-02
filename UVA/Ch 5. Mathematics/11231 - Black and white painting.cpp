// Problem: 11231 - Black and white painting

/**
 *	Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, c;
	ll count;
	while(cin>>n>>m>>c && n && m){
		if(c==0)
			printf("%d\n", (n-7)*(m-7)/2);
		else
			printf("%d\n", ((n-7)*(m-7)+1)/2);
	}
	return 0;
}
