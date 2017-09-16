// EE 3223 HW 4 Redo with Linked Lists
// Nayely Alvarado
// This program acts as a mini bank that can access 
// a customer's accounts and add/view transactions
// Uses linked lists

#include <iostream>
#include <string>

using namespace std;

struct node
{
	int info;
	struct node *next;
	struct node *prev;
}*start;

// Doubly Linked List Class
class double_llist
{
	public:
	void create_list(int);
	void insert_last(int, float);
	float balance();
	double_llist()
	{
		start = NULL;
	}
};

// Transaction Struct
struct Transaction
{
	int ID;
	float Amount;
	bool TransType; 		// 0 for Credit, 1 for Debit
};

// Account Struct
struct Account
{
	int ID;
	float Balance;
	string Name;
	string DateOpened;
	double_llist Transaction;
};

// Customer Class
class Customer
{
	public:
	int ID;
	string Name;
	string Address;
	double_llist Account;
};

void Menu();

int main()
{
	// Set-Up
	Customer John = {1, "John Doe", "100 Main St"};
	
	Account Checking;
	Checking.ID = 1;
	Checking.Name = "Main Checking";
	Checking.Balance = 100.00;
	Checking.DateOpened = "Mar 12";
	
	Account Savings;
	Savings.ID = 2;
	Savings.Name = "Life Savings";
	Savings.Balance = 100.00;
	Savings.DateOpened = "Mar 12";
	
	Transaction Check1;
	Transaction Save1;
	
	int action;
	float holder;
	
	double_llist Check_Account;
	Check_Account.insert_last(2, 100);		// $100 in checking
	
	double_llist Save_Account;
	Save_Account.insert_last(2, 100);		// $100 in savings
	
	start = NULL;
	
	while(1)
	{
		void Menu();
		cin >> action;
		
		switch (action)
		{
			case 1:
				cout << endl << "View Balance of: " << endl;
				cout << "1.Checking Account" << endl;
				cout << "2.Savings Account" << endl;
				cout << "3.Both Accounts" << endl;
				cout << "Please enter your choice: " << endl;
				cin >> action;
				
				switch (action)
				{
					case 1:
						cout << endl << "Checking Account Balance: " << Check_Account.balance() << endl;
						break;
					case 2:
						cout << endl << "Savings Account Balance: " << Save_Account.balance() << endl;
						break;
					case 3:
						holder = Check_Account.balance() + Save_Account.balance();
						cout << endl << "Combined Account Balance: " << holder << endl;
						break;
				}
				cout << endl;
				break;

			case 2:
				cout << endl << "Deposit into: " << endl;
				cout << "1.Checking Account" << endl;
				cout << "2.Savings Account" << endl;
				cout << "Please enter your choice: ";
				cin >> action;
				cout << endl << "How much would you like to deposit?: ";
				cin >> holder;
				
				switch (action)
				{
					case 1:
						Check_Account.insert_last(2, holder);
						break;
					case 2:
						Save_Account.insert_last(2, holder);
						break;
				}
				cout << endl;
				break;

			case 3:
				cout << endl << "Withdraw from: " << endl;
				cout << "1.Checking Account" << endl;
				cout << "2.Savings Account" << endl;
				cout << "Please enter your choice: ";
				cin >> action;
				cout << endl << "How much would you like to withdraw?: ";
				cin >> holder;
				
				switch (action)
				{
					case 1:
						Check_Account.insert_last(3, holder);
						break;
					case 2:
						Save_Account.insert_last(3, holder);
						break;
				}
				cout << endl;
				break;
			case 4:
				cout << endl << "Thank you for visiting!" << endl;
				return(0);
				break;
			default:
				cout << endl << "Invalid response, please try again!" << endl;
		}
	}
	
	
	return(0);
}

// Menu
void Menu()
{
	cout << endl << "--------------------------" << endl;
	cout << endl << "Welcome to Bank of Nayely" << endl;
	cout << endl << "--------------------------" << endl;
	cout << "1.View Balance" << endl;
	cout << "2.Deposit" << endl;
	cout << "3.Withdraw" << endl;
	cout << "4.Exit" << endl;
	cout << "Please enter your choice: ";	
}

// Create Node
/*node *single_llist::creat_node(int value)
{
	struct node *temp;
	temp = new(struct node);
	if (temp == NULL)
	{
		cout << "Memory not allocated" << endl;
		return(0);
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}*/

// Create Double Link List
void double_llist::create_list(int value)
{
	struct node *s, *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	if (start = NULL)
	{
		temp->prev = NULL;
		start = temp;
	} else {
		s = start;
		while (s->next != NULL) {
			s = s->next;
		}
		s->next = temp;
		temp->prev = s;
	}
}

// Insert new transaction
void double_llist::insert_last(int sign, float money)
{
	if (sign = 3) {
		money = money * -1.0;
	}
	struct node *temp;
	temp = new(struct node);
	temp->prev = NULL;
	temp->info = money;
	temp->next = start;
	start->prev = temp;
	start = temp;
	
	cout << "Transaction Complete" << endl;
}

// Find Account Balance
float double_llist::balance()
{
	float value = 0.00;
	
	struct node *s = start;
	//s = start;
	while (s != NULL)
	{
		value = value + s->info;
		s = s->next;
	}
	return(value);
}

