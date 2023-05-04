#include<iostream>
using namespace std;

class CircularQueue
{
    int rear,front,size;
    int* arr;
public:
    void initialize()
    {
        cout<<"Enter the size : ";
        cin>>size;
        arr=new int[size];
        front=rear=-1;
    }

    void display()
    {

        cout<<"-------------------------------------------"<<endl;
        if(front==-1)
            cout<<"Circular Queue is empty!!"<<endl;
        else if(rear>=front)
        {
            for(int i=front;i<=rear;i++)
                cout<<arr[i]<<" ";
                cout<<endl;

        }
        else{
             for (int i = front; i < size; i++)
                cout<<arr[i]<<" ";
             for (int i = 0; i <= rear; i++)
                cout<<arr[i]<<" ";
              cout<<endl;
        }
    }
    void enqueue(int x)
    {
        if((front==0 &&rear==size-1)|| rear==front-1)
            cout<<"Overflow!!"<<endl;
        else if(front==-1)
            {
                front=rear=0;
                arr[rear]=x;

            }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=x;
        }
        else
        {
            rear++;
            arr[rear]=x;
        }

        display();
    }

    void dequeue()
    {
        if(front==-1)
            cout<<"Circular Queue is empty!!!"<<endl;

        if(front==rear)
         {
             front=rear=-1;
         }
         else if(front==size-1)
         {
             front=0;
         }
         else
            front++;

         display();

    }
};
int main()
{
    CircularQueue cq;
    cq.initialize();
    cq.enqueue(10);
    cq.enqueue(50);
    cq.enqueue(40);
    cq.enqueue(80);
    cq.dequeue();
    cq.enqueue(200);
    cq.enqueue(70);
    cq.enqueue(150);
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();

    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
