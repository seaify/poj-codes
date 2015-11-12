import java.io.*;
import java.math.*;
import java.util.*;


public class Main {
     public static void main(String[] args)
     {  
    	 int m;
    	 String x,y; 
         BigInteger a,b,c;
         
    	 Scanner cin = new Scanner (new BufferedInputStream(System.in));
    	 while(true)
    	 {
    	  
            m=cin.nextInt();
            if(m==0)
        	    return ;
            x=cin.next();
            y=cin.next();
            a=new BigInteger(x,m);
            b=new BigInteger(y,m);
            c=a.mod(b);
            x=c.toString(m);
            System.out.println(x);
        }
     }
}
