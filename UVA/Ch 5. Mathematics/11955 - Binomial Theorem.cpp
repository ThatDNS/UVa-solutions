// Problem: 11955 - Binomial Theorem

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

ll C[55][55];
void GenerateComb();

int main(){
  int tests, n, cases=0;
  sf(tests);
  clr(C, 0);
  GenerateComb();

  string s, var1, var2, out = "";
  char a = '+', b = ')', c = '^';
  getline(cin, s);
  size_t f1, f2, f3;
  while(tests--){
    out = "";
    getline(cin, s);
    f1 = s.find(a); f2 = s.find(b); f3 = s.find(c);
    var1 = s.substr(1, f1-1);
    var2 = s.substr(f1+1, f2-f1-1);
    n = stoi(s.substr(f3+1, s.length()-f3));
    for(int i=0; i<=n; i++){
      if(C[n][i] != 1)
        out += to_string(C[n][i]) + "*";
      if(i<n){
        out += var1;
        if(n-i != 1) out += "^" + to_string(n-i);
      }
      if(i>0){
        if(i<n) out += "*" + var2;
        else out += var2;
        if(i != 1) out += "^" + to_string(i);
      }
      if(i!=n) out += "+";
    }

    TheCase(++cases) cout << out << endl;
  }
  return 0;
}

void GenerateComb(){
  C[0][0] = 1;
  for(int n=1; n<=50; n++){
    C[n][0] = 1;
    for(int i=1; i<=n; i++){
      for(int j=min(i,50); j>0; j--)
        C[n][j] = C[n][j] + C[n][j-1];
    }
  }
}


