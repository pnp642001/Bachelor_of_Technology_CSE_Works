#include<iostream>
using namespace std;

class deque
{
    int size,front,rear;
    int* arr;
public:
    void initialize()
    {
        cout<<"Enter the size  : ";
        cin>>size;
        arr=new int[size];
        front=rear=-1;
    }
    void enqueue_front(int x)
    {
        if((front==0 && rear==size-1)|| (front==rear+1))
            cout<<"Overflow"<<endl;
        else if(front==-1&& rear==-1)
        {
            front=rear=0;
            arr[front]=x;
        }
        else if(front==0)
        {
            front=size-1;
            arr[front]=x;
        }
        else
        {
            front=front-1;
            arr[front]=x;
        }
    }

    void enqueue_rear(int x)
    {
        if((front==0 && rear==size-1)&&(front==rear+1))
            cout<<"Overflow!!"<<endl;
        else if(front==-1 && rear==-1)
        {
            rear=0;
            arr[rear]=x;
        }
        else if(rear==size-1)
        {
            rear=0;
            arr[rear]=x;
        }
        else
        {
            rear++;
            arr[rear]=x;
        }
    }

    void dequeue_front()
    {
        if(front==1 && rear==-1)
            cout<<"Underflow!!"<<endl;
        else if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
    }

    void dequeue_rear()
    {
        if(front==-1 && rear==-1)
            cout<<"Underflow!!"<<endl;
        else if(front==rear)
            front=rear=-1;
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear=rear-1;
        }
    }

    void display()
    {
        int i=front;
        cout<<"Elements : ";
        while(i!=rear)
           {
               cout<<arr[i]<<" ";
               i=(i+1)%size;
           }
           cout<<endl;
    }
    void getFront()
    {
        if(front==-1 && rear==-1)
            cout<<"Queue is Empty!!"<<endl;
        else
            cout<<"Front : "<<arr[front]<<endl;
    }

    void getRear()
    {
        if(front==-1 && rear==-1)
            cout<<"Queue is Empty!!"<<endl;
        else
            cout<<"Rear : "<<arr[rear]<<endl;
    }
};
int main()
{
    deque d;
    d.initialize();
    d.enqueue_front(10);
    d.enqueue_rear(50);
    cout<<"--------------------------------------"<<endl;
    d.getRear();
    cout<<"---------------------------------------"<<endl;
    d.enqueue_front(2);
    d.enqueue_front(20);
    d.enqueue_rear(80);
    cout<<"---------------------------------------"<<endl;
    d.display();
    cout<<"---------------------------------------"<<endl;
    d.getFront();
    d.getRear();
    d.dequeue_front();
    d.dequeue_rear();
    d.dequeue_front();
    cout<<"---------------------------------------"<<endl;
    d.display();
    cout<<"---------------------------------------"<<endl;

    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
