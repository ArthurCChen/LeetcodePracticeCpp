// 面试题56 - I. 数组中数字出现的次数

// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

// 示例 1：

// 输入：nums = [4,1,4,6]
// 输出：[1,6] 或 [6,1]

// 示例 2：

// 输入：nums = [1,2,10,4,1,4,3,3]
// 输出：[2,10] 或 [10,2]
 

// 限制：

// 2 <= nums <= 10000


//  &(按位与)、|(按位或)、^(按位异或)、~ (按位取反)。

//     其中，按位取反运算符是单目运算符，其余均为双目运算符。

//     位运算符的优先级从高到低，依次为~、&、^、|，

//     其中~的结合方向自右至左，且优先级高于算术运算符，其余运算符的结合方向都是自左至右，且优先级低于关系运算符。



//My Codes
// 执行结果：通过
// 执行用时 :36 ms, 在所有 C++ 提交中击败了64.01%的用户
// 内存消耗 :16.1 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        //O(n)意味着只能遍历一次
        //O(1)意味着空间与n无关
        //考虑按位异或运算，却不能直接找到
        //再考虑，直接异或后的结果，为1的位即是俩数那一位不同
        //取这样一位，按这一位为0/1分俩组
        //则俩数字各在一组，且所有对子都被分在一组
        int allxor = 0, div = 1;
        for(int i = 0; i< nums.size(); i++){
            allxor ^= nums[i];
        }
        while((allxor & div) == 0)
            div <<= 1;
        
        vector<int> finalPair(2,0);
        
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] & div){
                finalPair[0] ^= nums[i];
            }
            else{
                finalPair[1] ^= nums[i];
            }            
        }
        return finalPair;
    }
};



// ATTENTION！
// 1. for(int num:nums)是更好的循环遍历方法
// 2. int g1, g2, allxor = 0; 只赋值allxor,不赋值g1 g2




// Universal:

// 使用字典直接求只出现一次的数字即可。

// 时间复杂度是O(N), 空间复杂度是 O(N)。

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> count;
        for (int n : nums) count[n] ++;
        vector<int> res;
        for (auto p : count)
            if (p.second == 1)
                res.push_back(p.first);
        return res;
    }
};

// 作者：fuxuemingzhu
// 链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/zi-dian-vs-yi-huo-fu-li-kou-shua-ti-mo-ban-by-fuxu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 

//nice codes:
// class Solution {
// public:
//     //输入: [1,2,1,3,2,5]
//     //输出: [3,5]
//     vector<int> singleNumbers(vector<int>& nums) {
//         int s = 0;
//         for (int num : nums) {
//             s ^= num;
//         }
//         //s是只出现一次的2个数字的^ 记做数字a,b
//         //既然a,b 不一样，那么s肯定不是0，那么s的二进制肯定至少有1位（第n位）是1，只有0^1才等于1
//         //所以a,b 在第n位，要么a是0，b是1 ，要么b是0，a是1    ---->A
//         //s = 3 ^ 5; 0011 ^ 0101 = 0110 = 6
//         //假设int是8位
//         //-6  原码1000 0110
//         //    反码1111 1001
//         //    补码1111 1010
//         //s & (-s) 
//         //  0000 0110
//         //& 1111 1010
//         //  0000 0010
//         //所以k = s & (-s) 就是保留s的最后一个1，并且将其他位变为0  也就是s最后一个1是倒数第二位   --->B
//         //由于s & (-s)很方便找到一个1 所以用他了，其实找到任何一个1都可以
//         //根据A和B  我们可以确定 3 和 5 必定可以分到 不同的组里
//         //同理 1和1 由于二进制完全相同，所有必定分到相同的组里
//         //同理 2和2 由于二进制完全相同，所有必定分到相同的组里
//         int k = s & (-s);
//         //1  0001  第一组
//         //2  0010  第二组
//         //1  0001  第一组
//         //3  0011  第二组
//         //2  0010  第二组
//         //5  0101  第一组
//         //第一组 1 1 5  第二组 2 3 2 这样我们就将2个只有一个的数 分到了2个数组里了
//         vector<int> rs(2,0);
//         for(int num : nums){
//             if(num & k){
//                 //第二组
//                 rs[0] ^= num;
//             }else{
//                 //第一组
//                 rs[1] ^= num;
//             }
//         }
//         return rs;
//     }
// };

// 作者：chuang-bian-gu-shi
// 链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/c-0ms-chao-ji-xiang-xi-jie-shi-kan-bu-dong-de-ji-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。