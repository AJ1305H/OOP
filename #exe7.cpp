#include <iostream>

using namespace std;

int main()
{
    int a[5][5],b[5][5],c[5][5],r1,r2,c1,c2;
    cout<<"Enter Rows of Matrix 1 : ";
    cin>>r1;
    cout<<"Enter columns of Matrix 1 : ";
    cin>>c1;
    cout<<"Enter Rows of Matrix 2 : ";
    cin>>r2;
    cout<<"Enter columns of Matrix 2 : ";
    cin>>c2;
    if(c1!=r2)
    {
        cout<<"Matrix Multiplaction can not be done!";
        return 0;
    }
    cout<<"Enetr the Elements of Matrix 1 : \n";
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<"Enter element a"<<i+1<<j+1<<" : ";
            cin>>a[i][j];
        }
    }
    cout<<"\nMATRIX 1\n";
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    

    cout<<"Enetr the Elements of Matrix 2 : \n";
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<"Enter element b"<<i+1<<j+1<<" : ";
            cin>>b[i][j];
        }
    }
    cout<<"\nMATRIX 2\n";
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<b[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<c1;k++)
            {
                
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    cout<<"----OUTPUT MATRIX-----\n";
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<c[i][j]<<" ";
            
        }
        cout<<endl;
    }

    return 0;
}
