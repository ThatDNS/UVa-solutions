// Problem: 10036 - Divisibility
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
#define For(i,a,b) for(int i=0; i<n; i++)
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int arr[10005];
int memo[10005][110];
int m, n, k;
int calc(int index, int sum);

int main(){
	sf(m);
	while(m--){
		sff(n,k);
		For0(i,n){
			sf(arr[i]);
		}
		clr(memo, -1);
		if(calc(0, 0))
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}

	//cout << -21/7 + 1 << endl; // -6
	return 0;
}

int calc(int index, int mod){
	if(index == n && mod == 0)
		return 1;
	if(index >= n)
		return 0;
	if(memo[index][mod] != -1)
		return memo[index][mod];
	int off = (arr[index]/k) + 1;
	return memo[index][mod] = max(calc(index+1, (mod+arr[index]+off*k)%k), calc(index+1, (mod-arr[index]+off*k)%k));
}
