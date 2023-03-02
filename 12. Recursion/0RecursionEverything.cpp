#include<iostream>
#include<climits>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

// Factorial

// int factorial(int n)
// {
//     if(n == 1)
//     {
//         return 1;
//     }

//     return n * factorial(n-1);
// }

// int main()
// {
//     int n;
//     cout<<"Enter the number : ";
//     cin>>n;

//     cout<<"Factorial is : "<<factorial(n);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Power of a number

// int power(int x, int n)
// {
//     if(n == 0)
//     {
//         return 1;
//     }

//     return x * power(x,n-1);
// }

// int main()
// {
//     int x;
//     cout<<"Enter the number : ";
//     cin>>x;

//     int n;
//     cout<<"Enter the power : ";
//     cin>>n;

//     cout<<"The power is : "<<power(x,n);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Print Numbers

// void print(int n)
// {
//     if(n == 1)
//     {
//         cout<<n<<" ";
//         return;
//     }

//     print(n-1);
//     cout<<n<<" ";
// }

// int main()
// {
//     int n;
//     cout<<"Enter the numbers : ";
//     cin>>n;

//     print(n);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Number of digits

// int numDigits(int n)
// {
//     if(n == 0)
//     {
//         return 0;
//     }

//     return 1 + numDigits(n/10);
// }

// int main()
// {
//     int n;
//     cout<<"Enter the number : ";
//     cin>>n;

//     cout<<"Number of digits are : "<<numDigits(n);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Fibonacci

// int fib(int n)
// {
//     if(n == 0 || n == 1)
//     {
//         return n;
//     }

//     return fib(n-1) + fib(n-2);
// }

// int main()
// {
//     int n;
//     cout<<"Enter the number : ";
//     cin>>n;

//     cout<<"Fibonacci number is : "<<fib(n);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Sum of Array 

// int arraySum(int *input, int n)
// {
//     if(n == 0)
//     {
//         return 0;
//     }

//     return input[0] + arraySum(input+1,n-1);
// }

// int main()
// {
//     int n;
//     cin >> n;
  
//     int *input = new int[n];
    
//     for(int i = 0; i < n; i++) 
//     {
//         cin >> input[i];
//     }
    
//     cout << arraySum(input, n) << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Check Number 

// bool checkNumber(int *input, int n, int x)
// {
//     if(n == 0)
//     {
//         return false;
//     }

//     if(input[0] == x)
//     {
//         return true;
//     }

//     return checkNumber(input+1,n-1,x);
// }

// int main()
// {
//     int n;
//     cin >> n;
  
//     int *input = new int[n];
    
//     for(int i = 0; i < n; i++) 
//     {
//         cin >> input[i];
//     }
    
//     int x;
    
//     cin >> x;
    
//     if(checkNumber(input, n, x)) 
//     {
//         cout << "true" << endl;
//     }

//     else 
//     {
//         cout << "false" << endl;
//     }
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// First Index

// int firstIndex(int *input, int n, int x)
// {
//     if(n == 0)
//     {
//         return -1;
//     }

//     if(input[0] == x)
//     {
//         return 0;
//     }

//     int ans = firstIndex(input+1,n-1,x);

//     if(ans == -1)
//     {
//         return -1;
//     }

//     else
//     {
//         return ans + 1;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
  
//     int *input = new int[n];
    
//     for(int i = 0; i < n; i++) 
//     {
//         cin >> input[i];
//     }
    
//     int x;
    
//     cin >> x;
    
//     cout << firstIndex(input, n, x) << endl;

// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Last Index

// int lastIndex(int *input, int n, int x)
// {
//     // Starting from first
//     if(n == 0)
//     {
//         return -1;
//     }

//     int smallAns = lastIndex(input+1,n-1,x);

//     if(smallAns != -1)
//     {
//         return smallAns+1;
//     }

//     if(input[0] == x)
//     {
//         return 0;
//     }
//     else
//     {
//         return -1;
//     }

//     // Starting from last
//     /*
//     if(n == 0)
//     {
//         return -1;
//     }

//     if(input[n-1] == x)
//     {
//         return n-1;
//     }

//     lastIndex(input,n-1,x);
//     */
// }

// int main()
// {
//     int n;
//     cin >> n;
  
//     int *input = new int[n];
    
//     for(int i = 0; i < n; i++) 
//     {
//         cin >> input[i];
//     }
    
//     int x;
    
//     cin >> x;
    
//     cout << lastIndex(input, n, x) << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Find all indexes of a number

// void allIndexesHelper(int *input, int currentIndex,int n, int x, int *output, int &k)
// {
//     if(currentIndex == n)
//     {
//         return;
//     }

//     if(input[currentIndex] == x)
//     {
//         output[k] = currentIndex;
//         k++;
//     }

//     allIndexesHelper(input,currentIndex+1,n,x,output,k);
// }

// int allIndexes(int *input, int n, int x, int *output)
// {
//     int k = 0;

//     allIndexesHelper(input,0,n,x,output,k);

//     return k;
// }

// int main()
// {
//     int n;
//     cin >> n;
  
//     int *input = new int[n];
    
//     for(int i = 0; i < n; i++) 
//     {
//         cin >> input[i];
//     }
    
//     int x;
    
//     cin >> x;
    
//     int *output = new int[n];
    
//     int size = allIndexes(input, n, x, output);

//     for(int i = 0; i < size; i++) 
//     {
//         cout << output[i] << " ";
//     }
    
//     delete [] input;
    
//     delete [] output;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Multiplication

// int multiply(int m, int n)
// {
//     if(n > m)
//     {
//         multiply(n,m);
//     }

//     if(n == 0 || m == 0)
//     {
//         return 0;
//     }

//     return m + multiply(m,n-1);
// }

// int main() 
// {
//     int m, n;
//     cin >> m >> n;
//     cout << multiply(m, n) << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Count Zeores

// int countZeros(int n)
// {
//     if(n <= 9)
//     {
//         if(n == 0)
//         {
//             return 1;
//         }

//         else
//         {
//             return 0;
//         }
//     }

//     int last = n%10;

//     int count = 0;

//     if(last == 0)
//     {
//         count = 1;
//     }

//     return count + countZeros(n/10);
// }

// int main() 
// {
//     int n;
//     cin >> n;
//     cout << countZeros(n) << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Geometric Sum

// double geometricSum(int n)
// {
//     if(n == 0)
//     {
//         return 1;
//     }

//     return (1/pow(2,n)) + geometricSum(n-1);
// }

// int main() 
// {
//     int k;
//     cin >> k;
//     cout << fixed << setprecision(5);
//     cout << geometricSum(k) << endl;   
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Check Palindrome

// int length(char *input)
// {
//     int len = 0;
//     for(int i=0;input[i] != '\0';i++)
//     {
//         len++;
//     }

//     return len;
// }

// bool checkPalindromeHelper(char *input, int start, int end)
// {
//     if(start >= end)
//     {
//         return true;
//     }

//     if(input[0] == '\0' || input[1] == '\0')
//     {
//         return true;
//     }

//     if(input[start] == input[end])
//     {
//         checkPalindromeHelper(input,start+1,end-1);
//     }

//     else
//     {
//         return false;
//     }
// }

// bool checkPalindrome(char *input)
// {
//     int len = length(input);

//     checkPalindromeHelper(input,0,len-1);
// }

// int main() 
// {
//     char input[50];
//     cin >> input;
    
//     if(checkPalindrome(input)) 
//     {
//         cout << "true" << endl;
//     }

//     else 
//     {
//         cout << "false" << endl;
//     }
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Sum of Digits

// int sumOfDigits(int n)
// {
//     if(n <= 9)
//     {
//         return n;
//     }

//     return n % 10 + sumOfDigits(n/10);
// }

// int main() 
// {
//    int n;
//    cin >> n;
//    cout << sumOfDigits(n) << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Replace PI

// int length(char input[])
// {
//     int len = 0;

//     for(int i=0;input[i] != '\0';i++)
//     {
//         len++;
//     }

//     return len;
// }

// void replacePiHelper(char input[], int start)
// {
//     if(input[start] == '\0' || input[start+1] == '\0')
//     {
//         return;
//     }

//     replacePiHelper(input,start+1);

//     if(input[start] == 'p')
//     {
//         if(input[start+1] == 'i')
//         {
//             int len = length(input);
//             input[len+2] = '\0';

//             for(int i=len-1;i>=start+2;i--)
//             {
//                 input[i+2] = input[i];
//             }

//             input[start] = '3';
//             input[start+1] = '.';
//             input[start+2] = '1';
//             input[start+3] = '4';
//         }
//     }
// }

// void replacePi(char input[])
// {
//     replacePiHelper(input,0);
// }

// int main() 
// {
//     char input[10000];
//     cin.getline(input, 10000);
//     replacePi(input);
//     cout << input << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Remove X

// int length(char input[]) 
// { 
//     int len = 0; 
    
//     for (int i = 0; input[i] != '\0'; i++) 
//     { 
//         len++; 
//     } 
    
//     return len;
// }

// void removeXhelper(char *input, int start)
// {
//     if(input[start] == '\0')
//     {
//         return;
//     }

//     removeXhelper(input,start+1);

//     if(input[start] == 'x')
//     {
//         int len = length(input);
//         int i;

//         for(i=start+1;i<len;i++)
//         {
//             input[i-1] = input[i];
//         }

//         input[i-1] = '\0';
//     } 
// }

// /* Alternate Approach

// void removeX(char input[]) 
// {
//     if(input[0]=='\0')
//         return;

//     if(input[0]!='x')
//     {
//         removeX(input+1);
//     }

//     else
//     {
//         int i=1;

//         for(;input[i]!='\0';i++)
//         {
//             input[i-1]=input[i];
//         }

//         input[i-1]=input[i];
//         removeX(input);
//     }
// }

// */

// void removeX(char *input)
// {
//     removeXhelper(input,0);
// }

// int main() 
// {
//     char input[100];
//     cin.getline(input, 100);
//     removeX(input);
//     cout << input << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// String to Integer

// int length(char input[]) 
// { 
//     int len = 0; 
    
//     for(int i = 0; input[i] != '\0'; i++) 
//     { 
//         len++; 
//     } 
    
//     return len; 
// } 

// int stringToNumber_helper(char input[], int last) 
// { 
//     if(last == 0) 
//     { 
//         return input[last] - '0'; 
//     } 
    
//     int smallAns = stringToNumber_helper(input, last-1);
    
//     int a = input[last] - '0'; 
    
//     return smallAns * 10 + a; 
// } 

// int stringToNumber(char input[]) 
// { 
//     int len = length(input); 
    
//     int ans = stringToNumber_helper(input, len - 1); 
    
//     return ans; 
// }

// int main() 
// {
//     char input[50];
//     cin >> input;
//     cout << stringToNumber(input) << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Pair Star

// int length(char input[]) 
// { 
//     int len = 0; 
    
//     for (int i = 0; input[i] != '\0'; i++) 
//     { 
//         len++; 
//     } 
    
//     return len; 
// }

// void pairStar(char input[], int start) 
// { 
//     if (input[start] == '\0') 
//     { 
//         return; 
//     } 
    
//     pairStar(input, start + 1); 
    
//     if (input[start] == input[start + 1]) 
//     { 
//         int l = length(input); 
//         input[l + 1] = '\0'; 
//         int i; 
        
//         for (i = l - 1; i >= start + 1; i--) 
//         { 
//             input[i + 1] = input[i]; 
//         } 
        
//         input[i + 1] = '*'; 
//     } 
// } 

// void pairStar(char input[]) 
// { 
//     pairStar(input, 0); 
// }

// int main() 
// {
//    char input[100];
//    cin.getline(input, 100);
//    pairStar(input);
//    cout << input << endl;
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Tower Of Hanoi

// void towerOfHanoi(int n, char source, char auxiliary, char destination) 
// {
// 	if(n==0)
//     {
//         return;
//     }
    
//     towerOfHanoi(n-1,source,destination,auxiliary);
    
//     cout<<source<<" "<<destination<<endl;
    
//     towerOfHanoi(n-1,auxiliary,source,destination); 
// }

// int main() 
// {
//     int n;
//     cin >> n;
//     towerOfHanoi(n, 'a', 'b', 'c');
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/