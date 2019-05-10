// Problem: 167 - The Sultan's Successors
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
#define PI 3.14159265
#define EPS 1e-9 // 10^-9
#define pb push_back
#define mp make_pair
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define clr(x,a) memset(x,a,sizeof(x))
#define disableSync ios_base::sync_with_stdio(0);
#define disableAutoFlush cin.tie(NULL); cout.tie(NULL);
#define SWAP(a,b) a=a^b, b=a^b, a=a^b

int board[10][10], avail[10][10];
vi allScores;
void genNonAvail(int ix, int ij);
void genAvail(int ix, int ij);
void waysSum(int ix, int ij, int score);

int main(){
  int k;
  string s;
  cin >> k;
  while(k--){
    allScores.clear();
    for(int i=0; i<9; i++)
      for(int j=0; j<9; j++)
        avail[i][j] = 1;
    for(int i=1; i<=8; i++){
      for(int j=1; j<=8; j++)
        cin >> board[i][j];
    }
    for(int j=1; j<=8; j++){
      if(avail[0][j]){
        // generate non-avail pos
        genNonAvail(1, j);
        waysSum(1, j, board[1][j]);
        // generate avail pos
        genAvail(1, j);
      }
    }
    sort(allScores.begin(), allScores.end());
    s = to_string(allScores[(int)allScores.size()-1]);
    cout << setw(5) << right << s << endl;
  }
  return 0;
}

void waysSum(int ix, int ij, int score){
  if(ix >= 8){
    allScores.pb(score);
    return;
  }
  for(int j=1; j<=8; j++){
    if(avail[ix+1][j]){
      // generate non-avail pos
      genNonAvail(ix+1, j);
      waysSum(ix+1, j, score + board[ix+1][j]);
      // generate avail pos
      genAvail(ix+1, j);
    }
  }
  return;
}

void genNonAvail(int ix, int ij){
  //row and col
  for(int i=1; i<=8; i++){
    avail[ix][i] = 0;
    avail[i][ij] = 0;
  }
  //diag
  int i=ix, j=ij;
  while(i>=1 && j>=1){ //Top left
    avail[i][j] = 0;
    --i; --j;
  }
  i=ix, j=ij;
  while(i>=1 && j<=8){ //Top right
    avail[i][j] = 0;
    --i; ++j;
  }
  i=ix, j=ij;
  while(i<=8 && j>=1){ //Bottom left
    avail[i][j] = 0;
    ++i; --j;
  }
  i=ix, j=ij;
  while(i<=8 && j<=8){ //Bottom right
    avail[i][j] = 0;
    ++i; ++j;
  }
  avail[ix][ij] = 10; //queen's position
}

void genAvail(int ix, int iy){
  vi I; vi J;
  avail[ix][iy] = 1;
  for(int i=1; i<=8; i++)
    for(int j=1; j<=8; j++){
      if(avail[i][j] == 10){
        I.pb(i); J.pb(j);
      }
      avail[i][j] = 1;
    }
  int i,j;
  for(int ind=0; ind<I.size(); ind++){
    i = I[ind]; j = J[ind];
    genNonAvail(i, j);
  }
}


// Solved again soln: (same approach)

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

int boardNums[10][10];
int allPos[100][10], ind, currPos[10];
void place(int row, int col);
bool canPlace(int x, int y);

int main(){
  disableSync
  int k;
  ll sum, temp;
  cin >> k;

  // Preprocessing
  ind = 0;
  for(int c=1; c<=8; c++){
    clr(currPos, 1);
    place(1, c);
  }

  // Evaluating
  while(k--){
    sum = -1;
    for(int i=1; i<=8; i++)
      for(int j=1; j<=8; j++)
        cin >> boardNums[i][j];
    for(int i=0; i<=91; i++){
      temp = 0;
      for(int j=1; j<=8; j++){
        temp += boardNums[j][allPos[i][j]];
      }
      sum = max(sum, temp);
    }
    cout << setw(5) << right << sum << endl;
  }
  return 0;
}

void place(int row, int col){
  currPos[row] = col;
  if(row == 8){
    for(int i=1; i<=8; i++)
      allPos[ind][i] = currPos[i];
    ++ind;
    return;
  }
  for(int c=1; c<=8; c++){
    if(canPlace(row+1, c))
      place(row+1, c);
  }
}

bool canPlace(int rowNo, int colNo){
  for(int r=1; r<rowNo; r++){
    if(currPos[r]==colNo || abs(colNo-currPos[r]) == abs(rowNo-r))
      return false;
  }
  return true;
}

