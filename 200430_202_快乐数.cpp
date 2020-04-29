// 202. 快乐数
// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

// 如果 n 是快乐数就返回 True ；不是，则返回 False 。

 

// 示例：

// 输入：19
// 输出：true
// 解释：
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// https://leetcode-cn.com/problems/happy-number/


//My Codes
// 执行结果：通过
// 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗 :5.7 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    bool isHappy(int n) {
        int a, b, c, d, e, f, g, h, i, j, sum;
        while(true){
            //int 最高10位，做十次
            a = n % 10;
            b = (n / 10) % 10;
            c = (n / 100) % 10;
            d = (n / 1000) % 10;
            e = (n / 10000) % 10;
            f = (n / 100000) % 10;
            g = (n / 1000000) % 10;
            h = (n / 10000000) % 10;
            i = (n / 100000000) % 10;
            j = (n / 1000000000) % 10;
            //cout << d << c << b << a;
            //Cpp次方是pow(a,b),a必须是double,需要<cmake>
            sum = a * a + b * b + c * c + d * d + e * e + f * f+ g * g + h*h+i*i+j*j;
            //cout << sum << endl;
            if(sum == 1 || sum == 7){
                return true;
            }
            else if(sum / 10 == 0 && sum != 1 && sum != 7){
                return false;
            }
            n = sum;
        }
    }
};


//nice codes:
// 方法：使用“快慢指针”思想找出循环：“快指针”每次走两步，“慢指针”每次走一步，当二者相等时，即为一个循环周期。
// 此时，判断是不是因为1引起的循环，是的话就是快乐数，否则不是快乐数。
// 注意：此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；
// 另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。不要因为这个题目给出的整数是int型而投机取巧。

class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);
        
        return slow == 1;
    }
};


// 作者：linux-man
// 链接：https://leetcode-cn.com/problems/happy-number/solution/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




// 2.
// Magic number一般是指硬写到代码里的整数常量，数值是编程者自己指定的，
// 其他人不知道数值有什么具体意义，表示不明觉厉，就称作magic number。
// 而编程教材书用magic number指代初学者不定义常量直接写数的不良习惯。

// 但我觉得这样定义是过于片面的。
// 很多编程问题的求解对应数学上的迭代收敛问题，而一些特定的迭代函数能够快速收敛，从而大大提高求解的效率。
// 例如著名的平方根倒数算法：

// i = 0x5f3759df - ( i >> 1 );

// 平方根倒数速算法在速度上的优势源自将浮点数转化为长整型以作整数看待，并用特定常数0x5f3759df与之相减。
// 如此将浮点数当作整数先位移后减法，所得的浮点数结果即是对输入数字的平方根倒数的粗略估计值，
// 而后再进行一次牛顿迭代法，以使之更精确后，代码即执行完毕。
// 由于算法所生成的用于输入牛顿法的首次近似值已经相当精确，此算法所得近似值的精度已可接受。
// 又如拉马努金公式及其变体Chudnovsky公式是最快的级数公式之一，可以以超线性的速度收敛，这些公式中的魔数为我们的程序插上了魔力的翅膀。

// 在这个问题中，我们同样可以找到这样的魔数，
// 由于所有的非快乐数最终都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中，
// 我们只有在跳出条件中添加这些魔数，就能让我们用非一般的速度完成求解：


bool isHappy(int n){
    short _n;
    while(n!= 0 && n != 1 && n != 4 && n != 16 && n != 37 && n != 58 
    && n != 89 && n != 145 && n != 42 && n != 20) {
        _n = 0;
        while(n) {
            _n = _n + pow(n % 10, 2);
            n = n / 10;
        }
        n = _n;
    }
    if(n == 1) return 1;
    else return 0;
}

// 作者：JemmyYu
// 链接：https://leetcode-cn.com/problems/happy-number/solution/ni-ting-shuo-guo-mo-shu-ma-by-jemmyyu/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。