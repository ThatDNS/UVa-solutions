// Problem: 10140 - Prime Distance
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

int p[700000], pt = 0;

bitset<10000010> bs; // 10^7
void sieve(ll upperBound){
  ll sieveSize = upperBound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  ll i, j, k;
  for(i=2; i<=sieveSize; i++)
    if(bs[i]){
      p[pt++] = i;
      // cross out multiples of i starting from i
      for(k = sieveSize/i, j = i*k; k>=i; k--, j-=i)
        bs[j] = 0;
    }
}

bool isPrime(ll n){
  if(n<10000000) return bs[n];
  if(n==2) return true;
  if(n%2 == 0) return false;
  ll sq = (int)sqrt(n);
  for(ll i=0; i<pt && p[i]<=sq; i++)
    if(n%p[i] == 0)
      return false;
  return true;
}

int main(){
  sieve(10000000);
  ll L, U;
  ll prime1, prime2;
  ll a, b, sDiff;
  ll c, d, lDiff;
  while(cin >> L >> U){
    prime1 = -1; prime2 = -1;
    a = -1; b = -1; c = -1; d = -1;
    sDiff = 2147483647; lDiff = -1*2147483647;
    for(ll i=L; i<=U; i++){
      if(isPrime(i)){
        if(prime1 != -1 && prime2 != -1){
          prime1 = prime2;
          prime2 = i;
          if(prime2-prime1 < sDiff){
            sDiff = prime2 - prime1;
            a = prime1; b = prime2;
          }
          if(prime2-prime1 > lDiff){
            lDiff = prime2 - prime1;
            c = prime1; d = prime2;
          }
        }
        if(prime1 == -1){
          prime1 = i;
          continue;
        }
        if(prime2 == -1){
          prime2 = i;
          if(prime2-prime1 < sDiff){
            sDiff = prime2 - prime1;
            a = prime1; b = prime2;
          }
          if(prime2-prime1 > lDiff){
            lDiff = prime2 - prime1;
            c = prime1; d = prime2;
          }
        }
      }
    }
    if(prime1 != -1 && prime2 != -1){
      printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a,b,c,d);
    }else{
      printf("There are no adjacent primes.\n");
    }
  }
  return 0;
}
