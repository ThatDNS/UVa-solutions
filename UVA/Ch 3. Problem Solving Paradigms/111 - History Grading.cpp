// Problem: 111 - History Grading
// This can be solved by either Longest inc subseq or longest common subseq. I've used LIS to solve it.

#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define PI 3.14159265
#define EPS 1e-9 // 10^-9
#define pb push_back
#define mp make_pair
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

int n, c_rank[22], curr[22], LIS[22];
bool comesAfter(int a, int b);

int main(){
  int i, flag=0, ans, maxNum, temp;
  string s;
  while(getline(cin, s)){
    if(flag==0){
      n = stoi(s);
      getline(cin, s);
    }
    i=0;
    istringstream is(s);

    while(is >> temp){
      temp--;
      c_rank[temp] = i;
      ++i;
    }

    while(getline(cin, s) && s.length() > 2){
      i=0;
      istringstream is(s);
      while(is >> temp){
        temp--;
        curr[temp] = i;
        ++i;
      }

      LIS[0] = 1;
      ans = 1;
      for(int i=1; i<n; i++){
        maxNum = 0;
        for(int j=0; j<i; j++){
          if(comesAfter(curr[i], curr[j]))
            maxNum = max(maxNum, LIS[j]);
        }
        LIS[i] = maxNum + 1;
        ans = max(ans, LIS[i]);
      }
      printf("%d\n", ans);
    }

    if(flag==0) flag=1;
    if(s.length() <= 2 && s!="") n = stoi(s);
  }
  return 0;
}

bool comesAfter(int a, int b){
  // does a come after b?
  int ind_a=-1, ind_b=-1;
  for(int i=0; i<n; i++){
    if(c_rank[i] == a)
      ind_a = i;
    else if(c_rank[i] == b)
      ind_b = i;
  }
  if(ind_a > ind_b)
    return true;
  return false;
}

