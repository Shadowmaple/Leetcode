class Solution:
    def reverseVowels(self, s: str) -> str:
        arr = list(s)
        i, j = 0, len(s)-1
        ch = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        while i < j:
            while arr[i] not in ch and i < j:
                i += 1
            while arr[j] not in ch and i < j:
                j -= 1
            if i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1
        return ''.join(arr)
