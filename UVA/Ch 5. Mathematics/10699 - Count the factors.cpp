// Problem: 10699 - Count the factors

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

int diffPriNums[1000005];
void sieve(ll upperBound){
  ll sieveSize = upperBound + 1;
  for(ll i=2; i<=sieveSize; i++)
    if(diffPriNums[i] == 0){
      for(ll j=i; j<=sieveSize; j+=i)
        ++diffPriNums[j];
    }
}

int main(){
  sieve(1000000);
  int n;
  while(sf(n)==1 && n)
    printf("%d : %d\n", n, diffPriNums[n]);
  return 0;
}
