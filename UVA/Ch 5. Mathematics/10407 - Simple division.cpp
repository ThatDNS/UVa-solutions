// Problem: 10407 - Simple division
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
#define TheCase(i) printf("Case %d: ", i);
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);
#define MOD 1000000007

int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }

int main(){
  int n, f, ans;
  vi nums;
  while(sf(f) && f){
    nums.clear(); nums.pb(f);
    while(sf(n) && n){
      nums.pb(n);
    }
    sort(nums.begin(), nums.end());
    f = nums[0];
    for(int i=0; i<nums.size(); i++)
      nums[i] -= f;
    ans = nums[0];
    for(int i=1; i<nums.size(); i++)
      ans = GCD(ans, nums[i]);
    pfn(ans);
  }
  return 0;
}
