// Problem: 11988 - Broken Keyboard (a.k.a. Beiju Text)
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  while(cin >> s){
    list <char> li;
    list <char> ::iterator iter;
    iter = li.begin();
    for(int i=0; i<s.size(); i++){
      if(s[i] == '['){
        iter = li.begin();
      }else if(s[i] == ']'){
        iter = li.end();
      }else{
        li.insert(iter, s[i]);
      }
    }
    for(iter = li.begin(); iter != li.end(); ++iter){
      cout << *iter;
    }
    cout << "\n";
  }
  return 0;
}
