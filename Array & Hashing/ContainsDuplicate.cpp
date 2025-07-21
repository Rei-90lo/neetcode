class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // for(int i=1; i<nums.size(); i++){
        //     for(int j=0; j<i; j++){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        std::unordered_set<int> numSet;
        for(int i=0; i<nums.size(); i++){
            if(numSet.count(nums[i]))
                return true;
            numSet.insert(nums[i]);
        }
        return false;
    }
};