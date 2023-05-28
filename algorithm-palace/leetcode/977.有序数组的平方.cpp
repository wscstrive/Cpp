// 给你一个按 非递减顺序 排序的整数数组 nums，返回每个数字的平方 组成的新数组，要求也按非递减顺序排序。

// c++
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l, r, k = 0, len(nums) - 1, len(nums) - 1
        result = [float('inf')] * len(nums)
        while l <= r:
            if nums[l] ** 2 < nums[r] ** 2:
                result[k] = nums[r] ** 2
                r -= 1
            else:
                result[k] = nums[l] ** 2
                l += 1
            k -= 1
        return result

// python
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l, r, k = 0, len(nums) - 1, len(nums) - 1
        result = [float('inf')] * len(nums)
        while l <= r:
            if nums[l] ** 2 < nums[r] ** 2:
                result[k] = nums[r] ** 2
                r -= 1
            else:
                result[k] = nums[l] ** 2
                l += 1
            k -= 1
        return result
