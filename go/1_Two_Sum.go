package leetcode

func twoSum(nums []int, target int) []int {
    numMap := make(map[int]int)
    for index, num := range(nums) {
        m := target - num
        if i, exist := numMap[m]; exist {
            return []int{i, index}
        }
        numMap[num] = index
    }
    return nil
}
