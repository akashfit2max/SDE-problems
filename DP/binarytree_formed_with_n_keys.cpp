Unique Binary Search Trees

class Solution {
public:
    int numTrees(int n) {
        vector<int>T(n+1);
        T[0] = 1;
        T[1] = 1;
        for (int i=2; i <= n; i++) {
            for (int j=0; j <i; j++) {
                T[i] += T[j]*T[i-j-1]; //this is also called as cattlan number formula
            }
        }
        return T[n];
    }
};