// Problem: 11951 - Area
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define For0(i,n) for(int i=0;i<n;i++)
#define ForA(i,a,n) for(int i=a;i<n;i++)
#define EPS 1e-9 // 10^-9
#define pb push_back
#define INF 1e9 // 10^9

int main(){
  short int tc, N, M;
  long long K;
  int P[105][105], area[105][105], cases=0;
  cin >> tc;
  while(tc--){
    cin >> N >> M >> K;
    int ar=1;
    For0(i, N)
      For0(j, M){
        scanf("%d", &P[i][j]);
        area[i][j] = ar;
      }
    For0(i, N)
      For0(j, M){
        if(i>0){
          P[i][j] += P[i-1][j];
          area[i][j] += area[i-1][j];
        }
        if(j>0){
          P[i][j] += P[i][j-1];
          area[i][j] += area[i][j-1];
        }
        if(i>0 && j>0){
          P[i][j] -= P[i-1][j-1];
          area[i][j] -= area[i-1][j-1];
        }
      }
    // For0(i, N){
    //   For0(j, M)
    //     printf("%d  ", area[i][j]);
    //   printf("\n");
    // }printf("\n");
    // For0(i, N){
    //   For0(j, M)
    //     printf("%d  ", P[i][j]);
    //   printf("\n");
    // }printf("\n");
    int tempAr, tempPrc;
    int currArea=INT_MIN, currPrice=INT_MIN; 
    For0(i, N) For0(j, M)
    ForA(k, i, N) ForA(l, j, M){
      tempAr = area[k][l];
      if(i>0) tempAr -= area[i-1][l];
      if(j>0) tempAr -= area[k][j-1];
      if(i>0 && j>0) tempAr += area[i-1][j-1];
      tempPrc = P[k][l];
      if(i>0) tempPrc -= P[i-1][l];
      if(j>0) tempPrc -= P[k][j-1];
      if(i>0 && j>0) tempPrc += P[i-1][j-1];
      if(tempAr > currArea && tempPrc <= K){
        currArea = tempAr;
        currPrice = tempPrc;
      }else if(tempAr == currArea && tempPrc <= K){
        if(currPrice > tempPrc)
          currPrice = tempPrc;
      }
    }
    if(currPrice == INT_MIN || currArea == INT_MIN){
      currPrice=0; currArea=0;
    }
    printf("Case #%d: %d %d\n", ++cases, currArea, currPrice);
  }
  return 0;
}
