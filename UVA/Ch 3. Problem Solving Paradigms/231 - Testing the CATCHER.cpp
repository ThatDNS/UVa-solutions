// Problem: 231 - Testing the CATCHER
/**
 *	Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define For0(i,n) for(int i=0;i<n;i++)
#define ForA(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9

int main(){
	int n, tc=1, flag=0;
	vi vec;
	while(cin >> n && n!=-1){
		if(flag==1) printf("\n");
		if(flag==0) flag=1;
		vec.clear(); vec.pb(n);
		while(cin >> n && n!=-1)
			vec.pb(n);
		int LDS[(int)vec.size()+2], val;
		LDS[0] = 1;
		for(int i=1; i<(int)vec.size(); i++){
			val = INT_MIN;
			for(int j=0; j<i; j++){
				if(vec[i]<=vec[j])
					val = max(val, LDS[j]+1);
			}
			if(val!=INT_MIN)
				LDS[i] = val;
			else
				LDS[i] = 1;
		}
		val = INT_MIN;
		for(int i=0; i<(int)vec.size(); i++)
			val = max(val, LDS[i]);
		printf("Test #%d:\n", tc++);
		printf("  maximum possible interceptions: %d\n", val);
	}
	return 0;
}
