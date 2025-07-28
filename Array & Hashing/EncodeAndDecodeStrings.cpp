#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


class Solution {
public:
    /**
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    std::string encode(const std::vector<std::string>& strs) {
        // ここにエンコードのロジックを書いてみましょう。
        std::string coded;
        for(const auto& s : strs){
            coded += std::to_string(s.length()) + "#" + s;
        }
        return coded;
    }

    /**
     * @param s: A string
     * @return: decodes a single string to a list of strings
     */
    std::vector<std::string> decode(const std::string& s) {
        // 初見 だいぶ良くない
        // std::string word="";
        // std::vector<std::string> decoded;
        // std::string wordsize=""; 
        // int flag = 0;
        // int counter = 0;

        // if(s.empty())
        //     return {};
        // for(const char& c: s){
        //     if(c == '#' && flag == 0){
        //         flag = 1;
        //         if (wordsize.empty()) { // Handle cases like ##
        //             counter = 0;
        //         } else {
        //             counter = std::stoi(wordsize);
        //         }
                
        //         if(counter == 0){
        //             decoded.push_back("");
        //             word = "";
        //             wordsize = "";
        //             flag = 0;
        //         }
        //     }
        //     else if(flag == 0){
        //         wordsize += c;
        //     }
        //     else{ 
        //         word += c;
        //         if(--counter == 0){
        //             decoded.push_back(word);
        //             word = "";
        //             wordsize = "";
        //             flag = 0;
        //         }
        //     }
        // }
        // return decoded;

        // find substr使います
        std::string word="";
        std::vector<std::string> decoded;
        int wordsize = 0;
        int i = 0; 
        while(i < s.size()){
            int j = s.find("#", i);
            wordsize = std::stoi(s.substr(i, j-i));
            word = s.substr(++j, wordsize);
            decoded.push_back(word);
            i = j + wordsize;
        }
        return decoded;
    }
};

void print_vector(const std::vector<std::string>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    std::vector<std::string> input1 = {"neet", "code", "love", "you"};
    std::cout << "Original: ";
    print_vector(input1);
    
    std::string encoded1 = solution.encode(input1);
    std::cout << "Encoded: " << encoded1 << std::endl;
    
    std::vector<std::string> decoded1 = solution.decode(encoded1);
    std::cout << "Decoded: ";
    print_vector(decoded1);
    std::cout << "--------------------" << std::endl;

    // Test Case 2
    std::vector<std::string> input2 = {"we", "say", ":", "yes"};
    std::cout << "Original: ";
    print_vector(input2);
    
    std::string encoded2 = solution.encode(input2);
    std::cout << "Encoded: " << encoded2 << std::endl;
    
    std::vector<std::string> decoded2 = solution.decode(encoded2);
    std::cout << "Decoded: ";
    print_vector(decoded2);
    std::cout << "--------------------" << std::endl;

    // Test Case 3 (with empty string)
    std::vector<std::string> input3 = {};
    std::cout << "Original: ";
    print_vector(input3);
    
    std::string encoded3 = solution.encode(input3);
    std::cout << "Encoded: " << encoded3 << std::endl;
    
    std::vector<std::string> decoded3 = solution.decode(encoded3);
    std::cout << "Decoded: ";
    print_vector(decoded3);
    std::cout << "--------------------" << std::endl;

    return 0;
}
