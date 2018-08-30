// Problem: 11507 - Bender B. Rodríguez Problem
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int L, iter, count;
  while(cin>>L && L!=0){
    iter=0; count=0;
    string arr[L-1], defDirec;
    for(int i=0; i<L-1; i++){
      cin >> arr[i];
    }
    while(arr[iter] == "No")
      ++iter;
    while(iter < L-1){
      if(arr[iter] == "No"){
        ++iter;
        continue;
      }
      if(count%4 == 0){
        defDirec = arr[iter];
        count = 0;
      }else if(count%4 == 2){
        if(arr[iter] == "+z"){
          defDirec = "-z";
          arr[iter] = "-z";
        }else if(arr[iter] == "-z"){
          defDirec = "+z";
          arr[iter] = "+z";
        }else if(arr[iter] == "+y"){
          defDirec = "-y";
          arr[iter] = "-y";
        }else if(arr[iter] == "-y"){
          defDirec = "+y";
          arr[iter] = "+y";
        }
        count = 0;
      }
      if(defDirec == "+z" || defDirec == "-z"){
        if(arr[iter] == "+y" || arr[iter] == "-y"){
          ++iter;
          continue;
        }
      }
      if(defDirec == "+y" || defDirec == "-y"){
        if(arr[iter] == "+z" || arr[iter] == "-z"){
          ++iter;
          continue;
        }
      }
      if(arr[iter] == defDirec){
        count += 1;
      }else{
        count -= 1;
      }
      ++iter;
    }
    while(count<0)
      count+=4;
    if(count>=0){
      if(count%4 == 0){
        cout << "+x" << endl;
      }else if(count%4 == 1){
        cout << defDirec << endl;
      }else if(count%4 == 2){
        cout << "-x" << endl;
      }else if(count%4 == 3){
        if(defDirec == "+z" || defDirec == "-z"){
          if(defDirec == "+z")
            cout << "-z" << endl;
          else
            cout << "+z" << endl;
        }else{
          if(defDirec == "+y")
            cout << "-y" << endl;
          else
            cout << "+y" << endl;
        }
      }
    }
  }
}
