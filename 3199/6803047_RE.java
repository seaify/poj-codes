import java.io.*;
import java.math.*;
import java.util.*;


public class Main {
     public static void main(String[] args)
     {
    	 while(true)
    	 {
    		 Scanner cin = new Scanner (new BufferedInputStream(System.in));
         
    	 int x,y;
         BigInteger a,c;
         
         x=cin.nextInt();
         y=cin.nextInt();
         if(x==0&&y==0)
        	 return ;
         a=BigInteger.valueOf(x);
         c=a.pow(y);
         System.out.println(c);
     }
     }
}
