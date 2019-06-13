// Problem: 11728 - Alternate Task
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

vi priNums;
bitset<105> bs;
void sieve(ll upperBound);
ll sumDiv(ll N);

int main(){
  sieve(100);
  int ans[1005], val, cases=0;
  clr(ans, -1);
  for(int i=1; i<=1000; i++){
    val = sumDiv(i);
    if(val <= 1000)
      ans[val] = i;
  }
  while(sf(val)==1 && val){
    TheCase(++cases); pfn(ans[val]);
  }
  return 0;
}

void sieve(ll upperBound){
  ll sieveSize = upperBound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<=sieveSize; i++)
    if(bs[i]){
      priNums.pb(i);
      // cross out multiples of i starting from i
      for(ll j=i*i; j<=sieveSize; j+=i)
        bs[j] = 0;
    }
}

ll sumDiv(ll N){
  ll PF_ind = 0, PF = priNums[PF_ind], ans = 1, power;
  while(N!=1 && (PF*PF <= N)){
    power = 0;
    while(N%PF == 0) { N /= PF; ++power; }
    ans *= ((ll)pow((double)PF, power+1.0) - 1) / (PF-1);
    PF = priNums[++PF_ind];
  }
  if(N!=1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N-1);
  return ans;
}
