func appendCharacters(s string, t string) int {
    m := len(s)
	n := len(t)

	var i, j int
	for i < m && j < n {
		if s[i] == t[j] {
			j++
		}
		i++
	}

	return n - j
}