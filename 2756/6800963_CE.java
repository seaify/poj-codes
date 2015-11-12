import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		Scanner cin=new Scanner(System.in);
        String a,c,d;
		int x,t,j,i;

		BigInteger f,g;
                BigInteger result;
		String myRegex = "+?(-?%d+)";

		Pattern p = java.util.regex.Pattern.compile(myRegex);
                t = cin.nextInt();
for(j=1;j<=t;j++)
{

		for(i=0;i<2;i++)
		{
		    a=cin.nextLine();
			Matcher m = p.matcher(a);
                    if(i==0) 
{c = m.group(); f = new BigInteger(c);}
else
{d = m.group();g = new BigInteger(d);
          System.out.println(f.add(g));}
                                             
		}

	}
}
}