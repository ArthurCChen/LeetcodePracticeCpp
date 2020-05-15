// 136. 只出现一次的数字
// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 说明：

// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// 示例 1:

// 输入: [2,2,1]
// 输出: 1
// 示例 2:

// 输入: [4,1,2,1,2]
// 输出: 4

// https://leetcode-cn.com/problems/single-number/



//My Codes
// 执行结果：通过
// 执行用时 :20 ms, 在所有 C++ 提交中击败了64.65%的用户
// 内存消耗 :11.7 MB, 在所有 C++ 提交中击败了5.88%的用户
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i:nums)
            res ^= i;
        return res;
    }
};

//nice codes:

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ret = 0;
//         for (auto e: nums) ret ^= e;
//         return ret;
//     }
// };
// 复杂度分析

// 时间复杂度：O(n)O(n)，其中 nn 是数组长度。只需要对数组遍历一次。

// 空间复杂度：O(1)O(1)。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/single-number/solution/zhi-chu-xian-yi-ci-de-shu-zi-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。