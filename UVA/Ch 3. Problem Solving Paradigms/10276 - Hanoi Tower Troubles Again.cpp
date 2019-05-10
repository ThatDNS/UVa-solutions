// Problem: 10276 - Hanoi Tower Troubles Again

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

int n;
bool shouldBreak;
int pegs[52]; // topmost number on peg
void placeIt(int currNo);

int main(){
  disableSync
  int t, no=1;
  cin >> t;
  while(t--){
    clr(pegs, 0);
    cin >> n;
    no=1;
    shouldBreak = false;
    while(!shouldBreak && n<1000){
      placeIt(no);
      ++no;
    }
    cout << no-2 << endl;
  }
  return 0;
}


void placeIt(int currNo){
  bool found = false;
  for(int i=1; i<=n; i++){
    if(sqrt(pegs[i]+currNo) == (int)sqrt(pegs[i]+currNo) || pegs[i] == 0){
      pegs[i] = currNo;
      found = true;
      break;
    }
  }
  if(!found)
    shouldBreak = true;
}

