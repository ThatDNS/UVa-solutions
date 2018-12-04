// Problem: 10827 - Maximum sum on a torus
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define For0(i,n) for(int i=0;i<n;i++)
#define ForA(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9

int main(){
  short int tc, n;
  short int arr[80][80], mir[200][200];
  cin >> tc;
  while(tc--){
    cin >> n;
    For0(i, n)
      For0(j, n)
        scanf("%hd", &arr[i][j]);
    int I, J;
    For0(i, 2*n){
      For0(j, 2*n){
        if(i>=n)
          I = i-n;
        else
          I = i;
        if(j>=n)
          J = j-n;
        else
          J = j;
        mir[i][j] = arr[I][J];
      }
    }
    For0(i, 2*n)
      For0(j, 2*n){
        if(i>0) mir[i][j] += mir[i-1][j];
        if(j>0) mir[i][j] += mir[i][j-1];
        if(i>0 && j>0) mir[i][j] -= mir[i-1][j-1];
      }
    int temp, ans=INT_MIN;
    For0(i, n) For0(j, n)
    ForA(k, i, i+n) ForA(l, j, j+n){
      temp = mir[k][l];
      if(i>0) temp -= mir[i-1][l];
      if(j>0) temp -= mir[k][j-1];
      if(i>0 && j>0) temp += mir[i-1][j-1];
      ans = max(ans, temp);
    }
    printf("%d\n", ans);
  }
  return 0;
}

