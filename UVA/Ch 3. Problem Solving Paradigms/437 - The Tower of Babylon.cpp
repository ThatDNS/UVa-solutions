// Problem: 437 - The Tower of Babylon

#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define PI 3.14159265
#define EPS 1e-9 // 10^-9
#define pb push_back
#define mp make_pair
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

int main(){
  int n, i;
  int x[35], y[35], z[35], H[100];
  int x1[100], y1[100], LIS[100], ans, cases=0, maxVal;

  multimap<int, pair<int, pair<int, int> > > vals;
  map<int, pair<int, pair<int, int> > >::iterator it;
  pair<int, pair<int, int> > temp;
  pair<int, int> temp1;

  while(scanf("%d", &n)==1 && n){
    vals.clear();
    for(int i=0; i<n; i++){
      scanf("%d %d %d", &x[i], &y[i], &z[i]);

      temp1.first = x[i];
      temp1.second = y[i];
      temp.first = z[i];
      temp.second = temp1;
      vals.insert(pair<int, pair<int, pair<int, int> > >(x[i]*y[i], temp));

      temp1.first = y[i];
      temp1.second = z[i];
      temp.first = x[i];
      temp.second = temp1;
      vals.insert(pair<int, pair<int, pair<int, int> > >(y[i]*z[i], temp));

      temp1.first = z[i];
      temp1.second = x[i];
      temp.first = y[i];
      temp.second = temp1;
      vals.insert(pair<int, pair<int, pair<int, int> > >(z[i]*x[i], temp));
    }
    i=vals.size()-1;
    for(it = vals.begin(); it!=vals.end(); ++it){
      temp = it->second;
      H[i] = temp.first;
      temp1 = temp.second;
      x1[i] = temp1.first;
      y1[i] = temp1.second;
      --i;
    }
    LIS[0] = H[0];
    ans = LIS[0];
    for(int i=1; i<vals.size(); i++){
      maxVal = INT_MIN;
      for(int j=0; j<i; j++){
        if((x1[i]<x1[j] && y1[i]<y1[j]) || (x1[i]<y1[j] && y1[i]<x1[j]))
          maxVal = max(maxVal, LIS[j]+H[i]);
      }
      if(maxVal == INT_MIN)
        LIS[i] = H[i];
      else
        LIS[i] = maxVal;
      ans = max(LIS[i], ans);
    }
    printf("Case %d: maximum height = %d\n", ++cases, ans);
  }
  return 0;
}
