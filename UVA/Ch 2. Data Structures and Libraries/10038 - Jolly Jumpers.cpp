// Problem: 10038 - Jolly Jumpers
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, diff;
  bool isJolly = true;
  while(cin >> n){
    int arr[n]; isJolly = true;
    bool isTaken[n];
    for(int i=0; i<n; i++){
      cin >> arr[i];
      isTaken[i] = false;
    }
    for(int i=1; i<n; i++){
      diff = abs(arr[i]-arr[i-1]);
      if(diff >= n){
        isJolly = false;
        break;
      }else{
        isTaken[diff] = true;
      }
    }
    for(int i=1; i<n; i++){
      if(!isTaken[i])
        isJolly = false;
    }
    if(isJolly){
      cout << "Jolly" << endl;
    }else{
      cout << "Not jolly" << endl;
    }
  }
  return 0;
}
