// Problem: 10616 - Divisible Group Sums
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

ll arr[202], dp[202][22][12];
// dp: Stores number of groups of size M divisible by D
int cc, D, M, n, q;
ll solve(int curr, int sum, int rem);

int main(){
  int cnt=0, cnt1=0;
  while(sff(n, q)==2 && n && q){
    printf("SET %d:\n", ++cnt);
    For0(i, n)
      scanf("%lld", &arr[i]);
    cnt1=0;
    For0(i, q){
      sff(D, M);
      clr(dp, -1);
      printf("QUERY %d: %lld\n", ++cnt1, solve(0, 0, M));
    }
  }
  return 0;
}

ll solve(int curr, int sum, int rem){
  // Base conditions:
  if(rem == 0){
    if(sum == 0) return 1; // divisible group
    return 0; // non-divisible group
  }
  if(curr >= n)
    return 0;
  if(dp[curr][sum][rem] != -1)
    return dp[curr][sum][rem];
  int temp = (sum + arr[curr]) % D;
  if(temp < 0) temp += D;
  ll val1 = solve(curr+1, sum%D, rem);
  ll val2 = solve(curr+1, temp, rem-1);
  return dp[curr][sum][rem] = val1 + val2;
}

