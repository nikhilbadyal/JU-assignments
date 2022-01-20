#include<iostream>
#include<fstream>
using namespace std;
class Member_list;
class Book
{
	int book_id,price;
	char title[30],author[30],publisher[10];
	int count = 0;

	public:
		void get_book_id(int n)
		{
			book_id=n;
		}
		void get_book()
		{
			cout<<"\nEnter price : ";
			cin>>price;
			cout<<"\nEnter title : ";
			cin>>title;
			cout<<"\nEnter author name : ";
			cin>>author;
			cout<<"\nEnter publisher : ";
			cin>>publisher;
			count++;
		}

		void display_book()
		{
			cout<<"\n\n\nBOOK DETAILS\n\n";
			cout<<"BOOK ID : "<<book_id<<"\nPRICE : "<<price<<"\nAUTHOR : "<<author<<"\nTITLE : "<<title<<"\nPUBLISHER : "<<publisher<<"\n";
		}

		int return_book_id()
		{
			return(book_id);
	    }
};

class Book_list
{

	public:
		//static int total_books;

		void add_book(int book_id)
		{
		     Book temp;
//			book a;
			int i=0,n;
			fstream f;
			f.open("book_list.txt",fstream::app);
			if(!f)
			{
				cout<<"\nfile can't open ";
				return;
			}
			while(f.read((char *)&b,sizeof(book)))
			{
				if(book_id == b.bk.return_book_id())
				{
					cout<<"\n\nThis book is already present having book details : ";
					b.bk.display_book();
					cout<<"\nhow many copies do you want to add : ";
					cin>>n;
					b.sln=b.sln+n;
					f.seekp(i*sizeof(book),ios::beg);
					f.write((char *)&b,sizeof(book));
					f.close();
					return;
				}
				i++;
			}
			temp.bk.get_book_id(book_id);
			temp.bk.get_book();
			cout<<"\nHow many copies do you want to add : ";
			cin>>n;
			temp.sln=n;
			temp.bk.display_book();
			n=2;
			string s = "book_list.txt";
			f.write(temp,sizeof(Book));
			total_books++;
			f.close();
		//	printf("\nhello");
		}

		int verify_available(book bx)
		{
			if(bx.sln > 0)
			return(1);

			return(0);
		}
		int verify_book(int book_id)
		{
			int return_sln=0,i=0;
			book a;
			fstream f;

			f.open("book_list.txt",ios::in|ios::out|ios::binary);
			while(f.read((char *)&b,sizeof(book)))
			{
				if(b.bk.return_book_id() == book_id)
				{
					if(verify_available(b))
					{
						return_sln=b.sln;
						b.sln--;
						a=b;

						f.seekp(i*sizeof(book),ios::beg);
						f.write((char *)&a,sizeof(book));
						f.close();
						return(return_sln);
					}
					else
					{
						f.close();
						cout<<"\nThe book is not available (out of stock): ";
						return(0);
					}
				}
				i++;
			}

			cout<<"\nWrong book id : ";
			f.close();
			return(0);
		}

	    void update_serial_no(int book_id)
	    {
	    	int i=0;
	    	book a;
	    	fstream f;

	    	f.open("book_list.txt",ios::in|ios::out|ios::binary);
	    	while(f.read((char *)&b,sizeof(book)))
	    	{
	    		if(b.bk.return_book_id() == book_id)
	    		{
	    			b.sln++;
	    			a=b;
	    			f.seekp(i*sizeof(book),ios::beg);
	    			f.write((char *)&a,sizeof(book));
	    			f.close();
	    			return;
				}
				i++;
			}
		}

		void display_book_list()
		{
			int i=0;
			ifstream in;

			in.open("book_list.txt",ios::in|ios::binary);
			if(!in)
			{
				cout<<"\nfile cannot open";
				return;
			}
			while(in.read((char *) &b,sizeof(book)))
				{
					cout<<"\n"<<in.gcount()<<"bytes read :";
					b.bk.display_book();
		    		cout<<"\nNumber of copies : "<<b.sln;
		    		i++;
			    }

			in.close();
		}

};
int Book_list::total_books=0;

class Member
{
	protected:

	char name[30];
	char email[30];
	class address
	{
		int flat_no,pincode;
		char locality[30],city[30],state[30];
		public:
		  void get_address()
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

		  void show_address()
		  {
		  	cout<<"\nAddress details : \n";
		  	cout<<"Pincode : "<<pincode<<"\nState"<<state<<"\nCity"<<city<<"\nFlat no "<<flat_no<<"\nLocality : "<<locality<<"\n";
		  }
    }a;
	public:

	   void get_member()
	   {
	    cout<<"\nEnter name  : ";
	    cin>>name;
	    cout<<"\nEnter email  ";
	    cin>>email;
	    cout<<"\nEnter address : ";
	    a.get_address();
	   }

	   void display_member()
	   {
	   	cout<<"Name : "<<name<<"Email : "<<email;
	   	a.show_address();
       }
};

class Student:public Member
{
	int roll;
	char depart[30];
	public:
		void get_student()
		{
			cout<<"\nEnter roll : ";
			cin>>roll;
			cout<<"\nEnter department : ";
			cin>>depart;
			get_member();
		}

		void register_s(Member_list &ml);
		void display_student()
		{
			cout<<"\n\n\nStudent details : \n\n";
			cout<<"Roll no : "<<roll<<"\nDepartment : "<<depart<<"\n";
			display_member();
		}
};

class Faculty:public Member
{
	int salary;
	char qual[30];
	public:
		void get_faculty()
		{
			cout<<"\nEnter Salary : ";
			cin>>salary;
			cout<<"\nEnter qualification : ";
			cin>>qual;
			get_member();
		}

		void register_f(Member_list &ml);
		void display_faculty()
		{
			cout<<"\n\n\nFaculty details : \n\n";
			cout<<"Salary : "<<salary<<"\nQualification : "<<qual;
			display_member();
		}
};

class Member_list
{
	struct mem
	{
		int aadhar;
		int member_id;
    	char type;
    	int book_issued;
	}m;
	public:
		static int member_id_generator;
		int register_(int a,char tag)
		{
			//int done=0;
			ifstream in;

			cout<<"Searching if you are member or not : ";
			in.open("member_list.txt",ios::in);
			while(in.read((char *)&m,sizeof(mem)))
			{
				if(m.aadhar == a)
				{
					cout<<"\nYou are already a member u dumbass : ";
					in.close();
					return(0);
				}
		    }
		    if(in)
		    {
		    	in.seekg((-1)*sizeof(mem),ios::end);
		        in.read((char *)&m,sizeof(mem));
     		    member_id_generator=m.member_id;
			}

			in.close();

			member_id_generator++;
			cout<<"\nYou are not a member : ";
			m.aadhar=a;
			m.member_id=member_id_generator;
			m.book_issued=0;
			m.type=tag;

			ofstream out;
			out.open("member_list.txt",ios::out|ios::app);
			out.write((char *)&m,sizeof(mem));
			out.close();

			return(1);
		}

		void display_member_list()
		{
			ifstream in;
			in.open("member_list.txt",ios::in);

			while(in.read((char *)&m,sizeof(mem)))
			{
				cout<<"\nMember id : "<<m.member_id;
				if(m.type == 's')
				{
					cout<<"\nMember type : Student";
				}
				else if(m.type == 'f')
				{
					cout<<"\nMember type : Faculty";
				}
				cout<<"\nNumber of book issued : "<<m.book_issued;
			}
		}
		int max_book(char ch,int i)
		{
			fstream f;
			f.open("member_list",ios::in|ios::out|ios::binary);

			f.seekp(i*sizeof(mem),ios::beg);
			f.seekg(i*sizeof(mem),ios::beg);
			f.read((char *)&m,sizeof(mem));
			if(ch == 's')
			{
				if(m.book_issued < 2)
				{
					m.book_issued++;
					f.write((char *)&m,sizeof(mem));
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
				if(m.book_issued < 10)
				{
					m.book_issued++;
					f.write((char *)&m,sizeof(mem));
					return(1);
				}
				else
				{
					cout<<"\nMORE THAN 10 BOOKS HAVE BEEN ISSUED : ";
					return(0);
				}
			}
		}
		int verify_member(int n)
		{
			int i=0;
			ifstream in;
			in.open("member.txt",ios::in);

			while(in.read((char *)&m,sizeof(mem)))
			{
				if(n == m.member_id)
				{
					if(max_book(m.type,i))
					return(1);
				}
				else
				{
					return(0);
				}
				i++;
			}

		    in.close();
		    cout<<"\nWRONG MEMBER ID : ";
		    return(0);
		}
		void update_book_issued(int n)
		{

			fstream f;
			f.open("member_list.txt",ios::in|ios::out|ios::binary);
			while(f.read((char *)&m,sizeof(mem)))
			{
				if(n == m.member_id)
				{
					m.book_issued--;
					f.write((char *)&m,sizeof(mem));
					f.close();
					return;
				}
			}
			return;
		}
};
int Member_list::member_id_generator=1000;

void Student::register_s(Member_list &ml)
{
	int c;
	cout<<"\nEnter aadhar : ";
	cin>>c;
	if(ml.register_(c,'s'))
	get_student();
}
void Faculty::register_f(Member_list &ml)
{
	int d;
	cout<<"\nEnter aadhar : ";
	cin>>d;
	if(ml.register_(d,'f'))
	get_faculty();
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
	}t;
	public:
		void make_transaction_slip(int m,int b,int s)
		{
			t.member_id=m;
			t.book_id=b;
			t.sln=s;
			cout<<"\nEnter today's date : ";
			for(int i=0;i<3;i++)
			{
				cin>>t.dot_issue[i];
			}
			t.return_flag=0;

			ofstream out;
			out.open("transaction_list.txt",ios::out|ios::app);

		    out.write((char *)&t,sizeof(trans));
		    out.close();
		}

		int search_for_return(int m,int b,int s)
		{
			int i=0;
			fstream  f;
			f.open("transaction_list.txt",ios::in);

			while(f.read((char *)&t,sizeof(trans)))
			{
				if(t.member_id == m)
				{
					if(t.book_id == b)
					{
						if(t.sln == s)
						{
							t.return_flag=1;
							f.seekp(i*sizeof(trans),ios::beg);
							f.write((char *)&t,sizeof(trans));
							f.close();
							return(1);
						}
					}
				}
				i++;
			}
			return(0);
		}
		void display_transaction()
		{
			ifstream in;
			in.open("transaction_list.txt",ios::in);
			while(in.read((char *)&t,sizeof(trans)))
			{
				cout<<"\n\nMember id"<<t.member_id;
    			cout<<"\nBook id"<<t.book_id;
	    		cout<<"\nBook serial number"<<t.sln;
	    		for(int j=0;j<3;j++)
	    		{
	    			cout<<t.dot_issue[j];
	    			if(j<2){
	    			cout<<"/"; }
				}
				cout<<"\nReturned status: ";
				if(t.return_flag == 0)
				{
					cout<<"NOT RETURNED";
				}
				else
				{
					cout<<"RETURNED";
				}

				if(t.return_flag != 0)
				{
					cout<<"\nDate of issue : ";
					for(int j=0;j<3;j++)
					{
						cout<<t.dot_issue[j];
						if(j<2)
						cout<<"/";
					}
				}
			}
		}
};
class issue_book
{
	int member_id,book_id,sln;
	public:
		void issue_b(Member_list &ml,Book_list &b,Transaction_list &t)
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
			cout<<"\nVERIFYING BOOK ID AND AVAILABLILTY: ";
			sln=b.verify_book(book_id);
			if(!sln)
			{
				cout<<"\nSO, TRANSACTION CANT BE DONE : ";
				return;
			}
			t.make_transaction_slip(member_id,book_id,sln);
		}
};

class return_book
{
	int member_id,book_id,sln,return_dot[3];
	public:
		void return_b(Member_list &ml,Book_list &b,Transaction_list &t)
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
			cout<<"\nEnter today's date : ";
			for(int i=0;i<3;i++)
			{
				cin>>return_dot[i];
			}
			ml.update_book_issued(member_id);
			b.update_serial_no(book_id);
		}
};


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
					       break;

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

					case 5:issue_book	I;
					       I.issue_b(ml,b,t);
						   break;

					case 6:return_book R;
					       R.return_b(ml,b,t);
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
