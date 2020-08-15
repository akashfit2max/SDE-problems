class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;
        // check iff the first row is zero
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 0){
                 row0 = true; 
                 break;
            }
        }
        //check if the first col is zero
        for(int j = 0; j < m; j++){
            if(matrix[j][0] == 0){
                 col0 = true;      
                 break;
            }
        }
        //other than firsst row and col
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){  
                if(matrix[i][0] == 0 or matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }        
            }
        }
        if(row0){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        if(col0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};