/*input
7
1 1
3 4
4 5
5 7
*/
// 0/1 knapsack
#include <bits/stdc++.h>
using namespace std;
void calcMaxValue(vector<int> wt, vector<int>val, int n);
int main(){
  int wtOfBag, a, b;
  cin >> wtOfBag;
  vector<int> wt;
  vector<int> val;
  while(cin >> a >> b){
    wt.push_back(a);
    val.push_back(b);
  }
  calcMaxValue(wt, val, wtOfBag);
}

void calcMaxValue(vector<int> wt, vector<int>val, int n){
  int T[wt.size()][n+1];
  for(int i=0; i<wt.size(); i++){
    for(int j=0; j<=n; j++){
      if(j < wt[i]){
        if(i>0)
          T[i][j] = T[i-1][j];
        else
          T[i][j] = 0;
      }else{
        if(i>0)
          T[i][j] = max(T[i-1][j], val[i]+T[i-1][j-wt[i]]);
        else
          T[i][j] = val[i];
      }
    }
  }
  cout << "Max value is: " << T[wt.size()-1][n] << "\n";
  cout << "The weights taken are: ";
  int i = wt.size()-1, j = n;
  while(i>=0 && T[i][j]!=0){
    if(T[i][j] == T[i-1][j]){
      i--;
    }else{
      cout << wt[i] << " ";
      j-=wt[i];
      i--;
    }
  }
  cout << "\n";
}
