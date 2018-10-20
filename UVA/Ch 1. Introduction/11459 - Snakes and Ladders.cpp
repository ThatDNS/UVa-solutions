// Problem: 11459 - Snakes and Ladders
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int cases, a, b, c, roll, player=0;
  bool over=false;
  cin >> cases;
  while(cases-- > 0){
    player=0; over = false;
    cin >> a >> b >> c;
    int arr[b][2], score[a];
    for(int i=0; i<a; i++)
      score[i] = 1;
    for(int i=0; i<b; i++){
      cin >> arr[i][0] >> arr[i][1];
    }
    for(int i=0, j=0; i<c; i++, j++){
      if(j>=a) j=0;
      cin >> roll;
      if(!over){
        score[j] += roll;
        for(int k=0; k<b; k++){
          if(arr[k][0] == score[j]){
            score[j] = arr[k][1];
            break;
          }
        }
        if(score[j] >= 100){
      	  score[j] = 100;
      	  over = true;
        }
      }
    }
    for(int i=0; i<a; i++)
      printf("Position of player %d is %d.\n", ++player, score[i]);
  }
  return 0;
}
