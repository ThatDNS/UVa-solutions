// Problem: 10334 - Ray Through Glasses
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] fiboNums = new BigInteger[1006];
    fiboNums[0] = BigInteger.valueOf(1);
    fiboNums[1] = BigInteger.valueOf(2);
    for(int i=2; i<=1000; i++)
      fiboNums[i] = fiboNums[i-1].add(fiboNums[i-2]);
    int num = 0;
    while(sc.hasNext()){
      num = sc.nextInt();
      System.out.println(fiboNums[num]);
    }
  }
}
