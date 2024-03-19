#include <iostream>
#include "item.h"
#include <list>
#include <fstream>

using namespace std;

int main()
{
    int n,q;
    float p;
    string name;
    cout<<"Enter the Number of Items : ";
    cin>>n;

    list<Item *> l1;
    cout<<"\n\tENTER ALL ITEMS\t\n";
    for(int i = 0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" Item Name :";
        cin>>name;
        cout<<"Enter "<<i+1<<" Item Price :";
        cin>>p;
        cout<<"Enter "<<i+1<<" Item Quantity :";
        cin>>q;
        l1.push_back(new Item(name,p,q));
    }
    ofstream ofs("item.txt");
    list<Item *>::iterator itr;
    for(itr = l1.begin();itr != l1.end();itr++)
    {
        ofs << **itr;
    }
    Item item;
    ifstream ifs("item.txt");
    for (int i = 0; i < n; i++)
    {
        ifs>>item;
        cout<<"Item "<<i+1<<endl;
        cout<<item;
    }
    
    return 0;
}
