// 3. 无重复字符的最长子串
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

// 示例 1:

// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/



//My Codes
// 执行结果：通过
// 执行用时 :8 ms, 在所有 C++ 提交中击败了93.00%的用户
// 内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            const int MAX_CHARS = 256;
    int m[MAX_CHARS];
    memset(m, -1, sizeof(m));

    int maxLen = 0;
    int lastRepeatPos = -1;
    for(int i=0; i<s.size(); i++){
        if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if ( i - lastRepeatPos > maxLen ){
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
        
    }
};

//nice codes:
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         // 哈希集合，记录每个字符是否出现过
//         unordered_set<char> occ;
//         int n = s.size();
//         // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
//         int rk = -1, ans = 0;
//         // 枚举左指针的位置，初始值隐性地表示为 -1
//         for (int i = 0; i < n; ++i) {
//             if (i != 0) {
//                 // 左指针向右移动一格，移除一个字符
//                 occ.erase(s[i - 1]);
//             }
//             while (rk + 1 < n && !occ.count(s[rk + 1])) {
//                 // 不断地移动右指针
//                 occ.insert(s[rk + 1]);
//                 ++rk;
//             }
//             // 第 i 到 rk 个字符是一个极长的无重复字符子串
//             ans = max(ans, rk - i + 1);
//         }
//         return ans;
//     }
// };

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。