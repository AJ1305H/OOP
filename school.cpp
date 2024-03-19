#include <iostream>
#include <map>

using namespace std;

enum courses {C=1,Python,Java,MySQL};

// ---------------------CLASS STANDARD ---------------------------------------

class Standard
{
    static char nextDivision;
    static int nextRoll_No;
public:
    Standard(){}
    static void setNextDivision(char div);
    static void setNextRollNo(int roll);

    static char getLastDivision();
    static int getLastRollNo();

    int isDivisionFull(int prevroll);
    //int isStandardFull(char div);
    string displaySubject(courses sub);
    
};
int Standard::nextRoll_No = 0;
char Standard::nextDivision = 'A';


void Standard::setNextDivision(char div)
{
    nextDivision = div;
}
void Standard::setNextRollNo(int roll)
{
    nextRoll_No = roll;
}

char Standard::getLastDivision()
{
    return nextDivision;
}
int Standard::getLastRollNo()
{
    return nextRoll_No;
}

int Standard::isDivisionFull(int prevroll)
{
    if(prevroll == 2)
        return 1;
    return 0;
}
// int Standard::isStandardFull(char div)
// {
//     if(div == 'C')
//         return 1;
//     return 0;
// }


//--------------------------CLASS STUDENT --------------------------------

class Student:virtual public Standard
{
    
    string student_name;
    static int nextAdmissionNo;
    int student_standard,rollNo,admission_no;    
    char student_division;
    courses student_subject;
    string t_name;
    bool flag;
    

public:
    
    Student(){}
    Student(string name,int std,courses sub);
    
    void setFlag(bool flag);
    void setStudentName(string name);
    void setSubject(courses sub);
    void allotTeacher(string name);

    int getAdmissionNo();
    string getStudentName();
    int getStudentStandard();
    int getStudentRollNo();
    char getStudentDivision();
    courses getStudentSubject();
    bool getFlag();

    string showTeacherAlloted();

    friend ostream & operator<< (ostream &os, Student &s);
    

};
int Student::nextAdmissionNo = 0;

Student::Student(string name,int std,courses sub)
{
    admission_no = ++nextAdmissionNo;
    student_name = name;
    student_standard = std;
    student_subject = sub;
    int i = isDivisionFull(getLastRollNo());
    if(i == 1)
    {
        setNextRollNo(0);
        char d = getLastDivision();
        setNextDivision(++d);
        student_division = getLastDivision();

    }
    else
    {
        student_division = getLastDivision();
    }
    int j = getLastRollNo();
    rollNo = ++j;
    flag = true;
    

}

void Student::setStudentName(string name)
{
    student_name = name;
}
void Student::setSubject(courses sub)
{
    student_subject = sub;
}
void Student::allotTeacher(string name)
{
    t_name = name;
}
void Student::setFlag(bool flag)
{
    this->flag = flag;
}

int Student::getAdmissionNo()
{
    return admission_no;
}
string Student::getStudentName()
{
    return student_name;
}
int Student::getStudentStandard()
{
    return student_standard;
}
int Student::getStudentRollNo()
{
    return rollNo;
}
char Student::getStudentDivision()
{
    return student_division;
}
courses Student::getStudentSubject()
{
    return student_subject;
}
bool Student::getFlag()
{
    return flag;
}

string Student::showTeacherAlloted()
{
    string x = "No Teacher Is Alloted!";
    if(t_name != "\0")
    {
        return t_name;
    }
    else
        return x;
}

ostream & operator<< (ostream &os, Student &s)
{
    os<<"\t Student Details \n";
    os<<"Admission No. : "<<s.admission_no<<endl;
    os<<"Student Name : "<<s.student_name<<endl;
    os<<"Standard : "<<s.student_standard<<endl;
    os<<"Division : "<<s.student_division<<endl;
    os<<"Roll No. : "<<s.rollNo<<endl;
    os<<"Subject : "<<s.displaySubject(s.student_subject)<<endl;
    os<<"Teacher Assign : "<<s.showTeacherAlloted()<<endl;
    return os;
}

//---------------------------CLASS TEACHER-----------------------------------------

class Teacher:virtual public Standard
{
    static int nextTeacher_Id;
    int teacher_id,salary,teacher_standard;
    char teacher_division;
    courses teacher_subject;
    string teacher_name;
    bool teacher_flag;
public:
    Teacher(){}
    Teacher(string name,int salary,int std,char div,courses sub);

    void setTeacherName(string name);
    void setSalary(int sal);
    void setTeacherStandard(int std);
    void setTeacherDivision(char div);
    void setTeacherSubject(courses sub);
    void setTeacherFlag(bool flag);

    int getTeacherId();
    string getTeacherName();
    int getSalary();
    int getTeacherStandard();
    char getTeacherDivision();
    courses getTeacherSubject();
    bool getTeacherFlag();

    friend ostream & operator <<(ostream &os,Teacher &t);
};

int Teacher::nextTeacher_Id = 0;

Teacher::Teacher(string name,int salary,int std,char div,courses sub)
{
    teacher_id = ++nextTeacher_Id;
    this->salary = salary;
    teacher_standard = std;
    teacher_division = div;
    teacher_subject = sub;
    teacher_name = name;
}

void Teacher::setTeacherName(string name)
{
    teacher_name = name;
}
void Teacher::setSalary(int sal)
{
    salary = sal;
}
void Teacher::setTeacherStandard(int std)
{
    teacher_standard = std;
}
void Teacher::setTeacherDivision(char div)
{
    teacher_division = div;
}
void Teacher::setTeacherSubject(courses sub)
{
    teacher_subject = sub;
}
void Teacher::setTeacherFlag(bool flag)
{
    teacher_flag = flag;
}

int Teacher::getTeacherId()
{
    return teacher_id;
}
string Teacher::getTeacherName()
{
    return teacher_name;
}
int Teacher::getSalary()
{
    return salary;
}
int Teacher::getTeacherStandard()
{
    return teacher_standard;
}
char Teacher::getTeacherDivision()
{
    return teacher_division;
}
courses Teacher::getTeacherSubject()
{
    return teacher_subject;
}
bool Teacher::getTeacherFlag()
{
    return teacher_flag;
}

ostream & operator <<(ostream &os,Teacher &t)
{
    os<<"\tTeacher Details\n";
    os<<"Teacher Id : "<<t.teacher_id<<endl;
    os<<"Name : "<<t.teacher_name<<endl;
    os<<"Salary : "<<t.salary<<endl;
    os<<"Teach's Class : "<<t.teacher_standard<<" - "<<t.teacher_division<<endl;
    os<<"Subject : "<<t.displaySubject(t.teacher_subject)<<endl;
    return os;

}

// ---------------------------- CLASS SCHOOL --------------------------------

class School: public Teacher,public Student
{   
    map<int,Student> mst;
    map<int,Teacher> mteach;
    map<char,int> mstd;

public:
    
    Student NewAdmission(string fname,int std,courses sub);
    Student ShowStudentDetails(int admin);
    void ShowAllStudentDetails();
    void RemoveStudent(int admin);


    Teacher NewJoinning(string fname,int salary,int std,courses sub,char div);
    Teacher ShowTeacherDetails(int id);
    void ShowAllTeacherDetails();
    void RemoveTeacher(int id);

    void assign_Div_Roll(int std);
    void assign_Teacher();
    int noDivisionPresent(int std);

};

Student School::NewAdmission(string fname,int std,courses sub)  
{
    assign_Div_Roll(std);
    Student s(fname,std,sub);
    mst.insert(pair<int,Student>(s.getAdmissionNo(),s));
    mstd.insert(pair<char,int>(getLastDivision(),std));

    return s;
}

Student School::ShowStudentDetails(int admin)
{   
    map<int,Student>::iterator it;
    it = mst.find(admin);
    if(it == mst.end())
        throw 1;
    if(it->second.getFlag() == true)
        return it->second;
    else
        throw 2;
        
}

void School::ShowAllStudentDetails()
{
    map<int,Student>::iterator it;
    for(it = mst.begin();it != mst.end();it++)
    {
        if(it->second.getFlag() == true)
        {
            cout<<it->second;
            showTeacherAlloted();
        }
    }    

}

void School::RemoveStudent(int admin)
{
    map<int,Student>::iterator it;
    it = mst.find(admin);
    if(it == mst.end())
        throw 1;
    it->second.setFlag(false);
    // mst.erase(it->first);

}

Teacher School::NewJoinning(string fname,int salary,int std,courses sub,char div)
{
    Teacher t(fname,salary,std,div,sub);
    mteach.insert(pair<int,Teacher>(t.getTeacherId(),t));
    return t;
}

Teacher School::ShowTeacherDetails(int id)
{
    map<int,Teacher>::iterator it;
    it = mteach.find(id);
    if(it == mteach.end())
        throw 1;
    if(it->second.getTeacherFlag() != true)
        throw 1;    
    return it->second;
}

void School::ShowAllTeacherDetails()
{
    map<int,Teacher>::iterator it;
    for(it = mteach.begin();it != mteach.end();it++)
        if(it->second.getTeacherFlag() == true)
            cout<<it->second;
}

void School::RemoveTeacher(int id)
{
    map<int,Teacher>::iterator it;
    it = mteach.find(id);
    if(it == mteach.end())
        throw 1;
    it->second.setTeacherFlag(false);
    // mteach.erase(it->first);

}

void School::assign_Teacher()
{
    map<int,Student>::iterator sit;
    map<int,Teacher>::iterator tit;
    for(sit = mst.begin();sit != mst.end();sit++)
    {    
        for(tit = mteach.begin();tit != mteach.end();tit++)
        {
            if(tit->second.getTeacherFlag() == true)
            {
                if(sit->second.getStudentStandard() == tit->second.getTeacherStandard())
                {
                    if(sit->second.getStudentDivision() == tit->second.getTeacherDivision() && sit->second.getStudentSubject() == tit->second.getTeacherSubject())
                    {   
                        sit->second.allotTeacher(tit->second.getTeacherName());
                    }
                    else
                        sit->second.allotTeacher("\0");
                }
            }
            
        }
        
    }
}

void School::assign_Div_Roll(int std)
{
    map<int,Student>::reverse_iterator it;
    for(it = mst.rbegin();it != mst.rend();it++)
    {
        if(it->second.getStudentStandard() == std)
        {
            setNextRollNo(it->second.getStudentRollNo());
            setNextDivision(it->second.getStudentDivision());
            break;
        }
    }
    if(it == mst.rend())
    {
        it->second.setNextRollNo(0);
        it->second.setNextDivision('A');
    }
}

int School::noDivisionPresent(int std)
{
    int count = 0;
    map<char,int>::iterator it;
    for(it = mstd.begin();it != mstd.end();it++)
    {
        if(it->second == std)
        {
            count++;
        }
    }
    return count;
}

string Standard::displaySubject(courses sub)
{
    switch(sub)
    {
        case C:
            return "C";
            break;
        case 2:
            return "Python";
            break;
        case 3:
            return "Java";
            break;
        case 4:
            return "MySQL";
            break;
        default:
            cout<<"Wrong Subject Code!!! \n";
            break;
    }  

}
