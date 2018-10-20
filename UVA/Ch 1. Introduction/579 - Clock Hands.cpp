// Problem: 579 - Clock Hands
/**
 *  Author: DNS-404
 **/
#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, M;
  float angleH, angleM, netAngle;
  while(scanf("%d:%d", &H, &M)){
    if(H==0 && M==0)
      break;
    if(H!=12){
      angleH = 30*H + (0.5)*M;
    }else{
      angleH = (0.5)*M;
    }
    angleM = 6*M;
    netAngle = (angleM>=angleH)?(angleM-angleH):(angleH-angleM);
    if(netAngle>180){
      netAngle = 360 - netAngle;
    }
    printf("%.3f\n", netAngle);
  }
  return 0;
}
