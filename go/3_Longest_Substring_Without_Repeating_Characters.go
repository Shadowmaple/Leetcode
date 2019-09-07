func lengthOfLongestSubstring(s string) int {
    if s == "" {
        return 0
    }
    max := 0
    l := make([]byte, 0)
    var c string
    for i := 0; i < len(s); i++ {
        j := strings.Index(c, string(s[i]))
        if j == -1 {
            l = append(l, s[i])
            c = string(l)
            if lens := len(l); max < lens {
                max = lens
            }
            continue
        }
        l = append(l[j + 1:], l[j])
        c = string(l)
        if lens := len(l); max < lens {
            max = lens
        }
    }
    return max
}
