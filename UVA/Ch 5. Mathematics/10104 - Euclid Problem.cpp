// Problem: 10104 - Euclid Problem

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

int x, y, d;
void ExtendedEuclid(int a, int b);

int main(){
  ll A, B;
  while(scanf("%lld %lld", &A, &B)==2){
    ExtendedEuclid(A, B);
    printf("%d %d %d\n", x, y, d);
  }
  return 0;
}

void ExtendedEuclid(int a, int b){
  if(b==0){
    x = 1;
    y = 0;
    d = a;
    return;
  }
  ExtendedEuclid(b, a%b);
  int x1 = y;
  int y1 = x - (a/b)*y;
  x = x1;
  y = y1;
}

