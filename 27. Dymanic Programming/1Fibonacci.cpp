#include<iostream>

using namespace std;

//memoization (top-down approach)
int fib_helper(int n, int *ans)
{
    if(n<=1)
    {
        return n;
    }

    //Check if ans alrealy exists
    if(ans[n] != -1)
    {
        return ans[n];
    }

    int a = fib_helper(n-1,ans);
    int b = fib_helper(n-2,ans);

    // Save the output for future use
    ans[n] = a + b;

    // Return the final output
    return ans[n]; 
}
int fib(int n)
{
    int *ans = new int[n+1];

    for(int i=0;i<n+1;i++)
    {
        ans[i] = -1;
    }

    fib_helper(n,ans);
}

//tabulation (bottom-up approach)


int main()
{

}