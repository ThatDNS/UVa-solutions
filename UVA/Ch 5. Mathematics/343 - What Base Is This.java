// Problem: 343 - What Base Is This?

import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNext()){
      String s1 = sc.next();
      String s2 = sc.next();
      s1 = s1.toUpperCase(); s2 = s2.toUpperCase();
      BigInteger big1, big2;
      Boolean found = false;
      int i=0, j=0;
      for(i=2; i<=36 && !found; i++){
        for(j=2; j<=36 && !found; j++){
          try {
            big1 = new BigInteger(s1, i);
            big2 = new BigInteger(s2, j);
            if(big1.equals(big2))
              found = true;
          }
          catch(NumberFormatException ex){
            continue;
          }
        }
      }
      i = i-1;
      j = j-1;
      if(found){
        System.out.println(s1+" (base "+i+") = "+s2+" (base "+j+")");
      }else{
        System.out.println(s1+" is not equal to "+s2+" in any base 2..36");
      }
    }
  }
}
