func replaceElements(arr []int) []int {
	n := len(arr)
	ans := make([]int, n)
	ans[n-1] = -1

	if n == 1 {
		return ans
	}

	maxTillNow := arr[n-1]
	for i := n - 2; i >= 0; i-- {
		ans[i] = maxTillNow
		maxTillNow = max(maxTillNow, arr[i])
	}

	return ans
}
