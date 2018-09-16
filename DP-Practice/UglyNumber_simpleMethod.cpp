/*input
150
*/
// Ugly Numbers (Simple method)
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int getUgly(int n);
bool isUgly(int x);
int checkDivisibility(int a, int n);
int main(){
  int n;
  cin >> n;
  cout << getUgly(n) << endl;
  return 0;
}

int getUgly(int n){
  int count = 0, currNo=1;
  while(count < n){
    if(isUgly(currNo)){
      count++;
    }
    currNo++;
  }
  return currNo-1;
}

bool isUgly(int x){
  x = checkDivisibility(x, 2);
  x = checkDivisibility(x, 3);
  x = checkDivisibility(x, 5);
  if(x==1)
    return true;
  else
    return false;
}

int checkDivisibility(int a, int n){
  while(a%n == 0){
    a = a/n;
  }
  return a;
}
