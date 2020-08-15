int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i,j;
    int k[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                k[i][j]=0;
            else if(wt[i-1]<=j)
                k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
        }
    }
    return k[n][W];
    
   // Your code here
}

