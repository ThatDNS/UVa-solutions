// Problem: 11879 - Multiple of 17

import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNextLine()){
      String num = sc.nextLine();
      if(num.equals("0")) break;
      BigInteger n = new BigInteger(num);
      BigInteger d = n.mod(BigInteger.valueOf(10));
      n = n.divide(BigInteger.valueOf(10));
      d = d.multiply(BigInteger.valueOf(5));
      n = n.subtract(d);
      n = n.mod(BigInteger.valueOf(17));
      if(n.equals(BigInteger.ZERO))
        System.out.println(1);
      else
        System.out.println(0);
    }
  }
}
