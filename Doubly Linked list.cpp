using namespace std;
#include<iostream>
struct node
{
    int data;
    node * next;
    node * prev;
};
node *head;

void push(int data,int i)
{
    node * temp=new node;
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(i==1)
    {
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }

    }
    else
    {
        node * temp1=head;
        for(int j=0;j<i-2;j++)
        {
            temp1=temp1->next;
        }
        if(temp1->next==NULL)
        {
            temp->prev=temp1;
            temp1->next=temp;
        }
        else
        {
            temp->next=temp1->next;
            temp->prev=temp1;
            temp1->next=temp;
            temp->next->prev=temp;
        }
    }
}


void show()                         //printing forward ,iterative method;
{
    node *temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}

void reverseprint()
{
    node * temp=head;
    while(temp->next!=NULL)         //traversing the linked list till the last node;
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }

}
int main()
{
    head=NULL;
    push(2,1);
    push(3,2);
    push(4,2);
   // show();
    reverseprint();
}
