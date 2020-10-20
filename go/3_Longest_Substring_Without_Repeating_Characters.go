package leetcode

import "strings"

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

// 滑动窗口
func lengthOfLongestSubstring2(s string) int {
	var l, r int
	count := 0
	for ; r < len(s); r++ {
		i := strings.Index(s[l:r], s[r])
		if i != -1 {
			l += i + 1
			continue
		}
		if count < r-l+1 {
			count = r - l + 1
		}
	}
	return count
}
