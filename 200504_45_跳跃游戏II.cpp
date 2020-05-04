// 45. 跳跃游戏 II
// 给定一个非负整数数组，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。

// 示例:

// 输入: [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 说明:

// 假设你总是可以到达数组的最后一个位置。

// https://leetcode-cn.com/problems/jump-game-ii/



//My Codes
// 执行结果：通过
// 执行用时 :8 ms, 在所有 C++ 提交中击败了94.56%的用户
// 内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int jump(vector<int>& nums) {
        //贪心，局部最优搞到全局最优
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0, last = 0; i < n; i++) {
            if (!i) f[i] = 0;
            else {
                // 找到第一个能跳到i的点last
                while (last < n && last + nums[last] < i) last++;
                // 使用点last更新f[i]
                f[i] = f[last] + 1; 
                
            }
        }
        return f[n - 1];
    }
};

//nice codes:
// 方法二：正向查找可到达的最大位置
// 方法一虽然直观，但是时间复杂度比较高，有没有办法降低时间复杂度呢？

// 如果我们「贪心」地进行正向查找，每次找到可到达的最远位置，就可以在线性时间内得到最少的跳跃次数。

// 例如，对于数组 [2,3,1,2,4,2,3]，初始位置是下标 0，从下标 0 出发，最远可到达下标 2。下标 0 可到达的位置中，下标 1 的值是 3，从下标 1 出发可以达到更远的位置，因此第一步到达下标 1。

// 从下标 1 出发，最远可到达下标 4。下标 1 可到达的位置中，下标 4 的值是 4 ，从下标 4 出发可以达到更远的位置，因此第二步到达下标 4。



// 在具体的实现中，我们维护当前能够到达的最大下标位置，记为边界。我们从左到右遍历数组，到达边界时，更新边界并将跳跃次数增加 1。

// 在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。如果访问最后一个元素，在边界正好为最后一个位置的情况下，我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。

// JavaC++Python3Golang
// class Solution {
//     public int jump(int[] nums) {
//         int length = nums.length;
//         int end = 0;
//         int maxPosition = 0; 
//         int steps = 0;
//         for (int i = 0; i < length - 1; i++) {
//             maxPosition = Math.max(maxPosition, i + nums[i]); 
//             if (i == end) {
//                 end = maxPosition;
//                 steps++;
//             }
//         }
//         return steps;
//     }
// }
// 复杂度分析

// 时间复杂度：O(n)O(n)，其中 nn 是数组长度。

// 空间复杂度：O(1)O(1)。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。