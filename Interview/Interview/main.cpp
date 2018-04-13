//
//  main.cpp
//  Interview
//
//  Created by Solon Chen on 26/02/2018.
//  Copyright © 2018 Solon. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

#include <sys/mount.h>

#include "arrangement.hpp"
#include "charBoard.hpp"
#include "customSortString.hpp"
#include "findSubString.hpp"
#include "rightReference.hpp"
#include "math.hpp"
#include "randomizedSet.hpp"
#include "reversePolishNotation.hpp"
#include "taskScheduler.hpp"

using namespace std;

//class Solution {
//private:
//    typedef map<pair<int, int>, int> ScoreMap;
//
//public:
//     string longestPalindrome(const string& str) {
//         int strLength = (int)str.length();
//         int subStrLength = strLength;
//         while (subStrLength > 0) {
//             for (int from = 0; from <= strLength - subStrLength; from++) {
//                 int to = from + subStrLength - 1;
//                 if (isPalindrome(str, from, to))
//                     return str.substr(from, subStrLength);
//             }
//
//             subStrLength--;
//         }
//
//         return "";
//     }
////    string longestPalindrome(const string& s) {
////        int n = (int)s.size(), len = 0, start = 0;
////        for(int i = 0; i < n; i++){
////            int left = i, right = i;
////            while(right < n && s[right+1] == s[right]) right++;
////            i = right;
////            while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
////                left--;
////                right++;
////            }
////
////            if(len < right-left+1){
////                len = right - left + 1;
////                start = left;
////            }
////        }
////        return s.substr(start, len);
////    }
//
//    string findLongestCommonSubstring(const string& strA, const string& strB) {
//        string lcs = "";
//        ScoreMap scores;
//
//        for (int i = 0; i < strA.length(); i++) {
//            for (int j = 0; j < strB.length(); j++) {
//                if (strA[i] == strB[j]) {
//                    auto upLeftScore = 0;
//                    auto iter = scores.find({i - 1, j - 1});
//                    if (iter != scores.end())
//                        upLeftScore = iter->second;
//
//                    auto score = upLeftScore + 1;
//                    scores.insert({{i, j}, score});
//
//                    if (score > lcs.length())
//                        lcs = strA.substr(i - score + 1, score);
//                }
//            }
//        }
//        return lcs;
//    }
//
//private:
//    bool isPalindrome(const string& str, int from, int to) {
//        if (from == to)
//            return true;
//
//        auto distance = (to - from + 1) / 2;
//        return equal(str.begin() + from, str.begin() + from + distance, str.rbegin() + (str.length() - to - 1));
//    }
//};

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//private:
//    struct SortableNode {
//        TreeNode *node;
//
//        bool operator < (const SortableNode& other) const {
//            return node->val < other.node->val;
//        }
//    };
//
//public:
//    int kthSmallest(TreeNode* root, int k) {
//        set<SortableNode> nodes;
//        collectNodes(root, nodes);
//        cout << "k: " << k << endl;
//        for (auto& a : nodes) {
//            cout << "   " << a.node->val << endl;
//        }
//
//        auto iter = nodes.begin();
//        while (k > 1) {
//            iter++;
//            k--;
//        }
//
//        return iter->node->val;
//    }
//
//    void collectNodes(TreeNode* current,
//                      set<SortableNode>& nodes) {
//        if (current == nullptr)
//            return;
//
//        nodes.insert({current});
//
//        collectNodes(current->left, nodes);
//        collectNodes(current->right, nodes);
//    }
//};


class Solution {
public:
    vector<string> generateParenthesis(int n) {
//        set<string> parentheses;
//
//        for (int i = 0; i < n; i++) {
//            parentheses = addOne(parentheses);
//        }
//
//        return vector<string>(parentheses.begin(), parentheses.end());

        vector<string> parentheses;
        generate(n, n, "", parentheses);

        return parentheses;
    }

    set<string> addOne(const set<string>& parentheses) {
        if (parentheses.empty())
            return {"()"};

        set<string> newParentheses;
        for (auto& str : parentheses) {
            for (int i = 0; i < str.length(); i++) {
                auto strWithLeft = str;
                strWithLeft.insert(i, "(");

                for (int j = i + 1; j < strWithLeft.length(); j++) {
                    auto strWithLeftRight = strWithLeft;
                    strWithLeftRight.insert(j, ")");

                    newParentheses.insert(strWithLeftRight);
                }
            }

            newParentheses.insert(str + "()");
        }

        return newParentheses;
    }

    void generate(int nLeft, int nRight,
                  const string& current,
                  vector<string>& parentheses) {
        if (nRight == 0) {
            parentheses.push_back(current);
            return;
        }

        if (nLeft > 0) {
            generate(nLeft - 1, nRight, current + "(", parentheses);
        }

        if (nRight > nLeft) {
            generate(nLeft, nRight - 1, current + ")", parentheses);
        }
    }
};

void testGetmntinfo() {
    struct statfs* stats = NULL;
    int num = getmntinfo(&stats, 0);
    for( int i = 0; i < num; i++ ) {
        cout << stats[i].f_mntfromname << " | " << stats[i].f_mntonname << endl;
    }
}

void testMask(vector<bool> mask, int index) {
    if (index == mask.size()) {
        for (auto a : mask) {
            cout << a << ' ';
        }
        cout << endl;
    }

    if (index >= mask.size())
        return;

    mask[index] = false;
    testMask(mask, index + 1);

    mask[index] = true;
    testMask(mask, index + 1);
}

size_t calcFactorial(size_t k) {
    if (k == 0)
        return 1;

    return k * calcFactorial(k - 1);
}

void testPermutation(vector<int> digits, vector<vector<int>>& fullPermutation, int x, int y) {
    auto digitsCount = digits.size();
    if (digitsCount == 0)
        return;

    if (digitsCount == 1) {
        fullPermutation[x][y] = digits[0];
        return;
    }

    auto loopCount = calcFactorial(digitsCount - 1);
    int row = x;

    for (auto i = 0; i < digits.size(); i++) {
        auto nextDigits = digits;
        nextDigits.erase(nextDigits.begin() + i);
        testPermutation(nextDigits, fullPermutation, row, y + 1);

        auto num = digits[i];
        for (auto j = 0; j < loopCount; j++) {
            fullPermutation[row][y] = num;
            row++;
        }
    }
}

size_t c_n_r(size_t n, size_t r) {
    return calcFactorial(n) / (calcFactorial(r) * calcFactorial(n - r));
}

void testPickup(vector<int> digits, vector<vector<int>>& sequences, size_t n) {
    if (n == 0)
        return;

    auto digitsCount = digits.size();
    if (digitsCount == 0)
        return;

    auto loopCount = c_n_r(digitsCount - 1, n - 1);

    for (auto i = 0; i < digits.size(); i++) {
        auto nextDigits = digits;
        nextDigits.erase(nextDigits.begin() + i);
        testPickup(nextDigits, sequences, n - 1);
    }

    for (auto i = 0; i < sequences.size(); i++) {
        auto digitsIndex = i % loopCount;
        auto num = digits[digitsIndex];

        sequences[i].push_back(num);
    }
}

vector<vector<int>> testSubsets(vector<int>& nums) {
    vector<vector<int>> results({{}});
    for (auto i = 0; i <= nums.size(); i++) {
        auto arrangement = Arrangement::CreateAsCombination(nums.size(), i);

        for (auto& indexes : arrangement->Values()) {
            vector<int> subNums;
            for (auto index : indexes) {
                subNums.push_back(nums[index]);
            }
            results.push_back(subNums);
        }
    }

    return results;
}

int main(int argc, const char * argv[]) {
//    cout << Solution().findLongestCommonSubstring("abbc", "aabbabbc") << endl;
//    cout << Solution().longestPalindrome("babadada") << endl;
//    cout << Solution().longestPalindrome("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc") << endl;

//    testGetmntinfo();

//    auto root = new TreeNode(1);
//    root->right = new TreeNode(2);
//
//    cout << Solution().kthSmallest(root, 2) << endl;

//    Solution().generateParenthesis(4);

//    vector<bool> mask {false, false, false, false};
//    testMask(mask, 0);

//    vector<int> nums {1, 2, 3};

//    auto factorial = calcFactorial(nums.size());
//    vector<vector<int>> fullPermutation(factorial, vector<int>(nums.size(), 0));
//
//    testPermutation(nums, fullPermutation, 0, 0);
//
//    for (auto& oneRow : fullPermutation) {
//        for (auto val : oneRow) {
//            cout << val << ",";
//        }
//        cout << endl;
//    }

//    vector<vector<int>> allSequences;
//    for (auto n = nums.size(); n > 0; n--) {
//        auto count = c_n_r(nums.size(), n);
//        vector<vector<int>> sequences(count, vector<int>());
//
//        testPickup(nums, sequences, n);
//        allSequences.insert(allSequences.end(), sequences.begin(), sequences.end());
//    }
//
//    for (auto& oneRow : allSequences) {
//        for (auto val : oneRow) {
//            cout << val << ",";
//        }
//        cout << endl;
//    }

//    auto arrangement = Arrangement::CreateAsPermutation(3, 0);
//    auto arrangement = Arrangement::CreateAsCombination(5, 3);
//    arrangement->Print();

//    cout << Arrangement::Permutation(5, 3) << endl;
//    cout << Arrangement::Combination(5, 3) << endl;

//    vector<int> nums {1, 2, 3};
//    auto values = testSubsets(nums);
//
//    for (auto& oneRow : values) {
//        for (auto val : oneRow) {
//            cout << val << ",";
//        }
//        cout << endl;
//    }

//    CharBoard board({
//        {'A','B','C','E'},
//        {'S','F','C','S'},
//        {'A','D','E','E'}
//    });
//
//    cout << board.Exist("ABCCED") << endl;
//    cout << board.Exist("SEE") << endl;
//    cout << board.Exist("ABCB") << endl;

//    CharBoard board2({
//        {'A'}
//    });
//
//    cout << board2.Exist("A") << endl;

    // Init an empty set.
    RandomizedSet randomSet;

//    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
//    cout << "1, " << randomSet.insert(1) << endl;
//
//    // Returns false as 2 does not exist in the set.
//    cout << "0, " << randomSet.remove(2) << endl;
//
//    // Inserts 2 to the set, returns true. Set now contains [1,2].
//    cout << "1, " << randomSet.insert(2) << endl;
//
//    // getRandom should return either 1 or 2 randomly.
//    cout << "1/2, " << randomSet.getRandom() << endl;
//
//    // Removes 1 from the set, returns true. Set now contains [2].
//    cout << "1, " << randomSet.remove(1) << endl;
//
//    // 2 was already in the set, so return false.
//    cout << "0, " << randomSet.insert(2) << endl;
//
//    // Since 2 is the only number in the set, getRandom always return 2.
//    cout << "2, " << randomSet.getRandom() << endl;

    /*
     insert: 3
     insert: -2
     remove: 2
     insert: 1
     insert: -3
     insert: -2
     remove: -2
     remove: 3
     insert: -1
     remove: -3
     insert: 1
     insert: -2
     insert: -2
     insert: -2
     insert: 1
     4,5
     -1,-2,1,
     */

//    cout << "remove 0, " << std::boolalpha << randomSet.remove(0) << ":    " << randomSet.toString() << endl;
//    cout << "remove 0, " << std::boolalpha << randomSet.remove(0) << ":    " << randomSet.toString() << endl;
//    cout << "insert 0, " << std::boolalpha << randomSet.insert(0) << ":    " << randomSet.toString() << endl;
//    cout << "remove 0, " << std::boolalpha << randomSet.remove(0) << ":    " << randomSet.toString() << endl;
//    cout << "insert 0, " << std::boolalpha << randomSet.insert(0) << ":    " << randomSet.toString() << endl;

//    cout << "insert 3, " << std::boolalpha << randomSet.insert(3) << ":    " << randomSet.toString() << endl;
//    cout << "insert -2, " << std::boolalpha << randomSet.insert(-2) << ":    " << randomSet.toString() << endl;
//    cout << "remove 2, " << std::boolalpha << randomSet.remove(2) << ":    " << randomSet.toString() << endl;
//    cout << "insert 1, " << std::boolalpha << randomSet.insert(1) << ":    " << randomSet.toString() << endl;
//    cout << "insert -3, " << std::boolalpha << randomSet.insert(-3) << ":    " << randomSet.toString() << endl;
//    cout << "insert -2, " << std::boolalpha << randomSet.insert(-2) << ":    " << randomSet.toString() << endl;
//    cout << "remove -2, " << std::boolalpha << randomSet.remove(-2) << ":    " << randomSet.toString() << endl;
//    cout << "remove 3, " << std::boolalpha << randomSet.remove(3) << ":    " << randomSet.toString() << endl;
//    cout << "insert -1, " << std::boolalpha << randomSet.insert(-1) << ":    " << randomSet.toString() << endl;
//    cout << "remove -3, " << std::boolalpha << randomSet.remove(-3) << ":    " << randomSet.toString() << endl;
//    cout << "insert 1, " << std::boolalpha << randomSet.insert(1) << ":    " << randomSet.toString() << endl;
//    cout << "insert -2, " << std::boolalpha << randomSet.insert(-2) << ":    " << randomSet.toString() << endl;
//    cout << "insert -2, " << std::boolalpha << randomSet.insert(-2) << ":    " << randomSet.toString() << endl;
//    cout << "insert -2, " << std::boolalpha << randomSet.insert(-2) << ":    " << randomSet.toString() << endl;
//    cout << "insert 1, " << std::boolalpha << randomSet.insert(1) << ":    " << randomSet.toString() << endl;
//    cout << randomSet.getRandom() << endl;

//    auto rpn = ReversePolishNotation::Create({"2", "1", "+", "3", "*"});
//    cout << rpn.Calculate() << endl;
//
//    rpn = ReversePolishNotation::Create({"4", "13", "5", "/", "+"});
//    cout << rpn.Calculate() << endl;

//    TaskScheduler ts({'G','C','A','H','A','G','G','F','G','J','H','C','A','G','E','A','H','E','F','D','B','D','H','H','E','G','F','B','C','G','F','H','J','F','A','C','G','D','I','J','A','G','D','F','B','F','H','I','G','J','G','H','F','E','H','J','C','E','H','F','C','E','F','H','H','I','G','A','G','D','C','B','I','D','B','C','J','I','B','G','C','H','D','I','A','B','A','J','C','E','B','F','B','J','J','D','D','H','I','I','B','A','E','H','J','J','A','J','E','H','G','B','F','C','H','C','B','J','B','A','H','B','D','I','F','A','E','J','H','C','E','G','F','G','B','G','C','G','A','H','E','F','H','F','C','G','B','I','E','B','J','D','B','B','G','C','A','J','B','J','J','F','J','C','A','G','J','E','G','J','C','D','D','A','I','A','J','F','H','J','D','D','D','C','E','D','D','F','B','A','J','D','I','H','B','A','F','E','B','J','A','H','D','E','I','B','H','C','C','C','G','C','B','E','A','G','H','H','A','I','A','B','A','D','A','I','E','C','C','D','A','B','H','D','E','C','A','H','B','I','A','B','E','H','C','B','A','D','H','E','J','B','J','A','B','G','J','J','F','F','H','I','A','H','F','C','H','D','H','C','C','E','I','G','J','H','D','E','I','J','C','C','H','J','C','G','I','E','D','E','H','J','A','H','D','A','B','F','I','F','J','J','H','D','I','C','G','J','C','C','D','B','E','B','E','B','G','B','A','C','F','E','H','B','D','C','H','F','A','I','A','E','J','F','A','E','B','I','G','H','D','B','F','D','B','I','B','E','D','I','D','F','A','E','H','B','I','G','F','D','E','B','E','C','C','C','J','J','C','H','I','B','H','F','H','F','D','J','D','D','H','H','C','D','A','J','D','F','D','G','B','I','F','J','J','C','C','I','F','G','F','C','E','G','E','F','D','A','I','I','H','G','H','H','A','J','D','J','G','F','G','E','E','A','H','B','G','A','J','J','E','I','H','A','G','E','C','D','I','B','E','A','G','A','C','E','B','J','C','B','A','D','J','E','J','I','F','F','C','B','I','H','C','F','B','C','G','D','A','A','B','F','C','D','B','I','I','H','H','J','A','F','J','F','J','F','H','G','F','D','J','G','I','E','B','C','G','I','F','F','J','H','H','G','A','A','J','C','G','F','B','A','A','E','E','A','E','I','G','F','D','B','I','F','A','B','J','F','F','J','B','F','J','F','J','F','I','E','J','H','D','G','G','D','F','G','B','J','F','J','A','J','E','G','H','I','E','G','D','I','B','D','J','A','A','G','A','I','I','A','A','I','I','H','E','C','A','G','I','F','F','C','D','J','J','I','A','A','F','C','J','G','C','C','H','E','A','H','F','B','J','G','I','A','A','H','G','B','E','G','D','I','C','G','J','C','C','I','H','B','D','J','H','B','J','H','B','F','J','E','J','A','G','H','B','E','H','B','F','F','H','E','B','E','G','H','J','G','J','B','H','C','H','A','A','B','E','I','H','B','I','D','J','J','C','D','G','I','J','G','J','D','F','J','E','F','D','E','B','D','B','C','B','B','C','C','I','F','D','E','I','G','G','I','B','H','G','J','A','A','H','I','I','H','A','I','F','C','D','A','C','G','E','G','E','E','H','D','C','G','D','I','A','G','G','D','A','H','H','I','F','E','I','A','D','H','B','B','G','I','C','G','B','I','I','D','F','F','C','C','A','I','E','A','E','J','A','H','C','D','A','C','B','G','H','G','J','G','I','H','B','A','C','H','I','D','D','C','F','G','B','H','E','B','B','H','C','B','G','G','C','F','B','E','J','B','B','I','D','H','D','I','I','A','A','H','G','F','B','J','F','D','E','G','F','A','G','G','D','A','B','B','B','J','A','F','H','H','D','C','J','I','A','H','G','C','J','I','F','J','C','A','E','C','H','J','H','H','F','G','E','A','C','F','J','H','D','G','G','D','D','C','B','H','B','C','E','F','B','D','J','H','J','J','J','A','F','F','D','E','F','C','I','B','H','H','D','E','A','I','A','B','F','G','F','F','I','E','E','G','A','I','D','F','C','H','E','C','G','H','F','F','H','J','H','G','A','E','H','B','G','G','D','D','D','F','I','A','F','F','D','E','H','J','E','D','D','A','J','F','E','E','E','F','I','D','A','F','F','J','E','I','J','D','D','G','A','C','G','G','I','E','G','E','H','E','D','E','J','B','G','I','J','C','H','C','C','A','A','B','C','G','B','D','I','D','E','H','J','J','B','F','E','J','H','H','I','G','B','D'});
//    cout << ts.leastInterval(1) << endl;

//    std::string S = "cba";
//    std::string T = "abcd";
//    CustomSortString sorter(S);
//    cout << S << endl << T << endl << sorter.sort(T) << endl;

//    FindSubString().test();
    
//    RightReference a("");
//    a.test();

    Math().test();

    return 0;
}
