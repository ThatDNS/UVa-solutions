// Problem: 10161 - Ant on a Chessboard

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

#define N 2000000005

int main(){
	ll n, no;
	int ind, iX, iY;
	//cout << ceil(sqrt(N)) << endl;
	vector<ll> diags;
	diags.pb(0);
	no = 1;
	for(int i=1, add=2; i<=ceil(sqrt(N))+1; i++){
		diags.pb(no);
		no += add;
		add += 2;
	}
	while(cin >> n && n){
		ind = -1;
		for(int i=1; i<=ceil(sqrt(N)); i++){
			if(n >= diags[i]-i+1 && n <= diags[i+1]-(i+1)){
				ind = i;
				break;
			}
		}
		if(n == diags[ind]){
			printf("%d %d\n", ind, ind);
		}else if(n > diags[ind]){
			iY = ind;
			iX = ind;
			if(ind%2 != 0){
				no = diags[ind];
				while(no != n){
					++no;
					--iX;
				}
			}else{
				no = diags[ind];
				while(no != n){
					++no;
					--iY;
				}
			}
			printf("%d %d\n", iX, iY);
		}else{
			iY = ind;
			iX = ind;
			if(ind%2 != 0){
				no = diags[ind];
				while(no != n){
					--no;
					--iY;
				}
			}else{
				no = diags[ind];
				while(no != n){
					--no;
					--iX;
				}
			}
			printf("%d %d\n", iX, iY);
		}
	}
	return 0;
}

