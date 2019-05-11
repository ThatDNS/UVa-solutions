// Problem: 10074 - Take the Land
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

int main(){
  int m, n, sum, ans;
  int arr[102][102];
  while(cin >> m >> n && m && n){
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++){
        scanf("%d", &arr[i][j]);
        if(arr[i][j]==0) arr[i][j] = 1;
        else if(arr[i][j]==1) arr[i][j] = -100000;
      }
    for(int i=0; i<m; i++)
      for(int j=0; j<n; j++){
        if(i>0) arr[i][j] += arr[i-1][j];
        if(j>0) arr[i][j] += arr[i][j-1];
        if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1]; 
      }
    sum = 0; ans = INT_MIN;
    for(int a=0; a<m; a++)
      for(int b=0; b<n; b++)
        for(int c=a; c<m; c++)
          for(int d=b; d<n; d++){
            sum = arr[c][d];
            if(a>0) sum -= arr[a-1][d];
            if(b>0) sum -= arr[c][b-1];
            if(a>0 && b>0) sum += arr[a-1][b-1];
            ans = max(ans, sum);
          }
    if(ans<0) ans=0;
    printf("%d\n", ans);
  }
  return 0;
}

