class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        position = {value: index for index, value in enumerate(arr2)}
        res = sorted(arr1, key= lambda x: (0, position[x]) if x in position else (1, x))
        return res
        