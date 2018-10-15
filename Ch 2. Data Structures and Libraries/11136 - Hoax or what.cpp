// Problem: 11136 - Hoax or what
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, k, val, sum=0, temp;
	multiset<long long> mSet;
	while(cin >> n && n!=0){
		sum=0;
		mSet.clear();
		while(n--){
			cin >> k;
			for(long long i=0; i<k; i++){
				cin >> val;
				mSet.insert(val);
			}
			multiset<long long>::iterator it1 = mSet.begin();
			multiset<long long>::iterator it2 = prev(mSet.end());
			sum += *it2 - *it1;
			mSet.erase(it1);
			mSet.erase(prev(mSet.end()));
		}
		cout << sum << endl;
	}
	return 0;
}