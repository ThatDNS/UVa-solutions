// Problem: 10684 - The jackpot
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin >> n && n!=0){
    int maxSumTill=0, maxGlobalSum=0, bet;
    for(int i=0; i<n; i++){
      cin >> bet;
      maxSumTill += bet;
      if(maxSumTill < 0){
        maxSumTill = 0;
      }
      if(maxGlobalSum < maxSumTill){
        maxGlobalSum = maxSumTill;
      }
    }
    if(maxGlobalSum > 0)
      cout << "The maximum winning streak is " << maxGlobalSum << ".\n";
    else
      cout << "Losing streak.\n";
  }
  return 0;
}
