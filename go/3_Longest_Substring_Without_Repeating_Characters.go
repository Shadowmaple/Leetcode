package leetcode

func lengthOfLongestSubstring(s string) int {
	if s == "" {
		return 0
	}

	x, y := 0, 0
	max := 1
	for i := 1; i < len(s); i++ {
		isRepeat := false
		for j := x; j <= y; j++ {
			if s[i] != s[j] {
				continue
			}
			x, y = j+1, i
			if max < y-x+1 {
				max = y - x + 1
			}
			isRepeat = true
			break
		}
		if !isRepeat {
			y = i
			if max < y-x+1 {
				max = y - x + 1
			}
		}
	}
	return max
}
