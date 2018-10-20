// Problem: 11849 - CD
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, m, temp, prev=-1, next=-1, same=0;
	multiset<long long> NetSet;
	while(cin >> n >> m && (n!=0 && m!=0)){
		NetSet.clear();
		prev=-1; next=-1; same=0;
		for(long long i=0; i<n; i++){
			cin >> temp;
			NetSet.insert(temp);
		}
		for(long long i=0; i<m; i++){
			cin >> temp;
			NetSet.insert(temp);
		}
		multiset<long long>::iterator it = NetSet.begin();
		while(it != NetSet.end()){
			if(prev==-1){
				prev = *it;
				++it;
				continue;
			}
			if(next==-1){
				next = *it;
				if(prev == next){
					++same;
				}
				++it;
				continue;
			}
			prev = next;
			next = *it;
			if(prev == next){
				++same;
			}
			++it;
		}
		cout << same << endl;
	}
	return 0;
}