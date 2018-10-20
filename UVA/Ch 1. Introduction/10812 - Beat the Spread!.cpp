// Problem: 10812 - Beat the Spread!
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, s, d, x, y;
  cin >> n;
  while(n-- > 0){
    x=0; y=0;
    cin >> s >> d;
    x = (s+d)/2;
    y = s-x;
    if(x>=0 && y>=0 && ((x+y == s) && (abs(x-y) == d)))
      if(x>y)
        cout << x << " " << y << endl;
      else
        cout << y << " " << x << endl;
    else
      cout << "impossible\n";
  }
  return 0;
}
