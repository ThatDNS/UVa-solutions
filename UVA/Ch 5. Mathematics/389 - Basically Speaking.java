// Problem: 389 - Basically Speaking
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNext()){
      String num = sc.next();
      int b1 = sc.nextInt();
      int b2 = sc.nextInt();
      BigInteger b = new BigInteger(num, b1);
      String ans = b.toString(b2);
      if(ans.length() > 7)
        System.out.println("  ERROR");
      else
        System.out.printf("%7s%n", ans.toUpperCase());
    }
  }
}
