//Palindrome

#include <iostream>

using namespace std;

int main()
{
    int n,rev=0,temp,r;
    cout<<"Enter a Number : ";
    cin>>n;
    temp = n;
    while(temp>0)
    {
        r = temp%10;
        rev = rev*10 + r;
        temp /= 10;
    }
    if(rev == n)
        cout<<n<<" is a Palindrome\n";
    else
        cout<<n<<" is nat a Palindrome\n";
        
}