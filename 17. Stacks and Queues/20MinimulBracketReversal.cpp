/*

Minimum bracket Reversal
Send Feedback
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to 
make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to 
reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence 
will not be able to make the expression balanced and the output will be -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// int countBracketReversals(string input)
// {
//     int len = input.length();

//     if(len == 0)
//     {
//         return 0;
//     }

//     if(len%2 != 0)
//     {
//         return -1;
//     }

//     stack<char> stack;

//     for(int i=0;i<len;i++)
//     {
//         char currChar = input[i];

//         if(currChar == '{')
//         {
//             stack.push(currChar);
//         }

//         else
//         {
//             if(!stack.empty() && stack.top() == '{')
//             {
//                 stack.pop();
//             }
//             else
//             {
//                 stack.push(currChar);
//             }
//         }
//     }

//     int count = 0;

//     while(!stack.empty())
//     {
//         char char1 = stack.top();
//         stack.pop();

//         char char2 = stack.top();
//         stack.pop();

//         if(char1!=char2)
//         {
//             count+=2;
//         }

//         else
//         {
//             count+=1;
//         }
//     }

//     return count;
// }

#include <stack>

int countBracketReversals(string input) 
{	
    if(input.length()%2!= 0)
    {
        return -1;
    }
    
    if(input.length() == 0)
    {
        return 0;
    }
    
    int count=0;
    stack<int> S;
    
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]== '{')
        {
            S.push(input[i]);
        }
        
        else if(input[i]== '}' && S.top()== '{')
        {
            S.pop();
        }
        
        else
        {
            S.push(input[i]);
        }
    }
    
    while(!S.empty())
    {
        char x= S.top();
        S.pop();
      
        char y= S.top();
        S.pop();
        
        if(x == y)
        {
            count++;
        }

        else
        {
            count+=2;
        }        
    }
    return count;
}

int main() {
    string input;
    cin >> input;

    cout << countBracketReversals(input);
}