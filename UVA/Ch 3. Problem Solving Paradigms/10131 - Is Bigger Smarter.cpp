// Problem: 10131 - Is Bigger Smarter?
// I've used lots of variables. Could have been easily done in less but well ¯_(ツ)_/¯

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
  int w, s, temp, val, ind;
  vi wts, iqs;
  vector<pair<int, int> > ele;
  while(cin >> w >> s){
    wts.pb(w); iqs.pb(s);
    ele.pb(make_pair(s, w));
  }
  sort(ele.begin(), ele.end(), greater<pair<int, int> >());
  vi LIS, pred;
  LIS.pb(1);
  pred.pb(-1);
  for(int i=1; i<ele.size(); i++){
    val = 1; temp = 0; ind = -1;
    for(int j=0; j<i; j++){
      if(ele[i].second > ele[j].second){
        temp = LIS[j]+1;
        if(temp > val){
          val = temp;
          ind = j;
        }
      }
    }
    LIS.pb(val);
    pred.pb(ind);
  }
  val = INT_MIN;
  for(int i=0; i<LIS.size(); i++){
    if(LIS[i] > val){
      val = LIS[i];
      ind = i;
    }
  }

  vector<pair<int, int> > vec;
  while(ind != -1){
    vec.pb(make_pair(ele[ind].second, ele[ind].first));
    ind = pred[ind];
  }
  sort(vec.begin(), vec.end());

  printf("%lu\n", vec.size());

  for(int i=0; i<vec.size(); i++){
    for(int j=0; j<wts.size(); j++){
      if(wts[j] == vec[i].first && iqs[j] == vec[i].second){
        printf("%d\n", j+1);
        break;
      }
    }
  }
  return 0;
}
