// Problem: 12356 - Army Buddies
// Side notes:
// This is an interesting question which will exceed time limit if you
// use the naive way of storing current status(dead/alive) of each soldier
// in an array and then check the buddies by iterating in the loop. This
// solution will give you an O(s*b) complexity. which sucks.
// The solution that I've implemented stores the value of left and right buddy
// of each soldier. In each case, it changes the left/right value and then prints
// the current buddies. This is of O(s+b). Total time on uhunt is 0.110.
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int s, b, l, r, ll, rr;
  while(scanf("%d %d", &s, &b) && (s!=0 && b!=0)){
    int L[s+2], R[s+2];
    for(int i=1; i<=s; i++){
      if(i==1){
        L[i] = -1;
        if(i<s) R[i] = i+1;
        else R[i] = -1;
      }else if(i==s){
        L[i] = i-1;
        R[i] = -1;
      }else{
        L[i] = i-1;
        R[i] = i+1;
      }
    }
    for(int i=0; i<b; i++){
      scanf("%d %d", &l, &r);
      if(L[l] != -1){
        R[L[l]] = R[r];
      }
      if(R[r] != -1){
        L[R[r]] = L[l];
      }
      if(L[l] != -1)
        printf("%d ", L[l]);
      else
        printf("* ");
      if(R[r] != -1)
        printf("%d\n", R[r]);
      else
        printf("*\n");
    }
    printf("-\n");
  }
  return 0;
}