class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int k = 0;
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] < nums[i - 1]){
                k ++;
                if(k > 1) return false;
                if(i == 1){
                    nums[i - 1] = nums[i];
                }
                else{ // i > 1
                    if(nums[i] >= nums[i - 2]){
                        nums[i - 1] = nums[i - 2];
                    }
                    else{
                        nums[i] = nums[i - 1];
                    }
                }
            }
        }
        return true;
    }
};