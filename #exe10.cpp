#include <iostream>

using namespace std;

class Rational {
    int numerator,denominator;
public:
    Rational()
    {
        numerator = 1;
        denominator = 1;
    }
    Rational(int numerator,int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }
    Rational(Rational &r){
        numerator = r.numerator;
        denominator = r.denominator;
    }
    Rational operator +(Rational &r){
        Rational temp;
        if(denominator == r.denominator)
        {
            temp.numerator = numerator + r.numerator;
            temp.denominator = denominator;
        }
        else
        {
            temp.numerator = numerator*r.denominator + r.numerator*denominator;
            temp.denominator = denominator*r.denominator;
        }
        return temp;
    }
    friend ostream & operator<<(ostream &out,Rational &r);
            
    
};

ostream & operator<<(ostream &out,Rational &r)
{
    out<<r.numerator<<"/"<<r.denominator;
    return out;
}
int main(){
    Rational r1(3,4),r2(2,5),r3;
    cout<<r1<<endl;
    cout<<r2<<endl;
    r3 = r1 + r2;
    cout<<"Addition of "<<r1<<" and "<<r2<<" is : "<<r3<<endl;
    return 0;
}