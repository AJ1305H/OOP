#include <iostream>
#include <fstream>

using namespace std;

class InsufficientBalance{};

class Account
{
    string first_name,last_name,mobile_no;
    float balance;
    long int account_no;
    static long int NextAccountNo;

public:
    Account(){}
    Account(string fname,string lname,float balance,string mobno);
    string getFirstName();
    string getLastName();
    float getBalance();
    long int getAccountNo();
    string getMobileNo();
    static long int getLastAcccountNo();
    static void setNextAccountNo(long int lastaccountno);
    void setBalance(float amount);
    void setMobileNo(string mobno);
    void deposit(float amount);
    void withdrawal(float amount);
    friend ofstream & operator<< (ofstream &ofs,Account &a);
    friend ifstream & operator>> (ifstream &ifs,Account &a);
    friend ostream & operator<< (ostream &os,Account &a);
};

long int Account::NextAccountNo = 0;

Account::Account(string fname,string lname,float balance,string mobno)
{
    // NextAccountNo++;
    account_no = ++NextAccountNo;
    first_name = fname;
    last_name = lname;
    setBalance(balance);
    mobile_no = mobno;
}

string Account::getFirstName()
{
    return first_name;
}

string Account::getLastName()
{
    return last_name;
}

float Account::getBalance()
{
    return balance;
}

long int Account::getAccountNo()
{
    return account_no;
}

long int Account::getLastAcccountNo()
{
    return NextAccountNo;
}

string Account::getMobileNo()
{
    return mobile_no;
}

void Account::setNextAccountNo(long int last_accno)
{
    NextAccountNo = last_accno;
}

void Account::setBalance(float amount)
{
    if(amount < 500)
        throw InsufficientBalance();
    balance = amount;
}

void Account::setMobileNo(string mobno)
{
    mobile_no = mobno;
}

void Account::deposit(float amount)
{ 
    balance += amount;
}

void Account::withdrawal(float amount)
{
    if(balance - amount < 500)
        throw InsufficientBalance();
    balance -= amount;
}

ofstream & operator<< (ofstream &ofs, Account &a)
{
    ofs<<a.account_no<<endl;
    ofs<<a.first_name<<endl;
    ofs<<a.last_name<<endl;
    ofs<<a.mobile_no<<endl;
    ofs<<a.balance<<endl;
    return ofs;
}

ifstream & operator>> (ifstream &ifs, Account &a)
{
    ifs>>a.account_no>>a.first_name>>a.last_name>>a.mobile_no>>a.balance;
    return ifs;
}

ostream & operator << (ostream &os, Account &a)
{
    os<<"\tDetails of Account No. : "<<a.getAccountNo()<<endl;
    os<<"Name of Account Holder : "<<a.getFirstName()<<" "<<a.getLastName()<<endl;
    os<<"Account No. : "<<a.getAccountNo()<<endl;
    os<<"Mobile No. : "<<a.mobile_no<<endl;
    os<<"Available Balance : "<<a.getBalance()<<endl;
    return os;
}