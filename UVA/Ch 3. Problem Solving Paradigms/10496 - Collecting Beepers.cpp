// Problem: 10496 - Collecting Beepers
/**
 *	Author: Fallen_Cryptic
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
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=0; i<n; i++)
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int n, x[12], y[12], dist[11][11], memo[11][1<<11];
int TSP(int pos, int bitmask);

int main(){
	int tc, xS, yS;
	cin >> tc;
	while(tc--){
		cin >> xS >> yS; //no use
		cin >> x[0] >> y[0];
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> x[i] >> y[i];
		}
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				dist[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
			}
		}
		memset(memo, -1, sizeof(memo));
		printf("The shortest path has length %d\n", TSP(0, 1));
	}
	return 0;
}

int TSP(int pos, int bitmask){
	if(bitmask == (1<<(n+1))-1)
		return dist[pos][0]; //finish trip
	if(memo[pos][bitmask] != -1)
		return memo[pos][bitmask];

	int netDist = 2000000000;
	for(int nxt=0; nxt<=n; nxt++){
		if(nxt != pos && !(checkBit(bitmask, nxt))){
			netDist = min(netDist, dist[pos][nxt] + TSP(nxt, bitmask|(1 << nxt)));
		}
	}
	return memo[pos][bitmask] = netDist;
}

