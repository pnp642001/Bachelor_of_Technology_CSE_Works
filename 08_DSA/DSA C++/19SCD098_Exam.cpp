#include<iostream>
using namespace std;

void line()
{
    for(int i=0;i<50;i++)
        cout<<"-";
    cout<<endl;
}
class dequeue
{

private:
    int size,front,rear;
    int *arr;
public:
    void initialize()
    {
        cout<<"Enter the size of double ended Queue : ";
        cin>>size;
        arr=new int[size];
        front=rear=-1;
        line();
        cout<<"The double ended queue created"<<endl;
        line();
    }

    void enqueueFront(int x)
    {
        if((front==0 && rear==size-1) || front==rear+1)
        {
            cout<<"Overflow happened!!!"<<endl;
            line();
            return;
        }

        else if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            arr[front]=x;

        }
        else
        {
            front--;
            arr[front]=x;
        }

        cout<<"Element "<<arr[front]<<" inserted in front "<<endl;
        line();
    }

    void enqueueRear(int x)
    {
        if((front==0 && rear==size-1) || front==rear+1)
        {
            cout<<"Overflow happened!!!"<<endl;
            line();
            return;
        }
        else if(front==-1 && rear==-1)
        {
            front=0;
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

        cout<<"Element "<<arr[rear]<<" inserted at rear"<<endl;
        line();
    }

    void dequeueRear()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"Underflow Happened!!"<<endl;
            line();
            return;
        }
        else if(front==rear)
        {
            cout<<"Element "<<arr[rear]<<" deleted from rear"<<endl;
            front=-1;
            rear=-1;
        }
        else if(rear==0)
        {
             cout<<"Element "<<arr[rear]<<" deleted from rear"<<endl;
             rear=size-1;
        }
        else
        {
             cout<<"Element "<<arr[rear]<<" deleted from rear"<<endl;
             rear--;
        }
        line();
    }

    void display()
    {
        int temp=front;
        cout<<"Elements in the double ended queue : "<<endl;
        while(temp!=rear)
        {
            cout<<arr[temp]<<" ";
            temp=(temp+1)%size;
        }

        cout<<arr[rear]<<endl;
        line();
    }

};
int main()
{
    int c,tmp;
    dequeue dq;
    dq.initialize();
    do
    {
        cout<<"Select the appropriate option : "<<endl;
        cout<<"1. Insertion at Front"<<endl;
        cout<<"2. Insertion at Rear"<<endl;
        cout<<"3. Deletion from Rear"<<endl;
        cout<<"4. Display"<<endl;
        line();
        cout<<"Enter your choice : "<<endl;
        cin>>c;
        line();
        if(c==1)
        {
            cout<<"Enter the value : ";
            cin>>tmp;
            line();
            dq.enqueueFront(tmp);
        }
        else if(c==2)
        {
              cout<<"Enter the value : ";
            cin>>tmp;
            line();
            dq.enqueueRear(tmp);
        }
        else if(c==3)
        {
            line();
            dq.dequeueRear();

        }
        else if(c==4)
        {
            line();
            dq.display();
        }

    } while(c!=0);
    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;

}
