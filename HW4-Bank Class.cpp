// EE 3223	Homework 4
// Nayely Alvarado
// This program acts as a mini bank that can access 
// a customer's accounts and add/view transactions


#include <iostream>
#include <string>

using namespace std;

struct Transaction{
	int ID;
	enum TransType{Credit, Debit};
	float Amount;
};

struct Account{
	int ID;
	float Balance;
	string Name;
	string DateOpened;
	Transaction Transactions[];
};

class Customer{
	public:
	int ID;
	string Name;
	string Address;
	Account Accounts[];
};

void error();
void Prompt();
void Repeat();

int main()
{
	// Customer Set-Up
	Customer John = {17, "John Doe", "205 E 29th St"};
	
	Account Checking;
	Checking.ID = 713;
	Checking.Balance = 100.00;
	Checking.Name = "Primary Checking";	
	Checking.DateOpened = "Mar 5";

	Account Savings;
	Savings.ID = 714;
	Savings.Balance = 100.00;
	Savings.Name = "Primary Savings";
	Savings.DateOpened = "Mar 5";

	Transaction Check1;
	Transaction Save1;
	
	string action;
	string deposit = "Deposit";
	string balance = "Balance";
	string withdraw = "Withdraw";
	string yes = "Yes";
	int input, i;
	float holder = 0;
	int check_trans = 1;
	int save_trans = 1;
	
	// End of set-up
	cout << "Hello! ";
	
	do
	{

		Prompt();
	
		cin >> action;
	
		// Check Balance
		if (action == balance){
			cout << "Which account balance would you like to see? Please enter the account ID (713 for Checking, 714 for Savings) or enter 0 for the total balance: ";
			cin >> input;
			
			// Checking Balance
			if (input == Checking.ID){
					
				cout << endl << "Checking Account Balance: " << Checking.Balance << endl;
			
			} 
			// Savings Balance	
			else if (input == Savings.ID){
				
				cout << endl << "Savings Account Balance: " << Savings.Balance << endl;
			
			} 
			// Total Balance
			else if (input == 0){

				holder = Savings.Balance + Checking.Balance;
				
				cout << endl << "Total Balance: " << holder << endl;
			}
		}
		// Deposit Money
		else if (action == deposit){
			cout << "Which account would you like to deposit money into? Please enter the account ID (713 for Checking, 714 for Savings): ";
			cin >> input;	
			
			cout << endl << "How much would you like to deposit?: ";
			cin >> holder;
		
			// Checking Deposit
			if (input == Checking.ID){
		
				Checking.Balance = Checking.Balance + holder;
				cout << endl << "New balance for Checking Account is: " << Checking.Balance << endl;

			}
			// Savings Deposit
			else if (input == Savings.ID){
		
				Savings.Balance = Savings.Balance + holder;
				cout << endl << "New balance for Savings Account is: " << Savings.Balance << endl;
			}
		}
		// Withdraw Money
		else if (action == withdraw){
			cout << "Which account would you like to withdraw money from? Please enther the account ID (713 for Checking, 714 for Savings): ";
			cin >> input;
			
			cout << endl << "How much would you like to withdraw?: ";
			cin >> holder;
	
			// Checking Withdraw
			if (input == Checking.ID){
				Checking.Balance = Checking.Balance - holder;
				cout << endl << "New balance for Checking Account is: " << Checking.Balance << endl;
			}
			// Savings Withdraw
			else if (input == Savings.ID){
				Savings.Balance = Savings.Balance - holder;
				cout << endl << "New balance for Savings Account is: " << Savings.Balance << endl;
			}
		} 
		// Invalid Input
		else {
			error();	
		}
		
		Repeat();
		
		cin >> action;
		
	} while (action == yes);	
	
	cout << endl << "Thank you for visiting!" << endl;
	
	return(0);
}

void Prompt() {
	cout << endl << "How can we assist you? Please type either: Balance, Withdraw, or Deposit, followed by the enter key" << endl;
}

void error() {
	cout << endl << "Sorry, we didn't understand your command"<< endl;
}

void Repeat() {
	cout << endl << "Anything else we can assist with? Please type Yes or No: " << endl;
	
}

