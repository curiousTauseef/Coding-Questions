#include <iostream>
#include <list>

using namespace std;

void setRowCol()
{
    struct matElem{
    int val,tag;
    };
    int nRow=0,nCol=0;
    cin>>nRow>>nCol;

    matElem**a=new matElem*[nRow];
    for(int i=0;i<nRow;i++)
        a[i]=new matElem[nCol];

    for(int i=0;i<nRow;i++)
    {
        for(int j=0;j<nCol;j++)
        {
         cin>>a[i][j].val;
         a[i][j].tag=1;
        }
    }

    for(int i=0;i<nRow;i++)
    {
        for(int j=0;j<nCol;j++)
            {
                if(a[i][j].val==0)
                {
                    for(int k=0;k<nCol;k++)
                        a[i][k].tag=0;
                    for(int u=0;u<nRow;u++)
                        a[u][j].tag=0;

                }

            }
    }
     for(int i=0;i<nRow;i++)
    {
        for(int j=0;j<nCol;j++)
            cout<<a[i][j].tag;
        cout<<"\n";
    }

}

void saddlepoint()
{
    int mRow=0,mCol=0,ct=0;
    cin>>mRow>>mCol;

    int**a=new int*[mRow];
    for(int i=0;i<mRow;i++)
        a[i]=new int[mCol];

    for(int i=0;i<mRow;i++)
    {
        for(int j=0;j<mCol;j++)
            cin>>a[i][j];
    }

    for(int i=0;i<mRow;i++)
    {
        for(int j=0;j<mCol;j++)
        {
            int minrow=0,mincol=0;

            for(int k=0;k<mCol;k++)
            {
                if(a[i][j]<a[i][k])
                {
                    minrow=1;
                    break;
                }

            }

            for(int k=0;k<mRow;k++)
            {
                if(a[i][j]>a[k][j])
                {
                    mincol=1;
                    break;
                }
            }

            if(mincol==0 && minrow==0)
            {
                ct+=1;
                cout<<"Saddle point found at "<<i+1 <<" "<<j+1<<"\n";
            }

        }
    }

    if(ct==0)
        cout<<"No saddle point found\n";
}

void keyFinding()
{
    int mRow=0,mCol=0,ct=0,key=0;
    cin>>mRow>>mCol;

    int**a=new int*[mRow];
    for(int i=0;i<mRow;i++)
        a[i]=new int[mCol];

    for(int i=0;i<mRow;i++)
    {
        for(int j=0;j<mCol;j++)
            cin>>a[i][j];
    }
    cout<<"key ";
    cin>>key;
    int n=mRow;
    int rownum=n-1,found=0;
    while( rownum>=0)
    {
        int low=0,upper=n-1;
        while(low<=upper)
        {
            int mid=(low+upper)/2;
            if(key<a[rownum][0])
            {
                rownum-=1;
                break;
            }
             if(a[rownum][mid]==key)
            {
                found=1;
                cout<<rownum+1<<" "<<mid+1;
                break;
            }
            else if(a[rownum][mid]<key)
                low=mid+1;
            else if(a[rownum][mid]>key)
                upper=mid-1;
        }
        if((found==1)||(low>upper && found==0))
            break;
    }
}

void maxsum()
{
    int n=0,totalsum=0,maxsum=0,pos=0;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++)
    {
         cin>>a[i];
        totalsum+=a[i];
    }

    for(int i=n-1;i>=1;i--)
    {
        int sumleft=0,sumright=0;
        for(int j=n-1;j>=i;j--)
            sumright+=a[j];

        sumleft=totalsum-sumright;
        if(sumright-sumleft>maxsum)
        {
            pos=i;
            maxsum=sumright-sumleft;
        }
    }
    cout<<a[pos];
}

void maxsumRoworColumn()
{
    int mRow=0,mCol=0;
    cin>>mRow>>mCol;

    int**a=new int*[mRow];
    for(int i=0;i<mRow;i++)
        a[i]=new int[mCol];

    for(int i=0;i<mRow;i++)
    {
        for(int j=0;j<mCol;j++)
            cin>>a[i][j];
    }

    int rowmaxsum=0,rownumber=0,columnmaxsum=0,columnnumber=0;
    for(int i=0;i<mRow;i++)
    {   int sum=0;

        for(int j=0;j<mCol;j++)
            sum+=a[i][j];
        if(sum>rowmaxsum)
        {
            rowmaxsum=sum;
            rownumber=i;
        }
    }

     for(int i=0;i<mCol;i++)
    {   int sum=0;

        for(int j=0;j<mRow;j++)
            sum+=a[i][j];
        if(sum>columnmaxsum)
        {
            columnmaxsum=sum;
            columnnumber=i;
        }
    }
    if(rowmaxsum>columnmaxsum)
    {
        cout<<rownumber+1 <<" row sum is max "<<rowmaxsum;
    }
    else
    {
        cout<<columnnumber+1<<"column sum is max "<<columnmaxsum;
    }
}

list<string>palin;
bool checkPalindrome(string tobechecked)
{
    string rev="";
    int len=tobechecked.length();
    for(int i=len-1;i>=0;i--)
        //rev.append(tobechecked[i]);
        rev+=tobechecked[i];
    if(tobechecked==rev)
    {
        int notfound=0;
        for(list<string>::iterator u=palin.begin();u!=palin.end();u++)
            if(*u==rev)
        {
            notfound=1;
            break;
        }
        if(notfound==0)
        {   palin.push_back(rev);
            cout<<rev<<"\n";
            return true;
        }
        else
        return false;
    }
    else
        return false;
}
void numberOfPalindromes()
{
    string s="";
    int ct=0;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
       //temp+=s[i];
        for(int j=i;j<len;j++)
        {
            string temp="";
            for(int k=i;k<=j;k++)
           temp+=s[k];
           if(checkPalindrome(temp))
            ct+=1;
        }
    }
    cout<<ct;
}

void spiralForm()
{
    int row=0,col=0,ct=1;
    cin>>row>>col;
    int xmin=0,xmax=row-1,ymin=0,ymax=col-1;

    int**a=new int*[row];
    for(int i=0;i<row;i++)
        a[i]=new int[col];

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        cin>>a[i][j];

    while((xmax>=xmin)&&(ymax>=ymin))
    {
        int i=xmin,j=ymin;
        while(j<=ymax)
        {
           cout<<a[i][j]<<" ";
            j+=1;
        }
        j-=1;
        while(i<xmax)
        {
             i+=1;
            cout<<a[i][j]<<" ";
        }
        while(j>ymin)
        {
             j-=1;
            cout<<a[i][j]<<" ";
        }
        while(i>xmin+1)
        {
            i-=1;
            cout<<a[i][j]<<" ";
        }
        xmin+=1;
        ymin+=1;
        xmax-=1;
        ymax-=1;
    }
}

void rectangles()
{
    int n=0;
    cin>>n;

    int**a=new int*[n];
    for(int i=0;i<n;i++)
        a[i]=new int[n];

    int xmin=0,xmax=n-1,ymin=0,ymax=n-1,ct=1,chr=0;
    while((xmax>=xmin)&&(ymax>=ymin))
    {
        if(ct%2==1)
            chr=0;
        else
            chr=1;

        for(int i=xmin;i<=xmax;i++)
        {
         a[i][ymin]=chr;
         a[i][ymax]=chr;
        }
        for(int j=ymin;j<=ymax;j++)
        {
            a[xmin][j]=chr;
            a[xmax][j]=chr;
        }
        xmin+=1;
        ymin+=1;
        xmax-=1;
        ymax-=1;
        ct+=1;

    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

}
int main()
{
    int choice=0;
    cout<<"1)Set Row/Column\n2)Saddle point\n3)Key Finding\n4)Max Sum\n5)Column or Row max sum\n6)Number of palindromes\n7)Spiral Form\n8)Rectangles\n";
    cin>>choice;
    switch(choice)
    {
        case 1:setRowCol();break;
        case 2:saddlepoint();break;
        case 3:keyFinding();break;
        case 4:maxsum();break;
        case 5:maxsumRoworColumn();break;
        case 6:numberOfPalindromes();break;
        case 7:spiralForm();break;
        case 8:rectangles();break;
    }
    return 0;
}
