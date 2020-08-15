class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1, pos2 = n - 1, new_pos = m + n - 1;
        while( new_pos >=0) {
            if(pos2 < 0) {
                break;
            }
            if(pos1 >=0 && nums1[pos1] > nums2[pos2]) {
                nums1[new_pos--] = nums1[pos1--];
            }
            else {
                nums1[new_pos--] = nums2[pos2--];
            }
        }
    }
};