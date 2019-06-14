// Problem: 10738 - Riemann vs Mertens

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

int M[1000005], diffPriFac[1000005], mu[1000005];
vi priNums;
void sieve(ll upperbound);
ll countFactors(ll N);

int main(){
  sieve(1000000);
  ll val;
  M[1] = 1;
  mu[1] = 1;
  for(ll i=2; i<=1000000; i++){
    val = countFactors(i);
    if(val == diffPriFac[i]){ // sq free
      if(val%2 == 0)
        mu[i] = 1;
      else
        mu[i] = -1;
    }else{
      mu[i] = 0;
    }
    M[i] = M[i-1] + mu[i];
  }
  int n;
  while(sf(n)==1 && n)
    printf("%8d%8d%8d\n", n, mu[n], M[n]);
  return 0;
}

void sieve(ll upperbound){
  ll sieveSize = upperbound + 1;
  for(ll i=2; i<=sieveSize; i++)
    if(diffPriFac[i] == 0){
      priNums.pb(i);
      for(ll j=i; j<=sieveSize; j+=i){
        ++diffPriFac[j];
      }
    }
}

ll countFactors(ll N){
  int ind=0;
  int PF = priNums[ind];
  ll count = 0;
  while(PF*PF <= N){
    while(N%PF == 0){
      ++count;
      N /= PF;
    }
    if(ind+1 == priNums.size()) break;
    PF = priNums[++ind];
  }
  if(N!=1) ++count;
  return count;
}

