#include <iostream>
#include "school1.cpp"

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
        if(*it >= '0' && *it <= '9' && no.length() == 10)
        {}
        else
        {
            cout<<"Invalid Number.!!! \n";
            return 0;
        }
        
    }
    return 1;
}

int main()
{   
    Teacher t;
    Student s;
    School sc;
    int ch,choice,tch,smch;
    string fname,lname,father,mother,contact;
    int std;
    string tfname,tlname,tmobno,sub;
    int salary,tstd,tmch;
    char tdiv;
    int valid;
    
    do{
        cout<<"\t*** School Name ***\n";
        cout<<"----- OPTIONS -----\n";
        cout<<"1.Student Section\n2.Teacher Section\n3.Quit\n";
        cout<<"-------------------\n";
        cout<<"Enter Your Choice : ";
        cin>>choice;
        cout<<"-------------------\n";
        switch(choice)
        {
            case 1:
                cout<<"\t*** Student Section ***\n";
                do
                {
                    cout<<"----- STUDENT MENU -----\n";
                    cout<<"1.New Admission\n2.Show Student Details\n3.All Student's Details\n4.Remove Student\n5.Quit\n";
                    cout<<"------------------------\n";
                    cout<<"Enter Your Choice : ";
                    cin>>ch;
                    cout<<"------------------------\n";
                    switch(ch)
                    {
                        default:
                            cout<<"Wrong Choice ! \n";
                            break;
                        case 1:
                            do
                            {
                                cout<<"Enter First Name of Student : ";
                                cin>>fname;
                                valid = validateName(fname);
                            }while(valid == 0);
                            do
                            {
                                cout<<"Enter Last Name of Student : ";
                                cin>>lname;
                                valid = validateName(lname);
                            }while(valid == 0);
                            do
                            {
                                cout<<"Enter Father's Name of Student : ";
                                cin>>father;
                                valid = validateName(father);
                            }while(valid == 0);   
                            do
                            {
                                cout<<"Enter Mother's Name of Student : ";
                                cin>>mother;
                                valid = validateName(mother);
                            }while(valid == 0);
                            do
                            {
                                cout<<"Enter Contact No. of Father : ";
                                cin>>contact;
                                valid = validateMobileNo(contact);
                            }while(valid == 0); 
                            cout<<"Enter in Which Standard you want Admission : ";
                            cin>>std;
                            s = sc.NewAdmission(fname,lname,father,mother,contact,std);
                            sc.assign_Teacher();
                            cout<<"Admission is Done Successfully!\n";
                            cout<<s;
                            break;
                        case 2:
                            int admin;
                            cout<<"Enter Admission No. : ";
                            cin>>admin;
                            s = sc.ShowStudentDetails(admin);
                            cout<<"\t Details of Student \n";
                            cout<<s;
                            s.ShowTeacherName(admin);
                            break;
                        case 3:
                            sc.ShowAllStudentDetails();
                            break;
                        case 4:
                            cout<<"Enter Admission No. : ";
                            cin>>admin;
                            sc.RemoveStudent(admin);
                            break;
                        case 5:
                            break;
                        case 6:
                            cout<<"Enter Admission No. : ";
                            cin>>admin;
                            s = sc.ShowStudentDetails(admin);
                            cout<<"Modification Options \n";
                            cout<<"1.Student First Name\n2. Student Last Name\n3. Father Name\n4. Mother Name\n5. Contact No.\n";
                            cin>>smch;
                            switch(smch)
                            {
                                case 1:
                                    do
                                    {
                                        cout<<"Enter Corect First Name of Student : ";
                                        cin>>fname;
                                        valid = validateName(fname);
                                    }while(valid == 0);
                                    s.setFirstName(fname);
                                case 2:
                                    break;
                                    do
                                    {
                                        cout<<"Enter Correct Last Name of Student : ";
                                        cin>>lname;
                                        valid = validateName(lname);
                                    }while(valid == 0);
                                    s.setLastName(lname);
                                    break;
                                case 3:
                                    do
                                    {
                                        cout<<"Enter Correct Father's Name of Student : ";
                                        cin>>father;
                                        valid = validateName(father);
                                    }while(valid == 0);
                                    s.setFatherName(father);
                                    break;
                                case 4:
                                    do
                                    {
                                        cout<<"Enter Correct Mother's Name of Student : ";
                                        cin>>mother;
                                        valid = validateName(mother);
                                    }while(valid == 0);
                                    s.setMotherName(mother);
                                    break;
                                case 5:
                                    do
                                    {
                                        cout<<"Enter Contact No. of Father : ";
                                        cin>>contact;
                                        valid = validateMobileNo(contact);
                                    }while(valid == 0);
                                    s.setContactNo(contact);
                                    break;
                                default:
                                    cout<<"Wrong Choice !\n";
                                    break;
                            }
                            break;
                    }
                }while(ch != 5);
                break;
            case 2:
                cout<<"\t*** Teacher Section ***\n";
                do
                {
                    cout<<"----- TEACHER MENU -----\n";
                    cout<<"1.New Joining\n2.Show Details of Teacher\n3.Show Details of All Teachers\n4.Remove Teacher\n5.Quit\n";
                    cout<<"------------------------\n";
                    cout<<"Enter Your Choice : ";
                    cin>>tch;
                    cout<<"------------------------\n";
                    switch(tch)
                    {
                        default: 
                            cout<<"Wrong Choice ! \n";
                            break;
                        case 1:
                            do
                            {
                                cout<<"Enter First Name of Teacher : ";
                                cin>>tfname;
                                valid = validateName(tfname);
                            }while(valid == 0);
                            do
                            {
                                cout<<"Enter Last Name of Teacher : ";
                                cin>>tlname;
                                valid = validateName(tlname);
                            }while(valid == 0);
                            cout<<"Enter Salary : ";
                            cin>>salary;
                            cout<<"Enter Subject Alloted : ";
                            cin>>sub;
                            cout<<"Enter Standard Alloted : ";
                            cin>>tstd;
                            cout<<"Enter Division Alloted : ";
                            cin>>tdiv;
                            do
                            {
                                cout<<"Enter your Mobile No. : ";
                                cin>>tmobno;
                                valid = validateMobileNo(tmobno);
                            }while(valid == 0);
                            t = sc.NewJoinning(tfname,tlname,salary,tstd,sub,tmobno,tdiv);
                            sc.assign_Teacher();
                            cout<<"New Teacher is been Recruited Successfully! \n";
                            cout<<t;
                            break;
                        case 2:
                            int id;
                            cout<<"Enter Id of Teacher : ";
                            cin>>id;
                            t = sc.ShowTeacherDetails(id);
                            cout<<"\t Details of Teacher \n";
                            cout<<t;
                            break;
                        case 3:
                            sc.ShowAllTeacherDetails();
                            break;
                        case 4:
                            cout<<"Enter Id of Teacher : ";
                            cin>>id;
                            sc.RemoveTeacher(id);
                            cout<<"Teacher is Removed Successfully!\n";
                            break;
                        case 5:
                            break;
                        case 6:
                            cout<<"Enter Id of Teacher : ";
                            cin>>id;
                            t = sc.ShowTeacherDetails(id);
                            cout<<"Modification Options \n";
                            cout<<"1.Teacher First Name\n2. Teacher Last Name\n3. Contact No.\n";
                            cin>>tmch;
                            switch(tmch)
                            {
                                case 1:
                                    do
                                    {
                                        cout<<"Enter First Name of Teacher : ";
                                        cin>>tfname;
                                        valid = validateName(tfname);
                                    }while(valid == 0);
                                    t.setTeacherFirstName(tfname);
                                    break;
                                case 2:
                                    do
                                    {
                                        cout<<"Enter Last Name of Teacher : ";
                                        cin>>tlname;
                                        valid = validateName(tlname);
                                    }while(valid == 0);
                                    t.setTeacherLastName(tlname);
                                    break;
                                case 3:
                                    do
                                    {
                                        cout<<"Enter your Mobile No. : ";
                                        cin>>tmobno;
                                        valid = validateMobileNo(tmobno);
                                    }while(valid == 0);
                                    t.setMobileNo(tmobno);
                                    break;
                                default:
                                    cout<<"Wrong Choice !\n";
                                    break;
                            }
                    }
                } while (tch != 5);
                break;
            case 3:
                return 0;
            default:
                cout<<"Wrong Choice !\n";
                break;

        }
    }while(true);   
}