import java.io.*;
import java.math.*;
import java.util.*;


public class Main{
     public static void main(String[] args)
     {  
    	 int i,v;
    	 String x,y; 
    	 BigDecimal a,b,c,M,tmp,sum;
         M= new BigDecimal(8);
    	 Scanner cin = new Scanner (new BufferedInputStream(System.in));
         while(true)
    	 {
    	     x=cin.next();
    	     sum= new BigDecimal(0);
    	     a= new BigDecimal(x);
    	     b= new BigDecimal(8);
    	     c= new BigDecimal(1);
    	     for(i=2;i<x.length();i++)
    	     {
                 v=x.charAt(i)-'0';
                 tmp=c.multiply(BigDecimal.valueOf(v));
                 tmp=tmp.divide(b);
                 b=b.multiply(M);
                 sum=sum.add(tmp);
    	     }
    	 //    0.75 [8] = 0.953125 [10]

    	     System.out.println(x+" [8] = "+sum.toString()+" [10]");
    	 }
    	 
     }
}
