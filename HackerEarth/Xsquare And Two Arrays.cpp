// Problem: Xsquare And Two Arrays
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
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int change(int swi);

int main(){
  disableSync
  int n, q, what, l, r, swi;
  cin >> n >> q;
  long long A[n+2], B[n+2], sum;
  for(int i=0; i<n; i++)
    cin >> A[i];
  for(int i=0; i<n; i++)
    cin >> B[i];

  while(q--){
    cin >> what >> l >> r;
    sum = 0;

    if(what == 1)
      swi = 1;
    else if(what == 2)
      swi = 2;

    for(int i=l; i<=r; i++){
      if(swi == 1)
        sum += A[i-1];
      else if(swi == 2)
        sum += B[i-1];
      swi = change(swi);
    }
    cout << sum << endl;
  }
  return 0;
}

int change(int swi){
  if(swi == 1) return 2;
  return 1;
}
