// Problem: 489 - Hangman Judge
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
bool isComplete(string s){
  for(int i=0; i<s.size(); i++){
    if(s[i] != '7')
      return false;
  }
  return true;
}
int main(){
  int round, hang=0, flag=0;
  string sol, guess;
  char c;
  bool appear = false;
  while(cin >> round && round != -1){
    hang=0;
    cin >> sol;
    cin >> guess;
    for(int i=0; i<guess.size() && !isComplete(sol); i++){
      c = guess[i];
      flag = 0;
      appear = false;
      for(int k=0; k<i; k++){
        if(c == guess[k])
          appear = true;
      }
      if(!appear){
        for(int j=0; j<sol.size(); j++){
          if(c == sol[j]){
            sol[j] = '7';
            flag=1;
          }
        }
        if(flag==0) ++hang;
      }
    }
    if(hang >= 7){
      cout << "Round " << round << "\nYou lose.\n";
    }else{
      flag=0;
      for(int i=0; i<sol.size(); i++){
        if(sol[i] != '7'){
          cout << "Round " << round << "\nYou chickened out.\n";
          flag=1;
          break;
        }
      }
      if(flag==0) cout << "Round " << round << "\nYou win.\n";
    }
  }
}
