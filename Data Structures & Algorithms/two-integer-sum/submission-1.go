func twoSum(nums []int, target int) []int {
    set := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		if v, ok := set[target - nums[i]]; ok {
			return []int{v, i}
		}
		set[nums[i]] = i
	}

	return []int{-1, -1}
}
