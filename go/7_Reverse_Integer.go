package leetcode

func reverse(x int) int {
	if x <= 9 && x >= -9 {
		return x
	}
	if x < 0 {
		return -reverse(-x)
	}
	y := 0
	for x > 0 {
		y = y*10 + x%10
		x /= 10
	}
	if y >= 2147483648 {
		return 0
	}
	return y
}
