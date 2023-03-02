#include <iostream>
using namespace std;

int main() 
{
	int i = 10;
	int j = 21;
	int const * p = &i; //pointer towards a constant integer

	p = &j;

	int * const p2 = &i;  //constant pointer to an integer
	(*p2)++;
	//p2 = &j;


	int const * const p3 = &i; //constant pointer to a constant integer
	p3 = &j;
	(*p3)++;
}