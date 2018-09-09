// Problem: 10855 - Rotated square
// This solution seems really simple and repetitive but it was ranked 26 on uhunt so it's really good. :wink:
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using std::cout; using std::cin; using std::string;
int main(){
  int N, n, a, b, flag=0, s1, s2, s3, s4;
  string x;
  while(scanf("%d %d", &N, &n) && (N!=0 && n!=0)){
    string S[N], s[n], s90[n], s180[n], s270[n];
    s1=0; s2=0; s3=0; s4=0;
    getline(cin, x); //storing extra \n
    for(int i=0; i<N; i++)
      getline(cin, S[i]);
    for(int i=0; i<n; i++){
      getline(cin, s[i]);
      s90[i] = s[i];
      s180[i] = s[i];
      s270[i] = s[i];
    }
    for(int i=n-1; i>=0; i--){
      for(int ia=0; ia<n; ia++){
        s90[ia][n-1-i] = s[i][ia];
      }
    }
    for(int i=n-1; i>=0; i--){
      for(int ia=0; ia<n; ia++){
        s180[ia][n-1-i] = s90[i][ia];
      }
    }
    for(int i=n-1; i>=0; i--){
      for(int ia=0; ia<n; ia++){
        s270[ia][n-1-i] = s180[i][ia];
      }
    }
    for(int i=0, j=0; i<N-n+1; i++){
      j=0;
      while(S[i].find(s[0], j) != std::string::npos){
        a = S[i].find(s[0], j);
        flag=0;
        for(int ii=1; ii<n; ii++){
          b = S[i+ii].find(s[ii], a);
          if(a!=b){
            flag=1;
          }
        }
        if(flag==0)
          ++s1;
        j = a+1;
      }
    }
    for(int i=0, j=0; i<N-n+1; i++){
      j=0;
      while(S[i].find(s90[0], j) != std::string::npos){
        a = S[i].find(s90[0], j);
        flag=0;
        for(int ii=1; ii<n; ii++){
          b = S[i+ii].find(s90[ii], a);
          if(a!=b){
            flag=1;
          }
        }
        if(flag==0)
          ++s2;
        j = a+1;
      }
    }
    for(int i=0, j=0; i<N-n+1; i++){
      j=0;
      while(S[i].find(s180[0], j) != std::string::npos){
        a = S[i].find(s180[0], j);
        flag=0;
        for(int ii=1; ii<n; ii++){
          b = S[i+ii].find(s180[ii], a);
          if(a!=b){
            flag=1;
          }
        }
        if(flag==0)
          ++s3;
        j = a+1;
      }
    }
    for(int i=0, j=0; i<N-n+1; i++){
      j=0;
      while(S[i].find(s270[0], j) != std::string::npos){
        a = S[i].find(s270[0], j);
        flag=0;
        for(int ii=1; ii<n; ii++){
          b = S[i+ii].find(s270[ii], a);
          if(a!=b){
            flag=1;
          }
        }
        if(flag==0)
          ++s4;
        j = a+1;
      }
    }
    cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<< std::endl;
  }
  return 0;
}
