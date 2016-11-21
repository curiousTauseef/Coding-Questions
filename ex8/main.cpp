#include <iostream>
#include <list>
using namespace std;

void binarySearch(int*a,int low,int high,int key)
{
    int mid=(low+high)/2;
    cout<<"low "<<low<<" high "<<high<<" mid "<<mid<<"\n";
    if(low>high)
        return;
    else if(a[mid]==key)
    {
        cout<<mid+1;
        return;
    }
    else if(a[mid]>key)
        binarySearch(a,low,mid-1,key);
    else if(a[mid]<key)
        binarySearch(a,mid+1,high,key);
}
void sum(int*a,int i,int ans)
{
    if(i<0)
    {
        cout<<ans;
         return;
    }
    ans=ans+a[i];
    i-=1;
    sum(a,i,ans);
}

void sortedOrNot(int*a,int i,int n)
{
    if(i==n-2)
    {
        cout<<"Array is Sorted ";
        return;
    }
    else
    {
        if(a[i]<a[i+1])
            sortedOrNot(a,i+1,n);
        else
        {
            cout<<"Array is not sorted ";
            return;
        }
    }
}

void numZeroesAndRecursion(int n,int ct,int rev)
{
    if(n<=0)
    {
        cout<<"No of zeroes "<<ct;
        cout<<" Reverse of number is "<<rev;
        return;
    }
    else
    {
        int x=n%10;
        if(x==0)
            ct+=1;
        rev=rev*10+x;
        numZeroesAndRecursion(n/10,ct,rev);
    }
}
void stringReverse(string s,int i)
{
    int len=s.length();
    if(i>=len/2)
    {
        cout<<"reversed string is "<<s;
        return;
    }
    char temp=s[i];
    s[i]=s[len-i-1];
    s[len-i-1]=temp;
    stringReverse(s,i+1);
}
void removeDuplicates(string s,int i)
{
    int len=s.length();
    if(len-1==i)
    {
        cout<<s;
        return;
    }
    if(s[i]==s[i+1])
    {
        s.erase(i+1,1);
        removeDuplicates(s,i);
    }
    else
    {
        removeDuplicates(s,i+1);
    }

}
list<string> subStringsList;
void substrings(string s,int i,int j)
{
    int len=s.length();
    if(i==len)
        return;

    string temp="";
    for(int m=i;m<=j;m++)
    {
        temp+=s[m];
    }

    int found=0;
    for(list<string>::iterator it=subStringsList.begin();it!=subStringsList.end();it++)
    {
        if(*it==temp)
        {
            found=1;
            break;
        }
    }
    if(found==0)
        subStringsList.push_back(temp);
    if(j==len-1)
        substrings(s,i+1,i+1);
    else
        substrings(s,i,j+1);
}
int countingPaths(int i,int j,int m,int n)
{
    if(i==m || j==n)
        return (1);
    else
        return countingPaths(i+1,j,m,n)+countingPaths(i,j+1,m,n);
}

int countStairPaths(int i,int n)
{
    if(n-i==3)
        return (4);
    else if(n-i==2)
        return (2);
    else if(n-i==1)
        return (1);
    else
    {
        return countStairPaths(i+1,n)+countStairPaths(i+2,n)+countStairPaths(i+3,n);
    }
}

int main()
{   int choice=0;
    cout << "1)Binary Search\n2)Sum\n3)Sorted or Not\n4)Number of zeroes and reverse\n5)Reverse a string\n6)Remove duplicates\n7)SubStrings\n";
    cout<<"8)Counting Paths\n9)Stair Paths\n";
    cin>>choice;

    if(choice==1)
    {
        int n=0,key=0;
        cin>>n;
        int*a=new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<"Element to be found ";
        cin>>key;
        binarySearch(a,0,n-1,key);
    }
    else if(choice==2)
    {
        int n=0;
        cin>>n;
        int*a=new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            sum(a,n-1,0);
    }
    else if(choice==3)
    {
        int n=0;
        cin>>n;
        int*a=new int[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            sortedOrNot(a,0,n);
    }
    else if(choice==4)
    {
        int n=0;
        cin>>n;
        numZeroesAndRecursion(n,0,0);
    }
    else if(choice==5)
    {
        string s;
        cin>>s;
        stringReverse(s,0);
    }
    else if(choice==6)
    {
        string s;
        cin>>s;
        removeDuplicates(s,0);
    }
    else if(choice==7)
    {
        string s;
        cin>>s;
        substrings(s,0,0);

        for(list<string>::iterator i=subStringsList.begin();i!=subStringsList.end();i++)
            cout<<*i<<"\n";
    }
    else if(choice==8)
    {
        int m=0,n=0;
        cin>>m>>n;
        cout <<countingPaths(0,0,m,n);
    }
    else if(choice==9)
    {
        int n=0;
        cin>>n;
        cout<<countStairPaths(0,n);
    }
    return 0;
}
