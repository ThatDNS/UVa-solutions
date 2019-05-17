// Problem: 147 - Dollars
#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define vi vector<int>
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define For0(i,n) for(int i=0; i<n; i++)
#define ForF(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

ll dp[14][30005];
int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll countWays(int id, int val);

int main(){
  float no;
  int num, val;
  ll ways;
  clr(dp, -1);
  while(cin >> no && no != 0.00){
    num = (int)(no*100);
    while(num%5!=0) ++num; //Lil trick to solve precision error (ex input: 38.85)
    ways = countWays(0, num);
    no = num;
    no /= 100.0;
    printf("%6.2f%17lld\n", no, ways);
  }
  return 0;
}

ll countWays(int id, int val){
  if(dp[id][val] != -1)
    return dp[id][val];
  if(id >= 11 || val < 0) return 0;
  if(val == 0) return 1;
  return dp[id][val] = countWays(id+1, val) + countWays(id, val-coins[id]);
}
