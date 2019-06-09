// Problem: 10689 - Yet another Number Sequence
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
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);
#define MOD 1000000007

int main(){
  int tests;
  sf(tests);
  int a,b,m,size=0,temp;
  ll n;
  while(tests--){
    scanf("%d %d %lld %d", &a, &b, &n, &m);
    if(m==1) size = 70;
    else if(m==2) size = 310;
    else if(m==3) size = 1510;
    else if(m==4) size = 15010;
    int arr[size];
    arr[0] = a;
    arr[1] = b;
    for(int i=2; i<=size-9; i++){
      arr[i] = (arr[i-1]%10000 + arr[i-2]%10000)%10000;
    }
    if(n > size-10)
      n = n % (size-10);
    printf("%d\n", arr[n]%((int)pow(10,m)));
  }
  return 0;
}
