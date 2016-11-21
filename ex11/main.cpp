#include <iostream>
#include <cstddef>
#include <unordered_map>
using namespace std;

class LinkedList
{
    struct node
    {
        int val;
        node *prev;
        node *next;
    };

public:
    LinkedList()
    {
       // head->next=NULL;
        //head->prev=NULL;
        head=new node();
        head->next=NULL;
        head->prev=NULL;
    }
    void addValue(int value)
    {
        if(head!=NULL)
        {
          node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *temp2=new node();
        temp2->val=value;
        temp2->next=NULL;
        temp2->prev=temp;
        temp->next=temp2;
        }
        else
        {
            node *temp =new node();
            temp->val=value;
            temp->next=NULL;
            temp->prev=NULL;
            head->next=temp;
            head->prev=NULL;
        }
    }
    void showList()
    {
        node *temp=head;
        temp=temp->next;
        while(temp->next!=NULL)
        {
         cout<<temp->val<<"->";
         temp=temp->next;
        }
        cout<<temp->val<<"->";
    }
    void popOut()
    {
        node*temp ;
        temp=head;
        temp=temp->next;
        head->next=temp->next;
        delete temp;

        node*temp2;
        temp2=head->next;
        temp2->prev=head;
    }

    void findElem(int k)
    {
        int i=1;
        node*temp=head->next;
        while(temp->next!=NULL && i<k)
        {
            i+=1;
            temp=temp->next;
        }
        if(i==k)
            cout<<temp->val;
        else
            cout<<"List doesn't have required elements";
    }
    void delElem(int k)
    {
        int i=1;
        node*temp=head->next;

        while(temp->next!=NULL && i<k)
        {
            i+=1;
            temp=temp->next;
        }
        if(k==ListLength())
        {
            node* x= temp->prev;
            x->next=NULL;
            delete temp;
        }
        else if(k==1)
        {
            temp=head->next;
            node* x=temp->next;
            head->next=temp->next;
            x->prev=head;
            delete temp;
        }
        else
        {
            if(i==k)
            {
                node*x=temp->prev;
                node*y=temp->next;
                x->next=temp->next;
                delete temp;
                y->prev=x;
            }
            else
                cout<<"No element found ";
        }

    }
    void insertElem(int k,int value)
    {
        int i=1;
        node*temp=head->next;
        while(temp->next!=NULL && i<k)
        {
            i+=1;
            temp=temp->next;
        }
     /*   cout<<"\n\n"<<temp->val<<"\n\n";
                cout<<"\n\n"<<temp->prev<<"\n\n";
                        cout<<"\n\nhi "<<temp->next<<"\n\n";*/
        if(i==k)
        {
            node*x=temp->prev;

            node *nn=new node();
            nn->val=value;

            x->next=nn;
            nn->prev=x;
            nn->next=temp;
            temp->prev=nn;
        }
        else
        addValue(value);
    }

    int ListLength()
    {
        node *temp=head;
        int i=0;
        while(temp->next!=NULL)
        {
            i+=1;
            temp=temp->next;
        }
        return (i);
    }

    void swapElem(int k,int m)
    {
        node*temp1,*temp2;
        int i=1,small,big;

        if(k<m)
        {
            big=m;
            small=k;
        }
        else
        {
            big=k;
            small=m;
        }
        k=small;
        m=big;




        if(k==m)
            return;
        else
        {
            if(k==1)
            temp1=head;

            else
            {
              temp1=head->next;
        while(temp1->next!=NULL && i<k-1)
        {
            i+=1;
            temp1=temp1->next;
        }

            }
         i=1;
        temp2=head->next;
        while(temp2->next!=NULL && i<m-1)
        {
            i+=1;
            temp2=temp2->next;
        }

            node* temp;
            temp=temp1->next;
            temp1->next=temp2->next;
            temp2->next=temp;

            node* previous;
            previous=temp1->next;
            previous->prev=temp1;

            previous=temp2->next;
            previous->prev=temp2;

            temp1=temp1->next;
            temp2=temp2->next;

             temp=temp1->next;
            temp1->next=temp2->next;
            temp2->next=temp;

             previous=temp1->next;
            previous->prev=temp1;

            previous=temp2->next;
            if(previous!=NULL)
            previous->prev=temp2;

        }
    }
    void appendElem(int i)
    {
        node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        int k=0;
        while(k<i)
        {
            k+=1;
            temp=temp->prev;
        }
        node *x=temp->next;
        temp->next=NULL;
        node *start=head->next;
        head->next=x;
        while(x->next!=NULL)
            x=x->next;
        x->next=start;
    }
    void reverseList()
    {
        int len=0;
        len=ListLength();
        for(int i=1;i<=len/2;i++)
            swapElem(i,len-i+1);
    }
    void palindrome()
    {
        node *temp;
        temp=head->next;
        long rev=0,str=0;
        while(temp->next!=NULL)
        {
            str=str*10+temp->val;
            temp=temp->next;
        }
        while(temp->prev!=NULL)
        {
            rev=rev*10+temp->val;
            temp=temp->prev;
        }
        if(str==rev)
            cout<<"Palindrome\n\n";
        else
            cout<<"not a palindrome\n\n";
    }
    void bubbleSort()
    {
       node *temp=head;
        node *temp2;
        int len=ListLength();
        for(int i=1;i<len;i++)
        {
            temp=temp->next;
             temp2=temp->next;
            for(int j=i+1;j<=len;j++)
            {
                cout<<"i: "<<i<<" j: "<<j;
                cout<<" temp->val "<<temp->val;
                cout<<" temp2->val "<<temp2->val<<"\n";
               if((temp->val)>(temp2->val))
                    {
                        int x=temp->val;
                        temp->val=temp2->val;
                        temp2->val=x;
                    }
                temp2=temp2->next;
            }
        }
    }
    void removeDuplicates()
    {
        node* temp=head->next,*forw;
        int i=1,j=1;
        while(true)
        {
            j=i+1;
            forw=temp->next;
            while(temp->next!=NULL)
            {
                if(forw->val == temp->val)
                {
                    j=i+1;
                    forw=temp->next;
                    delElem(j);
                }
                else
                {
                    if(forw->next==NULL)
                    break;
                    else
                    {
                     forw=forw->next;
                     j+=1;
                    }
                }
                cout<<"\n";
                 showList();
            }
            i+=1;
             if(temp->next==NULL)
                break;
            temp=temp->next;
        }
    }
    void mergeList(node *head1,node *head2)
    {
        LinkedList llist;
        node* temp1=head1->next,*temp2=head2->next;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val<temp2->val)
            {
                llist.addValue(temp1->val);
                temp1=temp1->val;
            }
            else
            {
                llist.addValue(temp2->val);
                temp2=temp2->val;
            }
        }
        while(temp1!=NULL)
        {
            llist.addValue(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            llist.addValue(temp2->val);
            temp2=temp2->next;
        }
    }

private:
       node *head;
};
int main()
{
    LinkedList List;
    int value=0;
    char ch='y';

    List.addValue(1);
    List.addValue(3);
    List.addValue(3);
    List.addValue(6);
    List.addValue(3);
    List.addValue(4);
    List.addValue(3);
    List.addValue(2);
    List.addValue(8);
    List.addValue(7);
    List.addValue(3);
     List.addValue(2);
      List.addValue(2);
       List.addValue(2);
      List.addValue(2);
         List.addValue(2);
          List.addValue(2);
     List.addValue(3);
          List.addValue(3);
     List.addValue(2);
      List.addValue(2);
       List.addValue(2);
        List.addValue(2);
         List.addValue(3);
          List.addValue(3);
    List.showList();
    cout<<"\n\n";

    List.popOut();
    List.showList();
    List.findElem(2);
    cout<<"\n\n";
    List.showList();
    cout<<"\n\n delete elem\n\n";
    List.delElem(1);
    List.showList();
    cout<<"\n\n";
    List.insertElem(3,60);
    List.showList();
    cout<<"Append\n\n";
    List.appendElem(4);
    List.showList();
    cout<<"swap\n\n";

    cout<<"List Length "<<List.ListLength()<<"\n\n";
   cout<<"bubble Sort\n\n";
    List.bubbleSort();
    List.showList();
    cout<<"reverse list\n";
    List.reverseList();
    List.showList();
List.bubbleSort();
    cout<<"remove duplicates\n\n";
    List.removeDuplicates();
    List.showList();
    return 0;
}
