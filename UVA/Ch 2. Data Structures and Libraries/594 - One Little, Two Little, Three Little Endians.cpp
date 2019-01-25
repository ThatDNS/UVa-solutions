// Problem: 594 - One Little, Two Little, Three Little Endians
/**
 *	Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

#define N 32

int main(){
	int n, no;
	while(scanf("%d", &n)==1){
		no = n;
		char* bytes = (char*) &no;
		SWAP(bytes[0], bytes[3]);
		SWAP(bytes[1], bytes[2]);
		printf("%d converts to %d\n", n, no);
	}
	return 0;
}
