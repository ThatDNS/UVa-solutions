// Problem: 10338 - Mischievous Children
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

int main(){
  unsigned ll facts[22], ans;
  facts[0] = 1;
  for(unsigned ll i=1; i<=20; i++){
    facts[i] = facts[i-1]*i;
  }
  int n, num=0, multi[28];
  set<char> pre;
  char c;
  sf(n);
  string s;
  getline(cin, s);
  while(n--){
    getline(cin, s);
    pre.clear();
    for(int i=0; i<=26; i++)
      multi[i] = 0;
    for(int i=0; i<s.size(); i++){
      c = s[i];
      if(pre.count(c) == 0){
        pre.insert(c);
        multi[(int)c-64]++;
      }else{
        multi[(int)c-64]++;
      }
    }
    ans = facts[(int)s.size()];
    for(int i=1; i<=26; i++){
      if(multi[i] > 1)
        ans /= facts[multi[i]];
    }
    printf("Data set %d: %llu\n", ++num, ans);
  }
  return 0;
}
