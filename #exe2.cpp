#include <iostream>

using namespace std;

int main()
{
    int basic_salary,allowance,deducation,net_salary;
    cout<<"Enter Basic Salary : ";
    cin>>basic_salary;
    cout<<"Enter Percentage of Allowance : ";
    cin>>allowance;
    cout<<"Enter Percentage of Deducation : ";
    cin>>deducation;

    net_salary = basic_salary + (basic_salary * allowance)/100 - (basic_salary * deducation)/100;

    cout<<"Net Saraly : "<<net_salary<<endl;

    return 0;
}