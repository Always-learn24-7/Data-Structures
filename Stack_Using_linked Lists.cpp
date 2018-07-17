 using namespace std;

#include<iostream>

struct node
{
    int data;
    node *link;
};
node *top=NULL;
node *temp=NULL;


void push()
{
    temp=new node;
    cout<<"Enter Data:";
    cin>>temp->data;
    if(top==NULL)
    {
        temp->link=NULL;
        top=temp;
    }


    else
    {
    temp->link=top;
    top=temp;
    }

}
void pop()
{
    node*temp;
    temp=top;
    if(top!=NULL)
    {
        top=top->link;
        cout<<"Deleted data:"<<temp->data;
        temp->link=NULL;
        delete temp;
    }
    else
    cout<<"NO elements!!!";
}
void show()
{
   node *temp;
   temp=top;
   if(temp==NULL)
   cout<<"no Elements!!!";
   else
   {

        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->link;
        }
   }
}

int main()
{
    int c;
    char ch;
    label:
    cout<<"Enter your choice (1)Push    (2)Pop  (3)Show";
    cin>>c;
    switch(c)
    {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: show();
                break;


    }
    cout<<"Try more(y/n)?";
    cin>>ch;
    if(ch=='y')
        goto label;
    if(ch=='n')
       return 0;
}
