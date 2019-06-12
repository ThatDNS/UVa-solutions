// Problem: 324 - Factorial Frequencies
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] factorials = new BigInteger[1005];
    factorials[0] = BigInteger.ONE;
    factorials[1] = BigInteger.ONE;
    for(int i=2; i<=366; i++){
      factorials[i] = factorials[i-1].multiply(BigInteger.valueOf(i));
    }
    int[] nums = new int[12];
    while(sc.hasNext()){
      int n = sc.nextInt();
      if(n==0) break;
      String s = factorials[n].toString(10);
      for(int i=0; i<=9; i++)
        nums[i] = 0;
      for(int i=0; i<s.length(); i++){
        nums[Character.getNumericValue(s.charAt(i))]++;
      }
      System.out.println(n + "! --");
      for(int i=0; i<=9; i++){
        if(i==0 || i==5) System.out.printf("   (" + i + ")");
        else System.out.printf("    (" + i + ")");
        System.out.printf("%5s", nums[i]);
        if(i==4) System.out.println();
      }
      System.out.println();
    }
  }
}
