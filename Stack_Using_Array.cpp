using namespace std;
#include<iostream>
int top=-1;
void push(int x,int *p,int n)
{
    if(top==n)
        cout<<"Stack is full";
    else
    {
        top++;
        p[top]=x;
    }
}
void pop(int *p)
{
    if(top==-1)
    {
        cout<<"Stack is empty";
    }
    else
    {
        cout<<"element deleted:"<<p[top]<<endl;
        p[top--]=0;
    }

}
void show(int *p)
{
    for(int i=0;i<=top;i++)
    {
        cout<<p[i];
    }
}

int main()
{
    int n,c,x;
    cout<<"Enter size of stack:";
    cin>>n;
    int a[n]={0};
    ch:
    cout<<"\nEnter choice:";
        cin>>c;
    while(c!=4)
    {
        switch(c)
        {
            case 1:cin>>x;
                    push(x,a,n);
                    break;
            case 2:pop(a);
                    break;
            case 3:show(a);
                    break;

        }
        goto ch;
    }
    cout<<"End of program";
}
