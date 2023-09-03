function solution(numbers) {
  let answer = []
  let stack = [0]
  for (let i = 1; i < numbers.length; i++) {
    while (stack.length !== 0 && numbers[stack[stack.length - 1]] < numbers[i]) {
      answer[stack.pop()] = numbers[i]
    }
    stack.push(i)
  }
  for (let i = 0; i < stack.length; i++) answer[stack[i]] = -1
  return answer
}
