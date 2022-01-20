#include<iostream>
using namespace std;
class Member_list;
class Book
{
	int book_id,price;
	char title[30],author[30],publisher[10];

	public:
		void get_book_id(int n);
		void get_book();
		void display_book();
		int return_book_id();
};

void Book::get_book_id(int n)
{
	book_id=n;
}

void Book::get_book()
{
	cout<<"\nEnter price : ";
	cin>>price;
	cout<<"\nEnter title : ";
	cin>>title;
	cout<<"\nEnter author name : ";
	cin>>author;
	cout<<"\nEnter publisher : ";
	cin>>publisher;
}

void Book::display_book()
{
	cout<<"\n\n\nBOOK DETAILS\n\n";
	cout<<"BOOK ID : "<<book_id<<"\nPRICE : "<<price<<"\nAUTHOR : "<<author<<"\nTITLE : "<<title<<"\nPUBLISHER : "<<publisher<<"\n";
}

int Book::return_book_id()
{
	return(book_id);
}


class Book_list
{
	struct book
	{
		Book bk;
		int sln;
	}b[100];
	public:
		static int total_books;

		void add_book(int book_id);
		int verify_available(int i);
		int verify_book(int n);
		void update_availability(int n);
		void display_book_list();

};
int Book_list::total_books=0;

void Book_list::add_book(int book_id)
{
	int n;
	for(int i=0;i<total_books;i++)
	{
		if(book_id == b[i].bk.return_book_id())
		{
			cout<<"\nThis book is present having details given below : ";
			b[i].bk.display_book();
			cout<<"\nHow many copies do you want to add : ";
			cin>>n;
			b[i].sln=b[i].sln+n;
			cout<<"\nQuantity of this book is increased by "<<n;
			return;
		}
	}
	b[total_books].bk.get_book();
	b[total_books].bk.get_book_id(book_id);
	cout<<"\nHow many copies do you want to add : ";
	cin>>n;

	b[total_books].sln=n;

	total_books++;
}

int Book_list::verify_available(int i)
{
	if(b[i].sln > 0)
	return(1);

	return(0);
}

int Book_list::verify_book(int n)
{
	int check=0;
	for(int i=0;i<total_books;i++)
	{
		if(b[i].bk.return_book_id() == n)
		{
			if(verify_available(i))
			{
				b[i].sln--;
				return(i);
			}
			else
			{
				cout<<"\nThis book is not avaiable : ";
				return(0);
			}
		}
	}
	cout<<"\nWrong book id  : ";
    return(0);
}

void Book_list::update_availability(int n)
{
	for(int i=0;i<total_books;i++)
	{
	    if(b[i].bk.return_book_id() == n)
	    {
	    	b[i].sln++;
	    	return;
		}
	}
}

void Book_list::display_book_list()
{
	for(int i=0;i<total_books;i++)
	{
		b[i].bk.display_book();
		cout<<"\nNumber of copies : "<<b[i].sln;
	}
}


class Member
{
	protected:

	char name[30];
	char email[30];
	class Address
	{
		int flat_no,pincode;
		char locality[30],city[30],state[30];
		public:

		  void get_address();
		  void show_address();

    }a;
	public:

	   void get_member();
	   void display_member();
};

void Member::Address::get_address()
{
    cout<<"\nEnter pincode : ";
    cin>>pincode;
	cout<<"\nEnter state : ";
	cin>>state;
	cout<<"\nEnter city : ";
    cin>>city;
    cout<<"\nEnter flat no : ";
   	cin>>flat_no;
	cout<<"\nEnter locality : ";
	cin>>locality;
}

void Member::Address::show_address()
{
    cout<<"\nAddress details : \n";
	cout<<"Pincode : "<<pincode<<"\nState"<<state<<"\nCity"<<city<<"\nFlat no "<<flat_no<<"\nLocality : "<<locality<<"\n";
}

void Member::get_member()
{
	cout<<"\nEnter name  : ";
	cin>>name;
	cout<<"\nEnter email  ";
    cin>>email;
	cout<<"\nEnter address : ";
    a.get_address();
}

void Member::display_member()
{
	cout<<"Name : "<<name<<"Email : "<<email;
   	a.show_address();
}

class Student:public Member
{
	int roll;
	char depart[30];
	public:
		void get_student();
	    void register_s(Member_list &ml);
		void display_student();
};

void Student::get_student()
{
    cout<<"\nEnter roll : ";
	cin>>roll;
	cout<<"\nEnter department : ";
	cin>>depart;
	get_member();
}

void Student::display_student()
{
	cout<<"\n\n\nStudent details : \n\n";
	cout<<"Roll no : "<<roll<<"\nDepartment : "<<depart<<"\n";
	display_member();
}


class Faculty:public Member
{
	int salary;
	char qual[30];
	public:
		void get_faculty();

		void register_f(Member_list &ml);
		void display_faculty();
};

void Faculty::get_faculty()
{
	cout<<"\nEnter Salary : ";
	cin>>salary;
	cout<<"\nEnter qualification : ";
	cin>>qual;
	get_member();
}

void Faculty::display_faculty()
{
	cout<<"\n\n\nFaculty details : \n\n";
	cout<<"Salary : "<<salary<<"\nQualification : "<<qual;
	display_member();
}

class Member_list
{
	struct mem
	{
		int aadhar;
		int member_id;
    	char type;
    	int book_issued;
	}m[100];
	public:
		static int member_count;
		static int member_id_generator;

		int register_(int a,char tag);
		void display_member_list();
		int max_book(char ch,int i);
		int verify_member(int n);
		void update_book_returned(int n);
};
int Member_list::member_count=0;
int Member_list::member_id_generator=1000;

int Member_list::register_(int a,char tag)
{
	int done=0;
	cout<<"Searching if you are member or not : ";
	for(int i=0;i<member_count;i++)
	{
		if(a == m[i].aadhar)
		{
			cout<<"\nYou are already a member \n";
			return(0);
		}
	}
	cout<<"\nYou are not a member : ";
	m[member_count].aadhar=a;
	m[member_count].member_id=member_id_generator;
	m[member_count].book_issued=0;
	m[member_count].type=tag;
	cout<<"\nYour member id is : "<<m[member_count].member_id;

	member_id_generator++;
    member_count++;
	return(1);
}

void Member_list::display_member_list()
{
	for(int i=0;i<member_count;i++)
	{
		cout<<"\nMember id : "<<m[i].member_id;
		cout<<"\nType : ";
		if(m[i].type == 's')
		{
			cout<<"Student";
		}
		else if(m[i].type == 'f')
		{
			cout<<"Faculty";
		}
		cout<<"\nNumber of book issued : "<<m[i].book_issued;
		cout<<"\n\n";
	}
}

int Member_list::max_book(char ch,int i)
{
	if(ch == 's')
	{
		if(m[i].book_issued < 2)
		{
			m[i].book_issued++;
			return(1);
		}
		else
		{
			cout<<"\nMORE THAN 2 BOOKS HAVE BEEN ISSUED : ";
			return(0);
		}
	}
	else
	{
		if(m[i].book_issued < 10)
		{
			m[i].book_issued++;
			return(1);
		}
		else
		{
			cout<<"\nMORE THAN 2 BOOKS HAVE BEEN ISSUED : ";
			return(0);
		}
	}
}
int Member_list::verify_member(int n)
{
	for(int i=0;i<member_count;i++)
	{
		if(n == m[i].member_id)
		{
			if(max_book(m[i].type,i));
			return(1);
		}

		else
	    {
		    return(0);
	    }
    }
	cout<<"\nWRONG MEMBER ID : ";
    return(0);
}
void Member_list::update_book_returned(int n)
{
	for(int i=0;i<member_count;i++)
    {
		if(n == m[i].member_id)
		m[i].book_issued--;
	}
}

void Faculty::register_f(Member_list &ml)
{
	int a;
	cout<<"\nEnter aadhar : ";
	cin>>a;
	if(ml.register_(a,'f'))
	get_faculty();
}

void Student::register_s(Member_list &ml)
{
	int a;
	cout<<"\nEnter aadhar : ";
	cin>>a;
	if(ml.register_(a,'s'))
	get_student();
}

class Transaction_list
{
	struct trans
	{
		int dot_issue[3];
		int dot_return[3];
		int member_id;
		int book_id;
		int sln;
		int return_flag;
	}t[100];
	public:
		static int transaction_count;
		static int serial_no_generator;

		void make_transaction_slip(int m,int b);
		int search_for_return(int m,int b,int s);
		void display_transaction();
};
int Transaction_list::transaction_count=0;
int Transaction_list::serial_no_generator=1000;

void Transaction_list::make_transaction_slip(int m,int b)
{
	serial_no_generator++;
	t[transaction_count].member_id=m;
	t[transaction_count].book_id=b;
	t[transaction_count].sln=serial_no_generator;
	cout<<"\nEnter today's date : ";
	for(int i=0;i<3;i++)
	{
		cin>>t[transaction_count].dot_issue[i];
	}
	t[transaction_count].return_flag=0;
	transaction_count++;

	cout<<"\nBook issued : ";
	cout<<"\nYour book serial number is : "<<t[transaction_count].sln;
}

int Transaction_list::search_for_return(int m,int b,int s)
{
	for(int i=0;i<transaction_count;i++)
	{
		if(t[i].member_id == m)
		{
			if(t[i].book_id == b)
			{
				if(t[i].sln == s)
				{
					t[i].return_flag=1;
					return(1);
				}
			}
		}
	}
	return(0);
}
void Transaction_list::display_transaction()
{
	for(int i=0;i<transaction_count;i++)
	{
		cout<<"\n\nMember id"<<t[transaction_count].member_id;
    	cout<<"\nBook id"<<t[transaction_count].book_id;
	    cout<<"\nBook serial number"<<t[transaction_count].sln;
	    for(int j=0;j<3;j++)
	    {
	    	cout<<t[transaction_count].dot_issue[i];
	    	if(j<2);
	    	cout<<"/";
		}
		cout<<"\nReturned status: ";
		if(t[transaction_count].return_flag == 0)
		{
			cout<<"NOT RETURNED";
		}
		else
		{
			cout<<"RETURNED";
		}

		if(t[transaction_count].return_flag != 0)
		{
			cout<<"\nDate of return : ";
			for(int j=0;j<3;j++)
		    {
				cout<<t[transaction_count].dot_return[j];
				if(j<2)
				cout<<"/";
			}
		}
	}
}
class Issue_book
{
	int member_id,book_id,sln;
	public:
		void issue_request(Member_list &ml,Book_list &b,Transaction_list &t);
};

void Issue_book::issue_request(Member_list &ml,Book_list &b,Transaction_list &t)
{
	cout<<"\nEnter member id : ";
	cin>>member_id;
	cout<<"\nVERIFYING MEMBER ID : ";
	if(!ml.verify_member(member_id))
	{
	cout<<"\nSO, TRANSACTION CANT BE DONE : ";
	return;
	}
	cout<<"\nEnter book id : ";
	cin>>book_id;
	cout<<"\nVERIFYING BOOK ID AND AVAILABILITY : ";
	sln=b.verify_book(book_id);
	if(!sln)
	{
		cout<<"\nSO, TRANSACTION CANT BE DONE : ";
		return;
	}
	cout<<"\nBOOK IS AVAILABLE : ";
	t.make_transaction_slip(member_id,book_id);
}

class Return_book
{
	int member_id,book_id,sln;
	public:
		void return_request(Member_list &ml,Book_list &b,Transaction_list &t);
};

void Return_book::return_request(Member_list &ml,Book_list &b,Transaction_list &t)
{
	cout<<"\nEnter member id : ";
	cin>>member_id;
	cout<<"\nEnter book id : ";
	cin>>book_id;
	cout<<"\nEnter serial number : ";
	cin>>sln;
	if(!t.search_for_return(member_id,book_id,sln))
	{
		cout<<"\nYOUR ENTER DATA DOES NOT MATCHED WITH RECORDS :";
		return;
	}
	ml.update_book_returned(member_id);
	b.update_availability(book_id);
	cout<<"\nBOOK RETURNED ";
}


class Interface
{
	int ch;
	public:
		void library_functions()
		{
			Member_list ml;
			Book_list b;
			Transaction_list t;

			while(1)
			{
				cout<<"\n\n";
				cout<<"\n1.Add books";
				cout<<"\n2.Display book list : ";
				cout<<"\n3.Add member";
				cout<<"\n4.Display the member list ";
				cout<<"\n5.Make an issue request";
				cout<<"\n6.Return a book ";
				cout<<"\nYour choice : ";
				cin>>ch;
				switch(ch)
				{

					case 1:int book_id;
					       int n;
					       cout<<"\nEnter total number books that you want to add : ";
					       cin>>n;
					       for(int i=0;i<n;i++)
					       {
					       	cout<<"\nEnter book id of "<<i+1<<" book : ";
					        cin>>book_id;
					        b.add_book(book_id);
						   }

					case 2:b.display_book_list();
					       break;

					case 3:char choice;
					       Student st;
					       Faculty fa;
					       cout<<"Enter 's' for student or 'f' for faculty : ";
					       cin>>choice;
					       if(choice == 's')
					       {
					       	st.register_s(ml);
						   }
						   else if(choice == 'f')
						   {
						   	fa.register_f(ml);
						   }
						   break;

					case 4:ml.display_member_list();
					       break;

					case 5:Issue_book	I;
					       I.issue_request(ml,b,t);
						   break;

					case 6:Return_book R;
					       R.return_request(ml,b,t);
						   break;

					case 7:t.display_transaction();
					       break;

					default : cout<<"Wrong choice ";
					          break;
				}
			}
		}
};
int main()
{
    Interface I;
	I.library_functions();
}












