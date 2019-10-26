// Problem: 957 - Popes

#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long a, long long b, long long c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define showTime cout<<'\n'<<"time elapsed: "<<clock()*1000.0 / CLOCKS_PER_SEC<<" ms"<<'\n';
#define TheCase(i) printf("Case #%d: ", i)
#define pb push_back
#define vi vector<int>
#define ll long long
#define EPS 1e-9
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

int main(){
  disableSync disableAutoFlush
  int y, p, index, start, end, numPop;
  vi yearElect;
  while(cin >> y){
    cin >> p;
    yearElect.clear();
    yearElect.assign(p, 0);
    numPop=0;
    for(int i=0; i<p; i++)
      cin >> yearElect[i];
    for(int i=0; i<p; i++){
      index = upper_bound(yearElect.begin(), yearElect.end(), yearElect[i]+y-1) - yearElect.begin();
      if(index-i > numPop){
        numPop = index-i;
        start = yearElect[i];
        end = yearElect[index-1];
      }
    }
    cout << numPop << " " << start << " " << end << "\n";
  }
  return 0;
}

