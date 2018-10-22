// Problem: 11991 - Easy Problem from Rujia Liu?
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
  long long n, m, temp, k, v;
  vector<vector<int> > vec;
  while(cin >> n >> m){
    vec.assign(1000000, vector<int>());
    for(long long i=1; i<=n; i++){
      cin >> temp;
      vec[temp].pb(i);
    }
    for(long long i=0; i<m; i++){
      cin >> k >> v;
      if(k-1 < vec[v].size())
        cout << vec[v][k-1] << endl;
      else
        cout << "0\n";
    }
  }
  return 0;
}
