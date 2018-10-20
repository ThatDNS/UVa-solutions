// Problem: 11799 - Horror Dash
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int cases, k, max=0;
  cin >> cases;
  for(int i=0; i<cases; i++){
    cin >> k;
    int monsters[k];
    for(int i=0; i<k; i++){
      cin >> monsters[i];
      if(max <= monsters[i])
        max = monsters[i];
    }
    cout << "Case " << i+1 << ": " << max << endl;
    max=0;
  }
  return 0;
}
