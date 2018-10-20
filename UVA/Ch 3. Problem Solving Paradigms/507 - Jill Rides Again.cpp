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
