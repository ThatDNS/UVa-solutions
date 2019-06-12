// Problem: 10892 - LCM Cardinality
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
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
void findFactors(int n);
vi factors;

int main(){
  int n, num;
  while(sf(n) == 1 && n){
    factors.clear();
    findFactors(n);
    num=0;
    for(int i=0; i<factors.size(); i++){
      for(int j=i+1; j<factors.size(); j++){
        if(LCM(factors[i], factors[j]) == n)
          ++num;
      }
    }
    num++;
    printf("%d %d\n", n, num);
  }
  return 0;
}

void findFactors(int n){
  for(int i=1; i<=sqrt(n); i++)
    if(n%i == 0){
      if(n/i == i){
        factors.pb(i);
      }else{
        factors.pb(i);
        factors.pb(n/i);
      }
    }
}
