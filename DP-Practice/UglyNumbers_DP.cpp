// Sample Input: 150
// Output: 5832

// Ugly Numbers (DP)
// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
// The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
// By convention, 1 is included.

// Problem: Find nth ugly number.

/**
 *  Author: DNS-404
 **/

#include <bits/stdc++.h>
using namespace std;
bool checkUgly(bool arr[], int n);
int findUgly(bool arr[], int n);

int main(){
  int n;
  cin >> n;
  bool arr[10000]; // program will fail if number exceeds 10000
  arr[0] = 0;
  arr[1] = 1;
  for(int i=2; i<10000; i++)
    arr[i] = 0;
  cout << findUgly(arr, n) << endl;
  return 0;
}

int findUgly(bool arr[], int n){
  int count = 0, currNo=1;
  while(count < n){
    if(checkUgly(arr, currNo)){
      count++;
    }
    currNo++;
  }
  return currNo-1;
}

bool checkUgly(bool arr[], int n){
  if(n==1)
    return true;
  if(arr[n])
    return arr[n];
  if(n%2==0){
    arr[n] = checkUgly(arr, n/2);
    cout<<"arr["<<n<<"]="<<arr[n]<<endl;
  }else if(n%3==0){
    arr[n] = checkUgly(arr, n/3);
    cout<<"arr["<<n<<"]="<<arr[n]<<endl;
  }else if(n%5==0){
    arr[n] = checkUgly(arr, n/5);
    cout<<"arr["<<n<<"]="<<arr[n]<<endl;
  }else{
    arr[n] = false;
  }
  return arr[n];
}
