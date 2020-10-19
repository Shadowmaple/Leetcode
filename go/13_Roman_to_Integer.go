package leetcode

func romanToInt(s string) int {
	var num int
	numMap := map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	c := []byte(s)
	for i := 0; i < len(c)-1; i++ {
		n := numMap[c[i]]
		if n < numMap[c[i+1]] {
			num -= n
			continue
		}
		num += n
	}
	num += numMap[c[len(c)-1]]
	return num
}
