// Problem: 10312 - Expression Bracketing
import java.util.*;
import java.math.*;
import java.io.*;

class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    BigInteger[] supCat = new BigInteger[30];
    supCat[1] = BigInteger.ONE;
    supCat[2] = BigInteger.ONE;
    BigInteger a, b;
    for(int i=3; i<=26; i++){
      a = supCat[i-1].multiply(BigInteger.valueOf(6*i-9));
      b = supCat[i-2].multiply(BigInteger.valueOf(i-3));
      supCat[i] = a.subtract(b);
      supCat[i] = supCat[i].divide(BigInteger.valueOf(i));
    }
    BigInteger[] cat = new BigInteger[30];
    cat[0] = BigInteger.ONE;
    cat[1] = BigInteger.ONE;
    for(int i=2; i<=25; i++){
      cat[i] = BigInteger.valueOf((2*i)*((2*i)-1));
      cat[i] = cat[i].multiply(cat[i-1]);
      cat[i] = cat[i].divide(BigInteger.valueOf((i+1)*i));
    }
    while(sc.hasNext()){
      int i = sc.nextInt();
      System.out.println(supCat[i].subtract(cat[i-1]));
    }
  }
}
