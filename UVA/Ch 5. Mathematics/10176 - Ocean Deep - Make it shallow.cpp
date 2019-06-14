// Problem: 10176 - Ocean Deep! - Make it shallow!!

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

/*-------Relevant code starts-------*/

#define MOD 131071

ll power(ll x, ll n, ll m);

int main(){
  string biNum = "", temp;
  char c;
  int ans;
  while(getline(cin, temp)){
    biNum += temp;
    c = biNum[(int)biNum.size()-1];
    if(c != '#') continue;
    biNum = biNum.substr(0, biNum.size()-1);
    ans = 0;
    for(ll i=biNum.size()-1, n=0; i>=0; --i, ++n){
      c = biNum[i];
      if(c == '1')
        ans = ((ans%MOD) + power(2, n, MOD))%MOD;
    }
    if(ans == 0)
      printf("YES\n");
    else
      printf("NO\n");
    biNum = "";
  }
  return 0;
}

ll power(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n == 1)
    return x;
  if(n%2 == 0)
    return power((x*x)%m, n/2, m) % m;
  return (x * power(x, n-1, m)) % m;
}

/*-------Relevant code ends-------*/

