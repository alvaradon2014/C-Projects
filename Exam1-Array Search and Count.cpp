// Test 1 Day 2
// Nayely Alvarado	EE3223
// This program finds the frequency of each
// element in an array

#include <iostream>
#include <sstream>

using namespace std;


int match(int* list, int size, int value_check);

int main()
{
	int array[10] = {1, 1, 2, 3, 5, 8, 8, 8, 8, 1};			// Test array
	int n = 0;
	
	cout << "Array is:";
		
	for(n = 0; n < 10; n++)
	{
		cout << " " << array[n] << " ";				// Prints out array
	}
	
	for(n = 0; n < 10; n++)
	{
		cout << endl << "The frequency of " << array[n] << " is: " << match(array, 10, n) << endl;
	}
	// Note: Statement prints for each array element
	
	return(0);
}

int match(int* list, int size, int value_check)
{
	int frequency = 0;
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(*(list+i) == *(list+value_check))			// Checks if array elements repeat
		{
			frequency = frequency + 1;
		}
	}
		
	return(frequency);	
}


