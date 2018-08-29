// Problem: 10141 - Request for Proposal
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, p, number=0, flagA=0;
  string x;
  while(cin>>n>>p && (n!=0 && p!=0)){
    if(flagA==1) cout<<endl; // for putting new line after each output entry
    flagA=1;
    ++number;
    getline(cin, x); // variable "x" is used to store all the extra \n.
    string req[n], name[p];
    float price[p], comp[p];
    int noOfReqMet[p];;
    for(int i=0; i<n; i++){
      getline(cin, req[i]);
    }
    for(int i=0; i<p; i++){
      getline(cin, name[i]);
      cin >> price[i] >> noOfReqMet[i];
      getline(cin, x);
      string noUse[noOfReqMet[i]]; // Not using this input anywhere
      for(int j=0; j<noOfReqMet[i]; j++){
        getline(cin, noUse[j]);
      }
      comp[i] = (double)noOfReqMet[i]/n;
    }
    float max=0, min;
    int index, nos=0, tempNo, flag=0;
    vector <int> indexes;
    for(int i=0; i<p; i++){
      if(comp[i]>=max){
        max = comp[i];
        index = i;
      }
    }
    for(int i=0; i<p; i++){
      if(comp[i] == max){
        ++nos;
        indexes.push_back(i);
      }
    }
    if(nos==1){
      cout << "RFP #" << number << endl;
      cout << name[index] << endl;
    }else if(nos>1){
      min = price[indexes[0]];
      for(int i=1; i<indexes.size(); i++){
        if(price[indexes[i]] < min){
          min = price[indexes[i]];
        }
      }
      for(int i=0; i<p; i++){
        if(price[i] == min && comp[i] == max){
          index = i;
          break;
        }
      }
      cout << "RFP #" << number << endl;
      cout << name[index] << endl;
    }
  }
  return 0;
}
