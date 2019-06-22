// Problem: 836 - Largest Submatrix

// 2 WAYS:

// 1st Way:

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t, n, sum, ans, flag=0;
  string s;
  char c;
  int arr[30][30], x;
  scanf("%d", &t);
  getline(cin, s);getline(cin, s); // blank line
  while(t--){
    if(flag==1) printf("\n");
    if(flag==0) flag=1;
    x = 0;
    while(getline(cin, s) && s!=""){
      n = s.length();
      for(int i=0; i<s.length(); i++){
        c = s[i];
        if(c=='1') arr[x][i] = 1;
        else if(c=='0') arr[x][i] = -100000;
      }
      ++x;
    }
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++){
        if(i>0) arr[i][j] += arr[i-1][j];
        if(j>0) arr[i][j] += arr[i][j-1];
        if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
      }
    sum = 0; ans = INT_MIN;
    for(int a=0; a<n; a++)
      for(int b=0; b<n; b++)
        for(int c=a; c<n; c++)
          for(int d=b; d<n; d++){
            sum = arr[c][d];
            if(a>0) sum -= arr[a-1][d];
            if(b>0) sum -= arr[c][b-1];
            if(a>0 && b>0) sum += arr[a-1][b-1];
            ans = max(ans, sum);
          }
    if(ans < 0)
      ans = 0;
    printf("%d\n", ans);
  }
  return 0;
}

// 2nd Way:

/* Concept:
Rather than maximum sum in a submatrix, you have to consider maximum number of 1's.
So, do it the same way as max sum with just one variation.
Checkout line 78, we have to check if the matrix sum(number of 1's) is equal to area of matrix because we don't want to consider zeroes in the sum.
1 1 1
1 1 1
For this example, area = 6 and number of 1's = 6. They'll always be the same. Think!
*/
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
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(i>0) arr[i][j] += arr[i-1][j];
        if(j>0) arr[i][j] += arr[i][j-1];
        if(i>0 && j>0) arr[i][j] -= arr[i-1][j-1];
      }
    }
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
