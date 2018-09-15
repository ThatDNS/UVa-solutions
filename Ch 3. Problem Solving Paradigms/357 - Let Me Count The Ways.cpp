// Problem: 357 - Let Me Count The Ways
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[30001];
int main(){
  int n, val[5] = {1,5,10,25,50};
  dp[0] = 1;
  for(int i=0; i<5; i++){
    for(int j=val[i]; j<=30000; j++)
      dp[j] += dp[j - val[i]];
  }
  while(cin >> n){
    if(dp[n] == 1){
      printf("There is only 1 way to produce %d cents change.\n", n);
    }else{
      cout << "There are " << dp[n] << " ways to produce " << n << " cents change.\n";
    }
  }
  return 0;
}
