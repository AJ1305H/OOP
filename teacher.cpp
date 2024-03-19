#include <iostream>

using namespace std;

class Teacher
{
    static int nextTeacher_Id;
    string first_name,last_name,mobile_no;
    int teacher_id,salary,standard;
    string subject;
    char division;
public:
    Teacher(){};
    Teacher(string fname,string lname,int salary,int std,string sub,string mobno,char div);
    int getTeacherId();
    string getTeacherFirstName();
    string getTeacherLastName();
    string getMobileNo();
    int getTeacherStandard();
    char getTeacherDivision();

    void setTeacherFirstName(string fname);
    void setTeacherLastName(string lname);
    void setMobileNo(string mobno);
    void setTeacherStandard(int std);
    void setTeacherDivision(char div);

    friend ostream & operator <<(ostream &os,Teacher &t);

};

int Teacher::nextTeacher_Id = 0;

int Teacher::getTeacherId()
{
    return teacher_id;
}

Teacher::Teacher(string fname,string lname,int salary,int std,string sub,string mobno,char div)
{
    teacher_id = ++nextTeacher_Id;
    first_name = fname;
    last_name = lname;
    this->salary = salary;
    standard = std;
    subject = sub;
    division = div;
    mobile_no = mobno;
}

string Teacher::getTeacherFirstName()
{
    return first_name;
}
string Teacher::getTeacherLastName()
{
    return last_name;
}
string Teacher::getMobileNo()
{
    return mobile_no;
}
int Teacher::getTeacherStandard()
{
    return standard;
}
char Teacher::getTeacherDivision()
{
    return division;
}

void Teacher::setTeacherFirstName(string fname)
{
    first_name = fname;
}
void Teacher::setTeacherLastName(string lname)
{
    last_name = lname;
}
void Teacher::setMobileNo(string mobno)
{
    mobile_no = mobno;
}
void Teacher::setTeacherStandard(int std)
{
    standard = std;
}
void Teacher::setTeacherDivision(char div)
{
    division = div;
}

ostream & operator <<(ostream &os,Teacher &t)
{
    os<<"\tTeacher Details\n";
    os<<"Teacher Id : "<<t.teacher_id<<endl;
    os<<"Name : "<<t.first_name<<" "<<t.last_name<<endl;
    os<<"Mobile No. : "<<t.mobile_no<<endl;
    os<<"Salary : "<<t.salary<<endl;
    os<<"Teach's Class : "<<t.standard<<" - "<<t.division<<endl;
    os<<"Subject : "<<t.subject<<endl;
    return os;

}

