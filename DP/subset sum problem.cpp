#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--) {
        int n, t;
        cin>>n>>t;
        vector<int>nums(n);
        for (int i=0;i<n;i++) {
            cin>>nums[i];
        }
        bool dp[n+1][t+1];
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=t;j++)
            {
                if (j==0)
                    dp[i][j]=true;

                else if (i==0)
                    dp[i][j]=false;

                else
                {
                    if (j>=nums[i-1])
                        dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];

                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        if (dp[n][t]) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }


    return 0;
}