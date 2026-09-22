func twoSum(nums []int, target int) []int {
    set := make(map[int]int)

	for i, num := range nums {
		if v, ok := set[target - num]; ok {
			return []int{v, i}
		}
		set[num] = i
	}

	return []int{-1, -1}
}
