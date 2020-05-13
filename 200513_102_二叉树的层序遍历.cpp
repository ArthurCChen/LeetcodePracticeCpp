// 102. 二叉树的层序遍历
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

// 示例：
// 二叉树：[3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回其层次遍历结果：

// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/



//My Codes
// 执行结果：通过
// 执行用时 :4 ms, 在所有 C++ 提交中击败了88.13%的用户
// 内存消耗 :11.9 MB, 在所有 C++ 提交中击败了100.00%的用户
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        while (que.size() != 0) {
            int size = que.size();
            vector<int> level;
            while (size --) {
                TreeNode* cur = que.front();
                que.pop();
                if (!cur) {
                    continue;
                }
                level.push_back(cur->val);
                que.push(cur->left);
                que.push(cur->right);
            }
            if (level.size() != 0) {
                res.push_back(level);
            }
        }
        return res;
    }
};

//nice codes:
// 如何遍历一棵树
// 有两种通用的遍历树的策略：

// 深度优先搜索（DFS）

// 在这个策略中，我们采用深度作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。

// 深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为先序遍历，中序遍历和后序遍历。

// 宽度优先搜索（BFS）

// 我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。

// 下图中的顶点按照访问的顺序编号，按照 1-2-3-4-5 的顺序来比较不同的策略。



// 本问题就是用宽度优先搜索遍历来划分层次：[[1], [2, 3], [4, 5]]。

// 方法 1：递归
// 算法

// 最简单的解法就是递归，首先确认树非空，然后调用递归函数 helper(node, level)，参数是当前节点和节点的层次。程序过程如下：

// 输出列表称为 levels，当前最高层数就是列表的长度 len(levels)。比较访问节点所在的层次 level 和当前最高层次 len(levels) 的大小，如果前者更大就向 levels 添加一个空列表。
// 将当前节点插入到对应层的列表 levels[level] 中。
// 递归非空的孩子节点：helper(node.left / node.right, level + 1)。
// 实现


// 1 / 15

// PythonJava
// class Solution:
//     def levelOrder(self, root):
//         """
//         :type root: TreeNode
//         :rtype: List[List[int]]
//         """
//         levels = []
//         if not root:
//             return levels
        
//         def helper(node, level):
//             # start the current level
//             if len(levels) == level:
//                 levels.append([])

//             # append the current node value
//             levels[level].append(node.val)

//             # process child nodes for the next level
//             if node.left:
//                 helper(node.left, level + 1)
//             if node.right:
//                 helper(node.right, level + 1)
            
//         helper(root, 0)
//         return levels
// 复杂度分析

// 时间复杂度：O(N)O(N)，因为每个节点恰好会被运算一次。
// 空间复杂度：O(N)O(N)，保存输出结果的数组包含 N 个节点的值。
// 方法 2：迭代
// 算法

// 上面的递归方法也可以写成迭代的形式。

// 我们将树上顶点按照层次依次放入队列结构中，队列中元素满足 FIFO（先进先出）的原则。在 Java 中可以使用 Queue 接口中的 LinkedList实现。在 Python 中如果使用 Queue 结构，但因为它是为多线程之间安全交换而设计的，所以使用了锁，会导致性能不佳。因此在 Python 中可以使用 deque 的 append() 和 popleft() 函数来快速实现队列的功能。

// 第 0 层只包含根节点 root ，算法实现如下：

// 初始化队列只包含一个节点 root 和层次编号 0 ： level = 0。
// 当队列非空的时候：
// 在输出结果 levels 中插入一个空列表，开始当前层的算法。
// 计算当前层有多少个元素：等于队列的长度。
// 将这些元素从队列中弹出，并加入 levels 当前层的空列表中。
// 将他们的孩子节点作为下一层压入队列中。
// 进入下一层 level++。
// 实现

// PythonJava
// from collections import deque
// class Solution:
//     def levelOrder(self, root):
//         """
//         :type root: TreeNode
//         :rtype: List[List[int]]
//         """
//         levels = []
//         if not root:
//             return levels
        
//         level = 0
//         queue = deque([root,])
//         while queue:
//             # start the current level
//             levels.append([])
//             # number of elements in the current level 
//             level_length = len(queue)
            
//             for i in range(level_length):
//                 node = queue.popleft()
//                 # fulfill the current level
//                 levels[level].append(node.val)
                
//                 # add child nodes of the current level
//                 # in the queue for the next level
//                 if node.left:
//                     queue.append(node.left)
//                 if node.right:
//                     queue.append(node.right)
            
//             # go to next level
//             level += 1
        
//         return levels
// 复杂度分析

// 时间复杂度：O(N)O(N)，因为每个节点恰好会被运算一次。
// 空间复杂度：O(N)O(N)，保存输出结果的数组包含 N 个节点的值。

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-de-ceng-ci-bian-li-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 套模板！BFS 和 DFS 都可以解决
// 负雪明烛
// 发布于 1 天前
// 3.1k
// 本题是让我们把二叉树的每一层节点放入到同一个列表中，最后返回各层的列表组成的总的列表。

// 可以使用 BFS 和 DFS 解决。

// 左边是BFS，按照层进行搜索；图右边是DFS，先一路走到底，然后再回头搜索。

// BFS-and-DFS-Algorithms.png

// BFS
// BFS使用队列，把每个还没有搜索到的点依次放入队列，然后再弹出队列的头部元素当做当前遍历点。BFS总共有两个模板：

// 如果不需要确定当前遍历到了哪一层，BFS模板如下。
// while queue 不空：
//     cur = queue.pop()
//     for 节点 in cur的所有相邻节点：
//         if 该节点有效且未访问过：
//             queue.push(该节点)
// 如果要确定当前遍历到了哪一层，BFS模板如下。
// 这里增加了level表示当前遍历到二叉树中的哪一层了，也可以理解为在一个图中，现在已经走了多少步了。size表示在当前遍历层有多少个元素，也就是队列中的元素数，我们把这些元素一次性遍历完，即把当前层的所有元素都向外走了一步。
// level = 0
// while queue 不空：
//     size = queue.size()
//     while (size --) {
//         cur = queue.pop()
//         for 节点 in cur的所有相邻节点：
//             if 该节点有效且未被访问过：
//                 queue.push(该节点)
//     }
//     level ++;
// 上面两个是通用模板，在任何题目中都可以用，是要记住的！

// 本题要求二叉树的层次遍历，所以同一层的节点应该放在一起，故使用模板二。

// 使用队列保存每层的所有节点，每次把队列里的原先所有节点进行出队列操作，再把每个元素的非空左右子节点进入队列。因此即可得到每层的遍历。

// 各语言的代码如下：

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         queue<TreeNode*> que;
//         que.push(root);
//         vector<vector<int>> res;
//         while (que.size() != 0) {
//             int size = que.size();
//             vector<int> level;
//             while (size --) {
//                 TreeNode* cur = que.front();
//                 que.pop();
//                 if (!cur) {
//                     continue;
//                 }
//                 level.push_back(cur->val);
//                 que.push(cur->left);
//                 que.push(cur->right);
//             }
//             if (level.size() != 0) {
//                 res.push_back(level);
//             }
//         }
//         return res;
//     }
// };
// DFS
// 本题使用 DFS 同样能做。由于题目要求每一层的节点都是从左到右遍历，因此递归时也要先递归左子树、再递归右子树。

// DFS 做本题的主要问题是： DFS 不是按照层次遍历的。为了让递归的过程中同一层的节点放到同一个列表中，在递归时要记录每个节点的深度 level。递归到新节点要把该节点放入 level 对应列表的末尾。

// 当遍历到一个新的深度 level，而最终结果 res 中还没有创建 level 对应的列表时，应该在 res 中新建一个列表用来保存该 level 的所有节点。

// 各语言的代码如下：

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         dfs(res, root, 0);
//         return res;
//     }
//     void dfs(vector<vector<int>>& res, TreeNode* root, int level) {
//         if (!root) return;
//         if (level >= res.size())
//             res.push_back(vector<int>());
//         res[level].push_back(root->val);
//         dfs(res, root->left, level + 1);
//         dfs(res, root->right, level + 1);
//     }
// };
// 欢迎关注负雪明烛的刷题博客，刷题800多，每道都记录了写法！目前访问量已经100多万次！
// 送大家刷题模板和套路总结：【LeetCode】代码模板，刷题必会
// 力扣每日一题打卡群，大家一起监督力扣刷题：https://ojeveryday.com/