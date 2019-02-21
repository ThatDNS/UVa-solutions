// Problem: 10137 - The Trip

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

int main(){
  int n, m;
  ll last;
  double no, diffPos, diffNeg, avg;
  double temp;
  vector<double> nos;
  while(cin >> n && n){
    nos.clear();
    diffPos=0; diffNeg=0; avg=0;
    for(int i=0; i<n; i++){
      cin >> no;
      nos.pb(no);
      avg += no;
    }
    avg = avg/n;
    for(double var: nos){
      if(var > avg){
        temp = (ll)((var - avg)*100.0)/100.0;
        diffPos += temp;
      }else{
        temp = (ll)((avg - var)*100.0)/100.0;
        diffNeg += temp;
      }
    }
    if(diffNeg > diffPos){
      printf("$%.2lf\n", diffNeg);
    }else{
      printf("$%.2lf\n", diffPos);
    }
  }
  return 0;
}


