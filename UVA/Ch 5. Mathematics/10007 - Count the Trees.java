// Problem: 10007 - Count the Trees
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] fact = new BigInteger[305];
    fact[1] = BigInteger.ONE;
    for(int i=2; i<=300; i++){
      fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
    }
    BigInteger[] cat = new BigInteger[305];
    cat[1] = BigInteger.ONE;
    for(int i=2; i<=300; i++){
      cat[i] = BigInteger.valueOf((2*i)*((2*i)-1));
      cat[i] = cat[i].multiply(cat[i-1]);
      cat[i] = cat[i].divide(BigInteger.valueOf((i+1)*i));
    }
    while(sc.hasNext()){
      int i = sc.nextInt();
      if(i==0) break;
      System.out.println(cat[i].multiply(fact[i]));
    }
  }
}
