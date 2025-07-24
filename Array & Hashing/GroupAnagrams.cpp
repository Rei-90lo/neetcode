#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // // × まずそれぞれmapでやってみる <- mapの中にmapは入れれない(hashが定義されてないので)
        // typedef std::unordered_map<char, int> Amap;
        // typedef std::unordered_set<std::string> strSet;
        // std::unordered_map<Amap, strSet> sets; 
        // for(std::string s: strs) {
        //     // アナグラム判定用
        //     Amap strSet;
        //     for(char c: s){
        //         strSet[c]++;
        //     }

        //     //  アナグラムマップでマップを作って同じものの中にstrを入れてく
        //     if(sets.count(strSet)){
        //         sets[strSet].insert(s)
        //     }else{
        //         strSet m;
        //         m.insert(s);
        //         sets.insert({strSet, m});
        //     }
        // }
        // // 全部取り出して返したい
        // std::vector<std::vector<std::string>> v;
        // for(auto sets_pair: sets){
        //     std::vector<std::string> anas;
        //     for(auto str_pair: sets_pair->second){
        //         std::vector target;
        //         anas.insert(anas.end(), target.begin(), target.end());
        //     }
        //     v.insert(v.end(), anas.begin(), anas.end());
        // }
        // return v;

        // // まずはsort
        // std::vector<std::string> strs_sorted;
        // for(std::string s: strs){
        //     std::sort(s.begin(), s.end());
        //     strs_sorted.push_back(s);
        // }
        // std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        // for(int i=0; i<strs.size(); i++){
        //     anagramMap[strs_sorted[i]].push_back(strs[i]);
        // }

        // std::vector<std::vector<std::string>> answer;
        // for(auto& pair: anagramMap){
        //     answer.push_back(pair.second);
        // }
        // return answer;

        // ValidAnagramを参考に O(m*n)
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        for(std::string s: strs){
            std::vector<int> counter(26, 0);
            for(char c: s){
                counter[c - 'a']++;
            }
            std::string key;
            for(int i: counter){
                key = key + "," + std::to_string(i);
            }
            anagramMap[key].push_back(s);
        }        
        std::vector<std::vector<std::string>> answer;
        for(auto& pair: anagramMap){
            answer.push_back(pair.second);
        }
        return answer;
    }
};

// You can add test cases here in the main function
int main() {
    Solution sol;
    // Example 1
    std::vector<std::string> strs1 = {"act","pots","tops","cat","stop","hat"};
    std::vector<std::vector<std::string>> result1 = sol.groupAnagrams(strs1);
    // You can add code to print the result to verify your solution

    // Example 2
    std::vector<std::string> strs2 = {"x"};
    std::vector<std::vector<std::string>> result2 = sol.groupAnagrams(strs2);
    // You can add code to print the result to verify your solution

    // Example 3
    std::vector<std::string> strs3 = {""};
    std::vector<std::vector<std::string>> result3 = sol.groupAnagrams(strs3);
    // You can add code to print the result to verify your solution

    return 0;
}
