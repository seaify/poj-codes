import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class HelloWord {
     public static void main(String[] args)
     {
    	 Scanner cin = new Scanner (new BufferedInputStream(System.in));
         int i,a,T;
         BigInteger x,y;
         String c,d;
         
         T=cin.nextInt();
         for(i=1;i<=T;i++)
         {
               c=cin.next();
               if(c.charAt(0)=='+')
            	   c=c.substring(1);
               x=new BigInteger(c);
               d=cin.next();
               if(d.charAt(0)=='+')
            	   c=c.substring(1);
               y=new BigInteger(d);  
               System.out.println(x.add(y));
         }
     
     }
}
