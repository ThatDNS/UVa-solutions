// Problem: 455 - Periodic Strings
#include <bits/stdc++.h>
using namespace std;
inline int  MAX3(int a, int b, int c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define timeDikha cout<<'\n'<<"time elapsed: "<<clock()*1000.0 / CLOCKS_PER_SEC<<" ms"<<'\n';
#define FAIK(c, n) for(int i=0; i<n; i++) cout << c[i] << " "; cout << "\n";
#define vi vector<int>
#define in(n) cin>>n
#define out(n) cout<<n<<endl
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define TheCase(i) printf("Case %d: ", i);
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

string text = "";
string pattern = "";
vector<int> prePro;
void KMP_preProcess();
void KMP_Search();

int main(){
  int t, flag=0;
  sf(t);
  string temp;
  getline(cin, temp); // blank
  while(t--){
    getline(cin, temp); // blank
    getline(cin, pattern);
    text = pattern + pattern;
    if(flag == 1) cout << endl;
    else flag = 1;
    KMP_preProcess();
    KMP_Search();
  }
  return 0;
}

void KMP_preProcess(){
  int i=0, j=-1;
  prePro.assign(pattern.size()+2, 0);
  prePro[0] = -1;
  while(i < pattern.size()){
    while(j >= 0 && pattern[i] != pattern[j])
      j = prePro[j];
    ++i; ++j;
    prePro[i] = j;
  }
}

void KMP_Search(){
  int i=0, j=0;
  bool notFirst = false;
  while(i < text.size()){
    while(j >= 0 && text[i] != pattern[j])
      j = prePro[j];
    ++i; ++j;
    if(j == pattern.size()){
      if(notFirst){
        cout << i-j << endl;
        return;
      }
      if(!notFirst) notFirst = !notFirst;
      j = prePro[j];
    }
  }
}
