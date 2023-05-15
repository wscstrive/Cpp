// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                   最大值
// ---------------                ----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

class Solution {
public:
    class Myque{
    public:
        deque<int> que;
        void pop(int value){
            if (!que.empty() && value == que.front()){
                que.pop_front();
            }
        }

        void push(int value){
            while (!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }

        int front(){
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        Myque que;
        for (int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); i++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
