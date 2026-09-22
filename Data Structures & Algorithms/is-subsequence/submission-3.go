func isSubsequence(s string, t string) bool {
	var i, j int
	m, n := len(s), len(t)

	for i < m && j < n {
		if s[i] == t[j] {
			i++
		}
		j++
	}

	return i == m
}
