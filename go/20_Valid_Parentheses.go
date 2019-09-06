// 使用栈结构，FILO，0ms

func isValid(s string) bool {
    m := map[byte]byte{'(': ')', '[': ']', '{': '}'}
    var stack []byte
    top := 0
    
    for _, c := range []byte(s) {
        if top == 0 {
            stack = append(stack, c)
            top++
            continue
        }
        if m[stack[top-1]] == c {
            stack = stack[:top-1]
            top--
        } else if c == '(' || c == '{' || c == '[' {
            stack = append(stack, c)
            top++
        } else {
            return false
        }        
    }
    if top != 0 {
        return false
    }
    return true
}
