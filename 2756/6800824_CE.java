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
		int i;
		BigInteger x,y,result;
		String myRegex = "+?(-?%d+)";

		Pattern p = java.util.regex.Pattern.compile(myRegex);

		for(i=0;i<2;i++)
		{
		    a=Scanner.nextLine();
			Matcher m = p.matcher(a);
            a=m.group();
            x[i]=Integer.parseInt(a);
		}
        result=x[0].add(x[1]);
		System.out.println(result);
	}
}