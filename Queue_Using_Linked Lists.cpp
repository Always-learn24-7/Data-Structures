using namespace std;
#include<iostream>

struct node
{
    int data;
    node *link;
};
node *fr=NULL;
node *rear=NULL;
node *temp=NULL;

void push()
{
    temp= new node;
    cout<<"Enter Data:";
    cin>>temp->data;
    if(fr==NULL)
    {
        fr=rear=temp;
        rear->link=NULL;
    }
    else
    {
        rear->link=temp;
        rear=temp;
        rear->link=NULL;
    }

}

void pop()
{
    node *temp;
    if(fr==NULL)
    {
        cout<<"Queue is empty";
    }
    else
    {
        temp=fr;
        fr=fr->link;
        cout<<"deleted data is :"<< temp->data;
        delete temp;
    }
}

void show()
{
    node *temp;
    if(fr==NULL)
    {
        cout<<"Queue is empty";
    }
    else
    {
        cout<<"elements from front to back are:";
        temp=fr;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->link;
        }
    }
}

int main()
{
    menu:
         int c;
         char ch;
    cout<<"(1)enqueue   (2)dequeue  (3)show";

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
    cout<<"Try more?(y/n)";
    cin>>ch;
    if(ch=='y')
    {
        goto menu;
    }
    return 0;
}





