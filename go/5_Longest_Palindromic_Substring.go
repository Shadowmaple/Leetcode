func longestPalindrome(s string) string {
    if len(s) <= 1 {
        return s
    }
    m, n := 0, 1
    for rank := 2; rank <= len(s); rank++ {
        for i := 0; i + rank <= len(s); i++ {
            if c := s[i : i + rank]; isValid(c) {
                m, n = i, i + rank
                break
            }
        }
    }
    return s[m:n]
}

func isValid(s string) bool {
    for i, j := 0, len(s) - 1; i < j; i, j = i+1, j-1 {
        if s[i] != s[j] {
            return false
        }
    }
    return true
}

