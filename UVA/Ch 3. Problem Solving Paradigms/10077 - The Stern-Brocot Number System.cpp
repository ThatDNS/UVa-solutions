// Problem: 10077 - The Stern-Brocot Number System

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
  int n, d;
  int lB_n, lB_d, rB_n, rB_d;
  // left boundary numerator: lB_n
  // left boundary denominator: lB_n
  // right boundary numerator: rB_n
  // right boundary denominator: rB_n
  int curr_n, curr_d;
  while(cin >> n >> d){
    if(n==1 && d==1) break;
    lB_n=0; lB_d=1; rB_n=1; rB_d=0;
    curr_n=1; curr_d=1;
    while(n!=curr_n || d!=curr_d){
      if(d*curr_n > curr_d*n){ // current node is greater. go left
        rB_n = curr_n;
        rB_d = curr_d;
        curr_n += lB_n;
        curr_d += lB_d;
        cout << "L";
      }else{ // go right
        lB_n = curr_n;
        lB_d = curr_d;
        curr_n += rB_n;
        curr_d += rB_d;
        cout << "R";
      }
    }
    cout << "\n";
  }
  return 0;
}
