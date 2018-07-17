using namespace std;
#include<iostream>

struct node
{
    int data;
    node * link;
};
node * head;

void ins(int data,int i)        //inserting an element in ith position;
{
    node * temp;
    temp=new node;
    temp->data=data;
    node *temp1=head;
    if(i==1)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        for(int j=0;j<i-2;j++)      //traversing to position i;
        {
            temp1=temp1->link;
        }

        temp->link=temp1->link;
        temp1->link=temp;
    }
}
void del(int i)         //deleting ith element;
{
    node *temp=head;
    if(i==1)
    {
        head=head->link;
        temp->link=NULL;
        delete temp;
    }
    else
    {
        for(int j=0;j<i-2;j++)
        {
            temp=temp->link;        //going to (i-1) th pos
        }
        node * temp1=temp->link;
        temp->link=temp1->link;
        temp1->link=NULL;
        delete temp1;

    }

}
void revi()                         //reversing linked list ,iterative method;
{
    node *current,*prev,*nex;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        nex=current->link;
        current->link=prev;
        prev=current;
        current=nex;
    }
    head=prev;
}
void revr(node *temp)               //reversing linked list, recursive method;
{
    if(temp->link==NULL)
    {
        head=temp;
        return;
    }
    revr(temp->link);
       /* node * temp1=temp->link;
        temp1->link=temp;*/
        temp->link->link=temp;
        temp->link=NULL;
}

void revprint(node * temp)             //printing in reverse order, recursion method;
{
    if(temp==NULL)
        return;
    else
        revr(temp->link);
            cout<<temp->data<<" ";
}
void show()                         //printing forward ,iterative method;
{
    node *temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->link;
    }
}
void print(node * temp)             //printing forward ,recursive method;
{
    if(temp==NULL)
        return;
    else
        cout<<temp->data<<" ";
        print(temp->link);
}
int main()
{
    head=NULL;
    ins(10,1);
    ins(20,2);
    ins(30,3);
    ins(40,4);
 //   del(1);
 //  del(4);
    //revr(head);
    revr(head);
    show();
   // print(head);
}

