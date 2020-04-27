// 33. 搜索旋转排序数组
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

// 你可以假设数组中不存在重复的元素。

// 你的算法时间复杂度必须是 O(log n) 级别。

// 示例 1:

// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:

// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1

//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/


//My Codes
// 执行结果：通过
// 执行用时 :4 ms, 在所有 C++ 提交中击败了80.04%的用户
// 内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    int bs(vector<int>& nums, int target, int low, int high) {
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            target < nums[mid]? high = mid - 1: low = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;
        
        while(low <= high){
            int mid = (low + high)/2;
            //mid计算出来x.5时会向下取到x;
            cout << low << high;
            cout << mid << endl;
            if(nums[mid] == target)
                return mid;
            //目标比中间值小
            else if(nums[mid] > target){
                //图一型
                if(nums[mid] < nums[0]){
                    high = mid - 1;
                    continue;
                }
                //图二型
                else{
                    //在左端
                    if(target >= nums[0]){
                        high = mid - 1;
                        return bs(nums, target, low, high);
                    }
                    //在右端右部
                    else{
                        low = mid + 1;
                        continue;
                    }
                }
            }
            //目标比中间值大
            else{
                //图二型
                if(nums[mid] >= nums[0]){
                    low = mid + 1;
                }
                //图一型
                else{
                    //在左端左部
                    if(target >= nums[0]){
                        high = mid - 1;
                        continue;
                    }
                    //在右端
                    else{
                        low = mid + 1;
                        return bs(nums, target, low, high);
                    }
                }
            }
        }
        return -1;
    }    
};


//nice codes:
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int lo = 0, hi = nums.size() - 1;
//         while (lo < hi) {
//             int mid = (lo + hi) / 2;
//             if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
//                 lo = mid + 1;
//             else
//                 hi = mid;
//         }
//         return lo == hi && nums[lo] == target ? lo : -1;
//     }
// };

// 作者：LukeLee
// 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
