// EE 3223 Spring 2017
// Nayely Alvarado
// This program uses functions to find a word amongst a given amount of words


#include <string>
#include <iostream>

using namespace std;


void InAndOut (string SearchWord, string InputWords[]);


int main()
{
	string search;
	string UserIn[500];
	
	InAndOut(search, UserIn);
	
	return(0);
}

void InAndOut(string SearchWord, string InputWords[])
{
	int n = 0;
	int check;
	int count = 0;
	int arrayElements;
	string terminate = "*end*";	
	
	
	cout << "Please enter multiple words separated by pressing the enter key (type *end* then enter when finished):" << '\n';
	
	while(1)
	{
		cin >> InputWords[n];
		
		if(InputWords[n] == terminate){
			cout << "Entered: " << InputWords[n] << endl;
			break;
		} else{
			cout << "Entered: " << InputWords[n] << endl;
			n++;
		}
	}	
	
	cout << "Now please enter a word to search: " << endl;
	cin >> SearchWord;

	arrayElements = n;
		
	for(check = 0; check <= n; check++)
	{
		if(SearchWord == InputWords[arrayElements]){
			count = count + 1;
			arrayElements = arrayElements - 1;
		} else{
			arrayElements = arrayElements - 1;
		}
	}
	
	cout << SearchWord << " occurs " << count << " time(s)" << endl;
}







