// Longest common subsequence
/*sample input
acbcf abcdef
*/
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  string s1, s2;
  cin >> s1 >> s2;
  stack<char> ans;
  int T[s1.length()+1][s2.length()+1];
  for(int i=0; i<=s1.length(); i++){
    for(int j=0; j<=s2.length(); j++){
      if(i==0){
        T[i][j]=0;
        continue;
      }
      if(j==0){
        T[i][j]=0;
        continue;
      }
      if(s1[i-1] == s2[j-1]){
        T[i][j] = T[i-1][j-1]+1;
      }else{
        T[i][j] = max(T[i-1][j], T[i][j-1]);
      }
    }
  }
  int i=s1.length(), j=s2.length();
  while(T[i][j] != 0){
    if(T[i][j] == T[i-1][j]){
      --i; continue;
    }
    if(T[i][j] == T[i][j-1]){
      --j; continue;
    }
    ans.push(s2[j-1]);
    --i; --j;
  }
  while(!ans.empty()){
    cout << ans.top();
    ans.pop();
  }
  cout << "\n";
  return 0;
}
