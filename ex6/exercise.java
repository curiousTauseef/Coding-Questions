import java.util.Scanner;
import java.io.*;
class ex{
	public static Scanner scanner=new Scanner(System.in);
	
	void firstThree()
	{
		String a,b;
		/* System.out.println("Enter 1st String");
		a=scanner.nextLine();
		
		System.out.println("Enter 2nd String");
		b=scanner.nextLine();
		
		StringBuffer x=new StringBuffer(a);
		x.append(b);
		System.out.println(x); */
		a=scanner.next();
		int len=a.length();
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<len;j++)
			{	StringBuilder str=new StringBuilder("");
				for(int k=i;k<=j;k++)
					str.append(a.charAt(k));
				if(j>=i)
				System.out.println(str);
					
			}
		}
		
	}
	
	void rotation()
	{	int n=0,len=0,i=0;
		char[] a;
		try{
			BufferedReader buffer=new BufferedReader(new InputStreamReader(System.in));
			a=buffer.readLine().toCharArray();
		}catch(Exception e)
		{
			a=new char[50];
		}
		
		//a=scanner.next();
		n=scanner.nextInt();
		
		/* for( i=0;a[i]!='\0';i++);
		len=i; */
		len=a.length;
		for( i=1;i<=n;i++)
		{
			char temp=a[len-1];
			for(int j=len-2;j>=0;j--)
			{
				a[j+1]=a[j];
			}
			a[0]=temp;
		}
		//a[len]='\0';
		for(char m:a)
		System.out.print(m);
	}
	
	void getIntegerValue()
	{
		String s="";
		s=scanner.next();
		int num=0,len=0;
		
		len=s.length();
		for(int i=0;i<s.length();i++)
		{
			switch(s.charAt(i))
			{
				case '0':break;
				case '1':num+=(int)Math.pow(2,(4*(len-i-1)));break;
				case '2':num+=(int)Math.pow(2,(4*(len-i-1)+1));break;
				case '3':num+=(int)Math.pow(2,(4*(len-i-1))) + (int)Math.pow(2,(4*(len-i-1)+1));break;
				case '4':num+=(int)Math.pow(2,((4*(len-i-1)+2)));break;
				case '5':num+=(int)Math.pow(2,(4*(len-i-1)+2)) + (int)Math.pow(2,(4*(len-i-1)));break;
				case '6':num+=(int)Math.pow(2,(4*(len-i-1)+2)) + (int)Math.pow(2,(4*(len-i-1)+1));break;
				case '7':num+=(int)Math.pow(2,(4*(len-i-1))) + (int)Math.pow(2,(4*(len-i-1)+1)) + (int)Math.pow(2,((4*(len-i-1)+2)));break;
				case '8':num+=(int)Math.pow(2,(4*(len-i-1)+3));break;
				case '9':num+=(int)Math.pow(2,(4*(len-i-1)+3))+ (int)Math.pow(2,(4*(len-i-1)));break;
				case 'A':num+=(int)Math.pow(2,(4*(len-i-1)+3))+ (int)Math.pow(2,(4*(len-i-1)+1));break;
				case 'B':num+=(int)Math.pow(2,(4*(len-i-1)+3))+ (int)Math.pow(2,(4*(len-i-1)+1))+ (int)Math.pow(2,(4*(len-i-1)));break;
				case 'C':num+=(int)Math.pow(2,(4*(len-i-1)+3))+(int)Math.pow(2,((4*(len-i-1)+2)));break;
				case 'D':num+=(int)Math.pow(2,(4*(len-i-1)+3))+(int)Math.pow(2,((4*(len-i-1)+2)))+(int)Math.pow(2,(4*(len-i-1)));break;
				case 'E':num+=(int)Math.pow(2,(4*(len-i-1)+3))+(int)Math.pow(2,((4*(len-i-1)+2)))+(int)Math.pow(2,(4*(len-i-1)+1));break;
				case 'F':num+=(int)Math.pow(2,(4*(len-i-1)+3))+(int)Math.pow(2,((4*(len-i-1)+2)))+(int)Math.pow(2,(4*(len-i-1)+1))+(int)Math.pow(2,(4*(len-i-1)));break;
				default:System.out.println("Not a hexadecimal "+s.charAt(i));break;
			}
		}
		
		System.out.println("decimal number is = "+num);
	}
	
	void compress()
	{
		String inp;
		inp=scanner.next();
		int i=0;
		while(inp.charAt(i)!='\0')
		{
			int j=i+1,ct=0;
			StringBuffer buffer=new StringBuffer(inp);
			
			while(buffer.charAt(i)==buffer.charAt(j))
			{
				buffer.delete(j,j);
				ct+=1;
				System.out.println(ct);
			}
			buffer.insert(j,ct+1);
			i=j+1;
			System.out.println(buffer);
			inp=buffer.toString();
		}
	}
	public static void main(String[] args)
	{
		int choice=0;
		ex obj=new ex();
		System.out.println("1)Mixed Strings\n2)Rotation\n3)Get Integer Value\n4)Compress");
		choice=scanner.nextInt();
		
		switch(choice)
		{
			case 1:obj.firstThree();
				break;
			case 2:obj.rotation();
				break;
			case 3:obj.getIntegerValue();
				break;
			case 4:obj.compress();
			break;
		}
	}
}