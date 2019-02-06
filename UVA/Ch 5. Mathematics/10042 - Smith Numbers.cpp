// Problem: 10042 - Smith Numbers

/**
 *  Author: DNS404
 **/
#include <bits/stdc++.h>
using namespace std;
/*---------------Bitmask---------------*/
#define setBit(S, pos) (S |= (1 << pos))
#define resetBit(S, pos) (S &= ~(1 << pos))
#define checkBit(S, pos) (S & (1 << pos))
#define toggleBit(S, pos) (S ^= (1 << pos))
#define lowBit(S) (S & (-S)) //get least bit that is 1
/*-------------------------------------*/
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define PI 3.14159265
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define For0(i,n) for(int i=0; i<n; i++)
#define For(i,a,b) for(int i=a; i<=b; i++)
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

ll sumOfDigits(string n);
void SieveOfEratosthenes(int n);
bool isSmith(ll n);
vi primes;

int main(){
  ll t, n;
  string s;
  SieveOfEratosthenes(100000);
  cin >> t;
  while(cin >> n){
    ++n;
    while(!isSmith(n))
      ++n;
    cout << n << endl;
  }
  return 0;
}

bool isSmith(ll n){
  ll sum1 = sumOfDigits(to_string(n)), sum2, count=0, temp;
  vi factors;
  string s = "";
  ll no = n;
  for(int i=0; i<primes.size(); i++){
    if(no%primes[i] == 0){
      no = no/primes[i];
      factors.pb(primes[i]);
      i=-1;
      ++count;
    }
    if(i == primes.size()-1 && no>1){
      factors.pb(no);
      no = 1;
      i = -1;
      ++count;
    }
    if(no == 1)
      break;
  }
  for(int i=0; i<factors.size(); i++){
    temp = factors[i];
    s += to_string(temp);
  }
  sum2 = sumOfDigits(s);
  if(sum1 == sum2 && count>1)
    return true;
  return false;
}

ll sumOfDigits(string n){
  ll sum=0;
  string c;
  for(int i=0; i<n.length(); i++){
    c = n.substr(i,1);
    sum += stoi(c);
  }
  return sum;
}

void SieveOfEratosthenes(int n){
  bool prime[n+1];
  clr(prime, true);
  for(int p=2; p*p<=n; p++){
    if(prime[p]){
      for(int i=p*p; i<=n; i+=p)
        prime[i] = false;
    }
  }
  for(int p=2; p<=n; ++p){
    if(prime[p])
      primes.pb(p);
  }
}

