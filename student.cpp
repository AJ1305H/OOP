#include <iostream>

using namespace std;


class Student
{
    static int nextRoll_No;
    static char nextDivision;
    static int nextAdmissionNo;
    string first_name,last_name,father_name,mother_name,contact_no;
    int standard,rollNo,admission_no;    
    char division;
    string teacher_name[5];

    
public:
    Student(){};
    Student(string fname,string lname,string father,string mother,string contact,int std);
    int getAdmissionNo();
    static int getLastRollNo();
    static char getLastDivision();
    static int getLastAdmissionNo();
    int isDivisionFull(int prevroll);
    static void setNextRollNo(int lastrollno);
    static void setNextDivision(int lastdiv);
    string getFirstName();
    string getLastName();
    string getFatherName();
    string getMotherName();
    string getContactNo();
    int getStandard();
    int getRollNo();
    char getDivision();


    void setFirstName(string fname);
    void setLastName(string lname);
    void setFatherName(string father);
    void setMotherName(string mother);
    void setContactNo(string contact);
    void setTeacherName(int index,string name);

    void ShowTeacherName(int admin);
    friend ostream & operator <<(ostream &os,Student &s);
    

};
int Student::nextAdmissionNo = 0;
char Student::nextDivision = 'A';
int Student::nextRoll_No = 0;

Student::Student(string fname,string lname,string father,string mother,string contact,int std)
{
    admission_no = ++nextAdmissionNo;
    first_name = fname;
    last_name = lname;
    father_name = father;
    mother_name = mother;
    contact_no = contact;
    standard = std;
    int i = isDivisionFull(getLastRollNo());
    if(i == 1)
    {
        setNextRollNo(0); 
        division = ++nextDivision;
    }
    else
    {
        division = nextDivision;
    }
    rollNo = ++nextRoll_No;
    teacher_name[0] = "\0";
}   

int Student::getAdmissionNo()
{
    return admission_no;
}

int Student::getLastRollNo()
{
    return nextRoll_No;
}

char Student::getLastDivision()
{
    return nextDivision;
}

int Student::getLastAdmissionNo()
{
    return nextAdmissionNo;
}

int Student::isDivisionFull(int prevroll)
{
    if(prevroll == 3)
        return 1;
    return 0;
}

void Student::setNextRollNo(int lastrollno)
{
    nextRoll_No = lastrollno;
}

void Student::setNextDivision(int lastdiv)
{
    nextDivision = lastdiv;
}

string Student::getFirstName()
{
    return first_name;
}
string Student::getLastName()
{
    return last_name;
}
string Student::getFatherName()
{
    return father_name;
}
string Student::getMotherName()
{
    return mother_name;
}
string Student::getContactNo()
{
    return contact_no;
}
int Student::getStandard()
{
    return standard;
}
int Student::getRollNo()
{
    return rollNo;
}
char Student::getDivision()
{
    return division;
}

void Student::setFirstName(string fname)
{
    first_name = fname;
}
void Student::setLastName(string lname)
{
    last_name = lname;
}
void Student::setFatherName(string father)
{
    father_name = father;
}
void Student::setMotherName(string mother)
{
    mother_name = mother;
}
void Student::setContactNo(string contact)
{
    contact_no = contact;
}
void Student::setTeacherName(int index,string name)
{
    teacher_name[index] = name;
}

void Student::ShowTeacherName(int admin)
{
    if(teacher_name[0] != "\0")
    {
        for(int i = 0;i<5;i++)
        {
            cout<<"Teacher "<<i+1<<" : "<<teacher_name[i]<<endl;
            if(teacher_name[i+1] == "\0")
                break;
        }
    }
    else
        cout<<"No Teacher Is Alloted!\n";
}
ostream & operator <<(ostream &os,Student &s)
{
    os<<"\t Student Details \n";
    os<<"Admission No. : "<<s.admission_no<<endl;
    os<<"Student Name : "<<s.first_name<<" "<<s.last_name<<endl;
    os<<"Father's Name : "<<s.father_name<<endl;
    os<<"Mother's Name : "<<s.mother_name<<endl;
    os<<"Standard : "<<s.standard<<endl;
    os<<"Division : "<<s.division<<endl;
    os<<"Roll No. : "<<s.rollNo<<endl;
    os<<"Contact No. : "<<s.contact_no<<endl;
    return os;

}