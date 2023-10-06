function solution(prices) {
  let answer = []
  const stack = []
  const pos = []
  for (let i = 0; i < prices.length; i++) {
    while (stack.length !== 0 && stack[stack.length - 1] > prices[i]) {
      answer[pos[pos.length - 1]] = i - pos[pos.length - 1]
      pos.pop()
      stack.pop()
    }
    pos.push(i)
    stack.push(prices[i])
  }
  while (pos.length !== 0) {
    answer[pos[pos.length - 1]] = prices.length - pos[pos.length - 1] - 1
    pos.pop()
  }
  return answer
}
