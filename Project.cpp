//Library Management Project by Tehmoor Amjad, Zeeshan Tanveer, Muhammad Ayaz
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
using namespace std;


void getTime();  //Time Function
void getDate();  //Date Function

void startUpMenu(); //Menu on program startUp
void AddingDetails();


//Books Store Start
//node
class node
{
	private:
	 string bName;
	 string aName;
	 int ed;
	 double ISBN;
	 string status;
	 node *left;
	 node *right;
	public:
		node()
		{
			bName="";
			aName="";
			ed=0;
			ISBN=0;
			status="available";
			left=NULL;
			right=NULL;
		}
		//Setter Functions 
		void setData(string book,string author,int edition,double isbnNum)
		{
			bName=book;
			aName=author;
			ed=edition;
			ISBN=isbnNum;
		}
		//I didn't set the status here because i am adding the book so it is available now through constructor by default.
		//I create the status setter separately to set it to issue or available later.
		void setStatus(string s)
		{
			status=s;
		}
		void setLeft(node *l)
		{
			left=l;
		}
		void setRight(node *r)
		{
			right=r;
		}
		 //Getter Functions
		 string getBook()
		 {
		 	return bName;
		 }
		 string getAuthor()
		 {
		 	return aName;
		 }
		 int getEdition()
		 {
		 	return ed;
		 }
		 double getIsbn()
		 {
		 	return ISBN;
		 }
		 string getStatus()
		 {
		 	return status;
		 }
		 node *getLeft()
		 {
		 	return left;
		 }
		 node *getRight()
		 {
		 	return right;
		 }
};

class Books
{
	private:
		node *root;
	public:
		Books()
		{
			root=NULL;
		}
		node *getRootAddress()
		{
			return root;
		}
		//Add book function
		void AddBook(string book,string author,int edition,double Isbn);
		
		//Inorder Display Function
		void inOrder(node *temp);
		
		//Search Function
        string Search(double x);
        
        //Search node Function
        node * SearchNode(double x);
        
};


//Start of nodeIssue Class
class nodeIssue
{
private:
    
	double ISBN;//Isbn Number	
	string rNum; ///Student's Roll Number
	//for dueDate
	int day;
	int month;
	int year;
	//Previous and Next Addresses
	nodeIssue *pre;
	nodeIssue *next;


public:

	nodeIssue()
	{
		ISBN=0;
		rNum = "";
		day=0;
		month=0;
		year=0;
		pre = NULL;
		next = NULL;
	}
	void setData(string rollNum,double isbn)
	{
		ISBN=isbn;
		rNum = rollNum;
	}
	
	void setPre(nodeIssue *p)
	{
		pre = p;
	}
	void setNext(nodeIssue *n)
	{
		next = n;
	}
	void setDate(int dd,int mm,int yy)
		{
			day=dd;
			month=mm;
			year=yy;
		}
		int getDay()
		{
			return day;
		}
		int getMonth()
		{
			return month;
		}
		int getYear()
		{
			return year;
		}
	string getRnum()
	{
		return rNum;
	}
	double getIsbnIssue()
	{
		return ISBN;
	}
	nodeIssue *getPre()
	{
		return pre;
	}
	nodeIssue *getNext()
	{
		return next;
	}
	

};

//End of nodeIssue Class



//Start of Issue Book Class
class IssueBook
{
private:

	nodeIssue *head;
	nodeIssue *tail;

public:

	IssueBook()
	{
		head = NULL;
		tail = NULL;
	}
	void createNode(string roll,double isb);
	double deleteIssueBook(string roll);
	int length();
	void display();
	bool checkRoll(string ro);
	void DueDate(nodeIssue *a);

};
//End of Issue Book Class

//End of Issue a book to a student

void AddingDetails()
{
	system("CLS");
	cout << "\t\t\t\t\t\t\t\t____________________________" << endl;
	cout << "\t\t\t\t\t\t\t\t\xB2                          \xB2\n";
	cout << "\t\t\t\t\t\t\t\t\xB2      Adding Details      \xB2" << endl;
	cout << "\t\t\t\t\t\t\t\t\xB2__________________________\xB2" << endl;
	cout << "\n\n";
}





int main()
{
	startUpMenu();
	Books b;	
	IssueBook obj;
	int ch;
	do {
		
		cout << "\n\n\t\t\t____________________________________________________________________________________________________________________________\n";
		cout << "\t\t\t\t\t\t\t\t       ____________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t       \xB2                          \xB2\n";
		cout << "\t\t\t\t\t\t\t\t       \xB2       ~ Main Menu ~      \xB2" << endl;
		cout << "\t\t\t\t\t\t\t\t       \xB2__________________________\xB2" << endl;
		cout << "\n";
		cout << "\t\t\t__________________________________________________\t\t\t___________________________________________________" << endl;
		cout << "\t\t\t\xB2                                                \xB2\t\t\t\xB2                                                 \xB2" << endl;
		cout << "\t\t\t\xB2         Press 1 -> to Issue a Book             \xB2\t\t\t\xB2        Press 2 -> to Remove Issued Book         \xB2" << endl;
		cout << "\t\t\t\xB2________________________________________________\xB2\t\t\t\xB2_________________________________________________\xB2" << endl;
		cout << "\n";
		cout << "\t\t\t__________________________________________________\t\t\t___________________________________________________" << endl;
		cout << "\t\t\t\xB2                                                \xB2\t\t\t\xB2                                                 \xB2" << endl;
		cout << "\t\t\t\xB2     Press 3 -> to Check Total Issued Books     \xB2\t\t\t\xB2      Press 4 -> to Display all Issued Books     \xB2" << endl;
		cout << "\t\t\t\xB2________________________________________________\xB2\t\t\t\xB2_________________________________________________\xB2" << endl;
		cout << "\n";
		cout << "\t\t\t__________________________________________________\t\t\t___________________________________________________" << endl;
		cout << "\t\t\t\xB2                                                \xB2\t\t\t\xB2                                                 \xB2" << endl;
		cout << "\t\t\t\xB2  Press 5 -> to Check Book is Available or not  \xB2\t\t\t\xB2        Press 6 -> to Add Book in Library        \xB2" << endl;
		cout << "\t\t\t\xB2________________________________________________\xB2\t\t\t\xB2_________________________________________________\xB2" << endl;
		cout << "\n";
		cout << "\t\t\t__________________________________________________\t\t\t___________________________________________________" << endl;
		cout << "\t\t\t\xB2                                                \xB2\t\t\t\xB2                                                 \xB2" << endl;
		cout << "\t\t\t\xB2  Press 7 -> to Display all Available Books     \xB2\t\t\t\xB2                Press 0 -> to Exit               \xB2" << endl;
		cout << "\t\t\t\xB2________________________________________________\xB2\t\t\t\xB2_________________________________________________\xB2" << endl;
		cout << "\n\n\t\t\t____________________________________________________________________________________________________________________________\n";
		cout << "\n\n\t\t\tEnter Your Choice = ";    cin >> ch;

		switch (ch)
		{
		case 1:
		{
			string r;
			double is ;
			system("CLS");
			cout << "\n\n\n";
			cout << "\t\tEnter ISBN Number = "; cin>>is;
			string p=b.Search(is);
			if(p=="available")//
			{
				AddingDetails();
				cout << "\t\tISBN Number = " <<setfill(' ')<<setw(13)<<fixed<<setprecision(0)<<is << "\n\n";
				cout << "\n\t\t___________________________________________________________________________________________________________________________\n\n";
				cin.ignore();
				cout << "\t\tEnter Roll Number = "; getline(cin,r);
				if (obj.checkRoll(r) == 1)//no book is issued to roll number then
			  {
			  	node *var=b.SearchNode(is);
			  	var->setStatus("issued");
				
				AddingDetails();
				cout << "\t\tRoll Number = " <<setfill(' ')<<setw(20)<< r<<setfill(' ')<<setw(10)<<" "<< "ISBN Number = "<<setfill(' ')<<setw(13)<<fixed<<setprecision(0) << is << "\n\n";
				cout << "\n\t\t___________________________________________________________________________________________________________________________\n\n";
				cout << "\n\t\t\tBook has Issued Successfully" << endl;
				obj.createNode(r,is);
				break;

			  }
			else if (obj.checkRoll(r) == 0)
			 {
				cout << "\n\t\t\tOne Book is Already issued,Kindly First Return that Book.Then You can take another book" << endl;
				break;
		 	 }
			}
			else if(p=="issued")
			{
				cout<<"\n\t\t\tBook is already issued to someone..."<<endl;
				break;
			}
			else
			{
				cout<<"\n\t\t\t\t\t"<<p<<endl;
				break;
			}
			

		}
		case 2:
		{
			string r;
			cin.ignore();
			cout << "\n\t\t\tEnter Student's Roll Number = "; getline(cin,r);
			double z=obj.deleteIssueBook(r);
			if(z==0)
			{
				cout << "\n\t\t\tThere is no book issued against this Roll Number..!" << endl;
			}
			else
			{
				node *point=b.SearchNode(z);
				point->setStatus("available");
			}
			break;
		}
		case 3:
		{
			cout << "\n\t\t\tTotal number of issued books = " << obj.length() << endl;
			break;
		}
		case 4:
		{
			obj.display();
			break;
		}
		case 5:
		{
			double iNum;
			cout<<"\n\t\t\tEnter ISBN number to Check whether book is available or not = "; cin>>iNum; cout<<endl;
			string result=b.Search(iNum);
			if(result=="available")
			{
				cout<<"\n\t\t\tBook is Available"<<endl;
			}
			else if(result=="issued")
			{
				cout<<"\n\t\t\tBook is issued to someoned,Not available right now"<<endl;
			}
			else
			{
				cout<<result<<endl;
			}
			break;
			
		}
		case 6:
		{
			    string book,author;
				double isbn;
				int edition;
				cin.ignore();
				cout<<"\n\t\t\tEnter book    = "; getline(cin,book);
				//cin.ignore();
				cout<<"\t\t\tEnter author  = "; getline(cin,author);
				cout<<"\t\t\tEnter edition = "; cin>>edition;
				cout<<"\t\t\tEnter ISBN    = "; cin>>isbn;
				if(isbn>=1000000000000 && isbn<=9999999999999)
				{
					b.AddBook(book,author,edition,isbn);
					cout<<"\n\t\t\t"<<book<<" has added into the library"<<endl;
				}
				else
				{
					cout<<"Invalid input"<<endl;
				}
				break;
		}
		case 7:
		{
			node *t=b.getRootAddress();
			if(t==NULL)
			{
				cout<<"\n\t\t\tNo Books Available"<<endl;
			}
			else if(t!=NULL)
			{
				system("CLS");
			    b.inOrder(t);	
			}
			break;
		}
		case 0:
		{
			cout << "\n\t\t\t\t\t\t\t\t     Press Any Key to Exit" << endl;
			exit(0);
		}
		default:
		{
			cout << "\n\t\t\tInvalid Input" << endl;
			break;
		}

		}
		cout << "\n\t\t\t\t\t\t\t    Press any key to continue..." << endl;
		getch();
		system("CLS");
	} while (ch != 0);
















	return 0;
}





void getTime()
{
	SYSTEMTIME stime;
	GetLocalTime(&stime);
	cout<<setfill('0')<<setw(2)<<fixed<< stime.wHour << ":"<<setfill('0')<<setw(2)<<fixed << stime.wMinute<<":"<<setfill('0')<<setw(2)<<fixed << stime.wSecond;

}

void getDate()
{
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	cout<<setfill('0')<<setw(2)<<fixed<< stime.wDay << "/"<<setfill('0')<<setw(2)<<fixed<< stime.wMonth << "/"<<setfill('0')<<setw(4)<<fixed<<stime.wYear;
}

//Start of Startup Menu
void startUpMenu()
{
	cout << "\n\n\n";
	cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2\t"; getDate(); cout<<setfill(' ')<<setw(70) << "\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2\t"; getTime(); cout<<setfill(' ')<<setw(72) << "\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
    cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(46)<<"Welcome to"<<setfill(' ')<<setw(40)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(50)<<"Library  Management"<<setfill(' ')<<setw(36)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(44)<<"System"<<setfill(' ')<<setw(42)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2\tDeveloped By :"<<setfill(' ')<<setw(66)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(68)<<"Zeeshan Tanveer, Muhammad Ayaz & Tehmoor Amjad"<<setfill(' ')<<setw(18)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
    cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2"<<setfill(' ')<<setw(86)<<"\xB2\xB2" << endl;
	cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
	cout << "\n\n\n\t\tPress Any Key to Enter... "; getch();
	cout << endl;
	system("CLS");

}
//End of Startup Menu


//Issue Book Function
void IssueBook::DueDate(nodeIssue *a)
{
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int d,m,y,nd,nm,ny,ndays;
	d=stime.wDay;
	m=stime.wMonth;
	y=stime.wYear;
	ndays=month[m-1];
	if(m==2)
	{
		if(y%100==0)
		{
			if(y%400==0)
			{
				ndays=28;
			}
		}
		else if(y%4==0)
		{
			ndays=29;
		}
		
	}
	nd=d+1;
	nm=m;
	ny=y;
	if(nd>ndays)
	{
		nd=1;
		nm++;
	}
	if(nm >12)
	{
		nm=1;
		ny++;
	}
	a->setDate(nd,nm,ny);
    
}
void IssueBook::createNode(string roll,double isb) //This is same for insertion of node at end 
{
	nodeIssue *temp = new nodeIssue;
	temp->setData(roll,isb);
	DueDate(temp);
	temp->setPre(NULL);
	temp->setNext(NULL);
	//Now,node is ready

	if (head == NULL && tail == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else if (head != NULL)
	{
		tail->setNext(temp);
		temp->setPre(tail);
		tail = temp;
		temp = NULL;
	}
}

//Remove issued book from student's record
double IssueBook::deleteIssueBook(string roll)
{

	if (head == NULL && tail == NULL)
	{
		return 0;
		
	}
	else if (head == tail && head != NULL && roll == head->getRnum())
	{
		nodeIssue *temp = head;
		head = NULL;
		tail = NULL;
		cout << "\n\t\t\tRemoving Issued Book against " << temp->getRnum() << " Roll Number" << endl;
		double x=temp->getIsbnIssue();
		delete temp;
		return x;
	}
	else if (head != tail && head != NULL && roll == head->getRnum())
	{
		nodeIssue *temp = head;
		head = head->getNext();
		head->setPre(NULL);
		temp->setNext(NULL);
	    double x=temp->getIsbnIssue();
		cout << "\n\t\t\tRemoving Issued Book against " << temp->getRnum() << " Roll Number" << endl;
		delete temp;
		return x;
	}
	else if (head != tail && roll == tail->getRnum())
	{
		nodeIssue *temp = tail;
		tail->getPre()->setNext(NULL);
		tail = tail->getPre();
		temp->setPre(NULL);
		double x=temp->getIsbnIssue();
		cout << "\n\t\t\tRemoving Issued Book against " << temp->getRnum() << " Roll Number" << endl;
		delete temp;
		return x;
	}
	else
	{
		nodeIssue *cur = head;
		while (roll != cur->getRnum())
		{
			cur = cur->getNext();
		}

		cur->getPre()->setNext(cur->getNext());//next address of Previous node is set 
		cur->getNext()->setPre(cur->getPre());//previous address of next node is set
		cur->setPre(NULL);
		cur->setNext(NULL);
		double x=cur->getIsbnIssue();
		delete cur;
		return x;
	}

}


//How many books have issued?
int IssueBook::length()
{
	nodeIssue *temp = head; //node type pointer is created which is pointing to the first node if it exists
	int count = 0;
	if (head == NULL && tail == NULL)
	{
		return count;
	}
	else
	{
		while (temp != NULL)
		{
			count++;
			temp = temp->getNext();
		}
		return count;
	}
}

//Display Issued Books 
void IssueBook::display()
{
	if (head == NULL && tail == NULL)
	{
		cout << "\n\t\t\tNo books issued" << endl;
	}
	else if (head != NULL)
	{
		system("CLS");
		nodeIssue *temp = head;
		cout << "\n\n\n";
		cout << "\t\t\t\t\t\t______________________\t______________________\t______________________" << endl;
		cout << "\t\t\t\t\t\t\xB2                    \xB2\t\xB2                    \xB2\t\xB2                    \xB2\n";
		cout << "\t\t\t\t\t\t\xB2     Roll Number    \xB2\t\xB2     ISBN Number    \xB2\t\xB2      Due Date      \xB2" << endl;
		cout << "\t\t\t\t\t\t\xB2____________________\xB2\t\xB2____________________\xB2\t\xB2____________________\xB2" << endl;
		cout << "\n\n";

		while (temp != NULL)
		{
			cout << "\t\t\t\t\t\t"<<setfill(' ')<<setw(20)<< temp->getRnum()<<setfill(' ')<<setw(4)<<setfill(' ')<< setw(22) << temp->getIsbnIssue() <<setfill(' ')<<setw(4)<<setfill(' ')<<setw(18)<<temp->getDay()<<"/"<<setfill(' ')<<setw(2)<<temp->getMonth()<<"/"<<setfill(' ')<<setw(4)<<temp->getYear()<<"\n\n";
			temp = temp->getNext();
		}

	}
}

//Function to Check whether the student has already issued any book or not
bool IssueBook::checkRoll(string ro)
{

	if (head == NULL)
	{
		return 1;
	}
	else if (head != NULL)
	{
		nodeIssue *temp = head;
		while (temp->getRnum() != ro && temp != tail)
		{
			temp = temp->getNext();
		}

		if (ro != temp->getRnum())
		{
			return 1;
		}
		else if (ro == temp->getRnum())
		{
			return 0;
		}
	}
}
//Books Class Functions Definitions Start
void Books::AddBook(string book,string author,int edition,double Isbn)
		{
			node *temp=new node;
            temp->setData(book,author,edition,Isbn);
            temp->setLeft(NULL);
            temp->setRight(NULL);
			//Node is ready
			node *parent;
			if(root==NULL)
			{
				root=temp;
				temp=NULL;
			}
			else if(root!=NULL)
		{
			node *cur;
			cur = root;
			while (cur != NULL)
			{
				parent = cur;
				if (temp->getIsbn() < cur->getIsbn())
				{
					cur = cur->getLeft();
				}
				else if (temp->getIsbn() > cur->getIsbn())
				{
					cur = cur->getRight();
				}
			}

			if (temp->getIsbn() < parent->getIsbn()) 
			{
				parent->setLeft(temp);
				temp = NULL;
			}
			else if (temp->getIsbn() > parent->getIsbn())
			{
				parent->setRight(temp);
				temp = NULL;
			}
			}
		}
void Books::inOrder(node *temp)
		{
			if(temp->getLeft())
			{
				inOrder(temp->getLeft());
			}
			cout<<"\n\t\t\tBook Details :\n\n";
			cout<<setfill(' ')<<setw(30)<<fixed<<"\t\t\tBook name   = "<<temp->getBook()<<setfill(' ')<<setw(3)<<setfill(' ')<<setw(30)<<fixed<<"Author name  = "<<temp->getAuthor()<<setfill(' ')<<setw(3)<<setfill(' ')<<setw(20)<<fixed<<"\t\t\tEdition = "<<temp->getEdition()<<"\n\n";
			cout<<"\t\t"<<setfill(' ')<<setw(30)<<fixed<<setprecision(0)<<"ISBN Number = "<<temp->getIsbn()<<setfill(' ')<<setw(3)<<setfill(' ')<<setw(20)<<setfill(' ')<<fixed<<"Book Status  = "<<temp->getStatus()<<"\n"; 
			
			if(temp->getRight())
			{
				inOrder(temp->getRight());
			}
		}
		
string Books::Search(double x)
	{
		
		node *temp;
		temp = root;

		while (temp != NULL)
		{
			if (temp->getIsbn() == x)
			{
				return temp->getStatus();
			}

			else if (temp->getIsbn() > x)
				temp = temp->getLeft();

			else
				temp = temp->getRight();
		}

		 string b="\t\t\tBook is not Available...!";
		return b;
	}
	//to get address
node * Books::SearchNode(double x)
	{
		node *temp;
		temp = root;

		while (temp != NULL)
		{
			if (temp->getIsbn() == x)
			{
				return temp;
			}

			else if (temp->getIsbn() > x)
				temp = temp->getLeft();

			else
				temp = temp->getRight();
		}

		cout<<"\n\t\t\t Book not Found...!";
	
	}
//Books Class Functions Definitions End
