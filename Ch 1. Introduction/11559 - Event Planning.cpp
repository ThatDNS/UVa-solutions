// Problem: 11559 - Event Planning
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, b, h, w, minCost=2000001, currCost=0;
  bool possible;
  while(cin >> n >> b >> h >> w){
    minCost=2000001; currCost=0;
    int hotelPrice[h], rooms[w];
    for(int i=0; i<h; i++){
      possible=false;
      cin >> hotelPrice[i];
      for(int j=0; j<w; j++){
        cin >> rooms[j];
        if(rooms[j]>=n)
          possible=true;
      }
      if(possible){
        currCost = hotelPrice[i]*n;
        if(currCost <= minCost){
          minCost = currCost;
        }
      }
    }
    if(minCost <= b)
      cout << minCost << endl;
    else
      cout << "stay home" << endl;
  }
}
