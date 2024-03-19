#include <iostream>
#include <map>
#include <fstream>
#include "student.cpp"
#include "teacher.cpp"

using namespace std;


class School
{   
    map<int,Student> mst;
    map<int,Teacher> mteach;
public:
    
    Student NewAdmission(string fname,string lname,string father,string mother,string contact,int std);
    Student ShowStudentDetails(int admin);
    void ShowAllStudentDetails();
    void RemoveStudent(int admin);


    Teacher NewJoinning(string fname,string lname,int salary,int std,string sub,string mobno,char div);
    Teacher ShowTeacherDetails(int id);
    void ShowAllTeacherDetails();
    void RemoveTeacher(int id);

    void assign_Div_Roll(int std);
    void assign_Teacher();

};




Student School::NewAdmission(string fname,string lname,string father,string mother,string contact,int std)  
{
    assign_Div_Roll(std);
    Student s(fname,lname,father,mother,contact,std);
    mst.insert(pair<int,Student>(s.getAdmissionNo(),s));
    return s;
}

Student School::ShowStudentDetails(int admin)
{   
    map<int,Student>::iterator it;
    it = mst.find(admin);
    return it->second;
}

void School::ShowAllStudentDetails()
{
    map<int,Student>::iterator it;
    for(it = mst.begin();it != mst.end();it++)
        cout<<it->second;
}

void School::RemoveStudent(int admin)
{
    map<int,Student>::iterator it;
    it = mst.find(admin);
    mst.erase(it->first);

}

Teacher School::NewJoinning(string fname,string lname,int salary,int std,string sub,string mobno,char div)
{
    Teacher t(fname,lname,salary,std,sub,mobno,div);
    mteach.insert(pair<int,Teacher>(t.getTeacherId(),t));
    return t;
}

Teacher School::ShowTeacherDetails(int id)
{
    map<int,Teacher>::iterator it;
    it = mteach.find(id);
    return it->second;
}

void School::ShowAllTeacherDetails()
{
    map<int,Teacher>::iterator it;
    for(it = mteach.begin();it != mteach.end();it++)
        cout<<it->second;
}

void School::RemoveTeacher(int id)
{
    map<int,Teacher>::iterator it;
    it = mteach.find(id);
    mteach.erase(it->first);

}

void School::assign_Teacher()
{
    map<int,Student>::iterator sit;
    map<int,Teacher>::iterator tit;
    
    for(sit = mst.begin();sit != mst.end();sit++)
    {    
        int index=0;
        for(tit = mteach.begin();tit != mteach.end();tit++)
        {
            if(sit->second.getStandard() == tit->second.getTeacherStandard())
            {
                if(sit->second.getDivision() == tit->second.getTeacherDivision())
                {
                    sit->second.setTeacherName(index,tit->second.getTeacherFirstName());
                    index++;
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
        if(it->second.getStandard() == std)
        {
            it->second.setNextRollNo(it->second.getRollNo());
            it->second.setNextDivision(it->second.getDivision());
            break;
        }
    }
    if(it == mst.rend())
    {
        it->second.setNextRollNo(0);
        it->second.setNextDivision('A');
    }
}

