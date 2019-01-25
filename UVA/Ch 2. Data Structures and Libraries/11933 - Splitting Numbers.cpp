// Problem: 11933 - Splitting Numbers
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
	unsigned int n;
	vi val;
	bitset<N> a;
	bitset<N> b;
	while(cin >> n && n!=0){
		bitset<N> b1 = bitset<N>(n);
		a.reset(); b.reset();
		val.clear();
		for(int i=0; i<b1.size(); i++){
			if(b1.test(i) == 1)
				val.pb(i);
		}
		for(int i=0; i<val.size(); i+=2){
			a.set(val[i]);
		}
		for(int i=1; i<val.size(); i+=2){
			b.set(val[i]);
		}
		cout << a.to_ulong() << " " << b.to_ulong() << endl;
	}
	return 0;
}

