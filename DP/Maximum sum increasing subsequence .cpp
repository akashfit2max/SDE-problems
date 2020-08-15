#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        vector<int>dp(n);
        for(int i=0;i<n;i++) {
            dp[i]=v[i];
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(v[j] < v[i]) {
                    dp[i] = max(dp[i],dp[j]+v[i]);
                }
            }
        }
        int mx=dp[0];
        for(int i=1;i<n;i++) {
            if(dp[i] > mx) {
                mx=dp[i];
            }
        }
        cout<<mx<<endl;
    }
	
	return 0;
}