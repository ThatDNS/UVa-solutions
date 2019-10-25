// Problem: 10567 - Helping Fill Bates

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
  string s, ss;
  cin >> s;
  int q;
  cin >> q;
  set<int> line;
  vector<vector<int> > allInd;
  allInd.assign(53, vector<int>());
  for(int i=0; i<s.length(); i++){
    if(s[i]-'a' >= 0){
      line.insert(s[i]-'a');
      allInd[s[i]-'a'].pb(i);
    }else{
      line.insert(s[i]-'A'+26);
      allInd[s[i]-'A'+26].pb(i);
    }
  }
  for(int i=0; i<52; i++){
    sort(allInd[i].begin(), allInd[i].end());
  }
  int curr;
  int firstCharInd, lastCharInd, prevCharInd, index, indexxx;
  set<int>::iterator it;
  bool canBeDone;
  while(q--){
    cin >> ss;
    firstCharInd=-1; lastCharInd=-1; prevCharInd=-1;
    canBeDone = true;
    for(int i=0; i<ss.length(); i++){
      if(ss[i]-'a' >= 0)
        curr = ss[i]-'a';
      else
        curr = ss[i]-'A'+26;
      it = line.lower_bound(curr);
      if(*it == curr){ // this char is present
        // find index >= prev chosen index
        if(prevCharInd == -1)
          indexxx = 0;
        else
          indexxx = lower_bound(allInd[curr].begin(), allInd[curr].end(), prevCharInd+1) - allInd[curr].begin();
        if(indexxx > allInd[curr].size()-1){
          canBeDone = false;
          break;
        }
        index = allInd[curr][indexxx];
        if(firstCharInd == -1) firstCharInd = index;
        prevCharInd = index;
        if(i == ss.length()-1) lastCharInd = index;
      }
    }
    if(canBeDone)
      printf("Matched %d %d\n", firstCharInd, lastCharInd);
    else
      printf("Not matched\n");
  }
  return 0;
}
