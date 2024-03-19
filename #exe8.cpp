#include <iostream>

using namespace std;

int linearSearch(int a[],int size,int key)
{
    for(int i=0;i<=size ; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int k,a[]={2,4,8,6,10,12,16,14,20,18},key, size;
    cout<<"Enter the size of Array : ";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter Element "<<i+1<<" : ";
        cin>>a[i];
    }
    cout<<"Array Elements are : \n";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nEnter the element to be searched : ";
    cin>>key;
    k = linearSearch(a,10,key);
    if(k>=0)
        cout<<"Element is Present at Index : "<<k<<endl;
    else
        cout<<"Element is not Present!!"<<endl;

}