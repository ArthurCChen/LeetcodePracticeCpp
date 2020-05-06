// 983. 最低票价
// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

// 火车票有三种不同的销售方式：

// 一张为期一天的通行证售价为 costs[0] 美元；
// 一张为期七天的通行证售价为 costs[1] 美元；
// 一张为期三十天的通行证售价为 costs[2] 美元。
// 通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

// 返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

 

// 示例 1：

// 输入：days = [1,4,6,7,8,20], costs = [2,7,15]
// 输出：11
// 解释： 
// 例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
// 在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
// 在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
// 在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
// 你总共花了 $11，并完成了你计划的每一天旅行。
// 示例 2：

// 输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
// 输出：17
// 解释：
// 例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划： 
// 在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
// 在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。 
// 你总共花了 $17，并完成了你计划的每一天旅行。
 

// 提示：

// 1 <= days.length <= 365
// 1 <= days[i] <= 365
// days 按顺序严格递增
// costs.length == 3
// 1 <= costs[i] <= 1000

// https://leetcode-cn.com/problems/validate-binary-search-tree/



//My Codes
// 执行结果：通过
// 执行用时 :16 ms, 在所有 C++ 提交中击败了75.10%的用户
// 内存消耗 :18.2 MB, 在所有 C++ 提交中击败了100.00%的用户
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        TreeNode *last = NULL;
        return isValidBST(root, last);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* &last)
    { 
        if(!root) return true;
        if(!isValidBST(root->left, last) || (last && last->val >= root->val)) 
            return false;
        last = root;                          
        return isValidBST(root->right, last); 
    }
};


//nice codes:
// 方法一: 递归
// 思路和算法

// 要解决这道题首先我们要了解二叉搜索树有什么性质可以给我们利用，由题目给出的信息我们可以知道：如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；它的左右子树也为二叉搜索树。

// 这启示我们设计一个递归函数 helper(root, lower, upper) 来递归判断，函数表示考虑以 root 为根的子树，判断子树中所有节点的值是否都在 (l,r)(l,r) 的范围内（注意是开区间）。如果 root 节点的值 val 不在 (l,r)(l,r) 的范围内说明不满足条件直接返回，否则我们要继续递归调用检查它的左右子树是否满足，如果都满足才说明这是一棵二叉搜索树。

// 那么根据二叉搜索树的性质，在递归调用左子树时，我们需要把上界 upper 改为 root.val，即调用 helper(root.left, lower, root.val)，因为左子树里所有节点的值均小于它的根节点的值。同理递归调用右子树时，我们需要把下界 lower 改为 root.val，即调用 helper(root.right, root.val, upper)。

// 函数递归调用的入口为 helper(root, -inf, +inf)， inf 表示一个无穷大的值。

// 下图展示了算法如何应用在示例 2 上：


// 1 / 4

// C++
// class Solution {
// public:
//     bool helper(TreeNode* root, long long lower, long long upper) {
//         if (root == nullptr) return true;
//         if (root -> val <= lower || root -> val >= upper) return false;
//         return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
//     }
//     bool isValidBST(TreeNode* root) {
//         return helper(root, LONG_MIN, LONG_MAX);
//     }
// };
// 复杂度分析

// 时间复杂度 : O(n)O(n)，其中 nn 为二叉树的节点个数。在递归调用的时候二叉树的每个节点最多被访问一次，因此时间复杂度为 O(n)O(n)。

// 空间复杂度 : O(n)O(n)，其中 nn 为二叉树的节点个数。递归函数在递归过程中需要为每一层递归函数分配栈空间，所以这里需要额外的空间且该空间取决于递归的深度，即二叉树的高度。最坏情况下二叉树为一条链，树的高度为 nn ，递归最深达到 nn 层，故最坏情况下空间复杂度为 O(n)O(n) 。

// 方法二：中序遍历
// 思路和算法

// 基于方法一中提及的性质，我们可以进一步知道二叉搜索树「中序遍历」得到的值构成的序列一定是升序的，这启示我们在中序遍历的时候实时检查当前节点的值是否大于前一个中序遍历到的节点的值即可。如果均大于说明这个序列是升序的，整棵树是二叉搜索树，否则不是，下面的代码我们使用栈来模拟中序遍历的过程。

// 可能由读者不知道中序遍历是什么，我们这里简单提及一下，中序遍历是二叉树的一种遍历方式，它先遍历左子树，再遍历根节点，最后遍历右子树。而我们二叉搜索树保证了左子树的节点的值均小于根节点的值，根节点的值均小于右子树的值，因此中序遍历以后得到的序列一定是升序序列。



// C++
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         stack<TreeNode*> stack;
//         long long inorder = (long long)INT_MIN - 1;

//         while (!stack.empty() || root != nullptr) {
//             while (root != nullptr) {
//                 stack.push(root);
//                 root = root -> left;
//             }
//             root = stack.top();
//             stack.pop();
//             // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
//             if (root -> val <= inorder) return false;
//             inorder = root -> val;
//             root = root -> right;
//         }
//         return true;
//     }
// };
// 复杂度分析

// 时间复杂度 : O(n)O(n)，其中 nn 为二叉树的节点个数。二叉树的每个节点最多被访问一次，因此时间复杂度为 O(n)O(n)。

// 空间复杂度 : O(n)O(n)，其中 nn 为二叉树的节点个数。栈最多存储 nn 个节点，因此需要额外的 O(n)O(n) 的空间。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/validate-binary-search-tree/solution/yan-zheng-er-cha-sou-suo-shu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。