// Problem: 10916 - Factstone Benchmark

/**
 *  Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
/*---------------Bitmask---------------*/
#define setBit(S, pos) (S |= (1 << pos))
#define resetBit(S, pos) (S &= ~(1 << pos))
#define checkBit(S, pos) (S & (1 << pos))
#define toggleBit(S, pos) (S ^= (1 << pos))
#define lowBit(S) (S & (-S)) //get least bit that is 1
/*-------------------------------------*/
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
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
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int convertYear(int y);

int main(){
  int y, p;
  double val=0;
  vector<double> vals;
  for(double i=1; i<=300000; i++){
    val += log2(i);
    vals.pb(val);
  }
  while(cin >> y && y){
    p = convertYear(y);
    for(int i=(int)vals.size()-1; i>=0; i--){
      if(vals[i] < p){
        cout << i+1 << endl;
        break;
      }
    }
  }
  return 0;
}

int convertYear(int y){
  y = y-1960;
  y = y - y%10;
  int ans = 4;
  while(y){
    ans = ans*2;
    y -= 10;
  }
  return ans;
}

