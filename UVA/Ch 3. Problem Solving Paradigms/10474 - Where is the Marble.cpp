// Problem: 10474 - Where is the Marble?

#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long a, long long b, long long c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define showTime cout<<'\n'<<"time elapsed: "<<clock()*1000.0 / CLOCKS_PER_SEC<<" ms"<<'\n';
#define TheCase(i) printf("Case #%d: ", i)
#define pb push_back
#define vi vector<int>
#define ll long long
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);

int main(){
  disableSync disableAutoFlush
  int n, q, inp, cases=1;
  vi nums;
  while(cin >> n >> q){
    if(n==0 && q==0) break;
    nums.clear();
    nums.assign(n, 0);
    for(int i=0; i<n; i++)
      cin >> nums[i];
    sort(nums.begin(), nums.end());
    printf("CASE# %d:\n", cases++);
    for(int i=0; i<q; i++){
      cin >> inp;
      int index = lower_bound(nums.begin(), nums.end(), inp) - nums.begin();
      if(index < nums.size() && nums[index] == inp){
        printf("%d found at %d\n", inp, index+1);
      }else{
        printf("%d not found\n", inp);
      }
    }
  }
  return 0;
}

