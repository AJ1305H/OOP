#include <iostream>
#include "bank.cpp"

using namespace std;

int validateName(string name)
{
    string::iterator itr;
    for(itr = name.begin();itr != name.end();itr++)
    {
        if((*itr >= 'A' && *itr <='Z') || (*itr >= 'a' && *itr <= 'z'))
        {}
        else
        {
            cout<<"Invalid Name!!!\n";
            return 0;
        }
    }   
    return 1;
}
int validateMobileNo(string no)
{
    string::iterator it;
    for(it = no.begin();it != no.end();it++)
    {
        iit <= '9' && no.length() == 10)f(*it >= '0' && *
        {

        }
        else
        {
            cout<<"Invalid Mobile Number.!!! \n";
            return 0;
        }
        
    }
    return 1;
}

int main()
{   
    Account acc;
    Bank b;
    int ch;
    string fname,lname,mobno;
    float amount;
    int valid;
    cout<<"\t*** BANKING SYSTEM ***\n";
    do{
        cout<<"----- MENU -----\n";
        cout<<"1.OpenAccount\n2.Show Account Details\n3.Balance Enquiry\n4.Deposit\n5.Withdraw\n6.Close Account\n7.Show All Accounts\n8.Update Mobile No\n9.Quit";
        cout<<"\n---------------------";
        cout<<"\nEnter your Choice : ";
        cin>>ch;
        switch(ch)
        {
            default:
                cout<<"Entered Wrong Choice!!!\n";
                break;
            case 1:
                try
                {   
                    do{
                        cout<<"Enter Account Holder's First Name : ";
                        cin>>fname;
                        valid = validateName(fname);
                    }while(valid == 0);
                    do
                    {
                        cout<<"Enter Account Holder's Last Name : ";
                        cin>>lname;
                        valid = validateName(lname);
                    }while(valid == 0);
                    do
                    {
                        cout<<"Enter Mobile No. : ";
                        cin>>mobno;
                        valid = validateMobileNo(mobno);
                    }while(valid == 0);
                    cout<<"Enter Inital Amount to be Deposited (Minmum = ₹500) : ";
                    cin>>amount;

                    acc = b.OpenNewAccount(fname,lname,amount,mobno);
                    cout<<"\nYour Account is Created Successfully!"<<endl;
                    cout<<acc;
                }
                catch(int e)
                {
                    cout<<"Error in File Opening! File not Present!"<<endl;
                    cout<<"Please First Create File Named 'Bank.txt' !!!"<<endl;
                }
                catch(InsufficientBalance code)
                {
                    cout<<"Account can't be Created !\n";
                    cout<<"Minimum Balance Should ₹500 ! \n";
                }
                break;
            case 2:
                try
                {
                    long int accno;
                    cout<<"Enter your Account No. : ";
                    cin>>accno;
                    acc = b.ShowAccountDetails(accno);
                    cout<<"\tYour Account Details "<<endl;
                    cout<<acc;
                }
                catch(int e)
                {
                    cout<<"No Account Present! Please check your Account No. !\n";
                }
                break;
            case 3:
                long int accno;
                cout<<"Enter your Account No. : ";
                cin>>accno;
                acc = b.BalanceEnquiry(accno);
                cout<<"Available Balance : "<<acc.getBalance()<<endl;
                break;
            case 4:
                cout<<"Enter your Account No. : ";
                cin>>accno;
                cout<<"Enter Amount to Deposit : ";
                cin>>amount;
                acc = b.Deposit(accno,amount);
                cout<<"₹"<<amount<<" is been Deposited Successfully \n";
                cout<<"Updated Available Balance : "<<acc.getBalance()<<endl;
                break;
            case 5:
                cout<<"Enter your Account No. : ";
                cin>>accno;
                cout<<"Enter Amount to Withdraw : ";
                cin>>amount;
                acc = b.Withdrawal(accno,amount);
                cout<<"₹"<<amount<<" is been Withdrawal Successfully \n";
                cout<<"Updated Available Balance : "<<acc.getBalance()<<endl;         
                break;
            case 6:
                cout<<"Enter your Account No. : ";
                cin>>accno;
                b.CloseAccount(accno);
                cout<<"Your Account is been Closed Successfully! \n";
                break;
            case 7:
                b.ShowAllAccount();
                break;
            case 8:
                cout<<"Enter your Account No. : ";
                cin>>accno;
                do
                {
                    cout<<"Enter New Mobile No. : ";
                    cin>>mobno;
                    valid = validateMobileNo(mobno);
                }while(valid == 0);
                mobno = b.UpdateMobileNo(accno,mobno);
                cout<<"Your New Mobile No. is Updated Successfully! \n";
                cout<<"New Mobile No. : "<<mobno<<endl;
                break;
            case 9:
                return 0;
        }

    }while(true);
    
}