// Problem: 10611 - The Playboy Chimp

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
  int n;
  cin >> n;
  vector<int> h;
  h.assign(n, 0);
  for(int i=0; i<n; i++){
    cin >> h[i];
  }
  int q, height;
  bool foundS, foundT;
  cin >> q;
  int tall, shorter;
  for(int i=0; i<q; i++){
    cin >> height;
    foundS=true; foundT=true;
    shorter = lower_bound(h.begin(), h.end(), height) - h.begin();
    tall = upper_bound(h.begin(), h.end(), height) - h.begin();
    if(shorter >= n)
      --shorter;
    if(foundS && h[shorter] >= height){
      if(shorter == 0)
        foundS = false;
      else
        --shorter;
    }
    if(tall >= n)
      foundT = false;
    if(foundT && h[tall] <= height){
      if(tall == n-1)
        foundT = false;
      else
        ++tall;
    }
    if(foundS)
      cout << h[shorter] << " ";
    else
      cout << "X ";
    if(foundT)
      cout << h[tall] << "\n";
    else
      cout << "X\n";
  }
  return 0;
}
