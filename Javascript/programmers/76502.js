function solution(s) {
  let count = 0
  let len = s.length
  const list = {']': '[', ')': '(', '}': '{'}
  for (let x = 0; x < len; x++) {
    const stack = []
    for (let i = x; i < x + len; i++) {
      if (stack.length === 0 || stack[stack.length - 1] !== list[s[i % len]]) stack.push(s[i % len])
      else stack.pop()
    }
    if (stack.length === 0) count++
  }
  return count
}
