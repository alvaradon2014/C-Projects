// EE 3223 Homework 2
// Nayely Alvarado
// 
// This program takes multiple words from the user
// then takes a search word from the user and 
// counts the occurences of the search word
// in the original set of words


#include <string>
#include <iostream>

using namespace std;

int main()
{
	string SearchWord;
	string InputWords[500];
	string str = "*end*";
	
	int n, check, count, arrayElements;
	n = 0;
	count = 0;

	cout << "Please enter a word then press enter (use key phrase *end* when finished):";
	cout << endl;
	
	while(1)
	{
		cin >> InputWords[n];
	
		if (InputWords[n] == str)
		{
			cout << "You entered: " << InputWords[n];
			cout << endl;
		
			break;
		} 
		else
		{
			cout << "You entered: " << InputWords[n];
			cout << endl;
			n++;
		}
	}
	
	cout << "Now please enter a word to search:";
	cout << endl;
	
	cin >> SearchWord;
		
	arrayElements = n;
	
	for(check = 0; check <= n; check++)
	{
		if (SearchWord == InputWords[arrayElements])
		{
			count = count +1;
			arrayElements = arrayElements -1;
		}
		else
		{
			arrayElements = arrayElements -1;
		}
	}
	
	cout << SearchWord << "  occurs  " << count << "  time(s)" << endl;
	
	return(0);
}



