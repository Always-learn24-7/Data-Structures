using namespace std;
#include<bits/stdc++.h>

struct node
{
    int data;
    node *left;
    node *right;

};
node *root = NULL;  //creating an empty tree
node *temp = NULL;

//creating a new node
node *newnode(int data)
{
    temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//Binary Search Tree,insertion:;
node* ins(node *root,int data)
{
    if(root==NULL)
    {
        root=newnode(data);     //gets the address of new node
    }
    else if(data>root->data)
    {
        root->right=ins(root->right,data);      //to set the address of right link of temporary root & set the data of new node

    }
    else if(data<=root->data)
    {
        root->left=ins(root->left,data);        //to set the address of left link of temporary root & set the data of new node
    }
           return root;                     //gives the root address
}

//Searching an element;
int s(node *root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    if(data==root->data)
    {
        return 1;
    }
    else if(data<root->data)
    {

        return s(root->left,data);

    }
    else if(data>root->data)
    {

        return s(root->right,data);

    }
}
//Binary Tree insertion:;
void Binary_insert(node *root,int data)
{
    if(root==NULL)
        ::root=newnode(data);
    else
    {
        queue<node *> q;
        q.push(root);
        while(!q.empty())
        {
            if(!q.front()->left)
            {
                q.front()->left=newnode(data);
                q.pop();
                break;
            }

            else
                q.push(q.front()->left);
            if(!q.front()->right)
            {
               q.front()->right=newnode(data);
               q.pop();
               break;
            }

            else
                q.push(q.front()->right);
            q.pop();
        }
    }
}


//Types of Traversing Binary trees: ;
void inorder(node *root)        //call the left sub-tree,visit the node,call the right sub-tree;
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void preorder(node *root)       //Visit the node, call the left sub-tree, call the right sub-tree;
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)      //call the left sub-tree, call the right sub-tree, visit the node;
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(node *root)     //Visit each node and enqueue it's children,then pop element from queue;
{

        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            cout<<q.front()->data<<" ";
            if(q.front()->left!=NULL)
                q.push(q.front()->left);
            if(q.front()->right!=NULL)
                q.push(q.front()->right);
            q.pop();
        }

}
//Finding the height;
int height(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

//Finding the Breadth,using level order traversal :;
int Maxwidth(node * root)
{
    int maxwidth=0;
    if(root==NULL)
        return 0;
    else
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            int c=q.size();         //c= no. of nodes in each level;
            maxwidth=max(maxwidth,c);
            while(c--)              //removing all nodes of a level
            {
                if(q.front()->left!=NULL)
                    q.push(q.front()->left);
                if(q.front()->right!=NULL)
                    q.push(q.front()->right);
                 q.pop();
            }

        }
        return maxwidth;
    }
}



//Inverting the tree: all left child are swapped with right child;
void invert(node *root)
{
    node *temp;
    if(root==NULL)
        return ;
    else
    {
        invert(root->left);
        invert(root->right);
        swap(root->left,root->right);
    }
}

int main()
{
    int data;
    int menu = 5;
    do
    {
        cout<<"\n1.Binary Search Tree Insert\n2.Inorder\n3.Search\n4.Height\n5.Invert\n6.levelorder\n7.Binary Insert\n8.MaxWidth\n9.Exit\n";
        cin>>menu;
        if(menu == 1)
        {
            cout<<"Enter data: ";
            cin>>data;
            root=ins(root,data);        //building the link of root with new node
        }
        if(menu==2)
        {
            inorder(root);
        }
        else if(menu == 3)
        {
            cout<<"Enter data:";
            cin>>data;
            if(s(root,data)==1) cout<<"Element found";
            else cout<<"Not found";
        }
        else if(menu==4)
        {
            cout<<"Height="<<height(root);
        }
        else if(menu==5)
        {
            invert(root);
            cout<<"Inverted!!!\n";
        }
         else if(menu==6)
        {
            levelorder(root);
        }
        else if(menu==7)
        {
            cout<<"\nEnter Data:";
            cin>>data;
            Binary_insert(root,data);
        }
        else if(menu==8)
        {
            cout<<"Max Width="<<Maxwidth(root);
        }

    }while(menu !=9);
    return 0;
}
