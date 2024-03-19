#include <iostream>
#include <string>

using namespace std;

class Student
{
    int rollno;
    float matmark,chemmark,phymark;
    string name;
public:
    Student(int r,string n,float m1,float m2,float m3);
    float totalMarks();
    char grade();
};

int main()
{
    int r;
    float m1,m2,m3;
    string name;
    cout<<"Enter Name : ";
    getline(cin,name);
    cout<<"Enter Rollno. : ";
    cin>>r;
    cout<<"Enter Maths marks : ";
    cin>>m1;
    cout<<"Enter Chemistry marks : ";
    cin>>m2;
    cout<<"Enter Physics marks : ";
    cin>>m3;
    Student s(r,name,m1,m2,m3);
    cout<<"Total Marks : "<<s.totalMarks()<<endl;
    cout<<"Grade : "<<s.grade()<<endl;
    return 0;

}

Student::Student(int r,string n,float m1,float m2,float m3)
{
    rollno = r;
    name = n;
    matmark = m1;
    chemmark = m2;
    phymark = m3;
}

float Student::totalMarks()
{
    return matmark+chemmark+phymark;
}
char Student::grade()
{
    float avg=totalMarks()/3;
    if(avg>=60.0)
        return 'A';
    else if(avg<60.0 && avg>=40)
        return 'B';
    else 
        return 'C';
}