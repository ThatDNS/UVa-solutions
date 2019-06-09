// Problem: 763 - Fibinary Numbers
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] FiboNums = new BigInteger[115];
    FiboNums[1] = new BigInteger("1");
    FiboNums[2] = new BigInteger("2");
    for(int i=3; i<=109; i++)
      FiboNums[i] = FiboNums[i-1].add(FiboNums[i-2]);
    int j;
    int[] indices = new int[125];
    Boolean firstFound = false, flag=false;
    while(sc.hasNext()){
      String s1 = sc.next();
      String s2 = sc.next();
      if(flag){System.out.print("\n");}
      else{flag=true;}
      BigInteger val1 = BigInteger.ZERO;
      BigInteger val2 = BigInteger.ZERO;
      j=0;
      for(int i=s1.length()-1; i>=0; i--){
        if(s1.charAt(i) == '1')
          val1 = val1.add(FiboNums[j+1]);
        ++j;
      }
      j=0;
      for(int i=s2.length()-1; i>=0; i--){
        if(s2.charAt(i) == '1')
          val2 = val2.add(FiboNums[j+1]);
        ++j;
      }
      val1 = val1.add(val2);
      j=1;
      for(int i=0; i<=120; i++)
        indices[i] = 0;
      firstFound = false;
      while(!val1.equals(BigInteger.ZERO)){
        for(int i=108; i>=1; i--){
          if(val1.compareTo(FiboNums[i]) >= 0 && indices[i+1] != 1 && indices[i-1] != 1){
            val1 = val1.subtract(FiboNums[i]);
            indices[i] = 1;
            if(!firstFound){
              j = i;
              firstFound = true;
            }
            break;
          }
        }
      }
      for(int i=j; i>=1; i--)
        System.out.printf("%d", indices[i]);
      System.out.print("\n");
    }
  }
}
