/*

Binary to decimal
Send Feedback
Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N in the Binary Format
Output format :
Corresponding Decimal number (as integer)
Constraints :
0 <= N <= 10^9
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7

*/

#include<iostream>
using namespace std;
int main() 
{
    int num;
    cin >> num;

    int decimal = 0, pow = 1;

    while(num > 0) 
    {
        int last = num % 10;
        decimal = decimal + last * pow;
        pow = pow * 2;
        num = num / 10;
    }

    cout << decimal;
}