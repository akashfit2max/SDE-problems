void findPath(int i,int j,int m[MAX][MAX],int n,string s,vector<string> &res)
{
    if(i<0 or j<0 or i>=n or j>=n or m[i][j]==0 or m[i][j]==5 ) 
    {
        return;
    }
    if(i==n-1 && j==n-1)
    {
        res.push_back(s);
        return;
    }
    else
    {
        m[i][j]=5;
        findPath(i+1,j,m,n,s+'D',res); 
        findPath(i-1,j,m,n,s+'U',res);
        findPath(i,j+1,m,n,s+'R',res);
        findPath(i,j-1,m,n,s+'L',res);
        m[i][j]=1;
    }
}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string>res;
    findPath(0,0,m,n,"",res);
    sort(res.begin(),res.end());
    return res;
	// Your code goes here 
}
