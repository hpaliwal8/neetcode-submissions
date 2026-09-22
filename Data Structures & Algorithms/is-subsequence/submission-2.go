func isSubsequence(s string, t string) bool {
	var i, j int
	if len(s) == 0 {
		return true
	}
	m, n := len(s), len(t)

	for j < n {
		if i < m && s[i] == t[j] {
			i++
		}
		j++
	}

	return i == m

}
