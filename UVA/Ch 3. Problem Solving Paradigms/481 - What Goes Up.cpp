// Problem: 481 - What Goes Up

/*
arr[i]: Stores input elements
L[i]: Stores the smallest ending value of all i length LISs found so far.
L_id[i]: Simply stores the index of the value in L[i] as per in arr.
Prev_id[i]: Stores the index of the previous element in the LIS ending at index i as per in arr.
ans[i]: An extra vector I created because I didn't want to print answer recursively :P
*/

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

int main(){
  vi arr;
  int temp, pos;
  while(cin >> temp)
    arr.pb(temp);

  vi L; vi L_id; vi Prev_id; vi ans;

  for(int i=0; i<arr.size(); i++){
    pos = lower_bound(L.begin(), L.end(), arr[i]) - L.begin();
    if(pos == L.size()){
      L.pb(arr[i]);
      L_id.pb(i);
    }else{
      L[pos] = arr[i];
      L_id[pos] = i;
    }
    if(pos == L.size() || pos == L.size()-1) temp = i;
    if(pos == 0) Prev_id.pb(-1);
    else Prev_id.pb(L_id[pos-1]);
  }

  printf("%lu\n-\n", L.size());

  while(temp != -1){
    ans.pb(arr[temp]);
    temp = Prev_id[temp];
  }

  sort(ans.begin(), ans.end());

  for(int i=0; i<ans.size(); i++)
    cout << ans[i] << endl;
  
  return 0;
}
