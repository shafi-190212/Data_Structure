#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue
{
private:
    int Size;
    int Front;
    int Rear;
    Node **Q;
public:
    Queue(int S)
    {
        Front=Rear=-1;
        Size=S;
        Q=new Node*[Size];
    }
    int isEmpty()
    {
        return Front==Rear;
    }
    void Enqueue(Node *x);
    Node* Dequeue();
};

void Queue::Enqueue(Node *x)
{
    if(Rear==Size-1)
    {
        cout<<"Queue is Full.\n";
    }
    else
    {
        Q[++Rear]=x;
    }
}

Node* Queue::Dequeue()
{
    Node *x;
    if(Front==Rear)
    {
        cout<<"Queue is Empty.\n";
    }
    else
    {
        x=Q[++Front];
    }
    return x;
}

class Tree
{
public:
    Node *root;
    Tree()
    {
        root=NULL;
    }
    void CreateTree();
    void PreOrder(Node *x);
    void InOrder(Node *x);
    void PostOrder(Node *x);
    void LevelOrder(Node *x);
    int Height(Node *p);
    int NumOfNodes(Node *p);
    int NumOfDeg1s(Node *p);
    int NumOfDeg2s(Node *p);
    int NumOfLeafs(Node *p);
};

void Tree::CreateTree()
{
    Node *p,*t;
    Queue  q(50);
    int x;
    root=new Node;
    cout<<"Enter the root value: ";
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.Enqueue(root);
    while(!q.isEmpty())
    {
        p=q.Dequeue();
        cout<<"Enter the Left Child of "<<p->data<<": ";
        cin>>x;

        if(x!=-1)
        {
            t= new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.Enqueue(t);
        }

        cout<<"Enter the Right Child of "<<p->data<<": ";
        cin>>x;

        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.Enqueue(t);
        }
    }
}

void Tree::PreOrder(Node *x)
{
    if(x)
    {
        cout<<x->data<<" ";
        PreOrder(x->lchild);
        PreOrder(x->rchild);
    }
}

void Tree::InOrder(Node *x)
{
    if(x)
    {
        InOrder(x->lchild);
        cout<<x->data<<" ";
        InOrder(x->rchild);
    }
}

void Tree::PostOrder(Node *x)
{
    if(x)
    {
        PostOrder(x->lchild);
        PostOrder(x->rchild);
        cout<<x->data<<" ";
    }
}

void Tree::LevelOrder(Node *x)
{
    Node *k;
    Queue s(50);
    cout<<x->data<<" ";
    s.Enqueue(x);
    while(!s.isEmpty())
    {
        k=s.Dequeue();
        if(k->lchild)
        {
            cout<<k->lchild->data<<" ";
            s.Enqueue(k->lchild);
        }

        if(k->rchild)
        {
            cout<<k->rchild->data<<" ";
            s.Enqueue(k->rchild);
        }
    }
}

int Tree::NumOfNodes(Node *p)
{
    if(p==NULL)
        return 0;
    else
        return NumOfNodes(p->lchild)+NumOfNodes(p->rchild)+1;

}

int Tree::Height(Node *p)
{
    int x,y;
    if(p)
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int Tree::NumOfDeg1s(Node *p)
{
    int x,y;
    if(p)
    {
        x=NumOfDeg1s(p->lchild);
        y=NumOfDeg1s(p->rchild);

        if((!p->lchild&&p->rchild)||(p->lchild&&!p->rchild))
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int Tree::NumOfDeg2s(Node *p)
{
    int x,y;
    if(p)
    {
        x=NumOfDeg2s(p->lchild);
        y=NumOfDeg2s(p->rchild);

        if(p->lchild&&p->rchild)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}

int Tree::NumOfLeafs(Node *p)
{
    int x,y;
    if(p)
    {
        x=NumOfLeafs(p->lchild);
        y=NumOfLeafs(p->rchild);

        if(!p->lchild && !p->rchild)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
    }
    return 0;
}


int main()
{
    Tree t;
    t.CreateTree();
    cout<<"\n\nPreOrder: ";
    t.PreOrder(t.root);
    cout<<endl;
    cout<<"\nInOrder: ";
    t.InOrder(t.root);
    cout<<endl;
    cout<<"\nPostOrder: ";
    t.PostOrder(t.root);
    cout<<endl;
    cout<<"\nLevelOrder: ";
    t.LevelOrder(t.root);
    cout<<endl;
    cout<<"\nHeight of the Tree: "<<t.Height(t.root)<<endl;
    cout<<"\nNumber of Nodes: "<<t.NumOfNodes(t.root)<<endl;
    cout<<"\nNumber of Deg-1 Nodes: "<<t.NumOfDeg1s(t.root)<<endl;
    cout<<"\nNumber of Deg-2 Nodes: "<<t.NumOfDeg2s(t.root)<<endl;
    cout<<"\nNumber of Leaf Nodes: "<<t.NumOfLeafs(t.root)<<endl;
    return 0;
}
