// Spring 2017 EE 3223
// Nayely Alvarado
// xmg 736

// Homework 1: This program outputs a triangle with
// alternating characters on each row using functions

#include <iostream>

using namespace std;

int SPACE(int space)
{
   int i = 0;
   
   for(i=0; i<space; i++) {
      cout << " ";
   }
}

int STAR(int star) 
{
   int j = 0;
   
   for(j=0; j<star; j++) {
      cout << "*";
   }
   cout << endl;
}

int CARET(int carrot)
{
   int k = 0;
   
   for(k=0; k<carrot; k++) {
      cout << "^";
   }
   cout << endl;
}

int main()
{
   SPACE(5);
   STAR(1);
   
   SPACE(4);
   CARET(3);

   SPACE(3);
   STAR(5);

   SPACE(2);
   CARET(7);

   SPACE(1);
   STAR(9);

   CARET(11);

   return(0);
}



