import java.io.*;
import java.math.*;
import java.util.*;


public class Main{
     public static void main(String[] args)
     {  
    	 int i,sum;
    	 String x,y; 
         BigInteger a,b,c,d;
         BigInteger[] f;
         f = new BigInteger[500];
    
         d=BigInteger.valueOf(10);
         c=d.pow(100);
         d=BigInteger.valueOf(0);
         f[1]=BigInteger.valueOf(1);
         f[2]=BigInteger.valueOf(1);
         for(i=3;i<=800;i++)
         {
        	 f[i]=f[i-1].add(f[i-2]);
        	 if(f[i].compareTo(c)==1)
        		 break;
         }
        
     
    	 Scanner cin = new Scanner (new BufferedInputStream(System.in));
    	 while(true)
    	 {
    		 a=cin.nextBigInteger();
    		 b=cin.nextBigInteger();
    		 if(a.compareTo(d)==0&&b.compareTo(d)==0)
    			 return ;
    		 sum=0;
    		 for(i=1;i<=481&&f[i].compareTo(b)<=0;i++)
    			 if(f[i].compareTo(a)>=0)
    				 ++sum;
    		 System.out.println(sum);
    	 }
    	 
     }
}
