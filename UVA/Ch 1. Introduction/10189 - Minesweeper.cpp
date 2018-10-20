// Problem: 10189 - Minesweeper
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, field=0;
  while(cin>>n>>m && (n!=0 || m!=0)){
    if(field>0) cout << "\n";
    string s[n];
    int arr[n][m];
    for(int i=0; i<n; i++)
      cin >> s[i];
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        arr[i][j] = 0;
      }
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(s[i][j]=='*'){
          arr[i][j] = -1;
          if(i != 0){
            if(arr[i-1][j] != -1) ++arr[i-1][j];
            if(j != 0){
              if(arr[i-1][j-1] != -1) ++arr[i-1][j-1];
            }
            if(j != m-1){
              if(arr[i-1][j+1] != -1) ++arr[i-1][j+1];
            }
          }
          if(i != n-1){
            if(arr[i+1][j] != -1) ++arr[i+1][j];
            if(j != 0){
              if(arr[i+1][j-1] != -1) ++arr[i+1][j-1];
            }
            if(j != m-1){
              if(arr[i+1][j+1] != -1) ++arr[i+1][j+1];
            }
          }
          if(j != 0){
            if(arr[i][j-1] != -1) ++arr[i][j-1];
          }
          if(j != m-1){
            if(arr[i][j+1] != -1) ++arr[i][j+1];
          }
        }
      }
    }
    cout << "Field #" << ++field << ":" << endl;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(arr[i][j]==-1)
          cout << "*";
        else
          cout << arr[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
