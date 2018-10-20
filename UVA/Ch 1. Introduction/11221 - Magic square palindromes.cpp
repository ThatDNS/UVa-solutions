// Problem: 11221 - Magic square palindromes
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
string onlyAlpha(string s);
bool checkMagic(string s, int dim);
int main(){
  int t, cases=0, dim;
  bool isMagic = true;
  cin >> t;
  string s, ss;
  getline(cin, s); // storing extra \n
  while(cases < t){
    isMagic = true;
    getline(cin, s);
    ss = onlyAlpha(s); // removes everything except lowercase alphabets.
    dim = (int)sqrt(ss.size());
    if(ss.size() != dim*dim){
      isMagic = false;
    }else{
      isMagic = checkMagic(ss, dim);
    }
    printf("Case #%d:\n", cases+1);
    if(isMagic)
      cout << dim << endl;
    else
      cout << "No magic :(" << endl;
    cases++;
  }
  return 0;
}

bool checkMagic(string s, int dim){
  char sq[dim][dim];
  bool isMagic = true;
  int k=0;
  for(int i=0; i<dim; i++){
    for(int j=0; j<dim; j++){
      sq[i][j] = s[k++];
    }
  }
  for(int i=0; i<dim/2; i++){
    if(sq[i][i] != sq[dim-i-1][dim-i-1]){
      isMagic = false; break;
    }
    if(sq[i][dim-i-1] != sq[dim-i-1][i]){
      isMagic = false; break;
    }
    for(int j=i+1; j<dim-i-1; j++){
      if(sq[i][j] != sq[j][i]){
        isMagic = false; break;
      }
      if(sq[dim-i-1][dim-j-1] != sq[dim-j-1][dim-i-1]){
        isMagic = false; break;
      }
      if(sq[i][j] != sq[dim-i-1][dim-j-1]){
        isMagic = false; break;
      }
    }
  }
  return isMagic;
}

string onlyAlpha(string s){
  string final = "";
  for(int j=0; j<s.size(); j++){
    if(islower(s[j]))
      final += s[j];
  }
  return final;
}
