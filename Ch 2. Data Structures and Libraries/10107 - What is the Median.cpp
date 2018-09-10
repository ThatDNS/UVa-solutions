// Problem: 10107 - What is the Median?
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  vector<int> nums;
  while(cin >> a){
    nums.push_back(a);
    sort(nums.begin(), nums.end());
    a = nums.size();
    if(a%2 != 0){
      printf("%d\n", nums[a/2]);
    }else{
      printf("%d\n", (nums[a/2]+nums[(a/2)-1])/2);
    }
  }
  return 0;
}
