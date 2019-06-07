// Problem: 713 - Adding Reversed Numbers
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int cases = sc.nextInt();
    while(cases>0){
      --cases;
      BigInteger num1 = sc.nextBigInteger();
      BigInteger num2 = sc.nextBigInteger();
      String s1 = num1.toString(), s2 = num2.toString();
      StringBuilder ss1 = new StringBuilder();
      StringBuilder ss2 = new StringBuilder();
      ss1.append(s1); ss2.append(s2);
      ss1 = ss1.reverse();
      ss2 = ss2.reverse();
      num1 = new BigInteger(ss1.toString());
      num2 = new BigInteger(ss2.toString());
      num1 = num1.add(num2);
      ss1 = new StringBuilder();
      ss1.append(num1.toString());
      ss1 = ss1.reverse();
      num1 = new BigInteger(ss1.toString());
      System.out.println(num1);
    }
  }
}
