// 680. 验证回文字符串 Ⅱ
// 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

// 示例 1:

// 输入: "aba"
// 输出: True
// 示例 2:

// 输入: "abca"
// 输出: True
// 解释: 你可以删除c字符。

// https://leetcode-cn.com/problems/valid-palindrome-ii/



//My Codes
// 执行结果：通过
// 执行用时 :28 ms, 在所有 C++ 提交中击败了33.95%的用户
// 内存消耗 :8.9 MB, 在所有 C++ 提交中击败了100.00%的用户
//首尾指针更可以优化
class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            }
            else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
            }
        }
        return true;
    }
};


//nice codes:

//暴力超时
// time O(n^2)
// space O(n)


//起码用两头贪心
//解法用到150.检验回文串