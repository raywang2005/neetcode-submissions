class Solution {
public:
    int sum(vector<int> nums){
        int total = 0;
        for (int i = 0; i < nums.size(); i++){
            total += nums[i];
        }
        return total;
    }
    bool helper(vector<int>& nums, int cur){
        if (cur == sum(nums)){
            return true;
        }

        if(cur > sum(nums)){
            return false;
        }

        for (int i = 0; i < nums.size(); i++){
            int save = nums[i];
            vector<int> dup = nums;
            dup.erase(dup.begin() + i);
            if (helper(dup, cur + save)){
                return true;
            };
        }

        return false; 
    }
    bool canPartition(vector<int>& nums) {
        return helper(nums, 0);
    }
};
