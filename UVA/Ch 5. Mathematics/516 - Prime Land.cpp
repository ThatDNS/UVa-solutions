// Problem: 516 - Prime Land
#include <bits/stdc++.h>
using namespace std;
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
#define vi vector<int>
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define For0(i,n) for(int i=0; i<n; i++)
#define ForF(i,a,b) for(int i=a; i<=b; i++)
#define TheCase(i) printf("Case %d: ", i);
#define pb push_back
#define mp make_pair
#define ll long long
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(false);
#define disableAutoFlush cin.tie(NULL);
#define MOD 1000000007

vi priNums;
vi factors;
bitset<10000010> bs; // 10^7
void sieve(ll upperBound){
  ll sieveSize = upperBound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<=sieveSize; i++)
    if(bs[i]){
      priNums.pb(i);
      // cross out multiples of i starting from i
      for(ll j=i*i; j<=sieveSize; j+=i)
        bs[j] = 0;
    }
}
void getFactors(ll N);

int main(){
  vi nums;
  ll no;
  sieve(33000);
  string s, temp;
  map<int, int, greater<int> > facs;
  map<int, int>::iterator it;
  while(getline(cin, s) && s != "0"){
    nums.clear(); factors.clear(); facs.clear();
    stringstream ss(s);
    while(ss >> temp){
      nums.pb(stoi(temp));
    }
    no = 1;
    for(int i=0; i<nums.size(); i+=2){
      no *= pow(nums[i], nums[i+1]);
    }
    getFactors(no-1);
    for(int i: factors){
      if(facs.count(i) == 0){
        facs.insert(pair<int, int>(i, 1));
      }else{
        it = facs.find(i);
        (it->second)++;
      }
    }
    temp = "";
    for(it = facs.begin(); it != facs.end(); ++it)
      temp += to_string(it->first) + " " + to_string(it->second) + " ";
    temp = temp.substr(0, temp.size()-1);
    cout << temp;
    printf("\n");
  }
  return 0;
}

void getFactors(ll N){
  int ind=0;
  int PF = priNums[ind];
  while(PF*PF <= N){
    while(N%PF == 0){
      factors.pb(PF);
      N /= PF;
    }
    PF = priNums[++ind];
  }
  if(N!=1) factors.pb(N);
}
