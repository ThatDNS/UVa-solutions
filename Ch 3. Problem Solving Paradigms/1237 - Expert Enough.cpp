// Problem: 1237 - Expert Enough?
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  short int T, Q, count=0;
  int D, flag=0;
  vector<string> names;
  vector<long long> low;
  vector<long long> high;
  long long price, tempLow, tempHigh;
  string tempName;
  cin >> T;
  while(T--){
    names.clear(); low.clear(); high.clear();
    if(flag==1) cout << endl;
    if(flag==0) flag=1;
    cin >> D;
    for(int i=0; i<D; i++){
      cin >> tempName >> tempLow >> tempHigh;
      names.push_back(tempName);
      low.push_back(tempLow);
      high.push_back(tempHigh);
    }
    cin >> Q;
    while(Q--){
      count=0;
      cin >> price;
      for(int i=0; i<D; i++){
        if(price >= low[i] && price <= high[i]){
          tempName = names[i];
          ++count;
        }
        if(count > 1)
          break;
      }
      if(count == 1)
        cout << tempName << endl;
      else
        cout << "UNDETERMINED" << endl;
    }
  }
  return 0;
}