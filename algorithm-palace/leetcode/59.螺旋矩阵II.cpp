// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
// 1——2——3
//       |
// 8——9  4
// |     |
// 7——6——5

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;
        vector<vector<int>> answer(n, vector<int>(n));
        int k = 1;
        while (k <= n * n){
            for (int i = l; i <= r; k++, i++){
                answer[t][i] = k;
            }
            t++;
            for (int i = t; i <= b; k++, i++){
                answer[i][r] = k;
            }
            r--;
            for (int i = r; i >= l; k++, i--){
                answer[b][i] = k;
            }
            b--;
            for (int i = b; i >= t; k++, i--){
                answer[i][l] = k;
            }
            l++;
        }

        return answer;
    }
};

// python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        l, t, r, b, k = 0, 0, n - 1, n - 1, 1
        result = [[0] * n for _ in range(n)]
        while k <= n ** 2:
            for i in range(l, r + 1):
                result[t][i] = k
                k += 1
            t += 1
            for i in range(t, b + 1):
                result[i][r] = k
                k += 1
            r -= 1
            for i in range(r, l - 1, -1):
                result[b][i] = k
                k += 1
            b -= 1
            for i in range(b, t - 1, -1):
                result[i][l] = k
                k += 1
            l += 1
        return result
