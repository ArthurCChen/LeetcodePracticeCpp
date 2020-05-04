// 53. 最大子序和
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 进阶:

// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

// 通过次数229,425提交次数450,274

// https://leetcode-cn.com/problems/maximum-subarray/



//My Codes
// 执行结果：通过
// 执行用时 :4 ms, 在所有 C++ 提交中击败了97.65%的用户
// 内存消耗 :7.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //动态规划
        for(int i=1;i<nums.size();i++){
            nums[i] = max(nums[i], nums[i] + nums[i-1]);
            nums[0] = max(nums[0], nums[i]);
        }
        return nums[0];

    }
};

//nice codes:
// 1. 动规
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int pre = 0, maxAns = nums[0];
//         for (const auto &x: nums) {
//             pre = max(pre + x, x);
//             maxAns = max(maxAns, pre);
//         }
//         return maxAns;
//     }
// };


// 2.方法二：分治
// 思路和算法

// 这个分治方法类似于「线段树求解 LCIS 问题」的 pushUp 操作。 
// 也许读者还没有接触过线段树，没有关系，方法二的内容假设你没有任何线段树的基础。
// 当然，如果读者有兴趣的话，推荐看一看
// 线段树区间合并法解决 多次询问 的「区间最长连续上升序列问题」和「区间最大子段和问题」，还是非常有趣的。
// class Solution {
// public:
//     struct Status {
//         int lSum, rSum, mSum, iSum;
//     };

//     Status pushUp(Status l, Status r) {
//         int iSum = l.iSum + r.iSum;
//         int lSum = max(l.lSum, l.iSum + r.lSum);
//         int rSum = max(r.rSum, r.iSum + l.rSum);
//         int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
//         return (Status) {lSum, rSum, mSum, iSum};
//     };

//     Status get(vector<int> &a, int l, int r) {
//         if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
//         int m = (l + r) >> 1;
//         Status lSub = get(a, l, m);
//         Status rSub = get(a, m + 1, r);
//         return pushUp(lSub, rSub);
//     }

//     int maxSubArray(vector<int>& nums) {
//         return get(nums, 0, nums.size() - 1).mSum;
//     }
// };
// 复杂度分析

// 假设序列 aa 的长度为 nn。

// 时间复杂度：假设我们把递归的过程看作是一颗二叉树的先序遍历，那么这颗二叉树的深度的渐进上界为 O(\log n)O(logn)，这里的总时间相当于遍历这颗二叉树的所有节点，故总时间的渐进上界是 O(\sum_{i = 1}^{\log n} 2^{i - 1}) = O(n)O(∑ 
// i=1
// logn

//  2 
// i−1
//  )=O(n)，故渐进时间复杂度为 O(n)O(n)。
// 空间复杂度：递归会使用 O(\log n)O(logn) 的栈空间，故渐进空间复杂度为 O(\log n)O(logn)。
// 题外话
// 「方法二」相较于「方法一」来说，时间复杂度相同，但是因为使用了递归，并且维护了四个信息的结构体，运行的时间略长，空间复杂度也不如方法一优秀，而且难以理解。那么这种方法存在的意义是什么呢？

// 对于这道题而言，确实是如此的。但是仔细观察「方法二」，它不仅可以解决区间 [0, n - 1][0,n−1]，还可以用于解决任意的子区间 [l, r][l,r] 的问题。如果我们把 [0, n - 1][0,n−1] 分治下去出现的所有子区间的信息都用堆式存储的方式记忆化下来，即建成一颗真正的树之后，我们就可以在 O(\log n)O(logn) 的时间内求到任意区间内的答案，我们甚至可以修改序列中的值，做一些简单的维护，之后仍然可以在 O(\log n)O(logn) 的时间内求到任意区间内的答案，对于大规模查询的情况下，这种方法的优势便体现了出来。这棵树就是上文提及的一种神奇的数据结构——线段树。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。