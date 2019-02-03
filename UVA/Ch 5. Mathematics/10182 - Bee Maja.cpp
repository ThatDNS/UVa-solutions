// Problem: 10182 - Bee Maja

/**
 *	Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
/*---------------Bitmask---------------*/
#define setBit(S, pos) (S |= (1 << pos))
#define resetBit(S, pos) (S &= ~(1 << pos))
#define checkBit(S, pos) (S & (1 << pos))
#define toggleBit(S, pos) (S ^= (1 << pos))
#define lowBit(S) (S & (-S)) //get least bit that is 1
/*-------------------------------------*/
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define PI 3.14159265
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=a; i<=b; i++)
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int main(){
	int n;
	vi x, y, tempV;
	x.pb(0); x.pb(0);
	int count=2;
	bool isPos=false;
	int curr=1;
	for(; x.size()<=100005;){
		for(int i=0; i<tempV.size(); i++){
			if(isPos)
				x.pb(tempV[i]);
			else
				x.pb(-1*tempV[i]);
		}
		for(int i=0; i<count; i++){
			if(isPos)
				x.pb(curr);
			else
				x.pb(-1*curr);
		}
		for(int i=tempV.size()-1; i>=0; i--){
			if(isPos)
				x.pb(tempV[i]);
			else
				x.pb(-1*tempV[i]);
		}
		if(isPos){
			tempV.pb(curr);
			++curr;
			isPos = false;
		}else{
			++count;
			isPos = true;
		}
		x.pb(0);
	}
	tempV.clear();
	y.pb(0);
	isPos=true;
	curr = 1; count = 2;
	for(; y.size()<=100005;){
		for(int i=0; i<tempV.size(); i++){
			if(isPos)
				y.pb(tempV[i]);
			else
				y.pb(-1*tempV[i]);
		}
		for(int i=0; i<count; i++){
			if(isPos)
				y.pb(curr);
			else
				y.pb(-1*curr);
		}
		for(int i=tempV.size()-1; i>=0; i--){
			if(isPos)
				y.pb(tempV[i]);
			else
				y.pb(-1*tempV[i]);
		}
		if(isPos){
			isPos = false;
		}else{
			tempV.pb(curr);
			++curr;
			++count;
			isPos = true;
		}
		y.pb(0);
	}


	while(cin >> n){
		cout << x[n-1] << " " << y[n-1] << endl;
	}
	return 0;
}

