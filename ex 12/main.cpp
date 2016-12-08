#include <iostream>

using namespace std;

class LinkedList
{
    struct node
    {
        int val;
        node* next;
    };

public:
    LinkedList()
    {
        head=new node();
        head->next=NULL;
    }

    void insertValue(int x)
    {
        node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        node* z=new node();
        z->val=x;
        z->next=NULL;
        temp->next=z;
    }

    void printList()
    {
        node*temp=head->next;

        while(true)
        {
            if(temp==NULL)
                break;
            else
            {
             cout<<temp->val<<"->";
             temp=temp->next;
            }
        }
    }
    int listLength()
    {
        node* temp=head->next;
        int l=0;
        while(true)
        {
            if(temp==NULL)
                break;
            else
            {
                temp=temp->next;
                l+=1;
            }
        }
        return l;
    }
    void placeEvenAfterOdd()
    {
        node *temp=head->next,*parent=head;
        node* endNode=head;
        while(endNode->next!=NULL)
            endNode=endNode->next;

        int len=listLength();
        int i=0;
        while(i<len)
        {
            if(temp->val%2==0)
            {
                node* temp2=temp;
                temp=temp->next;

                endNode->next=temp2;
                parent->next=temp2->next;
                temp2->next=NULL;
                endNode=endNode->next;
            }
            else
            {
                temp=temp->next;
                parent=parent->next;
            }
            i+=1;
        }
    }

    void reverseOrNot(LinkedList secList)
    {
        int len1=listLength();
        int len2=secList.listLength();
        node* temp1=head->next;
        node* temp2=secList.head;
        int i=1,j=len2;
        while(temp2->next!=NULL)
            temp2=temp2->next;

        if(len1==len2)
        {
            while(i<=len1 && len2>=1)
            {
                if(temp1->val == temp2->val)
                {
                    temp1=temp1->next;
                    i+=1;
                    len2-=1;
                    int k=1;
                    node* x=secList.head->next;
                    while(k<len2)
                    {
                        x=x->next;
                        k+=1;
                    }
                    temp2=x;
                }
                else
                    break;
            }
            if(i==len1+1)
                cout<<"Reverse";
            else
                cout<<"Not reverse";
        }
    }

    void permutationOrNot(LinkedList secList)
    {
        int len1=listLength();
        int len2=secList.listLength();
        if(len1==len2)
        {
            node* list_one_itr=head->next;
            while(list_one_itr!=NULL)
            {
                node* list_two_itr=secList.head->next;
                while(list_two_itr!=NULL)
                {
                    if(list_one_itr->val == list_two_itr->val)
                        break;
                    else
                        list_two_itr=list_two_itr->next;
                }
                if(list_two_itr!=NULL)
                    list_one_itr=list_one_itr->next;
                else
                    break;
            }
            if(list_one_itr==NULL)
                cout<<"Yes Permutation ";
            else
                cout<<"Not Permutation ";
        }
        else
            cout<<"Not Permutation ";
    }

private:
    node* head;
};

int main()
{
    LinkedList llist;
    llist.insertValue(1);
    llist.insertValue(2);
    llist.insertValue(3);
    llist.insertValue(4);
    llist.insertValue(4);
    llist.insertValue(5);
    llist.insertValue(6);
    llist.insertValue(7);
    llist.printList();

    LinkedList llist2;
    llist2.insertValue(7);
    llist2.insertValue(6);
    llist2.insertValue(5);
    llist2.insertValue(4);
     llist2.insertValue(4);
    llist2.insertValue(3);
    llist2.insertValue(2);
    llist2.insertValue(1);

    cout<<"\nPrint even after odd\n";
    llist.placeEvenAfterOdd();
    llist.printList();
    llist.reverseOrNot(llist2);

    llist.permutationOrNot(llist2);
    return 0;
}
