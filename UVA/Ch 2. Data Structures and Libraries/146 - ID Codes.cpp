// Problem: 146 - ID Codes
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  while(cin >> s && s!="#"){
    if(next_permutation(s.begin(), s.end()))
      cout << s << endl;
    else
      cout << "No Successor" << endl;
  }
  return 0;
}
