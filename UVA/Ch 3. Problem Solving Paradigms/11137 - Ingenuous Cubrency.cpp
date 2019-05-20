// Problem: 11137 - Ingenuous Cubrency
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
#define ForF(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

int coins[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
ll dp[22][10000];
ll countWays(int curr, int val);

int main(){
  int vals;
  clr(dp, -1);
  while(sf(vals) == 1){
    printf("%lld\n", countWays(0, vals));
  }
}

ll countWays(int curr, int val){
  if(val == 0)
    return 1;
  if(curr >= 21 || val < 0)
    return 0;
  if(dp[curr][val] != -1)
    return dp[curr][val];
  return dp[curr][val] = countWays(curr+1, val) + countWays(curr, val-coins[curr]);
}
