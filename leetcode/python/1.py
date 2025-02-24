class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_index = {}
        for i, num in enumerate(nums):
            if target - num in num_index:
                return [i, num_index[target-num]]
            num_index[num] = i