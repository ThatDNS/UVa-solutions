// Problem: 11278 - One-Handed Typist

#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define vi vector<int>
#define in(n) cin>>n
#define out(n) cout<<n<<endl
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

string qwerty = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
string dvoark = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
string QWERTY = "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
string DVOARK = "!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";

int main(){
  string s, bi;
  bool found;
  char c, c1;
  while(getline(cin, s)){
    for(int i=0; i<s.length(); i++){
      c = s[i];
      found = false;
      for(int k=0; k<dvoark.length() && !found; k++){
        c1 = qwerty[k];
        if(c == c1){
          c = dvoark[k];
          found = true;
          break;
        }
      }
      for(int k=0; k<DVOARK.length() && !found; k++){
        c1 = QWERTY[k];
        if(c == c1){
          c = DVOARK[k];
          found = true;
          break;
        }
      }
      printf("%c", c);
    }
    printf("\n");
  }
  return 0;
}
