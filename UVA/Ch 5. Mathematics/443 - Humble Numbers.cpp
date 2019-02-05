// Problem: 443 - Humble Numbers

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



int main(){
  int n, temp;
  ll no;
  set<ll> s1;
  set<ll>::iterator it;
  for(int i=0; ; i++){
    no = pow(2,i);
      if(no > 2000000000)
        break;
    for(int j=0; ; j++){
      no = pow(2,i) * pow(3,j);
      if(no > 2000000000)
        break;
      for(int k=0; ; k++){
        no = pow(2,i) * pow(3,j) * pow(5,k);
        if(no > 2000000000)
            break;
        for(int l=0; ;l++){
          no = pow(2,i) * pow(3,j) * pow(5,k) * pow(7,l);
          if(no > 2000000000)
            break;
          s1.insert(no);
        }
      }
    }
  }
  vector<ll> vec;
  for(it=s1.begin(); it!=s1.end(); ++it){
    no = *it;
    vec.pb(no);
  }
  while(cin >> n && n){
    temp = n%100;
    if(temp>10 && temp<20)
      printf("The %dth humble number is %lld.\n", n, vec[n-1]);
    else if(temp%10 == 1)
      printf("The %dst humble number is %lld.\n", n, vec[n-1]);
    else if(temp%10 == 2)
      printf("The %dnd humble number is %lld.\n", n, vec[n-1]);
    else if(temp%10 == 3)
      printf("The %drd humble number is %lld.\n", n, vec[n-1]);
    else
      printf("The %dth humble number is %lld.\n", n, vec[n-1]);
  }
  return 0;
}

