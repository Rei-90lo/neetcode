#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map> // unordered_map を使うために必要です

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;

        for(char c : s){
            sMap[c]++;
        }
        for(char c : t){
            tMap[c]++;
        }

        return sMap == tMap;
    }
};

int main() {
    Solution sol;
    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    std::cout << "Test Case 1 (anagram, nagaram): " << (sol.isAnagram(s1, t1) ? "true" : "false") << std::endl;

    std::string s2 = "rat";
    std::string t2 = "car";
    std::cout << "Test Case 2 (rat, car): " << (sol.isAnagram(s2, t2) ? "true" : "false") << std::endl;

    return 0;
}
