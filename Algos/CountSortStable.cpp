/*input
8
2 5 3 0 2 3 0 3
*/
// Count Sort (Stable Version)
// Running Time: O(n+k)
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k=5;
  cin >> n;
  int arr[n], count[k+1], Final[n+1];
  // Size of count is the (largest number allowed + 1). In the example largest number is 5.
  // Index '3' of count will store the number of values less than or equal to 3.
  for(int i=0; i<n; i++)
    cin >> arr[i];
  for(int i=0; i<=k; i++)
    count[i]=0;
  for(int i=0; i<n; i++)
    ++count[arr[i]];

  for(int i=1; i<=k; i++){
    count[i] += count[i-1];
  }

  for(int i=n-1; i>=0; i--){
    Final[count[arr[i]]] = arr[i];
    count[arr[i]]--;
  }

  for(int i=1; i<=n; i++)
    printf("%d ", Final[i]);
  printf("\n");
  return 0;
}

