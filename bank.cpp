#include <iostream>
#include <map>
#include <fstream>
#include "account.cpp"

using namespace std;

class Bank
{
    map<long int,Account> m;
public:
    Bank();
    Account OpenNewAccount(string fname,string lname,float balance,string mobno);
    Account ShowAccountDetails(long int accno);
    Account BalanceEnquiry(long int accno);
    Account Deposit(long int accno,float amount);
    Account Withdrawal(long int accno,float amount);
    void CloseAccount(long int accno);
    void ShowAllAccount();
    string UpdateMobileNo(long int accno,string mobno);
    ~Bank();
};

Bank::Bank()
{   Account acc;
    ifstream ifs;
    ifs.open("Bank.txt");
    if(!ifs)
        throw 1;
    else
    {
        
        while(!ifs.eof())
        {
            ifs>>acc;
            m.insert(pair<long int,Account>(acc.getAccountNo(),acc));
        }
    }
    Account::setNextAccountNo(acc.getAccountNo());
    ifs.close();
}

Account Bank::OpenNewAccount(string f_name,string lname,float balance,string mobno)
{   
    Account acc(f_name,lname,balance,mobno);
    map<long int,Account>::iterator it;
    m.insert(pair<long int,Account>(acc.getAccountNo(),acc));
    return acc;;
}


Account Bank::ShowAccountDetails(long int accno)
{
    map<long int,Account>::iterator it;
    it = m.find(accno);
    if(it == m.end())
        throw 2;
    return it->second;
}

Account Bank::BalanceEnquiry(long int accno)
{
    map<long int,Account>::iterator it;
    it = m.find(accno);
    if(it == m.end())
        throw 2;
    return it->second;
}

Account Bank::Deposit(long int accno,float amount)
{
    map<long int,Account>::iterator it;
    it = m.find(accno);
    if(it == m.end())
        throw 2;
    it->second.deposit(amount);
    return it->second;
}

Account Bank::Withdrawal(long int accno,float amount)
{
    map<long int,Account>::iterator it;
    it = m.find(accno);
    if(it == m.end())
        throw 2;
    it->second.withdrawal(amount);
    return it->second;
}

void Bank::CloseAccount(long int accno)
{
    map<long int,Account>::iterator it;
    it = m.find(accno);
    if(it == m.end())
        throw 2;
    m.erase(it->first);
}

void Bank::ShowAllAccount()
{
    map<long int,Account>::iterator it;
    for(it = m.begin();it != m.end();it++)
    {
        cout<<it->second;
    }
}

string Bank::UpdateMobileNo(long int accno,string mobno)
{
    map<long int,Account>::iterator it;
    it = m.find(accno);
    if(it == m.end())
        throw 2;
    it->second.setMobileNo(mobno);
    return it->second.getMobileNo();
}

Bank::~Bank()
{
    ofstream ofs;
    ofs.open("Bank.txt",ios::trunc);
    map<long int,Account>::iterator it;
    for(it = m.begin();it != m.end();it++)
    {
        ofs<<it->second;
    }
    ofs.close();
}

