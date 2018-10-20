// Problem: 11389 - The Bus Driver Problem
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, d, r;
	while(cin >> n >> d >> r && n!=0 && d!=0 && r!=0){
		long long mrnng[n+2], evnng[n+2], extraHrs=0;
		for(long long i=0; i<n; i++)
			cin >> mrnng[i];
		for(long long i=0; i<n; i++)
			cin >> evnng[i];
		sort(mrnng, mrnng+n);
		sort(evnng, evnng+n, greater<long long>());
		for(long long i=0; i<n; i++){
			if(mrnng[i]+evnng[i] > d){
				extraHrs += (mrnng[i]+evnng[i])-d;
			}
		}
		cout << extraHrs*r << endl;
	}
	return 0;
}
