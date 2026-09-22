func isAnagram(s string, t string) bool {
	var count [26]int

	for _, ch := range s {
		idx := int(ch) - int('a')
		count[idx] += 1
	}

	fmt.Println(count)

	for _, ch := range t {
		idx := int(ch) - int('a')
		count[idx] -= 1
	}

	for i := range(26) {
		if count[i] != 0 {
			return false
		}
	}

	return true

}
