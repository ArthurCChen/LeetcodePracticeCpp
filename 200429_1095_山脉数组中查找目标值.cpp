// 1095. 山脉数组中查找目标值
// （这是一个 交互式问题 ）

// 给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 等于 target 最小 的下标 index 值。

// 如果不存在这样的下标 index，就请返回 -1。

 

// 何为山脉数组？如果数组 A 是一个山脉数组的话，那它满足如下条件：

// 首先，A.length >= 3

// 其次，在 0 < i < A.length - 1 条件下，存在 i 使得：

// A[0] < A[1] < ... A[i-1] < A[i]
// A[i] > A[i+1] > ... > A[A.length - 1]
 

// 你将 不能直接访问该山脉数组，必须通过 MountainArray 接口来获取数据：

// MountainArray.get(k) - 会返回数组中索引为k 的元素（下标从 0 开始）
// MountainArray.length() - 会返回该数组的长度
 

// 注意：

// 对 MountainArray.get 发起超过 100 次调用的提交将被视为错误答案。此外，任何试图规避判题系统的解决方案都将会导致比赛资格被取消。

// 为了帮助大家更好地理解交互式问题，我们准备了一个样例 “答案”：https://leetcode-cn.com/playground/RKhe3ave，请注意这 不是一个正确答案。

 

// 示例 1：

// 输入：array = [1,2,3,4,5,3,1], target = 3
// 输出：2
// 解释：3 在数组中出现了两次，下标分别为 2 和 5，我们返回最小的下标 2。
// 示例 2：

// 输入：array = [0,1,2,4,2,1], target = 3
// 输出：-1
// 解释：3 在数组中没有出现，返回 -1。
 

// 提示：

// 3 <= mountain_arr.length() <= 10000
// 0 <= target <= 10^9
// 0 <= mountain_arr.get(index) <= 10^9


//My Codes
// 执行结果：通过
// 执行用时 :4 ms, 在所有 C++ 提交中击败了80.04%的用户
// 内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// My Codes
// 执行结果：通过
// 执行用时 :8 ms, 在所有 C++ 提交中击败了66.67%的用户
// 内存消耗 :7 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak;
        int left = 0;
        int right = mountainArr.length();
        int mid = mountainArr.length() >> 1;
        while(right - left > 1){
            if(mountainArr.get(mid - 1) < mountainArr.get(mid)){
                left = mid;
            }
            else{
                right = mid;
            }
            mid = (left + right) >> 1;
        }
        peak = left;
        int pos = halfSearch(mountainArr, 0, peak+1, target); 
         return pos>=0?pos:halfSearch(mountainArr, mountainArr.length()-1, peak, target); 

    }
    int halfSearch(MountainArray &m, int lo, int hi, int target){
        for(int mi=(lo+hi)>>1; abs(hi-lo)>1; mi=(lo+hi)>>1)
            if(target < m.get(mi)) hi=mi;
            else lo=mi;
        return m.get(lo)==target?lo:-1;
    }
};


//nice codes:
// 1.找山峰双百
// class Solution {
// public:
//     int findPeak(MountainArray &mountainArr){
//         int n = mountainArr.length();
//         int left = 0,right = n - 1;
//         while(left <= right){
//             int mid = left + (right - left) / 2;
//             int x = mountainArr.get(mid);
//             if(x > mountainArr.get(mid + 1))
//                 right = mid - 1;
//             else
//                 left = mid + 1;  
//         }
//         return left;
//     }
//     int findInMountainArray(int target, MountainArray &mountainArr) {
//         int peak = findPeak(mountainArr);
//         int n = mountainArr.length();
//         int left = 0,right = peak;
//         while(left <= right){
//             int mid = left + (right - left) / 2;
//             int x = mountainArr.get(mid);
//             if(target == x) return mid;
//             if(target < x)
//                 right = mid - 1;
//             else
//                 left = mid + 1;  
//         }
//         left = peak, right = n - 1;
//         while(left <= right){
//             int mid = left + (right - left) / 2;

// 作者：django-r
// 链接：https://leetcode-cn.com/problems/find-in-mountain-array/solution/shuang-bai-san-ci-er-fen-cha-zhao-by-django-r/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//2.不先找山峰
// class Solution {
// public:
//     int findArr(int target, MountainArray &mountainArr, int head, int tail) {
//         int tmpAns, ans = INT_MAX, len = mountainArr.length();
//         if(head < tail) {
//             int mid = ( head + tail ) / 2;
//             int midArr = mountainArr.get(mid), midArr1 = -1;
//             if(midArr == target) {   
//                 midArr1 = mountainArr.get(mid + 1);
//                 if(midArr < midArr1)   // 此时正在上坡，则找到最小索引
//                     return ans < mid ? ans : mid;
//                 else {  // 如果正在下坡，则暂存ans，并向前继续寻找
//                     ans = mid;
//                     tail = mid;
//                     mid = ( head + tail ) / 2;
//                     midArr = mountainArr.get(mid);
//                 }
//             }
//             midArr1 = mountainArr.get(mid+1);
//             if(target > midArr) {      // 如果目标在中间
//                 if( midArr > midArr1) tail = mid - 1; // 上坡  
//                 else head = mid + 1;                  // 下坡
//                 tmpAns = findArr(target, mountainArr, head, tail);
//                 if(tmpAns != -1 && tmpAns < ans)
//                     ans = tmpAns;
//             }
//             else {    // 如果目标在两侧
//                 tmpAns = findArr(target, mountainArr, head, mid-1);
//                 if(tmpAns != -1 && tmpAns < ans)
//                     return tmpAns;
//                 tmpAns = findArr(target, mountainArr, mid+1, tail);
//                 if(tmpAns != -1 && tmpAns <= ans)
//                     ans = tmpAns;
//             }
//         }
//         if( mountainArr.get(head) == target)
//             return head < ans ? head : ans;
//         return ans != INT_MAX ? ans : -1;        
//     }
    
//     int findInMountainArray(int target, MountainArray &mountainArr) {
//         return findArr(target, mountainArr, 0, mountainArr.length()-1);
//     }
// };

// 作者：ymb123
// 链接：https://leetcode-cn.com/problems/find-in-mountain-array/solution/bu-zhao-feng-de-er-fen-cha-zhao-by-ymb123/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。