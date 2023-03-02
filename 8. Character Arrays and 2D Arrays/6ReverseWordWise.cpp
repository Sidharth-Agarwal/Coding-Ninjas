/*

Reverse Word Wise
Send Feedback
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 
2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always

*/

#include <iostream>

using namespace std;

/*

int length(char input[])
{
    int len=0;
    
    for(int i=0;input[i]!='\0';i++)
    {
        len++;
    }
    
    return len;
}

void reverse(char input[],int start,int end)
{
    int i=start;
    int j=end;
    
    while(i<j)
    {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}

void reverseCompleteString(char input[])
{
    int i=0;
    int j=length(input)-1;
    
    while(i<j)
    {
        char temp=input[i];
        input[i]=input[j];
        input[j]=temp;
        i++;
        j--;
    }
}

void reverseStringWordWise(char input[])
{
    // Write your code here
    
    reverseCompleteString(input);
    
    int start=0;
    int end=0;
    int i;
    
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]==' ')
        {
            end=i-1;
            
            reverse(input,start,end);
            
            start=i+1;
        }
    }
    
    end=i-1;
    
    reverse(input,start,end);
}

*/

void reverse(char input[], int start, int end) 
{ 
    while(start < end) 
    { 
        std::swap(input[start++], input[end--]); 
    } 
} 

void reverseStringWordWise(char input[]) 
{ 
    int previousSpaceIndex = -1; 
    int i = 0; 
    
    for(; input[i] != '\0'; i++) 
    { 
        if(input[i] == ' ') 
        { 
            reverse(input, previousSpaceIndex + 1, i - 1); 
            previousSpaceIndex = i; 
        } 
    } 
    reverse(input, previousSpaceIndex + 1, i - 1); 
    reverse(input, 0, i - 1);
}

int main() 
{
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}

/*

// void reverse(char input[],int start,int end)
// {
//     int i=start;
//     int j=end;
    
//     while(i<j)
//     {
//         char temp=input[i];
//         input[i]=input[j];
//         input[j]=temp;
//         i++;
//         j--;
//     }
// }

void reverse(char input[],int start,int end)
{
    int len=end-start+1;
    
    for(int i=start;i<len/2;i++)
    {
        int temp=input[i];
        input[i]=input[end-i];
        input[end-i]=temp;
    }
}

void reverseStringWordWise(char input[])
{
    // Write your code here
    int count=0;
    
    for(int i=0 ;input[i]!='\0';i++ )
    {
        count++;
    }
    //cout<<count;
    for(int k=0;k<count/2;k++)
    {
        int temp=input[k];
        input[k]=input[count-1-k];
        input[count-1-k]=temp;
    }
    
    int start=0;
    int end;
    
    int j;
    
    for(j=0;j<count;j++)
    {
        if(input[j]==' ')
        {
            end=j-1;
            
            reverse(input,start,end);
            
            start=j+1;
        }
    }
    end = j-1;
    
    reverse(input,start,end);
}

*/

/*

void reverseStringWordWise(char str[]) 
{
    int count=0;
    for(int i=0;str[i] != '\0';i++)
    {
        count++;
    }
    int s=0;
    int e=count-1;
    while(s<e)
    {
        char temp = 'a';
        temp = str[s];
        str[s]=str[e];
        str[e]=temp;
        s++;
        e--;
    }
    s=0;
    int i;
    for(i=0;i<=count;i++)
    {
        if(str[i]==' ' || str[i]== '\0')
        {
            e=i-1;
            while(s<=e)
            {
   			    char temp = str[s];
        		str[s]=str[e];
        		str[e]=temp;
        		s++;
        		e--;
            }
            s=i+1;
        }
    }
    
    // e=i-1;
    // while(s<=e)
    // {
    // char temp = str[s];
    //     str[s]=str[e];
    //     str[e]=temp;
    //     s++;
    //     e--;
    // } 
}

*/