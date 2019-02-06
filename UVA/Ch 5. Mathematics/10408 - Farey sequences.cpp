// Problem: 10408 - Farey sequences

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
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
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

int GCD(int a, int b);

int main(){
  int n, k;
  double val;
  multimap<double, ii> vals;
  multimap<double, ii>::iterator it;
  while(cin >> n >> k){
    vals.clear();
    //generate all pairs
    ii temp;
    temp.first = 1;
    temp.second = 1;
    vals.insert(pair<double, ii> (1, temp));
    for(int i=1; i<=n; i++){
      for(int j=1; j<i; j++){
        if(GCD(i, j)==1){
          val = (double)j/i;
          ii temp;
          temp.first = j;
          temp.second = i;
          vals.insert(pair<double, ii> (val, temp));
        }
      }
    }
    it = vals.begin();
    --k;
    while(k--)
      ++it;
    ii temp1 = it->second;
    cout << temp1.first << "/" << temp1.second << endl;
  }
  return 0;
}

int GCD(int a, int b){
  if(b==0)
    return a;
  return GCD(b, a%b);
}

