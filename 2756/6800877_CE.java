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
		int i,x[];
		BigInteger y[] , result;
		String myRegex = "+?(-?%d+)";

		Pattern p = java.util.regex.Pattern.compile(myRegex);

		for(i=0;i<2;i++)
		{
		    a=cin.nextLine();
			Matcher m = p.matcher(a);
            a=m.group();
            x[i]=Integer.parseInt(a);
			y[i]=BigInteger.valueOf(x[i]);
		}
        result=y[0].add(y[1]);
		System.out.println(result);
	}
}