#include<bits/stdc++.h>
using namespace std;
typedef struct Matrix mat;

class LowerTri
{
private:
    int n;
    int *A;
public:
    LowerTri(int q){n=q;A=new int[n*(n+1)/2];}
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~LowerTri(){delete[]A;}
};

void LowerTri::Set(int i,int j,int x)
{
    if(i<=j)
        A[j*(j-1)/2+i-1]=x;
}

int LowerTri::Get(int i,int j)
{
    if(i<=j)
        return A[j*(j-1)/2+i-1];
    else
        return 0;
}

void LowerTri::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<  =j)
                cout<<A[j*(j-1)/2+i-1]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int d;
    cout<<"Enter Dimention: ";
    cin>>d;
    LowerTri m(d);
    int x;
    for(int i=1;i<=d;i++)
    {
        for(int j=1;j<=d ;j++)
        {
            cin>>x;
            m.Set(i,j,x);
        }
    }
    m.Display();
}

