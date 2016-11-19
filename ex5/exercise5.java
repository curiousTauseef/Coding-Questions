import java.util.Scanner;

class ex
{	public static Scanner sc=new Scanner(System.in);
	/* int[] univ;
		
	void initialize(int n,int[]a)
	{
		univ=new int[n];
		for(int i=0;i<n;i++)
			univ[i]=a[i];
	} */
	int checkFibon()
	{	
		
		int n=0,first=0,second=1,third=0;
		n=sc.nextInt();
		while(true)
		{
			third=first+second;
			if(third<n)
			{
				first=second;
				second=third;
			}
			else if(third==n)
				return 1;
			else
				return 0;
		}
	}
	int binarySearch()
	{
		int n=0,x=0;
		n=sc.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		x=sc.nextInt();
		int low=0,upper=n-1,mid=0;
		while(low<=upper)
		{
			mid=(low+upper)/2;
			if(a[mid]==x)
				return mid;
			else if(a[mid]<x)
				low=mid+1;
			else
				upper=mid-1;
		}
		return -1;
	}
	void removeDuplicates(int[] a,int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[j]==a[i])
				{
					for(int k=j;k<=n-2;k++)
						a[k]=a[k+1];
					n-=1;
				}
			}
		}
		for(int i=0;i<n;i++)
		System.out.println(a[i]+" ");
	}
	
	boolean isThereAzeroSubArray(int[]a,int n)
	{
		int [][] sum=new int[n][n];
		for(int i=0;i<n;i++)
		{	
			
			for(int j=0;j<n;j++)
			{	
				int summation=0;
				for(int k=i;k<=j;k++)
					summation+=a[k];
				sum[i][j]=summation;
				if(summation==0)
				return true;
			}
		}
		return false;
	}
	void insertionSort()
	{
		int n=0;
		n=sc.nextInt();
		int[] a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		for(int i=1;i<n;i++)
		{
			int j=i,temp=a[i];
			while(j>=1)
			{
				if(a[j-1]>a[j])
				{
					a[j]=a[j-1];
					a[j-1]=temp;
					j-=1;
				}
				else
					break;
			}
			a[j]=temp;
		}
		for(int i=0;i<n;i++)
			System.out.println(a[i]);
	}
	public static void main(String[] args)
	{
		int choice =0;
		System.out.println("1)Check Fibonacci\n2)Binary Search\n3)Remove Duplicates\n4)Zero SubbArray\n5)Insertion Sort\6)Done In Previous");
		choice=sc.nextInt();
		ex obj=new ex();
		switch(choice)
		{
			case 1:
				System.out.println("value returned "+obj.checkFibon());
				break;
			case 2:
				System.out.println("value returned "+obj.binarySearch());
				break;
			case 3:
				int n=0;
				n=sc.nextInt();
				int[] arr=new int[n];
				for(int i=0;i<n;i++)
					arr[i]=sc.nextInt();
				obj.removeDuplicates(arr,n);
				break;
			case 4:
				int n2=0;
				n2=sc.nextInt();
				int[] arr2=new int[n2];
				for(int i=0;i<n2;i++)
					arr2[i]=sc.nextInt();
				System.out.println(obj.isThereAzeroSubArray(arr2,n2));
				break;
			case 5:
				obj.insertionSort();
				break;
		}
	}
}