import java.io.*;
import java.math.*;
import java.util.*;


public class Main{
     public static void main(String[] args)
     {  
    	 int i,j,a,b,v,T;
    	 String x;
    	 char it;
    	 char[] ch;
    	 ch=new char[200];

    	 BigInteger c,Z,M,N,tmp,base,sum;
    	 
    	 for(it='0';it<='9';it++)
    		 ch[it-'0']=it;
    	 for(it='A';it<='Z';it++)
    		 ch[it-'A'+10]=it;
    	 for(it='a';it<='z';it++)
    		 ch[it-'a'+36]=it;
    	 
    	 Scanner cin = new Scanner (new BufferedInputStream(System.in));
  
    	 Z=BigInteger.valueOf(0);
    	 T=cin.nextInt();
    	 for(j=1;j<=T;j++)
    	 {
    		 a=cin.nextInt();
    		 b=cin.nextInt();
    		 x=cin.next();
    		 M=BigInteger.valueOf(a);
    		 N=BigInteger.valueOf(b);
    		 sum=BigInteger.valueOf(0);
    		 base=BigInteger.valueOf(1);
    		 System.out.println(a+" "+x);
     		// 2 11011100000100010111110010010110011111001001100011010010001
       
    		 for(i=x.length()-1;i>=0;i--)
    		 {
    		     v=x.charAt(i);
    		     if(v>='0'&&v<='9')
    		    	 v-='0';
    		     else if(v>='A'&&v<='Z')
    		    	 v=v-'A'+10;
    		     else
    		    	 v=v-'a'+36;
    		     sum=sum.add(base.multiply(BigInteger.valueOf(v)));
    		     base=base.multiply(M);
    		 }
    		 if(sum.compareTo(Z)==0)
    			 System.out.println(b+" 0\n");
    		 else
    		 {
    			 String y="";
    		     while(sum.compareTo(Z)==1)
    		     {
    		    	 v=sum.mod(N).intValue();  ///
    		    	 y+=ch[v];
    		    	 sum=sum.divide(N);
    		     }
    		     System.out.print(b+" ");
    		     for(i=y.length()-1;i>=0;i--)
    		    	 System.out.print(y.charAt(i));
    		     System.out.println("\n");
    		 }
    		    		 
    	 }
    	 
     }
}
