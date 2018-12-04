// Problem: 836 - Largest Submatrix
/* Concept:
Rather than maximum sum in a submatrix, you have to consider maximum number of 1's.
So, do it the same way as max sum with just one variation.
Checkout line 78, we have to check if the matrix sum(number of 1's) is equal to area of matrix because
1 1 1
1 1 1
For this example, area = 6 and number of 1's = 6. They's always be the same. Think!
*/
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
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9

int main(){
  int tc, flag, count, n, cR, flag1=0;
  string s;
  int arr[27][27];
  cin >> tc;
  while(tc--){
    if(flag1==1) printf("\n");
    flag1=1;
    flag=0; count=20; cR=0;
    while(count>0 && getline(cin, s)){
      if(s=="") continue;
      if(flag==0){
        count = s.length();
        n = s.length();
        flag = 1;
      }
      --count;
      for(int j=0; j<s.length(); j++){
        char a = s[j];
        if(a=='0')
          arr[cR][j] = 0;
        else if(a=='1')
          arr[cR][j] = 1;
      }
      ++cR;
    }
    // for(int i=0; i<n; i++){
    //   for(int j=0; j<n; j++)
    //     printf("%d ", arr[i][j]);
    //   printf("\n");
    // }

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i>0) arr[i][j] += arr[i-1][j];
        if(j>0) arr[i][j] += arr[i][j-1];
        if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
      }
    }

    // for(int i=0; i<n; i++){
    //   for(int j=0; j<n; j++)
    //     printf("%d ", arr[i][j]);
    //   printf("\n");
    // }
    int ans = INT_MIN, temp;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        for(int k=i; k<n; k++)
          for(int l=j; l<n; l++){
            temp = arr[k][l];
            if(i>0) temp -= arr[i-1][l];
            if(j>0) temp -= arr[k][j-1];
            if(i>0 && j>0) temp += arr[i-1][j-1];
            if(temp == (k-i+1)*(l-j+1))
              ans = max(ans, temp);
          }
    if(ans == INT_MIN)
      ans = 0;
    printf("%d\n", ans);
  }
  return 0;
}