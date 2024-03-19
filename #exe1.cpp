#include <iostream>

using namespace std;

int main(){
    float radius,area;
    cout<<"Enter the radius : ";
    cin>>radius;
    area=(float)22/7*radius*radius;
    cout<<"Area of the Circle whose radius is "<<radius<<" will be : "<<area<<endl;

    return 0;    
}