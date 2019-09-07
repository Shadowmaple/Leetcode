// 傻瓜方法，遍历子串，从最长的开始通不过，要从最短的开始
func lengthOfLongestSubstring(s string) int {
    l := len(s)
    count := 0
    for size := 1; size <= l; size++ {
        flag := false
        for i := 0; i + size <= l; i++ {
            c := s[i : i + size]
            if !isRepeat(c) {
                count++
                flag = true
                break
            }
        }
        if !flag {
            return count
        }
    }
    return count
}

func isRepeat(s string) bool {
    for i := 0; i < len(s); i++ {
        c := []byte(s)
        a := append(c[:i], c[i+1:]...)
        if strings.Contains(string(a), string(s[i])) {
            return true
        }
    }
    return false
}

