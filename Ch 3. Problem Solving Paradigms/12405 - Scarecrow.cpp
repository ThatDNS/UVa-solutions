// Problem: 12405 - Scarecrow
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
	short int tests, len, ans=0, caseNo=0;
	string s; char c;
	cin >> tests;
	while(tests--){
		cin >> len;
		cin >> s;
		ans=0;
		for(int i=0; i<s.length();){
			c = s[i];
			if(c=='.'){
				++ans;
				i+=3;
			}else{
				i++;
			}
		}
		printf("Case %d: %d\n", ++caseNo, ans);
	}
	return 0;
}
