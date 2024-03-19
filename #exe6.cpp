#include <iostream>

using namespace std;

int main()
{
    int a[50],sum=0,n;
    cout<<"Enter number of elements : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<". Enter Numbers : ";
        cin>>a[i];
        sum += a[i];
    }
    cout<<"Average : "<<sum/n<<endl;

    return 0;
}