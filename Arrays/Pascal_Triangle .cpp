class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        if (numRows==0) {
            return result;
        }
        vector<int>fs;
        fs.push_back(1);
        result.push_back(fs);
        for (int i=1;i<numRows;i++) {
            vector<int>row;
            vector<int>prevrow=result[i-1];
            row.push_back(1);
            for (int j=1;j<i;j++) {
                row.push_back(prevrow[j-1]+prevrow[j]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};



#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll a[10][10], i, j;
    for (i=0;i<10;++i)
    {
        printf("\n");
        for (j=0;j<=i;++j)
        {
            if (j==0 || i==j)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            printf("%4d", a[i][j]);
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
