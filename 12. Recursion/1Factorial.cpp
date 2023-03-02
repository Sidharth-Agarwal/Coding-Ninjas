#include <iostream>
using namespace std;

int factorial(int n) 
{
	cout << n << endl;

	if (n == 0) 
    {
		return 1;
	}

	int smallOutput = factorial(n - 1);
	return n * smallOutput;
}

int main() 
{
	int n;
	cin >> n;
	int output = factorial(n);
	cout << output << endl;
}

/*

#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	int smallOutput = factorial(n - 1);
	int output = n * smallOutput;
	return output;
}

int main() {
	cout << factorial(4) << endl;
}

*/