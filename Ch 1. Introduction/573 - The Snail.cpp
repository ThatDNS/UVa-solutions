// Problem: 573 - The Snail
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  float h, u, d, f;
  int days;
  float currHeight, dailyCap, red;
  bool success=true;
  while(cin>>h>>u>>d>>f && h!=0){
    currHeight = 0;
    days = 0;
    dailyCap = u;
    success=true;
    red = (f/100)*u;
    while(currHeight >= 0){
      currHeight += dailyCap;
      ++days;
      if(dailyCap > 0)
        dailyCap -= red;
      if(currHeight > h){
        break;
      }else{
        currHeight -= d;
      }
    }
    if(currHeight < 0)
      success = false;
    if(success)
      cout << "success on day " << days << endl;
    else
      cout << "failure on day " << days << endl;
  }
  return 0;
}
