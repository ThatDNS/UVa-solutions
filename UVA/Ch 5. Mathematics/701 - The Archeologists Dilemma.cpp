// Problem: 701 - The Archeologists' Dilemma

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
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=a; i<=b; i++)
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int digits(ll n);

int main(){
  ll n, ans=0;
  double t1, t2;
  int digDiff;
  while(cin >> n){
    digDiff = digits(n) + 1;
    while(1){
      t1 = log2(n) + digDiff*log2(10);
      t2 = log2(n+1) + digDiff*log2(10);
      if(ceil(t1) == floor(t2)){
        ans = ceil(t1);
        break;
      }else if(ceil(t1) < t2){
        ans = ceil(t1);
        break;
      }else{
        ++digDiff;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

int digits(ll n){
  return (int)log10(n)+1;
}
