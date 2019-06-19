// Problem: 10878 - Decode the tape

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

int main(){
  string s, bi;
  unsigned ll val;
  char c;
  while(getline(cin, s)){
    if(s=="___________") continue;
    s = s.substr(2, 4) + s.substr(7,3);
    bi = "";
    for(int i=0; i<s.length(); i++){
      c = s[i];
      if(c == 'o')
        bi += "1";
      else
        bi += "0";
    }
    val = bitset<7>(bi).to_ullong();
    if(val == 13 || val == 10)
      printf("\n");
    else
      printf("%c", (char)val);
  }
  return 0;
}


