// Problem: 10943 - How do you add?

// Solved earlier using bottom up approach:
#include <bits/stdc++.h>
using namespace std;
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

int main(){
	int n, k;
	long long arr[102][102];
	memset(arr, 0, sizeof(arr));
	for(int i=1; i<=100; i++){ //k
		for(int j=0; j<=100; j++){ //n
			if(i==1){
				arr[i][j] = 1;
				continue;
			}
			for(int p=0; p<=j; p++){
				arr[i][j] += arr[i-1][p];
				arr[i][j] %= 1000000;
			}
		}
	}
	while(cin >> n >> k && n){
		cout << arr[k][n] << endl;
	}
	return 0;
}


// Solved later again using top down approach:
#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define vi vector<int>
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define For0(i,n) for(int i=0; i<n; i++)
#define ForF(i,a,b) for(int i=a; i<=b; i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

int CalcWays(int n, int k);
int memo[102][102];

int main(){
  int n, k, ways;
  clr(memo, -1);
  while(sff(n,k)==2 && n && k){
    ways = 0;
    ForF(i,0,n){
      ways += CalcWays(n-i,k-1)%1000000;
    }
    printf("%d\n", ways%1000000);
  }
  return 0;
}

int CalcWays(int n, int k){
  if(k == 0){
    if(n != 0) return 0;
    else return 1;
  }
  if(memo[n][k] != -1)
    return memo[n][k];
  int sum=0;
  ForF(i,0,n){
    sum += CalcWays(n-i, k-1)%1000000;
  }
  return memo[n][k] = sum%1000000;
}
