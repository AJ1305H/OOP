#include <iostream>

using namespace std;

class StackOverFlow {};
class StackUnderFlow {};

class Stack
{
    int *s;
    static int top;
    int size;

public: 
    Stack(int size)
    {
        this->size = size;
        s = new int[this->size];
    }
    void push(int x)
    {
        if(top == size-1)
            throw StackOverFlow();
        top++;
        s[top]= x;
    }
    int pop()
    {
        if(top == -1)
            throw StackUnderFlow();
        return s[top--];
    }
};

int Stack::top = -1;

int main()
{
    int x;
    try
    {
        //----MAKE IT MENU DRIVEN AND SELF RUNNING----//
        Stack st(4);
        //x=st.pop();
        st.push(5);
        st.push(15);
        st.push(12);
        st.push(20);
        st.push(2);

    }
    catch(StackOverFlow s)
    {
        cout<<"Stack is Over Flowed !\n";
    }
    catch(StackUnderFlow s)
    {
        cout<<"Stack is Under Flowed !\n";
    }
    
    return 0;

}