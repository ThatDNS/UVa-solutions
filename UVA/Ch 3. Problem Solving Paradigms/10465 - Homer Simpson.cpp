// Problem: 10465 - Homer Simpson
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
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=a; i<b; i++)
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

/*-------Relevant code starts-------*/

int table[10005], rem[10005];

int main(){
	int m, n, t, M, N;
	while(sfff(m,n,t)==3){
		table[0] = 0;
		M = max(m, n);
		if(m == M)
			N = n;
		else
			N = m;
		For(i, 1, t+2){
			if(i<N){
				table[i] = 0;
				rem[i] = i;
			}else if(i>=N && i<M){
				table[i] = table[i-N]+1;
				rem[i] = rem[i-N];
			}else{
				if(rem[i-N] <= rem[i-M]){
					table[i] = table[i-N]+1;
					rem[i] = rem[i-N];
				}else{
					table[i] = table[i-M]+1;
					rem[i] = rem[i-M];
				}
			}
		}
		if(rem[t] != 0)
			cout << table[t] << " " << rem[t] << endl;
		else
			cout << table[t] << endl;
	}
	return 0;
}

/*-------Relevant code ends-------*/
