// 编写一个算法来判断一个数 n 是不是快乐数。

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (n > 0){
            int result = 0;
            while (n > 0){
                result += (n % 10) * (n % 10);
                n = n / 10;
            }

            if (result == 1){
                return true;
            }
            else if(hash.find(result) != hash.end()){
                return false;
            }
            hash.insert(result);
            n = result;
        }
        return false;
    }
};
