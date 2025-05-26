#include<iostream>
#include<string>
#include<windows.h>
#include <sstream>
using namespace std;
class node{
	public:
		string data;
		node *next , *current;
		node (string value)
		{
			data =value;
			next=NULL;
		}
		node(node *value)
		{
			current = value;
			next=NULL;
		}
};
class list{
	public:
		node *head;
		list()
		{
			head= NULL;
		}
		void insertstr(string data)
		{
			node *newnode= new node(data);
			if(head==NULL)
			{
				head=newnode;
				return ;
			}
			node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
		void insertn(node *data)
		{
			node *newnode= new node(data);
			if(head==NULL)
			{
				head=newnode;
				return ;
			}
			node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
};
class enter{
	public:
		enter()
		{
			total=costly=i=0;
		}
		int total , costly ,i,w;
		list l[20] , master ;
		void display()
		{
			string a , notes ;
			int b;
			cout<<"Enter Product name ";
			cin>>a;
			l[i].insertstr(a);
			cout<<"Enter the date when you buy them (date - month - year): ";
			cin>>a;
			l[i].insertstr(a);
			cout<<"Enter the amount ";
			cin>>b;
			total=total +b;
			if(costly==0 || b>costly)
			{
				costly=b;
				w=i;
			}
			 stringstream ss;
   			 ss << b;
    		a = ss.str();
			l[i].insertstr(a);
			master.insertn(l[i].head);
			/*cout<<"Write the note why did you buy the product (optional, press Enter to skip):";
			 getline(cin, notes);
			 if(!(notes.empty()))
			 {
			 	l[i].insertstr(notes);
			 }
			 cout<<"Record is successfully enter !"<<endl;*/
			  i++;
		}
		void display1()
		{
			out:
			cout<<"1) Exit "<<endl;
			cout<<"2) Enter new record "<<endl;
			cout<<"3) Total amount spent on product "<<endl;
			cout<<"4) Most expensive product "<<endl;
			cout<<"5) Update any Expense "<<endl;
			cout<<"6) Delete the expense "<<endl;
			cout<<"7) Display all the data "<<endl;
			int n;
			cin>>n;
			if(n==1)
			{
				exit(0);
			}
			else if(n==2)
			{
				display();
			}
			else if(n==3)
			{
				cout<<"Total = "<<total;	
			}
			else if(n==4)
			{
				cout<<"Most expensive product "<<endl;
				node *temp=l[w].head;
				cout<<temp->data<<endl;
				cout<<"Amount spent on it is "<<costly<<endl;
			
			}
			else if(n==5)
			{
				int count=0 , check , o=1 ;
				node *temp1 = master.head;
				if(master.head==NULL)
				{
					cout<<"There is no product to update "<<endl;
					cout<<"Enter new record ";
				}
				else{
				while(temp1)
				{
					cout<<o<<" "<<temp1->current->data<<endl;
					temp1=temp1->next;
					o++;
				}
				cout<<"Enter the name of the product of which you want to update: ";
				string pro;
				cin>>pro;
				temp1 = master.head;
				while(temp1->current->data!=pro)
				{
					temp1=temp1->next;
					count++;
				}
				cout<<"What changes you want to do "<<endl;
				cout<<"1) Change product name "<<endl;
				cout<<"2) Change the amount "<<endl;
				cout<<"3) Change the date "<<endl;
				cin>>check;
				temp1=l[count].head;
				if(check==1)
				{
					cout<<"Enter the name of product: ";
					cin>>pro;
					temp1->data=pro;
				}
				else if(check==3)
				{
					cout<<"Enter the date:  ";
					cin>>pro;
					temp1=temp1->next;
					temp1->data=pro;
				}
				else if(check==2)
				{
					cout<<"Enter the Amount:  ";
					cin>>check;
					temp1=temp1->next;
					temp1=temp1->next;
					if(costly==0 || check>costly)
					{
					costly=check;
					w=count;
					}
					stringstream ss;
   			 		ss << check;
    				string a1 = ss.str();
					temp1->data=a1;
				}
				else 
				{
					cout<<"Wrong choice "<<endl;
					cout<<"Enter the correct choice "<<endl;
				}
							}}
			else if(n==6)
			{
				int o=1;
				node *temp1 = master.head;
				while(temp1)
				{
					cout<<o<<" "<<temp1->current->data<<endl;
					temp1=temp1->next;
					o++;
				}
				cout<<"Which product record you want to delete ";
				string en;
				cin>>en;
				temp1 = master.head;
				node *prev=NULL;
				int count =0;
				while(temp1->current->data!=en)
				{
					prev=temp1;
					temp1=temp1->next;
					count++;
				}
				l[count].head=NULL;
				deleteList(l[count].head);
				deleteNode(en);
			}
			else if(n==7)
			{
				displaylast();
			}
			else
			{
				cout<<"Wrong choice "<<endl;
				cout<<"Enter correct choice "<<endl;
			}
			Sleep(3000);
			system("CLS");
			goto out;
		}
		void displaylast()
		{
			int o1=1;
			node *temp;
			for(int j=0 ; j<i;j++)
			{
				temp=l[j].head;
				o1=1;
				while(temp!=NULL)
				{
					if(o1==1)
					{
						cout<<"Name: ";
					}
					else if(o1==2)
					{
						cout<<"Date: ";
					}
					else
					{
						cout<<"Amount: ";
					}
					cout<<temp->data<<endl;
					temp=temp->next;
					o1++;
				}
				cout<<endl;
			}
		}
		void deleteList(node* curr) {
    if (curr == NULL) {
        return;
    }
    deleteList(curr->next);
    delete curr;
}
void deleteNode(string key) {
    if (master.head != NULL && master.head->current->data==key) {
        node* temp = master.head;
        master.head = master.head->next; 
        delete temp;      
        cout << "Node with value " << key << " deleted from head." << endl;
        return;
    }
    node* current1 = master.head;
    node* prev = NULL;
    while (current1 != NULL && current1->current->data != key) {
        prev = current1;
        current1 = current1->next;
    }
    if (current1 == NULL) {
      cout << "Node with value " << key << " not found in the list." << endl;
        return;
    }
    if (prev != NULL) {
        prev->next = current1->next;
    }

    delete current1;
   cout << "Node with value " << key << " deleted." << endl;
}
	
};
int main()
{
	enter e;
	e.display1();
	return 0;
}
