#include<bits/stdc++.h>
using namespace std;

class Diagonal
{
private:
    int n;
    int *A;
public:
    Diagonal(int n){this->n=n;A=new int[n];}
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Diagonal(){delete[]A;}
} ;
void Diagonal::Set(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}

int Diagonal::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}
void Diagonal::Display()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
                printf("%d ",A[i]);
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int d;
    cout<<"Enter Dimensions: ";
    cin>>d;
    Diagonal D(d);
    int x;
    cout<<"Enter all Elements:\n";
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d;j++)
        {
            cin>>x;
            D.Set(i,j,x);
        }
    }

    cout<<"Matrix is:\n";
    D.Display();
    return 0;
}

