#include <iostream>
#include "school.cpp"

using namespace std;

int main()
{
    Student s;
    Teacher t;
    School sc;
    string name;
    courses sub;
    int code_sub;
    int std,salary,ch,sch,tch;
    char div;
    do
    {
        cout<<"\t*** School Name ***\n";
        cout<<"----- OPTIONS -----\n";
        cout<<"1.Student Section\n2.Teacher Section\n3.No. Division Present\n4.Quit\n";
        cout<<"-------------------\n";
        cout<<"Enter Your Choice : ";
        cin>>ch;
        cout<<"-------------------\n";
        switch(ch)
        {
            case 1:
                 cout<<"\t*** Student Section ***\n";
                do
                {
                    cout<<"----- STUDENT MENU -----\n";
                    cout<<"1.New Admission\n2.Show Student Details\n3.All Student's Details\n4.Remove Student\n5.Quit\n";
                    cout<<"------------------------\n";
                    cout<<"Enter Your Choice : ";
                    cin>>sch;
                    cout<<"------------------------\n";
                    switch(sch)
                    {
                        default:
                            cout<<"Wrong Choice ! \n";
                            break;
                        case 1:
                            
                            cout<<"Enter First Name of Student : ";
                            cin>>name;
                            cout<<"Enter in Which Standard you want Admission : ";
                            cin>>std;
                            do
                            {
                                cout<<"Select Subjaect : \n1.C \n2.Python\n3.Java\n4.MySQL\n";
                                cout<<"Enter the Subject Code : ";
                                cin>>code_sub;
                                if(code_sub == 5)
                                    cout<<"Wrong Subject Code!!!\n";
                            }while(code_sub >= 5);
                            sub = (courses)code_sub;
                            s = sc.NewAdmission(name,std,sub);
                            sc.assign_Teacher();
                            cout<<"Admission is Done Successfully!\n";
                            cout<<s;
                            
                            break;
                        case 2:
                            try
                            {
                                int admin;
                                cout<<"Enter Admission No. : ";
                                cin>>admin;
                                s = sc.ShowStudentDetails(admin);
                                cout<<"\t Details of Student \n";
                                cout<<s;
                                s.showTeacherAlloted();
                            }
                            catch(int e)
                            {
                                cout<<"Wrong Admission No!!!\n";
                            }
                            break;
                        case 3:
                            sc.ShowAllStudentDetails();
                            break;
                        case 4:
                            try
                            {
                                int admin;
                                cout<<"Enter Admission No. : ";
                                cin>>admin;
                                sc.RemoveStudent(admin);
                            }
                            catch(int e)
                            {
                                cout<<"Wrong Admission No!!!\n";
                            }
                            break;
                        case 5:
                            break;
                    }
                }while(sch != 5);
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
                         
                            cout<<"Enter First Name of Teacher : ";
                            cin>>name;                       
                            cout<<"Enter Salary : ";
                            cin>>salary;
                            do
                            {
                                cout<<"Select Subjaect : \n1.C \n2.Python\n3.Java\n4.MySQL\n";
                                cout<<"Enter the Subject Code : ";
                                cin>>code_sub;
                                if(code_sub == 5)
                                    cout<<"Wrong Subject Code!!!\n";
                            }while(code_sub >= 5);
                            sub = (courses)code_sub;
                            cout<<"Enter Standard Alloted : ";
                            cin>>std;
                            cout<<"Enter Division Alloted : ";
                            cin>>div;                        
                            t = sc.NewJoinning(name,salary,std,sub,div);
                            sc.assign_Teacher();
                            cout<<"New Teacher is been Recruited Successfully! \n";
                            cout<<t;
                            break;
                        case 2:
                            try
                            {
                                int id;
                                cout<<"Enter Id of Teacher : ";
                                cin>>id;
                                t = sc.ShowTeacherDetails(id);
                                cout<<"\t Details of Teacher \n";
                                cout<<t;
                            }
                            catch(int e)
                            {
                                cout<<"Wrong Teacher ID!!!\n";
                            }
                            break;
                        case 3:
                            sc.ShowAllTeacherDetails();
                            break;
                        case 4:
                            try
                            {
                                int id;
                                cout<<"Enter Id of Teacher : ";
                                cin>>id;
                                sc.RemoveTeacher(id);
                                sc.assign_Teacher();
                                cout<<"Teacher is Removed Successfully!\n";
                            }
                            catch(int e)
                            {
                                cout<<"Wrong Teacher ID!!!\n";
                            }
                            break;
                        case 5:
                            break;
                    }
                } while (tch != 5);
                break;
            case 3:
                int no;
                cout<<"Enter Standard : ";
                cin>>std;
                no = sc.noDivisionPresent(std);
                cout<<std<<" Standard has "<<no<<" Division\n";
                break;
            case 4:
                return 0;
            default:
                cout<<"Wrong Choice !\n";
                break;

        }
    }while(true);   
}