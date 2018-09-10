// Problem: 514 - Rails
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using std::cout; using std::cin; using std::string; using std::endl;
std::vector<string> SeparatorToVec(string s, char separator){
  std::vector<string> nums;
  std::stringstream ss(s);
  string indivStr;
  while(getline(ss, indivStr, separator)){
    nums.push_back(indivStr);
  }
  return nums;
}
int main(){
  int n=5, a, curr=0;
  string str;
  while(cin >> n && n!=0){
    getline(cin, str); // storing extra newline
    while(getline(cin, str)){
      std::vector<string> nums = SeparatorToVec(str, ' ');
      if(nums[0] == "0"){
        break;
      }
      curr=0;
      std::stack<int> s;
      for(auto num: nums){
        a = std::stoi(num);
        if(a>curr){
          for(int i=curr+1; i<=a; i++){
            s.push(i);
            curr = a;
          }
          s.pop();
        }else{
          if(s.top() == a)
            s.pop();
        }
      }
      if(s.empty())
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    cout << "\n";
  }
  return 0;
}
