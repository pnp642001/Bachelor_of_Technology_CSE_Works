#include<iostream>
using namespace std;

class DoubleStack
{
    int* arr;
    int size;
    int topA,topB;
public:
    void initialize()
    {
        cout<<"Enter the size of Stack : ";
        cin>>size;
        arr=new int[size];
        topA=-1;
        topB=size;
    }

    void pushA(int x)
    {
        if(topA<topB-1)
        {
            topA++;
            arr[topA]=x;
            cout<<"Element "<<x<<" added to stack!!"<<endl;
        }
        else
        {
            cout<<"Stack Overflow !!!\n Please try to delete some elements!!"<<endl;
        }
    }

    void pushB(int x)
    {
        if(topA<topB-1)
        {
            topB--;
            arr[topB]=x;
            cout<<"Element "<<x<<" added to stack!!"<<endl;
        }
        else
        {
            cout<<"Stack Overflow !!!\n Please try to delete some elements!!"<<endl;
        }
    }

    int popA()
    {
        if(topA>=0)
        {
          int tmp=arr[topA];
          topA--;
          return tmp;
        }
        else
        {
            return -1;
        }
    }

    int popB()
    {
        if(topB<size)
        {
            int tmp=arr[topB];
            topB++;
            return tmp;
        }
        else
        {
            return -1;
        }
    }
    int returnSize()
    {
        return size;
    }
};
int main()
{
  DoubleStack s;

  s.initialize();
  s.pushA(1);
  s.pushA(2);
  s.pushA(3);
  s.pushA(4);
  s.pushA(5);
  s.pushB(10);
  s.pushB(9);
  s.pushB(8);
  s.pushB(7);
  s.pushB(6);

  int x=s.popA();
  if(x!=-1)
    cout<<"Element "<<x<<" has been deleted from stack"<<endl;
  else
    cout<<"Stack Underflow!!!\n Seems stack is empty"<<endl;

  x=s.popB();
  if(x!=-1)
    cout<<"Element "<<x<<" has been deleted from stack"<<endl;
  else
    cout<<"Stack Underflow!!!\n Seems stack is empty"<<endl;

    cout<<"PARTH PATEL\n19DCS098"<<endl;

    return 0;
}
