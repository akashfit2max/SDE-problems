class Solution
{
public:
    int board[10][10];
    vector<vector<string>> ans;
    void result(int n)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            for (int j = 0; j < n; j++)
            {
                if (!board[i][j])
                    s += '.';
                else
                    s += 'Q';
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }
    bool issafe(int row, int col, int n)
    {
        for (int i = 0; i < col; i++) // current row
            if (board[row][i])
                return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // left upper diagonal
            if (board[i][j])
                return false;
        for (int i = row, j = col; i < n && j >= 0; i++, j--) // left lower diagonal
            if (board[i][j])
                return false;

        return true;
    }
    void nQueen(int col, int n)
    {
        if (col >= n)
        {
            result(n);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (issafe(i, col, n))
            {
                board[i][col] = 1;
                nQueen(col + 1, n);
                board[i][col] = 0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        memset(board, 0, sizeof(board));
        ans.clear();
        nQueen(0, n);
        return ans;
    }
};