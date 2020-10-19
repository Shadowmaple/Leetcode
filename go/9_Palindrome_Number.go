package leetcode

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	} else if x == 0 {
		return true
	}

	a, b := 0, x
	for b != 0 {
		a = a*10 + b%10
		b /= 10
	}
	if a == x {
		return true
	}
	return false
}
