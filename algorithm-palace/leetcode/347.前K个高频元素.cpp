// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

class Solution {
public:
    class Mycomparison{
    public:
        bool operator()(const pair<int, int>& left, const pair<int,int>& right){
            return left.second > right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Mycomparison> pri_que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if (pri_que.size() > k){
                pri_que.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};
