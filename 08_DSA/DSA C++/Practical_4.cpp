#include<iostream>
using namespace std;

class Stack
{
    char* arr;
    int size;
    int top;

public:
    void initialize()
    {
        top=-1;
        cout<<"Enter the size of string : ";
        cin>>size;
        arr= new char[size];
    }

    void push(char x)
    {
        if(top<size-1)
        {
            top++;
            arr[top]=x;
        }
        else
            cout<<"Stack Overflow!!!"<<endl;

    }

    char pop()
    {
        if(top==-1)
            {cout<<"UnderFlow!!"<<endl;
            return '0';}
        else
        {
            char x=arr[top];
            top--;
            return x;
        }
    }

    int returnSize()
    {
        return size;
    }


};
int main()
{
    Stack s;
    s.initialize();

     char c[s.returnSize()];
    cout<<"Enter the string : ";
    cin>>c;

    for(int i=0;i<s.returnSize();i++)
        s.push(c[i]);

    for(int i=0;i<s.returnSize();i++)
        c[i]=s.pop();

    cout<<"The reversed String is : "<<c<<endl;

    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
