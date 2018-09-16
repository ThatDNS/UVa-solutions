/*input
5832
*/
// Ugly Numbers (recursive)
// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
// The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
// By convention, 1 is included.
// Check if a number is ugly.
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
bool checkUgly(int n);
int main(){
  int n;
  cin >> n;
  if(checkUgly(n))
    cout << "Yes it's ugly!" << endl;
  else
    cout << "No it's not ugly!" << endl;
  return 0;
}

bool checkUgly(int n){
  if(n==1)
    return true;
  if(n%2==0){
    return checkUgly(n/2);
  }else if(n%3==0){
    return checkUgly(n/3);
  }else if(n%5==0){
    return checkUgly(n/5);
  }else{
    return false;
  }
}

