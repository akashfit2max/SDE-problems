
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int egg, int fl)
{
    // 2D array (Table) for storing all possiblities.
    int dp[egg + 1][fl + 1];

    // initialize base condition when no of floor is 0 or 1;
    for (int i = 0; i <= egg; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    // base condition when no of egg is 1.
    for (int j = 1; j <= fl; j++)
    {
        dp[1][j] = j;
    }

    // now update all entry with the help of base conditions values.
    for (int i = 2; i <= egg; i++)
    {
        for (int j = 2; j <= fl; j++)
        {

            //initially dp[i][j] is infinite(maximum possible value).
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++)
            {
                int temp = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);

                // update each time if we get minimum value.
                if (temp < dp[i][j])
                {
                    dp[i][j] = temp;
                }
            }
        }
    }

    return dp[egg][fl];

    // your code here
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        cout << eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends