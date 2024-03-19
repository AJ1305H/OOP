#include <iostream>
#include <string>
using namespace std;

class Employee{
    
    int eid;
    string name;
public:
    Employee(int eid,string name)
    {
        this->eid = eid;
        this->name = name;
    }
    int getEid()
    {
        return eid;
    }
    void setEid(int e)
    {
        if(e>0)
            eid = e;
        else
        {
            cout<<"Wrong Employee-id! \n";
            eid = 0;
        }
    }
    string getName()
    {
        return name;
    }
};

class FulltimeEmployee : public Employee
{
    
    int salary;
public:
    FulltimeEmployee(int x, string n, int s) : Employee(x,n)
    {
        salary = s;
    }
    int getSalary()
    {
        return salary;
    }
};

class ParttimeEmployee : public Employee
{

    int wage;
public:
    ParttimeEmployee(int x,string n,int w) : Employee(x,n)
    {
        wage = w;
    }
    int getWage()
    {
        return wage;
    }
};

int main()
{
    FulltimeEmployee f1(12,"Jay",10000);
    ParttimeEmployee p1(15,"Rohit",4000);

    cout<<"Salary of "<<f1.getName()<<" : "<<f1.getSalary()<<endl;
    cout<<"Daily wage of "<<p1.getName()<<" : "<<p1.getWage()<<endl;
}