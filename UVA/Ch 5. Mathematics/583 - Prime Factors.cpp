// Problem: 583 - Prime Factors
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

vi priNums;
vi factors;
bitset<10000010> bs; // 10^7
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
void primeFactors(int N);

int main(){
  int n;
  sieve(50000);
  string ans = "";
  while(cin >> n && n){
    factors.clear();
    if(n==1){
      printf("1 = \n");
      continue;
    }else if(n==-1){
      printf("-1 = -1 x \n");
      continue;
    }
    if(n<0){
      factors.pb(-1);
      primeFactors(n*-1);
    }else{
      primeFactors(n);
    }
    ans = to_string(n) + " =";
    For0(i, factors.size()){
      if(i == factors.size()-1)
        ans += " " + to_string(factors[i]);
      else
        ans += " " + to_string(factors[i]) + " x";
    }
    cout << ans;
    printf("\n");
  }
  return 0;
}

void primeFactors(int N){
  int ind = 0;
  int PF = priNums[ind];
  while(PF*PF <= N){
    while(N%PF == 0){
      factors.pb(PF);
      N /= PF;
    }
    if(ind+1 == priNums.size()) break;
    PF = priNums[++ind];
  }
  if(N != 1) factors.pb(N);
}

