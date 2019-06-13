// Problem: 10139 - Factovisors

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

bitset<10000010> bs; // 10^7
vi priNums;
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
vi getFactors(int n);
ll get_powers(int n, int p);

int main(){
  sieve(10000000);
  int m, n, val;
  ll b;
  vi a;
  int factor, num;
  bool divides;
  while(sff(n, m) == 2){
    a = getFactors(m);
    factor = -1; num = -1;
    divides = true;
    for(int i=0; i<a.size(); i++){
      val = a[i];
      if(factor==-1 && num==-1){
        factor = val;
        num = 1;
        continue;
      }
      if(val==factor){
        ++num;
      }else{
        b = get_powers(n, factor);
        if(b < num){
          divides = false;
          break;
        }
        factor = val;
        num = 1;
      }
    }
    if(divides && factor!=-1 && num!=-1){
      b = get_powers(n, factor);
      if(b < num) divides = false;
    }
    if(divides)
      printf("%d divides %d!\n", m, n);
    else
      printf("%d does not divide %d!\n", m, n);
  }
  return 0;
}

vi getFactors(int n){
  int ind=0;
  int PF = priNums[ind];
  vi factors;
  while(PF*PF <= n){
    while(n%PF == 0){
      factors.pb(PF);
      n /= PF;
    }
    if(ind+1 == priNums.size()) break;
    PF = priNums[++ind];
  }
  if(n!=1) factors.pb(n);
  return factors;
}

ll get_powers(int n, int p){
  ll res=0;
  if(p == 0) return 1;
  for(ll power=p; power<=n; power*=p)
    res += n/power;
  return res;
}


