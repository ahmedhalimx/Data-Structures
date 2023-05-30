#include<iostream>
using namespace std;

class Node
{
public:
	//data of each node 
	string bookname ;
	string publishername ;
	string authorname ;
	int book_ID ;
	int price ;

	//pointers of each node 
	Node* next ;
	Node* prev ;
};

// any thing made with doublelinkedlist
class doublelinkedlist
{
public:
	Node* first;
	Node* last;
	int counter;
	doublelinkedlist()
	{
		first = NULL;
		last = NULL;
		counter = 0;
	}

	void menu()
	{
		system("CLS");
		cout << "\n\n\t\t\t============================================================";
		cout << "\n\n\t\t\t=================Welcome To Our System =====================";
		cout << "\n\n\t\t\t============================================================\n";

		for (int i = 0; i <= 4; i++)
		{
			system("COLOR 03");
			system("COLOR 04");
			system("COLOR 05");
			system("COLOR 06");
		}
		system("pause");
		system("cls");
		cout << "\n 1.Inserting Books Information At Last\n";
		cout << "\n 2.Inserting Books Information At First\n";
		cout << "\n 3.Inserting Books Information At Certain Position\n";
		cout << "\n 4.Displaying Books Information\n";
		cout << "\n 5.Searching on A Book\n";
		cout << "\n 6.Updating A Book \n";
		cout << "\n 7.Delete First Books \n";
		cout << "\n 8.Delete Last Book\n";
		cout << "\n 9.Delete A Book At A Certain Position\n";
		cout << "\n 10.sell A Book To Customers\n";
		cout << "\n 11.to know the number of book that i have\n";
		cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
		system("COLOR 03");

	}

	void insertfirst()
	{
		system("CLS");
		cout << "\n\n~~Adding A New BooK Information From First";
		Node* newnode = new Node();
		cout << "\n 1.Book Name:";
		cin >> newnode->bookname;       //equal to newnode->item=item
		cout << "\n 2.Book ID:";
		cin >> newnode->book_ID;
		cout << "\n 3.Author Name:";
		cin >> newnode->authorname;
		cout << "\n 4.Publisher Name:";
		cin >> newnode->publishername;
		cout << "\n 5.price";
		cin >> newnode->price;
		if (counter == 0)
		{
			first = last = newnode;
			newnode->next = newnode->prev = NULL;
		}
		else
		{
			newnode->next = first;
			newnode->prev = NULL;
			first->prev = newnode;
			first = newnode;
		}
		cout << "\n\t\t New Book Inserted successfully ......\n";
		counter++;
	}

	void insertlast()
	{
		system("CLS");
		cout << "\n\n~~~ADDING BOOK INFORMATION";
		Node* newnode = new Node();
		cout << "\n 1.Book Name:";
		cin >> newnode->bookname;
		cout << "\n 2.Book ID:";
		cin >> newnode->book_ID;
		cout << "\n 3.Author Name:";
		cin >> newnode->authorname;
		cout << "\n 4.Publisher Name:";
		cin >> newnode->publishername;
		cout << "\n 5.price:";
		cin >> newnode->price;
		if (counter == 0)
		{
			first = last = newnode;
			newnode->next = newnode->prev = NULL;
		}
		else
		{
			newnode->next = NULL;
			newnode->prev = last;
			last->next = newnode;
			last = newnode;
		}
		cout << "\n\t\t New Book Inserted successfully ......\n";
		counter++;
	}

	void insertat()
	{
		system("CLS");
		int pos;
		cout << "Enter The Number(Position)Of The Book You Want To Add \n";
		cin >> pos;
		if (pos<0 || pos>counter)
		{
			cout << "desired position out of range \n";
		}
		else if (pos == 0)
		{
			insertfirst();
		}
		else if (pos == counter)
		{
			insertlast();
		}
		else
		{
			Node* newnode = new Node();
			cout << "\n 1.Book Name:";
			cin >> newnode->bookname;
			cout << "\n 2.Book ID:";
			cin >> newnode->book_ID;
			cout << "\n 3.Author Name:";
			cin >> newnode->authorname;
			cout << "\n 4.Publisher Name:";
			cin >> newnode->publishername;
			cout << "\n 5.price";
			cin >> newnode->price;
			Node* temp = first;
			for (int i = 1; i < pos; i++)
			{
				temp = temp->next;
			}
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next = newnode;
			temp->next->prev = newnode;
		}
		cout << "\n\t\t New Book Inserted successfully ......\n";
		counter++;
	}

	void traverse() // to display the selection data 
	{
		system("CLS");
		if (counter == 0)
		{
			cout << "sorry,The Library is still empty..... \n";
		}
		Node* temp = first;
		while (temp != NULL)
		{
			cout << "\n\n Book Name:" << temp->bookname;
			cout << "\n\n Book ID:" << temp->book_ID;
			cout << "\n\n Book Author:" << temp->authorname;
			cout << "\n\n Book publisher:" << temp->publishername;
			cout << "\n\n Book price :" << temp->price << endl;
			cout << "\n\n==================================================================\n";
			temp = temp->next;
		}
		system("pause");
	}

	void search()
	{
		system("CLS");
		//int g;
		int found = 0;
		string namechecker;
		cout << "\n Please Enter The Name Of the Book You are searching for \n";
		cin >> namechecker;
		if (first == NULL && last == NULL)
		{
			cout << "The double linked list is empty \n";
		}
		else
		{
			Node* temp = first;
			while (temp != NULL)
			{
				if (temp->bookname == namechecker)
				{
					cout << "\n\n The Book is found....\n";
					cout << "\n\n Book Name:" << temp->bookname;
					cout << "\n\n Book ID:" << temp->book_ID;
					cout << "\n\n Book Author:" << temp->authorname;
					cout << "\n\n Book publisher:" << temp->publishername << endl;
					found++;
				}
				temp = temp->next;
			}
			if (found == 0)
			{
				cout << "Sorry The Book not Avaliable.....\n";
			}
		}
		system("pause");
	}

	void update()
	{
		system("CLS");
		string n;
		int count = 0;
		cout << "update data" << endl;
		if (first == NULL) {
			cout << "Linked list is Empty...." << endl;
		}
		else
		{
			cout << "Enter Book name " << endl;
			cin >> n;
			Node* temp = first;
			while (temp != NULL)
			{
				if (n == temp->bookname)
				{
					cout << " Enter new Book Name:" << endl;
					cin >> temp->bookname;
					cout << " Enter new Book ID:" << endl;
					cin >> temp->book_ID;
					cout << " Enter new Author Name:" << endl;
					cin >> temp->authorname;
					cout << " Enter new publisher Name:" << endl;
					cin >> temp->publishername;
					cout << "\n 5.enter the new price";
					cin >> temp->price;
					count++;
					cout << "\n\n\t Update Book successfully..." << endl;
					break;
				}
				temp = temp->next;
			}
			if (count == 0)
				cout << "Book named" << " " << n << " " << "not found " << endl;
			cout << "The Books Available Is Those------------\n";
		}
	}

	void removefirst()
	{
		system("CLS");
		if (counter == 0)
		{

			cout << "the  list is empty" << endl;
			cout << "\n Book deleted sucessfully...." << endl;
			return;
		}
		else if (counter == 1)
		{
			cout << "list have one element will remove" << endl;
			delete first;
			first = last = NULL;
		}
		else
		{
			Node* temp = first;
			first = first->next;
			first->prev = NULL;
			delete temp;
		}
		counter--;
	}

	int listcountofbooks()
	{
		system("CLS");
		Node* temp = first;
		int counter = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			counter++;
		}
		return counter;
	}

	void removelast()
	{
		system("CLS");
		if (counter == 0)
		{
			cout << "Empty list" << endl;
			return;
		}
		else if (counter == 1)
		{

			delete first;
			first = last = NULL;
		}
		else
		{
			Node* temp = last;
			last = last->prev;
			last->next = NULL;
			delete temp;
		}
		counter--;

	}

	void removeat(string name)
	{
		system("CLS");
		if (counter == 0)
		{
			cout << "linked list is empty" << endl;
			return;
		}
		if (first->bookname == name)
		{
			removefirst();
			cout << "\n Book deleted sucessfully...." << endl;
			return;
		}
		else
		{
			Node* temp = first->next;
			while (temp != NULL)
			{
				if (temp->bookname == name)
				{
					break;
				}
				temp = temp->next;
			}
			if (temp == NULL)
			{
				cout << "the Book  not found..." << endl;
				cout << "The Only Books Found Is....." << endl;
				return;
			}
			else if (temp->next == NULL)
			{
				removelast();
				cout << "\n Book deleted sucessfully...." << endl;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				cout << "\n\n Book deleted successfully...." << endl;
				counter--;
			}
		}
	}

	void insert(string name,
		string publishname,
		string authname,
		int ID)
	{

		Node* newnode = new Node();
		newnode->bookname = name;
		newnode->publishername = publishname;
		newnode->authorname = authname;
		newnode->book_ID = ID;
		if (counter == 0)
		{
			first = last = newnode;
			newnode->next = newnode->prev = NULL;
		}
		else
		{
			newnode->next = NULL;
			newnode->prev = last;
			last->next = newnode;
			last = newnode;
		}
	}
	/*void sort()
	{
		Node* ptr1 = first;
		Node* ptr2 = NULL;
		int temp;
		string temp1;
		string bookName;
		if (first == NULL)
		{
			cout << ("The Library is empty \n");
		}
		else
		{
			while (ptr1 != NULL)
			{
				temp1 = ptr1->bookname;
				ptr2 = ptr1->next;
				temp = ptr1->book_ID;
				ptr2 = ptr1->next;
				while (ptr2 != NULL)
				{
					if (ptr2->book_ID < temp)
					{
						ptr1->bookname = ptr2->bookname;
						ptr2->bookname = temp1;
						ptr1->book_ID = ptr2->book_ID;
						ptr2->book_ID = temp;
					}
					ptr2 = ptr2->next;
				}
				ptr1 = ptr1->next;
			}
		}
	}*/
	void sell()
	{
		int cnt = 0;
		char answer;
		string bk;
		cout << "enter the bookname want to sell: ";
		cin >> bk;
		Node* temp = first;
		while (temp != NULL)
		{
			if (temp->bookname == bk)
			{
				cout << "name: " << temp->bookname << endl;
				cout << "publishername : " << temp->publishername << endl;
				cout << "Price: " << temp->price << endl;
				cnt++;
			}
			temp = temp->next;
		}
		if (cnt == 0)
			cout << "We dont have this book here\n ";

		cout << "do you want to sell? perss y or n: ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (cnt == 0)
				cout << "there is no book to sell\n ";
			else
				removeat(bk);
		}
		system("pause");

	}
};
class stack
{
public:
	Node* top;
	stack()
	{
		top = NULL;
	}
	void push(string name)
	{
		if (top == NULL)
		{
			Node* newnode = new Node();
			newnode->bookname = name;
			newnode->prev = top;//prev next=NULL
			newnode->next = top;
			top = newnode;

		}
		else
		{
			Node* newnode = new Node();
			newnode->bookname = name;
			newnode->prev = top;
			newnode->next = NULL;
			top->next = newnode;
			top = newnode;

		}
	}
	void pop()
	{
		if (top != NULL)
		{
			Node* temp = top;
			top = temp->prev;
			top->next = NULL;
			delete temp;
		}
		else
		{
			cout << "stack is empty" << endl;
		}
	}
	void display()
	{
		if (top != NULL) {
			Node* temp = top;
			while (temp)
			{
				cout << temp->bookname << endl;
				temp = temp->prev;
			}
		}
		else
		{
			cout << "stack is empty" << endl;
		}
	}
};

int main()
{
	doublelinkedlist library;
	int ans;
	int no_of_books;
	do
	{
		library.menu();
		cout << "\nPlease Enter Your Choice\n";
		cin >> ans;
		switch (ans)
		{
		case 1:
		{
			system("CLS");
			cout << "\n Please Enter The number Of The Books You Would Like To Insert \n";
			cin >> no_of_books;
			for (int i = 1; i <= no_of_books; i++)
			{
				library.insertlast();
				library.traverse();
			}
			break;
		}
		case 2:
		{
			cout << "\n Please Enter The number Of The Books You Would Like To Insert At First\n";
			cin >> no_of_books;
			for (int i = 1; i <= no_of_books; i++)
			{
				library.insertfirst();
				library.traverse();
			}
			break;
		}
		case 3:
		{
			library.insertat();
			library.traverse();
			break;
		}
		case 4:
		{
			library.traverse();
			break;
		}
		case 5:
		{
			library.search();
			break;
		}
		case 6:
		{
			library.update();
			break;
		}
		case 7:
		{
			library.removefirst();
			library.traverse();
			break;
		}
		case 8:
		{
			library.removelast();
			library.traverse();
			break;
		}
		case 9:
		{
			string name;
			cout << "Enter Name Of The Book You Want To Delete \n";
			cin >> name;
			library.removeat(name);
			library.traverse();
			break;
		}
		case 10:
		{
			library.sell();
			break;
		}
		case 11:
		{
			cout << library.listcountofbooks();
			break;
		}
		}
	} while (ans > 0 && ans < 11);
	system("CLS");
	char ch;
	cout << "Do You Want To View The Already Stored Books In The Library\n\n";
	cout << "Please Reply By Y or N only\n";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		cout << "\n\n";
		cout << "The Avaliable Books In our Library is:" << "\n";
		stack s;
		s.push("c++ Programming Book");
		s.push("Python Book");
		s.push("Action Novel");
		s.push("Data Structure Fundementals");
		s.push("Romantic Novel");
		s.push("kids stories");
		s.push("Science Books");
		s.push("Maths");
		s.push("Mind Games");
		s.pop();
		s.display();
	}
	else if (ch == 'N' || ch == 'n')
	{
		cout << "Thankyou.......\n";
		exit(0);
	}
	else
	{
		cout << "You Should Enter Y or N only....Please Try again...\n";
	}
}