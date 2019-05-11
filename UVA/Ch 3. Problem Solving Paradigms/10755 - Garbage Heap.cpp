// Problem: 10755 - Garbage Heap

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
  int t, a, b, c, flag=0;
  ll garb[22][22][22];
  ll sum, ans, real_ans;
  ll arr1d[22];
  cin >> t;
  while(t--){
    if(flag==1) printf("\n");
    if(flag==0) flag=1;
    cin >> a >> b >> c;
    for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
        for(int k=0; k<c; k++){
          cin >> garb[i][j][k];
        }

    // Getting 2d area for each 'a':
    for(int i=0; i<a; i++)
      for(int j=0; j<b; j++)
        for(int k=0; k<c; k++){
          // BUC = B + C - B^C
          if(j>0) garb[i][j][k] += garb[i][j-1][k];
          if(k>0) garb[i][j][k] += garb[i][j][k-1];
          if(j>0 && k>0) garb[i][j][k] -= garb[i][j-1][k-1];
        }

    // Finding all (0,j,k) & (0,m,n) combinations:
    sum=0; real_ans=LLONG_MIN;
    for(int j=0; j<b; j++)
      for(int k=0; k<c; k++)
        for(int m=j; m<b; m++)
          for(int n=k; n<c; n++){
            for(int i=0; i<a; i++){
              sum = garb[i][m][n];
              if(j>0) sum -= garb[i][j-1][n];
              if(k>0) sum -= garb[i][m][k-1];
              if(j>0 && k>0) sum += garb[i][j-1][k-1];
              arr1d[i] = sum;
            }
            // Max 1D range:
            sum=0; ans=INT_MIN;
            for(int i=0; i<a; i++){
              sum += arr1d[i];
              ans = max(ans, sum);
              if(sum<0) sum = 0;
            }
            real_ans = max(real_ans, ans);
          }
    cout << real_ans << endl;
  }
  return 0;
}

