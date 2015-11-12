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
        String a;
		int x,i;

		BigInteger c,d;
                BigInteger result;
		String myRegex = "+?(-?%d+)";

		Pattern p = java.util.regex.Pattern.compile(myRegex);

		for(i=0;i<2;i++)
		{
		    a=cin.nextLine();
			Matcher m = p.matcher(a);
            a=m.group();
            x=Integer.parseInt(a);
			if(i==0) c=BigInteger.valueOf(x);
 else
                  d=BigInteger.valueOf(x);
		}
        result=c.add(d);
		System.out.println(result);
	}
}