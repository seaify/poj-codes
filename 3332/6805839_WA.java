import java.util.*;
import java.util.regex.*;



public class Main {
        public static void main(String[] args) throws Exception
        {
        	int i,T;
        	String a,myRegex;
        	myRegex="^\\s*([+-])?\\d+(\\.\\d+)?([eE]([+-])?\\d+)?\\s*$";
        	
        	Pattern p=java.util.regex.Pattern.compile(myRegex);
        	
        	Scanner cin=new Scanner(System.in);
        	T=cin.nextInt();
        	cin.nextLine();
        	
        	for(i=1;i<=T;i++)
        	{
        		a=cin.nextLine();
        		java.util.regex.Matcher m=p.matcher(a);
        		if(m.find())
        		{
        			System.out.println(m.group());
        			System.out.println("LEGAL");
        		}
        		else
        			System.out.println("ILLEGAL");
        	}
        }
}

