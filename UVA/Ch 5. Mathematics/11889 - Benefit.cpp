// Problem: 11889 - Benefit
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

int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
bitset<10000010> bs; // 10^7
vi priNums;
map<int, int> getFactors(int n);
void sieve(ll upperBound);

int main(){
  sieve(100000);
  int A, C, num, B, ind, p1, p2;
  map<int, int> a, c;
  map<int, int>::iterator it;
  map<int, int>::iterator it2;
  sf(num);
  while(num--){
    sff(A,C);
    if(C%A != 0){
      printf("NO SOLUTION\n");
      continue;
    }
    B = 1;
    a = getFactors(A);
    c = getFactors(C);
    for(it=c.begin(); it!=c.end(); ++it){
      ind = it->first;
      p1 = it->second;
      if(a.count(ind)){
        it2 = a.find(ind);
        p2 = it2->second;
        if(p1 != p2)
          B *= pow(ind, max(p1,p2));
      }else{
        B *= pow(ind, p1);
      }
    }
    printf("%d\n", B);
  }
  return 0;
}

map<int, int> getFactors(int n){
  int ind=0;
  int PF = priNums[ind];
  map<int, int> factors;
  map<int, int>::iterator it;
  while(PF*PF <= n){
    while(n%PF == 0){
      if(factors.count(PF) == 0){
        factors.insert(pair<int, int> (PF, 1));
      }else{
        it = factors.find(PF);
        ++(it->second);
      }
      n /= PF;
    }
    if(ind+1 == priNums.size()) break;
    PF = priNums[++ind];
  }
  if(n!=1){
    if(factors.count(n) == 0){
      factors.insert(pair<int, int> (n, 1));
    }else{
      it = factors.find(n);
      ++(it->second);
    }
  }
  return factors;
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


