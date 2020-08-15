class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==0) {
            return -1;
        }
        int current_max=nums[0];
        int current_min=nums[0];
        int final_max=nums[0];

        for (int i=1;i<nums.size();i++) {
            if (nums[i]<0) {
                swap(current_max, current_min);
            }
            current_max=max(current_max*nums[i], nums[i]);
            current_min=min(current_min*nums[i], nums[i]);

            if (current_max > final_max) {
                final_max=current_max;
            }
        }

        return final_max;
    }
};