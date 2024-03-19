#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Item
{
    int quantity;
    string name;
    float price;
public:
    Item()
    {
        name = "null";
        price = 0.0;
        quantity = 0;
    }
    Item(string n,float p,int q);   
    Item(Item &i);
    float getPrice()
    {
        return price;
    }
    string getName()
    {
        return name;
    }
    int getQuantity()
    {
        return quantity;
    }
    void setName(string name)
    {
        this->name=name;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    friend ofstream & operator << (ofstream &ofs,Item &i);
    friend ifstream & operator >> (ifstream &ifs,Item &i);
    friend ostream & operator << (ostream &os,Item &i);
};

int main()
{
    int n,q;
    float p;
    string name;
    cout<<"Enter the number of Items : ";
    cin>>n;
    Item *list[n];
    cout<<"Enetr All Items : \n";
    for(int i=0;i<n;i++)
    {
    cout<<"Enter "<<i+1<<" Item Name :";
    cin>>name;
    cout<<"Enter "<<i+1<<" Item Price :";
    cin>>p;
    cout<<"Enter "<<i+1<<" Item Quantity :";
    cin>>q;
    list[i] = new Item(name,p,q);

    }
    ofstream ofs("Item.txt",ios::trunc);
    for(int i=0;i<n;i++)
    {
        ofs<<*list[i];
    }
    Item item;
    ifstream ifs("Item.txt");
    for(int i=0;i<n;i++)
    {
        ifs>>item;
        cout<<"Item "<<i+1<<" : "<<endl;
        cout<<" Name : "<<item.getName()<<endl;
        cout<<" Price : "<<item.getPrice()<<endl;
        cout<<" Quantity : "<<item.getQuantity()<<endl;
    }
    return 0;
}

Item::Item(string n,float p,int q)
{
    name = n;
    price = p;
    quantity = q;
}

Item::Item(Item &i)
{
    name = i.name;
    price = i.price;
    quantity = i.quantity;
}

ofstream & operator << (ofstream &ofs,Item &i)
{
    ofs<<i.name<<endl<<i.price<<endl<<i.quantity<<endl;
    return ofs;
}

ifstream & operator >> (ifstream &ifs,Item &i)
{
    ifs>>i.name>>i.price>>i.quantity;
    return ifs;
}

ostream & operator << (ostream &os,Item &i)
{
    cout<<i.name<<endl<<i.price<<endl<<i.quantity<<endl;
    return os;
}