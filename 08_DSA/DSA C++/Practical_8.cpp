#include <iostream>
#include<string>
using namespace std;

class list;
class node
{
	int prn;
	string name;
	node *next;
public:
	node(int pr,string tmp_name)
{
		prn=pr;
		next=NULL;
		name=tmp_name;
}

friend class list;
};
class list
{
	node *start;
public:
	list(){
		start=NULL;
	}
	bool reverseDisplay()
	{
        if(start==NULL)
            return false;
        node *temp=start;
        displayRev(temp);
            return true;
    }
void displayRev(node *t)
{
	if(t==NULL)
		return;
	else
	{
		displayRev(t->next);
		cout<<"PRN NO:"<<t->prn<<" Name: "<<t->name<<endl;
	}
}
void create()
{
	int no;
	string name;
	if(start==NULL)
	{
		cout<<"Enter PRN number: ";
		cin>>no;
		cout<<"Enter name: ";
		cin>>name;
		start=new node(no,name);
		cout<<"LIST CREATED SUCCESSFULLY"<<endl;

	}
	else
	{
		cout<<"List Exists. Cannot create new"<<endl;
	}
}
void display()
{
	node *t;
	t=start;
	if(start==NULL)
		cout<<"List Empty";
	else
	{ cout<<"LIST : "<<endl;
		while(t!=NULL){
			cout<<t->prn<<"  "<<t->name<<" \n";
					t=t->next;
		}
	}
}
void insertAtBeginning()
{
	int no;
	string nam;
 node *temp;
 if(start==NULL)
 {
	 create();
 }
 else
 {
	 cout<<"Enter PRN number: ";
	 cin>>no;
	 cout<<"Enter name: ";
	 cin>>nam;
	 temp=new node(no,nam);
	 temp->next=start;
	 start=temp;;
	 cout<<"Inserted  "<<temp->name<<" at root node.";
 }
}
void insertAtEnd()
{
	int no;
	string nam;
	node *t;
	if(start==NULL)
		create();
	else
	{
	 cout<<"Enter PRN number: ";
	 cin>>no;
	 cout<<"Enter name: ";
	 cin>>nam;
	 t=start;
	 while(t->next!=NULL)
	 	t=t->next;

	 	node*p=new node(no,nam);
	 	t->next=p;
	}
}
void insertAfter()
{
	int prev_no;
	cout<<"Enter PRN No:";
	cin>>prev_no;
	node *t;
	t=start;
	string nam;
	int flag=0,no;
	while(t!=NULL)
	{
		if(t->prn==prev_no)
		{
			flag=1;
			break;
		}
		t=t->next;
	}
	if(flag==1)
	{
		node *p;
		cout<<"Enter PRN number: ";
	    cin>>no;
	    cout<<"Enter name: ";
	    cin>>nam;
	    p=new node(no,nam);
	    p->next=t->next;
	    t->next=p;
	}
	else
	{
		cout<<prev_no<<" not in the list";
	}

}

void deleteAtFirst()
{
	node *t;
	if(start==NULL)
		cout<<"No members in club";
	else
	{
	t=start;
	start=start->next;
	t->next=NULL;
	delete t;
	cout<<"President removed/resigned from club";
}
}

void deleteByValue()
{
	int no,flag=0;
	node *t,*prev;
	if(start==NULL)
		cout<<"No members in club";
	else
	{
		cout<<"Enter PRN number of member to be removed: ";
		cin>>no;
		t=start->next;
		while(t->next!=NULL)
		{
			if(t->prn==no){
				flag=1;
				break;
			}
			prev=t;
			t=t->next;
		}
		if(flag==1)
		{
			prev->next=t->next;
			t->next=NULL;
			delete t;
			cout<<"Member with prn no: "<<no<<" is deleted"<<endl;
		}
		else
			cout<<"Member not in the list."<<endl;
	}
}
void deleteAtEnd()
{
	node *t,*prev;
	t=start;
		if(start==NULL)
		cout<<"No members in the club"<<endl;
	else
	{
	while(t->next!=NULL)
	{
		prev=t;
		t=t->next;
	}
	prev->next=NULL;
	delete t;
	cout<<"Secretary removed/resigned from the club"<<endl;
}
}
int computeTotal()
{
node *t;
int count=0;
t=start;
if(start==NULL)
{
	cout<<"No members in the club"<<endl;
	return 0;
}
while(t!=NULL)
{
count++;
t=t->next;
}

return count;
}

void sortList()
{
	node *i,*j,*last=NULL;
	int tprn;
	string tname;

if(start==NULL)
{
	cout<<"No members in the club"<<endl;
	return ;
}
for(i=start;i->next!=NULL;i=i->next)
{
	for(j=start;j->next!=last;j=j->next)
	{
		if((j->prn)>(j->next->prn))
		{
			tprn=j->prn;
			tname=j->name;
			j->prn=j->next->prn;
			j->name=j->next->name;

			j->next->prn=tprn;
			j->next->name=tname;

		}
	}
}
cout<<"List is sorted"<<endl;
display();
}
void concatList(list &q1)
{
	node *t,*p;
	t=q1.start;
	if(t==NULL)
	{
		cout<<"List 2 empty";
		return;
	}
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=t;
	q1.start=NULL; //second list is set to  null
	cout<<"After concatenation:"<<endl;
	display();
}

};
int main() {
	list *l;
	int choice,selectList;
	list l1,l2;
	l=&l1;
	start:
	    cout<<"Select List:"<<endl<<"1. List 1"<<endl<<"2. List 2"<<endl<<"Enter your choice: ";
	cin>>selectList;

	if(selectList==1)
	{
		l=&l1;
	}
	else if(selectList==2)
	{
		l=&l2;
	}
	else
	{
		cout<<"Please select correct option"<<endl;
		goto start;
	}
	do
	{
		cout<<"\n1. create\n2.Insert President\n3.Insert secretary\n4.insert after position(member)\n5.Display list"
		<<"\n6.Delete President\n7.Delete Secretary\n8.Delete Member\n9.Find total No. of members\n10.Sort list\n11. Previous Menu1"
		<<"\n12.Combine lists\n13.Reverse Display\n0. Exit"<<endl;
		cout<<"Please Enter your choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1: l->create();
				break;
			case 2:	l->insertAtBeginning();
				break;
			case 3: l->insertAtEnd();
				break;
			case 4: l->insertAfter();
				break;
			case 5: l->display();
				break;
			case 6: l->deleteAtFirst();
				break;
			case 7: l->deleteAtEnd();
				break;
			case 8: l->deleteByValue();
				break;
			case 9:	cout<<"\nTotal members: "<<l->computeTotal();
				break;
			case 10: l->sortList();
			break;
			case 11:
				goto start;
				break;
				case 12:
					l1.concatList(l2);
					break;
				case 13:
					l->reverseDisplay();
					break;
			deafult:
				 cout<<"Please select correct options"<<endl;
		}
	}while(choice!=0);
cout<<"PARTH PATEL\n19DCS098"<<endl;
	return 0;
}
