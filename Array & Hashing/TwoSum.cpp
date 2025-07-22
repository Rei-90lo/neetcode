#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // brute-force
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if(nums[i] + nums[j] == target) {
        //             return {i, j}; 
        //         }
        //     }
        // }
        // return {}; 

        // 少し冗長
        // std::unordered_map<int, int> numMap;
        // for(int i = 0; i < nums.size(); i++){
        //     if(numMap.find(target - nums[i]) != numMap.end())
        //         return {numMap.find(target-nums[i])->second, i};
            
        //     numMap.insert(std::unordered_map<int,int>::value_type(nums[i], i));
        // }

        std::unordered_map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++){
            if(numMap.find(target - nums[i]) != numMap.end())
                return {numMap[target - nums[i]], i};
            
            numMap.insert({nums[i], i});
        }
        return {};
    }
};
