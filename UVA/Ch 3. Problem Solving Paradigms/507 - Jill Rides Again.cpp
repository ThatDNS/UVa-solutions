// Problem: 507 - Jill Rides Again
// Kadane's Algorithm
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int b, s, count=0, like;
  cin >> b;
  while(b--){
    cin >> s;
    int maxSumTill=0, maxSumGlobal=0, start=0xffff, end=-1, tempStart=1;
    for(int i=2; i<=s; i++){
      cin >> like;
      maxSumTill += like;
      if(maxSumTill < 0){
        maxSumTill = 0;
        tempStart = i;
      }else if(maxSumTill>=maxSumGlobal){
        if(maxSumTill > maxSumGlobal || (maxSumTill==maxSumGlobal && (i - tempStart) > (end - start))){
          start = tempStart;
          end = i;
        }
        maxSumGlobal = maxSumTill;
      }
    }
    if(maxSumGlobal > 0)
      printf("The nicest part of route %d is between stops %d and %d\n", ++count, start, end);
    else
      printf("Route %d has no nice parts\n", ++count);
  }
  return 0;
}

// Solved again. Solution:

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
  disableSync
  int t, n, sum, ans, x, y, temp, count=0;
  cin >> t;
  while(t--){
    cin >> n;
    //cout << "n is " << n << endl;
    int arr[n+2];
    x = 0; y = 0; temp = 0;
    for(int i=0; i<n-1; i++)
      cin >> arr[i];

    // printf("Array is: \n");
    // for(int i=0; i<n-1; i++)
    //   cout << arr[i] << " ";
    // cout << endl;

    sum=0; ans=INT_MIN;
    for(int i=0; i<n-1; i++){
      //cout << "sum is " << sum << endl;
      sum += arr[i];
      //cout << "sum is " << sum << endl;
      if((sum > ans) || (sum == ans && abs(y-x) < abs(i-temp))){
        y = i;
        x = temp;
        ans = sum;
      }
      if(sum < 0){
        sum = 0;
        temp = i+1;
      }
    }
    //cout << ans << endl;
    if(ans < 0){
      printf("Route %d has no nice parts\n", ++count);
    }else{
      printf("The nicest part of route %d is between stops %d and %d\n", ++count, x+1, y+2);
    }
  }
  return 0;
}

