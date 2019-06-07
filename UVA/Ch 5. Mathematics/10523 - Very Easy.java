// Problem: 10523 - Very Easy !!!

import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    while(sc.hasNextInt()){
      int n = sc.nextInt();
      int a = sc.nextInt();
      BigInteger ans = new BigInteger("0");
      for(int i=1; i<=n; i++){
        BigInteger temp = BigInteger.valueOf(a);
        temp = temp.pow(i);
        temp = temp.multiply(BigInteger.valueOf(i));
        ans = ans.add(temp);
      }
      System.out.println(ans);
    }
  }
}
