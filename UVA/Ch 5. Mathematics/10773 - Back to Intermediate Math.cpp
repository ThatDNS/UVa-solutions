// Problem: 10773 - Back to Intermediate Math

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
	int t, cases=0;
	double t1, t2, d, v, u;
	double theta1, theta2;
	sf(t);
	while(t--){
		cin >> d >> v >> u;
		printf("Case %d: ", ++cases);

		//shortest path:
		if(u>0 && v/u < 1)
			theta1 = acos(v/u);
		else{
			printf("can't determine\n");
			continue;
		}
		t1 = d/(u*sin(theta1));

		//shortest time:
		if(v>0)
			theta2 = atan(u/v);
		else{
			printf("can't determine\n");
			continue;
		}
		t2 = d/((sin(theta2))*(v*cos(theta2)+u*sin(theta2)));
		if(t1>=t2)
			printf("%.3f\n", (t1-t2));
		else
			printf("%.3f\n", (t2-t1));
	}
	return 0;
}

