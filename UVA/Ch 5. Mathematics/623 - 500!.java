// Problem: 623 - 500!
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] factorials = new BigInteger[1005];
    factorials[0] = BigInteger.ONE;
    factorials[1] = BigInteger.ONE;
    for(int i=2; i<=1000; i++){
      factorials[i] = factorials[i-1].multiply(BigInteger.valueOf(i));
    }
    while(sc.hasNext()){
      int n = sc.nextInt();
      System.out.println(n + "!");
      System.out.println(factorials[n]);
    }
  }
}
