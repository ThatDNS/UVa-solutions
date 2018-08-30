// Problem: 401 - Palindromes
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
char getReverse(char x);
int main(){
  string ss;
  int len;
  bool palindrome, mirror;
  while(cin >> ss){
    len = ss.length();
    palindrome = true; mirror = true;
    if(len == 1){
      if(ss[0] != getReverse(ss[0]))
        mirror=false;
    }else{
      for(int i=0, j=len-1; i<len/2 && (len%2==0)?(j>=len/2):(j>len/2); i++, j--){
        if(ss[i] != ss[j])
          palindrome=false;
        if(ss[i] != getReverse(ss[j]))
          mirror=false;
      }
      if(len%2!=0){
        if(ss[len/2] != getReverse(ss[len/2]))
          mirror=false;
      }
    }
    if(palindrome && mirror)
      cout << ss << " -- is a mirrored palindrome.\n\n";
    else if(palindrome)
      cout << ss << " -- is a regular palindrome.\n\n";
    else if(mirror)
      cout << ss << " -- is a mirrored string.\n\n";
    else
      cout << ss << " -- is not a palindrome.\n\n";
  }
  return 0;
}
char getReverse(char x){
  char ch[] = {'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'};
  char reverse[] = {'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8'};
  for(int i=0; i<21; i++){
    if(x == ch[i]){
      x = reverse[i];
      return x;
    }
  }
  return '\0';
}
