#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 個数数えるならmapで
        std::unordered_map<int, int> counter;
        for(int n: nums){
            counter[n]++;
        } 
        // ソートするか O(n logn)
        // vectorじゃないとソートできんらしい(なら自分で書けばよいのでは。。。？)
        std::vector<std::pair<int, int>> vcounter;
        for(auto& p: counter){
            vcounter.push_back({p.first, p.second});
        }
        std::sort(vcounter.begin(), vcounter.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        std::vector<int> answer;
        for(int i=0; i<k; i++){
            answer.push_back(vcounter[i].first);
        }
        return answer;
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    
    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    std::vector<int> result1 = sol.topKFrequent(nums1, k1);
    std::cout << "Test Case 1 (nums={1,1,1,2,2,3}, k=2): ";
    printVector(result1);

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> result2 = sol.topKFrequent(nums2, k2);
    std::cout << "Test Case 2 (nums={1}, k=1): ";
    printVector(result2);

    std::vector<int> nums3 = {1, 2};
    int k3 = 2;
    std::vector<int> result3 = sol.topKFrequent(nums3, k3);
    std::cout << "Test Case 3 (nums={1,2}, k=2): ";
    printVector(result3);

    return 0;
}
