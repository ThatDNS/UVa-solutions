// Problem: 10179 - Irreducable Basic Fractions

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
bitset<10000010> bs; // 10^7
void sieve(ll upperBound);
ll EulerPhi(ll N);

int main(){
  sieve(10000000);
  ll n;
  while(scanf("%lld", &n) == 1 && n){
    printf("%lld\n", EulerPhi(n));
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

ll EulerPhi(ll N){
  ll PF_ind = 0, PF = priNums[PF_ind], ans = N;
  while(N!=1. && (PF*PF <= N)){
    if(N%PF == 0) ans -= ans/PF;
    while(N%PF == 0) N /= PF;
    PF = priNums[++PF_ind];
  }
  if(N != 1) ans -= ans/N;
  return ans;
}
