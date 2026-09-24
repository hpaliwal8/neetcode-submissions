class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def builder(index, temp):
            if index >= len(nums):
                res.append(temp.copy())
                return
            
            # include the num
            temp.append(nums[index])
            builder(index + 1, temp)
            temp.pop()

            # dont include the num
            builder(index + 1, temp)



        builder(0, [])
        return res