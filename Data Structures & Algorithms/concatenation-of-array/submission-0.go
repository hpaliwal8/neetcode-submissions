func getConcatenation(nums []int) []int {
    ans := make([]int, len(nums) * 2)

    for i := range len(nums) * 2 {
        idx := i % len(nums)
        ans[i] = nums[idx]
    }

    return ans
}
