#include<iostream>
using namespace std;

class Queue
{
    int size;
    int front,rear;
    int *arr;
public:
    void initialize()
    {
        cout<<"Enter the size of Queue : ";
        cin>>size;
        arr= new int[size];
        front=0;
        rear=-1;
    }

    bool isFull()
    {
        if(rear==size-1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if(front >rear)
            return true;
        else
            return false;
    }

    int peek()
    {
        return arr[front];
    }

    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Sorry !!! The phone line is full.\nTry again later"<<endl;
        }
        else if(isEmpty())
        {
             rear++;
            arr[rear]=x;
            cout<<"Welcome to CHARUSAT!!\nYour call has been placed in Queue.\n Your Token Number : "<<rear+1<<endl;
             cout<<"----------------------------------------------------------"<<endl;
        }
        else
        {
            rear++;
            arr[rear]=x;
            cout<<"Welcome to CHARUSAT!!\nYour call has been placed in Queue.\n Your Token Number : "<<rear+1<<endl;
            cout<<"Please Wait till our call representative pick your call!!"<<endl;
            cout<<"----------------------------------------------------------"<<endl;
            cout<<"Currently Token number : "<<front<<" is in call"<<endl;
            cout<<"----------------------------------------------------------"<<endl;

        }

    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"There are no customers in line."<<endl;
            cout<<"----------------------------------------------------------"<<endl;
        }

        else
        {
            cout<<"You have been disconnected from the call."<<endl;
            cout<<"Your Token Number was : "<<front+1<<endl;
            cout<<"Thank you !!"<<endl;
            cout<<"----------------------------------------------------------"<<endl;
            front++;
        }
    }



};
int main()
{
    Queue q;
    q.initialize();
for(int i=1;i<5;i++)
    q.enqueue(i);
for(int i=1;i<=3;i++)
    q.dequeue();

    cout<<endl;
    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
