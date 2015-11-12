import java.util.*;
import java.util.regex.*;

public class Main {
        public static void main(String[] args) throws Exception
        {
        	int i,T,flag;
        	String a,word,myC,myJava,first,next;
        	myC="^[^_]+(_[^_]+)*$";
        
        	Pattern p1=java.util.regex.Pattern.compile(myC);
        	Scanner cin=new Scanner(System.in);
        
        	T=0;
            while(cin.hasNext())
            {
            	++T;
            	flag=0;
            	word=cin.next();
            	java.util.regex.Matcher m=p1.matcher(word);
            	
            	if(word.matches("^.*_.*$")&&m.find())   ///C++
            	{
            		if(word.matches("^.*[A-Z].*$"))
            			flag=1;          ///不合法...     
            		else
            		for(i=0;i<word.length();i++)
            			if(word.charAt(i)=='_')
            				continue;
            			else if(i>0&&word.charAt(i-1)=='_')
            				System.out.print(Character.toUpperCase(word.charAt(i)));
            			else
            				System.out.print(word.charAt(i));
            		
            		 //  System.out.print("shit");
            	}
            
            	else if(word.matches("[a-z][^_]*"))
            	{          	     
                       //   System.out.print("shit");
            	      for(i=0;i<word.length();i++)
            	    		   if(word.charAt(i)>='A'&&word.charAt(i)<='Z')
            	    			   System.out.print("_"+Character.toLowerCase(word.charAt(i)));
            	    		   else
            	    			   System.out.print(word.charAt(i));
            	  
            
            	}
            	else
            		flag=1;
            	
         
            	if(flag==1)
            		System.out.print("Error!");
            	System.out.println();
            
            }
        }
}


